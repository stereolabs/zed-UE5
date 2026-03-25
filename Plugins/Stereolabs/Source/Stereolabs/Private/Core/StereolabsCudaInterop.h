//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include <cuda_runtime.h>
#include "RHIFwd.h"


// Interface to abstract how different APIs interop with CUDA
class IStereolabsCudaInterop
{
public:
	IStereolabsCudaInterop() = default;
	virtual ~IStereolabsCudaInterop() = default;

	IStereolabsCudaInterop(const IStereolabsCudaInterop&) = delete;
	IStereolabsCudaInterop& operator=(const IStereolabsCudaInterop&) = delete;

	// Gives a pointer to a Cuda array to write to this resource (mip 0, array slice 0)
	virtual void UpdateTexture(void* Mat, FRHICommandListImmediate& RHICmdList, cudaStream_t Stream) = 0;
};


// Provides synchronization between CUDA and Graphics API
// Allows for bulk synchronization of multiple resources to reduce overhead
class IStereolabsCudaInteropSyncPoint
{
public:
	IStereolabsCudaInteropSyncPoint() = default;
	virtual ~IStereolabsCudaInteropSyncPoint() = default;

	IStereolabsCudaInteropSyncPoint(const IStereolabsCudaInterop&) = delete;
	IStereolabsCudaInteropSyncPoint& operator=(const IStereolabsCudaInteropSyncPoint&) = delete;

	virtual void SyncCudaToGraphics(TArrayView<const IStereolabsCudaInterop*> Resources, FRHICommandListImmediate& RHICmdList, cudaStream_t Stream) = 0;
	virtual void SyncGraphicsToCuda(TArrayView<const IStereolabsCudaInterop*> Resources, FRHICommandListImmediate& RHICmdList, cudaStream_t Stream) = 0;

	void SyncCudaToGraphics(const IStereolabsCudaInterop* Resource, FRHICommandListImmediate& RHICmdList, cudaStream_t Stream);
	void SyncGraphicsToCuda(const IStereolabsCudaInterop* Resource, FRHICommandListImmediate& RHICmdList, cudaStream_t Stream);
};


class FStereolabsCudaInteropD3D11 final : public IStereolabsCudaInterop
{
public:
	FStereolabsCudaInteropD3D11(FTextureRHIRef TextureRHI);
	virtual ~FStereolabsCudaInteropD3D11();

	virtual void UpdateTexture(void* Mat, FRHICommandListImmediate& RHICmdList, cudaStream_t Stream) override;

	cudaGraphicsResource_t GetCudaResource() const { return CudaResource; }

private:
	cudaGraphicsResource_t CudaResource = nullptr;

};

class FStereolabsCudaInteropSyncPointD3D11 final : public IStereolabsCudaInteropSyncPoint
{
public:
	virtual void SyncCudaToGraphics(TArrayView<const IStereolabsCudaInterop*> Resources, FRHICommandListImmediate& RHICmdList, cudaStream_t Stream) override;
	virtual void SyncGraphicsToCuda(TArrayView<const IStereolabsCudaInterop*> Resources, FRHICommandListImmediate& RHICmdList, cudaStream_t Stream) override;
};


class FStereolabsCudaInteropD3D12 final : public IStereolabsCudaInterop
{
public:
	FStereolabsCudaInteropD3D12(FTextureRHIRef TextureRHI);
	virtual ~FStereolabsCudaInteropD3D12();

	virtual void UpdateTexture(void* Mat, FRHICommandListImmediate& RHICmdList, cudaStream_t Stream) override;

private:
	cudaExternalMemory_t CudaExternalMemory = nullptr;
	cudaMipmappedArray_t CudaMipmappedArray = nullptr;

	// On D3D12, to interop we need a texture created with TexCreate_Shared flag.
	// This cannot be done with a UTexture2D - instead we need a staging texture
	FTextureRHIRef CudaInteropStagingTexture;

	bool bOutputTextureSupportsInterop = false;
	FTextureRHIRef OutputTexture;
};

class FStereolabsCudaInteropSyncPointD3D12 final : public IStereolabsCudaInteropSyncPoint
{
public:
	FStereolabsCudaInteropSyncPointD3D12();
	~FStereolabsCudaInteropSyncPointD3D12();

	virtual void SyncCudaToGraphics(TArrayView<const IStereolabsCudaInterop*> Resources, FRHICommandListImmediate& RHICmdList, cudaStream_t Stream) override;
	virtual void SyncGraphicsToCuda(TArrayView<const IStereolabsCudaInterop*> Resources, FRHICommandListImmediate& RHICmdList, cudaStream_t Stream) override;

private:
	TRefCountPtr<class ID3D12Fence> Fence;
	cudaExternalSemaphore_t CudaExternalSemaphore = nullptr;
	uint64 FenceValue;
};
