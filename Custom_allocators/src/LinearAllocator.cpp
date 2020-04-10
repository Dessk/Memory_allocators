#include "../includes/Utility/Error.h"
#include "../includes/LinearAllocator.h"
#include "../includes/Utility/MemoryAllocationUtility.h"


LinearAllocator::LinearAllocator(size_t maxSize) : Allocator(maxSize){ initBlock(); }
LinearAllocator::~LinearAllocator(){}

void* LinearAllocator::allocate(size_t size, uint8_t alignment) {
	
	uintptr_t adjustment{ AllocationUtil::calculateAdjustment(currentPtr,alignment) };


	if (used + adjustment + size > maxSize) return nullptr;
	void* returnAddress{ (void*)(currentPtr + adjustment) };
	currentPtr += size + adjustment;
	used += size + adjustment;
	return returnAddress;
}

