#include "StackAllocator.h"
#include "MemoryAllocationUtility.h"

StackAllocator::StackAllocator(size_t maxSize) : Allocator(maxSize), topHeaderPtr{ nullptr }, prevAllocation{ blockPtr } {}
StackAllocator::~StackAllocator() {}

void* StackAllocator::allocate(size_t size, size_t alignment) {
	size_t adjustment{ AllocationUtil::calculateAdjustmentWithHeader(blockPtrValue, alignment, sizeof(HEADER)) };
	if (offSet + adjustment + size > maxSize) return nullptr;
	uintptr_t returnAdress{blockPtrValue+offSet+adjustment};
	HEADER* headerPtr{ reinterpret_cast<HEADER*>(returnAdress - sizeof(HEADER)) };
	headerPtr->adjustment = adjustment;
	headerPtr->prevAllocation = prevAllocation;
	topHeaderPtr = headerPtr;
	prevAllocation = reinterpret_cast<void*>(returnAdress);
	offSet += adjustment + size;
	std::cout << reinterpret_cast<void*>(returnAdress) << '\n';
	return reinterpret_cast<void*>(returnAdress);
}

void* StackAllocator::deallocate() {
	if (!(topHeaderPtr)) return nullptr;
	void* pAlloc{ prevAllocation };
	std::cout << pAlloc << '\n';

	HEADER* header = (HEADER*)(reinterpret_cast<uintptr_t>(pAlloc) - sizeof(HEADER));
	offSet = offSet - reinterpret_cast<uintptr_t>(pAlloc) - header->adjustment;
	prevAllocation = header->prevAllocation;
	topHeaderPtr = header;
}

