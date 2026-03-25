//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "StereolabsCudaInterop.h"

#include "ID3D11DynamicRHI.h"
#include "ID3D12DynamicRHI.h"
#include "D3D11RHI.h"
#include "D3D11Util.h"
#include "RHICommandList.h"
#include "RHIDefinitions.h"

#include "Utilities/StereolabsMatFunctionLibrary.h"
#include "Core/StereolabsTexture.h"

#include "Windows/AllowWindowsPlatformTypes.h" 
#include <cuda_d3d11_interop.h>

#include <aclapi.h>
#include "Windows/HideWindowsPlatformTypes.h"

THIRD_PARTY_INCLUDES_START
#include <d3d12.h>
THIRD_PARTY_INCLUDES_END


static void CheckCudaError(cudaError_t result) {
#if !UE_BUILD_SHIPPING
	if (result) {
		UE_LOG(SlTexture, Error, TEXT("CUDA error: %hs"), cudaGetErrorString(result));
		check(false);
	}
#endif
}

struct FScopedCudaContext
{
	FScopedCudaContext()
	{
		if (GSlCameraProxy)
			GSlCameraProxy->PushCudaContext();
	}
	~FScopedCudaContext()
	{
		if (GSlCameraProxy)
			GSlCameraProxy->PopCudaContext();
	}
};


// D3D11 IMPLEMENTATION

void IStereolabsCudaInteropSyncPoint::SyncCudaToGraphics(const IStereolabsCudaInterop* Resource,
	FRHICommandListImmediate& RHICmdList, cudaStream_t Stream)
{
	TArrayView<const IStereolabsCudaInterop*> ResourceArray( &Resource, 1 );
	SyncCudaToGraphics(ResourceArray, RHICmdList, Stream);
}

void IStereolabsCudaInteropSyncPoint::SyncGraphicsToCuda(const IStereolabsCudaInterop* Resource,
	FRHICommandListImmediate& RHICmdList, cudaStream_t Stream)
{
	TArrayView<const IStereolabsCudaInterop*> ResourceArray( &Resource, 1 );
	SyncGraphicsToCuda(ResourceArray, RHICmdList, Stream);
}

FStereolabsCudaInteropD3D11::FStereolabsCudaInteropD3D11(FTextureRHIRef TextureRHI)
{
	check(TextureRHI);
	FScopedCudaContext CudaContext;

	ID3D11Resource* D3D11NativeTexture = GetID3D11DynamicRHI()->RHIGetResource(TextureRHI);
	CheckCudaError(cudaGraphicsD3D11RegisterResource(&CudaResource, D3D11NativeTexture, cudaGraphicsMapFlagsNone));
}

FStereolabsCudaInteropD3D11::~FStereolabsCudaInteropD3D11()
{
	FScopedCudaContext CudaContext;

	if (CudaResource)
	{
		CheckCudaError(cudaGraphicsUnregisterResource(CudaResource));
	}
}

void FStereolabsCudaInteropD3D11::UpdateTexture(void* Mat, FRHICommandListImmediate& RHICmdList, cudaStream_t Stream)
{
	check(IsInRenderingThread());

	FScopedCudaContext CudaContext;

	cudaArray_t Array = nullptr;
	CheckCudaError(cudaGraphicsSubResourceGetMappedArray(&Array, CudaResource, 0, 0));

	CheckCudaError(cudaMemcpy2DToArrayAsync(
		Array, 0, 0, 
		sl_mat_get_ptr(Mat, SL_MEM_GPU), sl_mat_get_step_bytes(Mat, SL_MEM_GPU), sl_mat_get_width_bytes(Mat), sl_mat_get_height(Mat),
		cudaMemcpyDeviceToDevice, Stream));
}


void FStereolabsCudaInteropSyncPointD3D11::SyncCudaToGraphics(TArrayView<const IStereolabsCudaInterop*> Resources,
	FRHICommandListImmediate& RHICmdList, cudaStream_t Stream)
{
	check(IsInRenderingThread());

	FScopedCudaContext CudaContext;

	TArray<cudaGraphicsResource_t> CudaResources;
	CudaResources.Reserve(Resources.Num());
	for (const IStereolabsCudaInterop* Resource : Resources)
	{
		CudaResources.Add(static_cast<const FStereolabsCudaInteropD3D11*>(Resource)->GetCudaResource());
	}

	CheckCudaError(cudaGraphicsMapResources(Resources.Num(), CudaResources.GetData(), Stream));
}

