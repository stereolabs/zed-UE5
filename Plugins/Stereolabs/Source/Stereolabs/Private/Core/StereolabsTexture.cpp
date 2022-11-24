//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "Stereolabs/Public/Core/StereolabsTexture.h"
#include "StereolabsPrivatePCH.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"
#include "Stereolabs/Public/Utilities/StereolabsMatFunctionLibrary.h"

#include "RHI.h"
#include "RenderResource.h"

#include "D3D11RHIPrivate.h"
#include "D3D11StateCachePrivate.h"
#include "D3D11State.h"
typedef FD3D11StateCacheBase FD3D11StateCache;
#include "D3D11Resources.h"

#include "D3D12RHIPrivate.h"
#include "D3D12Util.h"

#include "Windows/AllowWindowsPlatformTypes.h" 
#include <aclapi.h>
#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_d3d11_interop.h>
#include <cuda_gl_interop.h>
#include "Windows/HideWindowsPlatformTypes.h"

#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(SlTexture);

#define CHECK_UPDATE_VALID()\
	if (MemoryType == ESlMemoryType::MT_CPU)\
	{\
		SL_LOG_E(SlTexture, "Trying to update texture %s which is a CPU texture.", *Name.ToString());\
		return;\
	}\
	else if (!Texture)\
	{\
		SL_LOG_E(SlTexture, "Trying to update texture %s which is not created.", *Name.ToString());\
		return;\
	}\
	else if (!CudaResource)\
	{\
		SL_LOG_E(SlTexture, "Trying to update texture %s which cuda resource is not registered.", *Name.ToString());\
		return;\
	}\

#define CHECK_CUDA_MEMCPY(CudaError)\
	if (CudaError != cudaSuccess)\
	{\
		SL_LOG_E(SlTexture, "Error while updating texture %s: %s", *Name.ToString(), *FString(cudaGetErrorString(CudaError)));\
	}\

//////////////////////////////////////////////
// WindowsSecurityAttributes implementation //
//////////////////////////////////////////////

class WindowsSecurityAttributes {
protected:
	SECURITY_ATTRIBUTES m_winSecurityAttributes;
	PSECURITY_DESCRIPTOR m_winPSecurityDescriptor;

public:
	WindowsSecurityAttributes();
	~WindowsSecurityAttributes();
	SECURITY_ATTRIBUTES* operator&();
};

WindowsSecurityAttributes::WindowsSecurityAttributes() {
	m_winPSecurityDescriptor = (PSECURITY_DESCRIPTOR)calloc(
		1, SECURITY_DESCRIPTOR_MIN_LENGTH + 2 * sizeof(void**));
	assert(m_winPSecurityDescriptor != (PSECURITY_DESCRIPTOR)NULL);

	PSID* ppSID = (PSID*)((PBYTE)m_winPSecurityDescriptor +
		SECURITY_DESCRIPTOR_MIN_LENGTH);
	PACL* ppACL = (PACL*)((PBYTE)ppSID + sizeof(PSID*));

	InitializeSecurityDescriptor(m_winPSecurityDescriptor,
		SECURITY_DESCRIPTOR_REVISION);

	SID_IDENTIFIER_AUTHORITY sidIdentifierAuthority =
		SECURITY_WORLD_SID_AUTHORITY;
	AllocateAndInitializeSid(&sidIdentifierAuthority, 1, SECURITY_WORLD_RID, 0, 0,
		0, 0, 0, 0, 0, ppSID);

	EXPLICIT_ACCESS explicitAccess;
	ZeroMemory(&explicitAccess, sizeof(EXPLICIT_ACCESS));
	explicitAccess.grfAccessPermissions =
		STANDARD_RIGHTS_ALL | SPECIFIC_RIGHTS_ALL;
	explicitAccess.grfAccessMode = SET_ACCESS;
	explicitAccess.grfInheritance = INHERIT_ONLY;
	explicitAccess.Trustee.TrusteeForm = TRUSTEE_IS_SID;
	explicitAccess.Trustee.TrusteeType = TRUSTEE_IS_WELL_KNOWN_GROUP;
	explicitAccess.Trustee.ptstrName = (LPTSTR)*ppSID;

	SetEntriesInAcl(1, &explicitAccess, NULL, ppACL);

	SetSecurityDescriptorDacl(m_winPSecurityDescriptor, 1, *ppACL, 0);

	m_winSecurityAttributes.nLength = sizeof(m_winSecurityAttributes);
	m_winSecurityAttributes.lpSecurityDescriptor = m_winPSecurityDescriptor;
	m_winSecurityAttributes.bInheritHandle = 1;
}

