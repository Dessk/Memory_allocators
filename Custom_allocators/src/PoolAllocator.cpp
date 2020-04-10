#include "../includes/PoolAllocator.h"
#include <cassert>

PoolAllocator::PoolAllocator(size_t sizeOfAllocation, size_t sizeOfPool) : Allocator(sizeOfAllocation), sizeOfPool{ sizeOfPool }{
	assert(!(sizeOfAllocation & (sizeOfAllocation - 1)));
	assert((sizeOfAllocation >= sizeOfPool));
	initBlock();
	fillStack();
}
PoolAllocator::~PoolAllocator() {}

void PoolAllocator::fillStack() {
	size_t amountOfPools{ maxSize / sizeOfPool };
	for (int i = 0; i < amountOfPools; i++) {
		allocatorStack.push((PoolStack::StackNode*)(blockPtrValue + (i * sizeOfPool)));
	}
}

void* PoolAllocator::allocate(size_t size, uint8_t alignment) {
	assert(size == sizeOfPool);
	PoolStack::StackNode* popNode{ allocatorStack.pop() };
	used += sizeOfPool;
	return static_cast<void*>(popNode);
}

void PoolAllocator::deallocate(void* ptr) {
	allocatorStack.push((PoolStack::StackNode*)ptr);
}