void FStereolabsCudaInteropSyncPointD3D11::SyncGraphicsToCuda(TArrayView<const IStereolabsCudaInterop*> Resources,
	FRHICommandListImmediate& RHICmdList, cudaStream_t Stream)
{
	check(IsInRenderingThread());

	FScopedCudaContext CudaContext;

	TArray<cudaGraphicsResource_t> CudaResources;
	CudaResources.Reserve(Resources.Num());
	for (const IStereolabsCudaInterop* Resource : Resources)
	{
		CudaResources.Add(static_cast<const FStereolabsCudaInteropD3D11*>(Resource)->GetCudaResource());
	}

	CheckCudaError(cudaGraphicsUnmapResources(Resources.Num(), CudaResources.GetData(), Stream));
}


// D3D12 IMPLEMENTATION

// From simpleD3D12 CUDA sample (https://github.com/NVIDIA/cuda-samples/tree/master/Samples/5_Domain_Specific/simpleD3D12)
class FWindowsSecurityAttributes
{
protected:
	SECURITY_ATTRIBUTES  m_winSecurityAttributes;
	PSECURITY_DESCRIPTOR m_winPSecurityDescriptor;

public:
	FWindowsSecurityAttributes()
	{
		m_winPSecurityDescriptor = (PSECURITY_DESCRIPTOR)calloc(1, SECURITY_DESCRIPTOR_MIN_LENGTH + 2 * sizeof(void**));
		check(m_winPSecurityDescriptor != (PSECURITY_DESCRIPTOR)NULL);

		PSID* ppSID = (PSID*)((PBYTE)m_winPSecurityDescriptor + SECURITY_DESCRIPTOR_MIN_LENGTH);
		PACL* ppACL = (PACL*)((PBYTE)ppSID + sizeof(PSID*));

		InitializeSecurityDescriptor(m_winPSecurityDescriptor, SECURITY_DESCRIPTOR_REVISION);

		SID_IDENTIFIER_AUTHORITY sidIdentifierAuthority = SECURITY_WORLD_SID_AUTHORITY;
		AllocateAndInitializeSid(&sidIdentifierAuthority, 1, SECURITY_WORLD_RID, 0, 0, 0, 0, 0, 0, 0, ppSID);

		EXPLICIT_ACCESS explicitAccess;
		ZeroMemory(&explicitAccess, sizeof(EXPLICIT_ACCESS));
		explicitAccess.grfAccessPermissions = STANDARD_RIGHTS_ALL | SPECIFIC_RIGHTS_ALL;
		explicitAccess.grfAccessMode = SET_ACCESS;
		explicitAccess.grfInheritance = INHERIT_ONLY;
		explicitAccess.Trustee.TrusteeForm = TRUSTEE_IS_SID;
		explicitAccess.Trustee.TrusteeType = TRUSTEE_IS_WELL_KNOWN_GROUP;
		explicitAccess.Trustee.ptstrName = (LPTSTR)*ppSID;

		SetEntriesInAcl(1, &explicitAccess, NULL, ppACL);

		SetSecurityDescriptorDacl(m_winPSecurityDescriptor, true, *ppACL, false);

		m_winSecurityAttributes.nLength = sizeof(m_winSecurityAttributes);
		m_winSecurityAttributes.lpSecurityDescriptor = m_winPSecurityDescriptor;
		m_winSecurityAttributes.bInheritHandle = true;
	}
	~FWindowsSecurityAttributes()
	{
		PSID* ppSID = (PSID*)((PBYTE)m_winPSecurityDescriptor + SECURITY_DESCRIPTOR_MIN_LENGTH);
		PACL* ppACL = (PACL*)((PBYTE)ppSID + sizeof(PSID*));

		if (*ppSID) {
			FreeSid(*ppSID);
		}
		if (*ppACL) {
			LocalFree(*ppACL);
		}
		free(m_winPSecurityDescriptor);
	}
	SECURITY_ATTRIBUTES* operator&() { return &m_winSecurityAttributes; }
};