WindowsSecurityAttributes::~WindowsSecurityAttributes() {
	PSID* ppSID = (PSID*)((PBYTE)m_winPSecurityDescriptor +
		SECURITY_DESCRIPTOR_MIN_LENGTH);
	PACL* ppACL = (PACL*)((PBYTE)ppSID + sizeof(PSID*));

	if (*ppSID) {
		FreeSid(*ppSID);
	}
	if (*ppACL) {
		LocalFree(*ppACL);
	}
	free(m_winPSecurityDescriptor);
}

SECURITY_ATTRIBUTES* WindowsSecurityAttributes::operator&() {
	return &m_winSecurityAttributes;
}

USlTexture::USlTexture()
	:
	Texture(nullptr),
	CudaResource(nullptr)
{
}

void USlTexture::BeginDestroy()
{
	if (CudaResource)
	{
		if (GSlCameraProxy && GSlCameraProxy->IsCameraOpened())
		{
			GSlCameraProxy->PushCudaContext();

			cudaGraphicsUnregisterResource(CudaResource);

			GSlCameraProxy->PopCudaContext();
		}

		CudaResource = nullptr;
	}

	if (Mat.Mat) {
		SL_MEM mem = (SL_MEM)sl_mat_get_memory_type(Mat.Mat);
		sl_mat_free(Mat.Mat, mem);
	}

	Super::BeginDestroy();
}

void USlTexture::BP_UpdateTexture()
{
#if WITH_EDITOR
	CHECK_UPDATE_VALID();
#endif

	ENQUEUE_RENDER_COMMAND(UpdateGPUTexture)(
		[this](FRHICommandListImmediate& RHICmdList)
		{
			GSlCameraProxy->PushCudaContext();

			cudaGraphicsMapResources(1, &CudaResource, 0);

			UpdateTexture();

			cudaGraphicsUnmapResources(1, &CudaResource, 0);

			GSlCameraProxy->PopCudaContext();
		}
	);
}

void USlTexture::BP_UpdateTextureWithMat(const FSlMat& NewMat)
{
#if WITH_EDITOR
	CHECK_UPDATE_VALID();
#endif

	ENQUEUE_RENDER_COMMAND(UpdateGPUTexture)(
		[this, &NewMat = NewMat](FRHICommandListImmediate& RHICmdList)
		{
			GSlCameraProxy->PushCudaContext();

			cudaGraphicsMapResources(1, &CudaResource, 0);

			UpdateTexture(NewMat);

			cudaGraphicsUnmapResources(1, &CudaResource, 0);

			GSlCameraProxy->PopCudaContext();
		}
	);
}

void USlTexture::UpdateTexture()
{
#if WITH_EDITOR
	CHECK_UPDATE_VALID();
#endif

	UE_LOG(LogTemp, Warning, TEXT(" 1 "));
	cudaArray_t TransitionArray = nullptr;
	SL_MEM MemType = (SL_MEM)sl_mat_get_memory_type(Mat.Mat);

	cudaGraphicsSubResourceGetMappedArray(&TransitionArray, CudaResource, 0, 0);
	cudaError_t CudaError = cudaError::cudaErrorInvalidTexture;
	CudaError = cudaMemcpy2DToArray(TransitionArray, 0, 0, sl_mat_get_ptr(Mat.Mat, MemType), sl_mat_get_step_bytes(Mat.Mat, MemType), sl_mat_get_width_bytes(Mat.Mat), sl_mat_get_height(Mat.Mat), cudaMemcpyDeviceToDevice);

#if WITH_EDITOR
	CHECK_CUDA_MEMCPY(CudaError)
#endif
}

void USlTexture::UpdateTexture(const FSlMat& NewMat)
{
#if WITH_EDITOR
	CHECK_UPDATE_VALID();
#endif

	UE_LOG(LogTemp, Warning, TEXT(" 2 "));
	cudaArray_t TransitionArray = nullptr;
	SL_MEM MemType = (SL_MEM)sl_mat_get_memory_type(NewMat.Mat);
	cudaGraphicsSubResourceGetMappedArray(&TransitionArray, CudaResource, 0, 0);

	cudaError_t CudaError = cudaError::cudaErrorInvalidTexture;
	CudaError = cudaMemcpy2DToArray(TransitionArray, 0, 0, sl_mat_get_ptr(NewMat.Mat, MemType), sl_mat_get_step_bytes(NewMat.Mat, MemType), sl_mat_get_width_bytes(NewMat.Mat), sl_mat_get_height(NewMat.Mat), cudaMemcpyDeviceToDevice);

#if WITH_EDITOR
	CHECK_CUDA_MEMCPY(CudaError)
#endif
}

