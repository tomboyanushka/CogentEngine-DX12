#include "Material.h"

uint32_t Material::Create(ID3D12Device* device, 
	const wchar_t* diffuseTextureFileName, 
	const wchar_t* normalTextureFileName, 
	const wchar_t* metalTextureFileName,
	const wchar_t* roughTextureFileName,
	ID3D12CommandQueue* commandQueue, 
	uint32_t index, 
	const DescriptorHeap* heap,
	uint32_t heapCount)
{

	diffuseTexture.Create(device, diffuseTextureFileName, commandQueue, index, heap);
	normalTexture.Create(device, normalTextureFileName, commandQueue, index + 1, heap);
	metalTexture.Create(device, metalTextureFileName, commandQueue, index + 2, heap);
	roughTexture.Create(device, roughTextureFileName, commandQueue, index + 3, heap);

	index += 4;
	this->materialIndex = index; 
	// Returning next index to be used for a new material
	return materialIndex;
}

D3D12_GPU_DESCRIPTOR_HANDLE Material::GetFirstGPUHandle(const DescriptorHeap* heap, uint32_t backBufferIndex)
{
	return diffuseTexture.GetGPUHandle(heap, backBufferIndex);
}

