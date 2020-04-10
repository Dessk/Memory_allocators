#include "../includes/Allocator.h"
#include "../includes/Utility/Error.h"

void Allocator::initBlock() {
	blockPtr = std::malloc(maxSize);
	if (blockPtr == nullptr) throw Error("Cannot allocate memory");
	blockPtrValue = reinterpret_cast<uintptr_t>(blockPtr);
	currentPtr = blockPtrValue;
}

Allocator::Allocator(size_t maxSize) : used{ 0 } {
	this->maxSize = maxSize;
}
Allocator::~Allocator() { free(blockPtr); }