void USlTexture::UpdateTexture(void* NewMat)
{
	FString RHIName = GDynamicRHI->GetName();
	if (RHIName.Equals("D3D12"))
	{
		sl_mat_update_cpu_from_gpu(NewMat);
		MatPtr = sl_mat_get_ptr(NewMat, SL_MEM_CPU);
		
		SL_MAT_TYPE mat_type = sl::unreal::GetSlMatTypeFormatFromSlTextureFormat(TextureFormat);
		int ByteSize = sl::unreal::GetSizeInBytes(mat_type);

		int TextureSize = Height * Width  * ByteSize;

		// Populate texture
		FTexture2DMipMap& Mip = Texture->GetPlatformData()->Mips[0];
		Mip.BulkData.Lock(LOCK_READ_WRITE);
		void* Data = Mip.BulkData.Realloc(TextureSize);
		FMemory::Memcpy(Data, MatPtr, TextureSize);
		Mip.BulkData.Unlock();

		return;
	}

#if WITH_EDITOR
	CHECK_UPDATE_VALID();
#endif

	cudaArray_t TransitionArray = nullptr;
	cudaGraphicsSubResourceGetMappedArray(&TransitionArray, CudaResource, 0, 0);
	SL_MEM MemType = (SL_MEM)sl_mat_get_memory_type(NewMat);
	cudaError_t CudaError = cudaError::cudaErrorInvalidTexture;
	CudaError = cudaMemcpy2DToArray(TransitionArray, 0, 0, sl_mat_get_ptr(NewMat, MemType), sl_mat_get_step_bytes(NewMat, MemType), sl_mat_get_width_bytes(NewMat), sl_mat_get_height(NewMat), cudaMemcpyDeviceToDevice);

#if WITH_EDITOR
	CHECK_CUDA_MEMCPY(CudaError)
#endif
}

bool USlTexture::Resize(int32 NewWidth, int32 NewHeight)
{
#if WITH_EDITOR
	if (!Texture && MemoryType == ESlMemoryType::MT_GPU)
	{
		SL_LOG_E(SlTexture, "Trying to resize unallocated texture.");

		return false;
	}
	else if (NewWidth <= 0 || NewHeight <= 0)
	{
		SL_LOG_E(SlTexture, "Trying to resize texture with size <= 0: %d - %d.", NewWidth, NewHeight);

		return false;
	}
#endif

	Width = NewWidth;
	Height = NewHeight;

	if (MemoryType == ESlMemoryType::MT_GPU && Texture)
	{
		TextureCompressionSettings Compression = Texture->CompressionSettings;

		Texture->ConditionalBeginDestroy();
		Texture = nullptr;

		if (CudaResource)
		{
			if (GSlCameraProxy && GSlCameraProxy->IsCameraOpened())
			{
				cudaGraphicsUnregisterResource(CudaResource);
			}

			CudaResource = nullptr;

			FMemory::Free(MatPtr);
		}

		InitResources(TextureFormat, Compression);
	}

	return true;
}

USlViewTexture* USlViewTexture::CreateGPUViewTexture(const FName& TextureName, int32 TextureWidth, int32 TextureHeight, ESlView TextureViewType, bool bCreateTexture2D/* = true*/, ESlTextureFormat TextureFormat/* = ESlTextureFormat::TF_B8G8R8A8_UNORM*/, ESlViewFormat TextureViewFormat /*= ESlViewFormat::VF_Signed*/)
{
	return USlViewTexture::CreateViewTexture(TextureName, TextureWidth, TextureHeight, TextureViewType, ESlMemoryType::MT_GPU, bCreateTexture2D, TextureFormat);
}

USlViewTexture* USlViewTexture::CreateCPUViewTexture(const FName& TextureName, int32 TextureWidth, int32 TextureHeight, ESlView TextureViewType, ESlViewFormat TextureViewFormat)
{
	return USlViewTexture::CreateViewTexture(TextureName, TextureWidth, TextureHeight, TextureViewType, ESlMemoryType::MT_CPU, false, ESlTextureFormat::TF_Unkown, TextureViewFormat);
}