// Modified from CUDA documentation (https://docs.nvidia.com/cuda/cuda-programming-guide/04-special-topics/graphics-interop.html#mapping-mipmapped-arrays-onto-imported-memory-objects-dir3d-12-int)
cudaChannelFormatDesc getCudaChannelFormatDescForDxgiFormat(DXGI_FORMAT dxgiFormat)
{
	cudaChannelFormatDesc d;

	memset(&d, 0, sizeof(d));

	switch (dxgiFormat) {
	case DXGI_FORMAT_R8_UINT:            d.x = 8;  d.y = 0;  d.z = 0;  d.w = 0;  d.f = cudaChannelFormatKindUnsigned;				break;
	case DXGI_FORMAT_R8_SINT:            d.x = 8;  d.y = 0;  d.z = 0;  d.w = 0;  d.f = cudaChannelFormatKindSigned;					break;
	case DXGI_FORMAT_R8G8_UINT:          d.x = 8;  d.y = 8;  d.z = 0;  d.w = 0;  d.f = cudaChannelFormatKindUnsigned;				break;
	case DXGI_FORMAT_R8G8_SINT:          d.x = 8;  d.y = 8;  d.z = 0;  d.w = 0;  d.f = cudaChannelFormatKindSigned;					break;
	case DXGI_FORMAT_R8G8B8A8_UINT:      d.x = 8;  d.y = 8;  d.z = 8;  d.w = 8;  d.f = cudaChannelFormatKindUnsigned;				break;
	case DXGI_FORMAT_R8G8B8A8_SINT:      d.x = 8;  d.y = 8;  d.z = 8;  d.w = 8;  d.f = cudaChannelFormatKindSigned;					break;
	case DXGI_FORMAT_R8G8B8A8_UNORM:     d.x = 8;  d.y = 8;  d.z = 8;  d.w = 8;  d.f = cudaChannelFormatKindUnsignedNormalized8X4;  break;
	case DXGI_FORMAT_R8G8B8A8_SNORM:     d.x = 8;  d.y = 8;  d.z = 8;  d.w = 8;  d.f = cudaChannelFormatKindSignedNormalized8X4;	break;
	case DXGI_FORMAT_R16_UINT:           d.x = 16; d.y = 0;  d.z = 0;  d.w = 0;  d.f = cudaChannelFormatKindUnsigned;				break;
	case DXGI_FORMAT_R16_SINT:           d.x = 16; d.y = 0;  d.z = 0;  d.w = 0;  d.f = cudaChannelFormatKindSigned;					break;
	case DXGI_FORMAT_R16G16_UINT:        d.x = 16; d.y = 16; d.z = 0;  d.w = 0;  d.f = cudaChannelFormatKindUnsigned;				break;
	case DXGI_FORMAT_R16G16_SINT:        d.x = 16; d.y = 16; d.z = 0;  d.w = 0;  d.f = cudaChannelFormatKindSigned;					break;
	case DXGI_FORMAT_R16G16B16A16_UINT:  d.x = 16; d.y = 16; d.z = 16; d.w = 16; d.f = cudaChannelFormatKindUnsigned;				break;
	case DXGI_FORMAT_R16G16B16A16_SINT:  d.x = 16; d.y = 16; d.z = 16; d.w = 16; d.f = cudaChannelFormatKindSigned;					break;
	case DXGI_FORMAT_R32_UINT:           d.x = 32; d.y = 0;  d.z = 0;  d.w = 0;  d.f = cudaChannelFormatKindUnsigned;				break;
	case DXGI_FORMAT_R32_SINT:           d.x = 32; d.y = 0;  d.z = 0;  d.w = 0;  d.f = cudaChannelFormatKindSigned;					break;
	case DXGI_FORMAT_R32_FLOAT:          d.x = 32; d.y = 0;  d.z = 0;  d.w = 0;  d.f = cudaChannelFormatKindFloat;					break;
	case DXGI_FORMAT_R32G32_UINT:        d.x = 32; d.y = 32; d.z = 0;  d.w = 0;  d.f = cudaChannelFormatKindUnsigned;				break;
	case DXGI_FORMAT_R32G32_SINT:        d.x = 32; d.y = 32; d.z = 0;  d.w = 0;  d.f = cudaChannelFormatKindSigned;					break;
	case DXGI_FORMAT_R32G32_FLOAT:       d.x = 32; d.y = 32; d.z = 0;  d.w = 0;  d.f = cudaChannelFormatKindFloat;					break;
	case DXGI_FORMAT_R32G32B32A32_UINT:  d.x = 32; d.y = 32; d.z = 32; d.w = 32; d.f = cudaChannelFormatKindUnsigned;				break;
	case DXGI_FORMAT_R32G32B32A32_SINT:  d.x = 32; d.y = 32; d.z = 32; d.w = 32; d.f = cudaChannelFormatKindSigned;					break;
	case DXGI_FORMAT_R32G32B32A32_FLOAT: d.x = 32; d.y = 32; d.z = 32; d.w = 32; d.f = cudaChannelFormatKindFloat;					break;
	default: check(false);
	}
	return d;
}

