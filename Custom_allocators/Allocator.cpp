#include "Allocator.h"
#include "Error.h"


Allocator::Allocator(size_t maxSize) : amount_of_allocations{ 0 }, offSet{ 0 } {
	blockPtr = std::malloc(maxSize);
	if (blockPtr == nullptr) throw Error("Cannot allocate memory");
	this->maxSize = maxSize;
	blockPtrValue = reinterpret_cast<uintptr_t>(blockPtr);
}

Allocator::~Allocator() {free(blockPtr);}