USlViewTexture* USlViewTexture::CreateViewTexture(const FName& TextureName, int32 TextureWidth, int32 TextureHeight, ESlView TextureViewType, ESlMemoryType TextureMemoryType, bool bCreateTexture2D, ESlTextureFormat TextureFormat, ESlViewFormat TextureViewFormat)
{
#if WITH_EDITOR
	if (TextureWidth <= 0 || TextureHeight <= 0)
	{
		SL_LOG_E(SlTexture, "Trying to create texture with size <= 0: %d - %d.", TextureWidth, TextureHeight);

		return nullptr;
	}
#endif

	USlViewTexture* ViewTexture = NewObject<USlViewTexture>();
	ViewTexture->Width = TextureWidth;
	ViewTexture->Height = TextureHeight;
	ViewTexture->Name = TextureName;
	ViewTexture->ViewType = TextureViewType;
	ViewTexture->MemoryType = TextureMemoryType;
	ViewTexture->TextureType = ESlTextureType::TT_View;
	ViewTexture->TextureFormat = TextureFormat;
	ViewTexture->ViewFormat = TextureViewFormat;

	if (TextureMemoryType == ESlMemoryType::MT_GPU && bCreateTexture2D)
	{
		UE_LOG(LogTemp, Warning, TEXT("Create view"));
		ViewTexture->InitResources(TextureFormat, TextureCompressionSettings::TC_VectorDisplacementmap);
	}

	return ViewTexture;
}

USlMeasureTexture* USlMeasureTexture::CreateGPUMeasureTexture(const FName& TextureName, int32 TextureWidth, int32 TextureHeight, ESlMeasure TextureMeasureType, bool bCreateTexture2D/* = true*/, ESlTextureFormat TextureFormat/* = ESlTextureFormat::TF_R32_FLOAT*/)
{
	return USlMeasureTexture::CreateMeasureTexture(TextureName, TextureWidth, TextureHeight, TextureMeasureType, ESlMemoryType::MT_GPU, bCreateTexture2D, TextureFormat);
}

USlMeasureTexture* USlMeasureTexture::CreateCPUMeasureTexture(const FName& TextureName, int32 TextureWidth, int32 TextureHeight, ESlMeasure TextureMeasureType)
{
	return USlMeasureTexture::CreateMeasureTexture(TextureName, TextureWidth, TextureHeight, TextureMeasureType, ESlMemoryType::MT_CPU, false, ESlTextureFormat::TF_Unkown);
}

USlMeasureTexture* USlMeasureTexture::CreateMeasureTexture(const FName& TextureName, int32 TextureWidth, int32 TextureHeight, ESlMeasure TextureMeasureType, ESlMemoryType TextureMemoryType, bool bCreateTexture2D, ESlTextureFormat TextureFormat)
{
	checkf(GSlCameraProxy && GSlCameraProxy->IsCameraOpened(), TEXT("Camera must be opened before creating a GPU texture"));

#if WITH_EDITOR
	if (TextureWidth <= 0 || TextureHeight <= 0)
	{
		SL_LOG_E(SlTexture, "Trying to create texture with size <= 0: %d - %d.", TextureWidth, TextureHeight);

		return nullptr;
	}
#endif

	USlMeasureTexture* MeasureTexture = NewObject<USlMeasureTexture>();
	MeasureTexture->Width = TextureWidth;
	MeasureTexture->Height = TextureHeight;
	MeasureTexture->Name = TextureName;
	MeasureTexture->MeasureType = TextureMeasureType;
	MeasureTexture->MemoryType = TextureMemoryType;
	MeasureTexture->TextureType = ESlTextureType::TT_Measure;
	MeasureTexture->TextureFormat = TextureFormat;

	if (TextureMemoryType == ESlMemoryType::MT_GPU && bCreateTexture2D)
	{
		MeasureTexture->InitResources(TextureFormat, TextureCompressionSettings::TC_DistanceFieldFont);
	}

	return MeasureTexture;
}