// From CUDA documentation (https://docs.nvidia.com/cuda/cuda-programming-guide/04-special-topics/graphics-interop.html#mapping-mipmapped-arrays-onto-imported-memory-objects-dir3d-12-int)
cudaExtent getCudaExtentForD3D12Extent(UINT64 width, UINT height, UINT16 depthOrArraySize, D3D12_SRV_DIMENSION d3d12SRVDimension) {
	cudaExtent e = { 0, 0, 0 };

	switch (d3d12SRVDimension) {
	case D3D12_SRV_DIMENSION_TEXTURE1D:        e.width = width; e.height = 0;      e.depth = 0;                break;
	case D3D12_SRV_DIMENSION_TEXTURE2D:        e.width = width; e.height = height; e.depth = 0;                break;
	case D3D12_SRV_DIMENSION_TEXTURE3D:        e.width = width; e.height = height; e.depth = depthOrArraySize; break;
	case D3D12_SRV_DIMENSION_TEXTURECUBE:      e.width = width; e.height = height; e.depth = depthOrArraySize; break;
	case D3D12_SRV_DIMENSION_TEXTURE1DARRAY:   e.width = width; e.height = 0;      e.depth = depthOrArraySize; break;
	case D3D12_SRV_DIMENSION_TEXTURE2DARRAY:   e.width = width; e.height = height; e.depth = depthOrArraySize; break;
	case D3D12_SRV_DIMENSION_TEXTURECUBEARRAY: e.width = width; e.height = height; e.depth = depthOrArraySize; break;
	default: check(false);
	}

	return e;
}

// From CUDA documentation (https://docs.nvidia.com/cuda/cuda-programming-guide/04-special-topics/graphics-interop.html#mapping-mipmapped-arrays-onto-imported-memory-objects-dir3d-12-int)
unsigned int getCudaMipmappedArrayFlagsForD3D12Resource(D3D12_SRV_DIMENSION d3d12SRVDimension, D3D12_RESOURCE_FLAGS d3d12ResourceFlags, bool allowSurfaceLoadStore) {
	unsigned int flags = 0;

	switch (d3d12SRVDimension) {
	case D3D12_SRV_DIMENSION_TEXTURECUBE:      flags |= cudaArrayCubemap;                    break;
	case D3D12_SRV_DIMENSION_TEXTURECUBEARRAY: flags |= cudaArrayCubemap | cudaArrayLayered; break;
	case D3D12_SRV_DIMENSION_TEXTURE1DARRAY:   flags |= cudaArrayLayered;                    break;
	case D3D12_SRV_DIMENSION_TEXTURE2DARRAY:   flags |= cudaArrayLayered;                    break;
	default: break;
	}

	if (d3d12ResourceFlags & D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET) {
		flags |= cudaArrayColorAttachment;
	}
	if (allowSurfaceLoadStore) {
		flags |= cudaArraySurfaceLoadStore;
	}

	return flags;
}


