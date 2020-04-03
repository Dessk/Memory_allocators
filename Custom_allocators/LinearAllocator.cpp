#include "Error.h"
#include "LinearAllocator.h"
#include "MemoryAllocationUtility.h"


LinearAllocator::LinearAllocator(size_t maxSize) : Allocator(maxSize), currAddress{ blockPtr } {}
LinearAllocator::~LinearAllocator(){}

void* LinearAllocator::allocate(size_t size, size_t alignment) {
	
	void* alignedAddress{ AllocationUtil::alignAddress(blockPtrValue+offSet,alignment) };
	uintptr_t adjustment{ AllocationUtil::calculateAdjustment(blockPtrValue + offSet,alignment) };

	if (offSet + adjustment + size > maxSize) return nullptr;
	void* returnAddress{ (void*)(blockPtrValue + offSet + adjustment) };
	offSet += adjustment + size;
	amount_of_allocations++;
	return returnAddress;
}

