#include "Error.h"
#include "LinearAllocator.h"
#include "MemoryAllocationUtility.h"


LinearAllocator::LinearAllocator(size_t maxSize) : Allocator(maxSize), currAddress{ blockPtr } {}
LinearAllocator::~LinearAllocator(){}

void* LinearAllocator::allocate(size_t size, size_t alignment) {
	
	size_t padding{ AllocationUtil::calculatePadding(blockPtrValue+offSet,alignment) };

	if (offSet + padding + size > maxSize) return nullptr;
	void* returnAddress{ (void*)(blockPtrValue + offSet + padding) };
	offSet += padding + size;
	return returnAddress;
}