FStereolabsCudaInteropD3D12::FStereolabsCudaInteropD3D12(FTextureRHIRef TextureRHI)
	: OutputTexture(TextureRHI)
{
	FScopedCudaContext CudaContext;

	check(TextureRHI);

	bOutputTextureSupportsInterop = EnumHasAnyFlags(OutputTexture->GetDesc().Flags, TexCreate_Shared);

	// D3D12 Interop textures must be created with TexCreate_Shared
	if (!bOutputTextureSupportsInterop)
	{
		// Create the staging texture
		ENQUEUE_RENDER_COMMAND(CreateSharedTexture)([this](FRHICommandListImmediate& CmdList)
			{
				FRHITextureCreateDesc Desc{
					OutputTexture->GetDesc(),
					ERHIAccess::SRVMask,
					TEXT("StereolabsCudaInteropStagingTexture")
				};
				Desc.Flags |= TexCreate_Shared;
#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 7
				FRHITextureInitializer TexInitializer = GDynamicRHI->RHICreateTextureInitializer(CmdList, Desc);
				this->CudaInteropStagingTexture = TexInitializer.Finalize();
#else
				this->CudaInteropStagingTexture = GDynamicRHI->RHICreateTexture(CmdList, Desc);
#endif
			});

		FlushRenderingCommands();
	}

	ID3D12DynamicRHI* D3D12RHI = GetID3D12DynamicRHI();
	uint32 NodeMask = D3D12RHI->RHIGetDeviceNodeMask(0);

	ID3D12Resource* D3D12NativeResource = D3D12RHI->RHIGetResource(bOutputTextureSupportsInterop ? OutputTexture : CudaInteropStagingTexture);

	HANDLE SharedHandle;
	FWindowsSecurityAttributes WindowsSecurityAttributes;
	D3D12RHI->RHIGetDevice(0)->CreateSharedHandle(D3D12NativeResource, &WindowsSecurityAttributes, GENERIC_ALL, nullptr, &SharedHandle);

	D3D12_RESOURCE_DESC ResourceDesc = D3D12NativeResource->GetDesc();
	D3D12_RESOURCE_ALLOCATION_INFO ResourceAllocationInfo = D3D12RHI->RHIGetDevice(0)->GetResourceAllocationInfo(NodeMask, 1, &ResourceDesc);

	cudaExternalMemoryHandleDesc ExternalMemoryDesc = {};
	memset(&ExternalMemoryDesc, 0, sizeof(ExternalMemoryDesc));

	ExternalMemoryDesc.type = cudaExternalMemoryHandleTypeD3D12Resource;
	ExternalMemoryDesc.handle.win32.handle = SharedHandle;
	ExternalMemoryDesc.size = ResourceAllocationInfo.SizeInBytes;
	ExternalMemoryDesc.flags = cudaExternalMemoryDedicated;

	CheckCudaError(cudaImportExternalMemory(&CudaExternalMemory, &ExternalMemoryDesc));

	cudaExternalMemoryMipmappedArrayDesc MipmappedArrayDesc = {};
	memset(&MipmappedArrayDesc, 0, sizeof(MipmappedArrayDesc));

	MipmappedArrayDesc.offset = 0;
	MipmappedArrayDesc.formatDesc = getCudaChannelFormatDescForDxgiFormat(ResourceDesc.Format);
	MipmappedArrayDesc.extent = getCudaExtentForD3D12Extent(ResourceDesc.Width, ResourceDesc.Height, ResourceDesc.DepthOrArraySize, D3D12_SRV_DIMENSION_TEXTURE2D);
	MipmappedArrayDesc.flags = getCudaMipmappedArrayFlagsForD3D12Resource(D3D12_SRV_DIMENSION_TEXTURE2D, ResourceDesc.Flags, false);
	MipmappedArrayDesc.numLevels = 1;

	CheckCudaError(cudaExternalMemoryGetMappedMipmappedArray(&CudaMipmappedArray, CudaExternalMemory, &MipmappedArrayDesc));

	CloseHandle(SharedHandle);
}

FStereolabsCudaInteropD3D12::~FStereolabsCudaInteropD3D12()
{
	FScopedCudaContext CudaContext;

	if (CudaMipmappedArray)
	{
		CheckCudaError(cudaFreeMipmappedArray(CudaMipmappedArray));
	}
	if (CudaExternalMemory)
	{
		CheckCudaError(cudaDestroyExternalMemory(CudaExternalMemory));
	}
}

void FStereolabsCudaInteropD3D12::UpdateTexture(void* Mat, FRHICommandListImmediate& RHICmdList, cudaStream_t Stream)
{
	check(IsInRenderingThread());

	FScopedCudaContext CudaContext;

	cudaArray_t LevelArray = nullptr;
	CheckCudaError(cudaGetMipmappedArrayLevel(&LevelArray, CudaMipmappedArray, 0));

	CheckCudaError(cudaMemcpy2DToArrayAsync(
		LevelArray, 0, 0,
		sl_mat_get_ptr(Mat, SL_MEM_GPU), sl_mat_get_step_bytes(Mat, SL_MEM_GPU), sl_mat_get_width_bytes(Mat), sl_mat_get_height(Mat),
		cudaMemcpyDeviceToDevice, Stream));

	if (!bOutputTextureSupportsInterop)
	{
		FRHICopyTextureInfo CopyInfo{ };
		RHICmdList.CopyTexture(CudaInteropStagingTexture, OutputTexture, CopyInfo);
	}
}


