#include "../includes/StackAllocator.h"
#include "../includes/Utility/MemoryAllocationUtility.h"

StackAllocator::StackAllocator(size_t maxSize) : Allocator(maxSize), savedAddress{ blockPtr } { initBlock(); }
StackAllocator::~StackAllocator() {}

void* StackAllocator::allocate(size_t size, uint8_t alignment) {
	uint8_t adjustment{ AllocationUtil::calculateAdjustmentWithHeader(currentPtr, alignment, sizeof(HEADER)) };
	if (used + adjustment + size > maxSize) return nullptr;
	uintptr_t returnAdress{currentPtr+adjustment};
	HEADER* headerPtr{ reinterpret_cast<HEADER*>(returnAdress - sizeof(HEADER)) };
	headerPtr->adjustment = adjustment;
	headerPtr->prevAllocation = (void*)currentPtr;
	savedAddress = reinterpret_cast<void*>(returnAdress);
	currentPtr += size + adjustment;
	used += size + adjustment;
	return savedAddress;
}

void StackAllocator::deallocate() {
	uintptr_t pAlloc{ reinterpret_cast<uintptr_t>(savedAddress) };

	HEADER* header = (HEADER*)(pAlloc - sizeof(HEADER));
	uintptr_t toClear{ currentPtr - pAlloc + header->adjustment};

	currentPtr = pAlloc - header->adjustment;
	savedAddress = header->prevAllocation;

	memset((void*)currentPtr, 0, toClear);
	
}