void USlTexture::InitResources(ESlTextureFormat Format, TextureCompressionSettings Compression)
{
	TextureFormat = Format;
	// Create texture
	Texture = UTexture2D::CreateTransient(Width, Height, GetPixelFormatFromSlTextureFormat(Format));
#if WITH_EDITORONLY_DATA
	Texture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
	Texture->CompressionNone = true;
	Texture->CompressionNoAlpha = true;
	Texture->DeferCompression = false;
#endif
	Texture->bNoTiling = true;
	Texture->SRGB = false;
	Texture->CompressionSettings = Compression;
	Texture->Filter = TextureFilter::TF_Bilinear;
	Texture->AddressX = TextureAddress::TA_Clamp;
	Texture->AddressY = TextureAddress::TA_Clamp;
	Texture->LODGroup = TextureGroup::TEXTUREGROUP_RenderTarget;
	Texture->UpdateResource();

	FlushRenderingCommands();

	GSlCameraProxy->PushCudaContext();

	cudaError_t CudaError = cudaError::cudaSuccess;
	FString RHIName = GDynamicRHI->GetName();

	if (RHIName.Equals("D3D11"))
	{
		
	// This function has changed between 5.0 and 5.1.
#if ENGINE_MINOR_VERSION < 1
		FD3D11TextureBase* D3D11Texture = GetD3D11TextureFromRHITexture(Texture->Resource->TextureRHI);
#else
		FD3D11Texture* D3D11Texture = GetD3D11TextureFromRHITexture(Texture->Resource->TextureRHI);
#endif

		CudaError = cudaGraphicsD3D11RegisterResource(&CudaResource, D3D11Texture->GetResource(), cudaGraphicsMapFlagsNone);
	}
	else if (RHIName.Equals("D3D12"))
	{
		if (ID3D12Device* D3D12DevicePtr = static_cast<ID3D12Device*>(GDynamicRHI->RHIGetNativeDevice()))
		{
			if (ID3D12Resource* D3D12ResourcePtr = (ID3D12Resource*)(Texture->Resource->TextureRHI->GetNativeResource()))
			{

				/*SL_MAT_TYPE mat_type = sl::unreal::GetSlMatTypeFormatFromSlTextureFormat(Format);
				int NbChannel = sl::unreal::GetNbChannel(mat_type);
				int ByteSize = sl::unreal::GetSizeInBytes(mat_type);

				int TextureSize = Height * Width * NbChannel* ByteSize;

				HANDLE sharedHandle{};
				WindowsSecurityAttributes secAttr{};
				D3D12DevicePtr->CreateSharedHandle(D3D12ResourcePtr, &secAttr, GENERIC_ALL, 0, &sharedHandle);

				FD3D12ResourceDesc texDesc;
				texDesc.PixelFormat = GetPixelFormatFromSlTextureFormat(Format);
				const auto texAllocInfo = D3D12DevicePtr->GetResourceAllocationInfo(0, 1, &texDesc);
				
				cudaExternalMemoryHandleDesc cuExtmemHandleDesc{};
				cuExtmemHandleDesc.type = cudaExternalMemoryHandleTypeD3D12Heap;
				cuExtmemHandleDesc.handle.win32.handle = sharedHandle;
				cuExtmemHandleDesc.size = texAllocInfo.SizeInBytes;
				cuExtmemHandleDesc.flags = cudaExternalMemoryDedicated;
				cudaImportExternalMemory(&m_externalMemory, &cuExtmemHandleDesc);
				
				cudaExternalMemoryMipmappedArrayDesc cuExtmemMipDesc{};
				cuExtmemMipDesc.extent = make_cudaExtent(Width, Height, 0);
				cuExtmemMipDesc.formatDesc = cudaCreateChannelDesc<char4>();
				cuExtmemMipDesc.numLevels = 1;
				cuExtmemMipDesc.flags = cudaArraySurfaceLoadStore;

				cudaMipmappedArray_t cuMipArray{};
				cudaExternalMemoryGetMappedMipmappedArray(&cuMipArray, m_externalMemory, &cuExtmemMipDesc);

				cudaArray_t cuArray{};
				cudaGetMipmappedArrayLevel(&cuArray, cuMipArray, 0);

				cudaResourceDesc cuResDesc{};
				cuResDesc.resType = cudaResourceTypeArray;
				cuResDesc.res.array.array = cuArray;
				cudaCreateSurfaceObject(&cuSurface, &cuResDesc);*/

				UE_LOG(LogTemp, Warning, TEXT(" Init Resource %d"), Format);

				SL_MAT_TYPE mat_type = sl::unreal::GetSlMatTypeFormatFromSlTextureFormat(Format);
				int ByteSize = sl::unreal::GetSizeInBytes(mat_type);

				int TextureSize = Height * Width * ByteSize;

				MatPtr = FMemory::Malloc(TextureSize);
				// Populate texture
				FTexture2DMipMap& Mip = Texture->GetPlatformData()->Mips[0];
				Mip.BulkData.Lock(LOCK_READ_WRITE);
				void* Data = Mip.BulkData.Realloc(TextureSize);

				FMemory::Memcpy(Data, MatPtr, TextureSize);
				Mip.BulkData.Unlock();
			}
		}
	}
	else
	{
		SL_LOG_F(SlTexture, "Selected RHI not supported : %s", *RHIName);
		CudaError = cudaError::cudaErrorInvalidTexture;
	}

#if WITH_EDITOR
	if (CudaError != cudaError::cudaSuccess)
	{
		SL_LOG_E(SlTexture, "Error while registering resource %s: %s", *Name.ToString(), *FString(cudaGetErrorString(CudaError)));
	}
#endif

	GSlCameraProxy->PopCudaContext();
}