FStereolabsCudaInteropSyncPointD3D12::FStereolabsCudaInteropSyncPointD3D12()
{
	FScopedCudaContext CudaContext;

	ID3D12DynamicRHI* D3D12RHI = GetID3D12DynamicRHI();

	// Create synchronization objects
	D3D12RHI->RHIGetDevice(0)->CreateFence(0, D3D12_FENCE_FLAG_SHARED, IID_PPV_ARGS(Fence.GetInitReference()));

	HANDLE SharedHandle;
	FWindowsSecurityAttributes WindowsSecurityAttributes;
	D3D12RHI->RHIGetDevice(0)->CreateSharedHandle(Fence.GetReference(), &WindowsSecurityAttributes, GENERIC_ALL, nullptr, &SharedHandle);

	cudaExternalSemaphoreHandleDesc ExternalSemaphoreHandleDesc = {};
	memset(&ExternalSemaphoreHandleDesc, 0, sizeof(ExternalSemaphoreHandleDesc));

	ExternalSemaphoreHandleDesc.type = cudaExternalSemaphoreHandleTypeD3D12Fence;
	ExternalSemaphoreHandleDesc.handle.win32.handle = SharedHandle;
	ExternalSemaphoreHandleDesc.flags = 0;

	CheckCudaError(cudaImportExternalSemaphore(&CudaExternalSemaphore, &ExternalSemaphoreHandleDesc));

	CloseHandle(SharedHandle);

	// Set initial fence value
	FenceValue = 1;
}

FStereolabsCudaInteropSyncPointD3D12::~FStereolabsCudaInteropSyncPointD3D12()
{
	FScopedCudaContext CudaContext;

	if (CudaExternalSemaphore)
	{
		CheckCudaError(cudaDestroyExternalSemaphore(CudaExternalSemaphore));
	}
	if (Fence)
	{
		Fence.SafeRelease();
	}
}

void FStereolabsCudaInteropSyncPointD3D12::SyncCudaToGraphics(TArrayView<const IStereolabsCudaInterop*> Resources,
	FRHICommandListImmediate& RHICmdList, cudaStream_t Stream)
{
	check(IsInRenderingThread());

	FScopedCudaContext CudaContext;

	// Signal fence
	GetID3D12DynamicRHI()->RHIRunOnQueue(ED3D12RHIRunOnQueueType::Graphics, [this](ID3D12CommandQueue* Queue)
		{
			Queue->Signal(Fence, FenceValue);
		}, true);

	// Make cuda wait on signalled fence
	cudaExternalSemaphoreWaitParams ExternalSemaphoreWaitParams = {};
	memset(&ExternalSemaphoreWaitParams, 0, sizeof(ExternalSemaphoreWaitParams));

	ExternalSemaphoreWaitParams.params.fence.value = FenceValue;
	ExternalSemaphoreWaitParams.flags = 0;

	CheckCudaError(cudaWaitExternalSemaphoresAsync(&CudaExternalSemaphore, &ExternalSemaphoreWaitParams, 1, Stream));

	FenceValue++;
}

void FStereolabsCudaInteropSyncPointD3D12::SyncGraphicsToCuda(TArrayView<const IStereolabsCudaInterop*> Resources,
	FRHICommandListImmediate& RHICmdList, cudaStream_t Stream)
{
	check(IsInRenderingThread());

	FScopedCudaContext CudaContext;

	// Signal fence
	cudaExternalSemaphoreSignalParams ExternalSemaphoreSignalParams = {};
	memset(&ExternalSemaphoreSignalParams, 0, sizeof(ExternalSemaphoreSignalParams));

	ExternalSemaphoreSignalParams.params.fence.value = FenceValue;
	ExternalSemaphoreSignalParams.flags = 0;

	CheckCudaError(cudaSignalExternalSemaphoresAsync(&CudaExternalSemaphore, &ExternalSemaphoreSignalParams, 1, Stream));

	// Make graphics queue wait on signalled fence
	GetID3D12DynamicRHI()->RHIRunOnQueue(ED3D12RHIRunOnQueueType::Graphics, [this](ID3D12CommandQueue* Queue)
		{
			Queue->Wait(Fence, FenceValue);
		}, true);

	FenceValue++;
}
