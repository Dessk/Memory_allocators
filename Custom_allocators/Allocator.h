#ifndef ALLOCATOR_H
#define ALLOCATOR_H
#include <cstdint>
class Allocator {
protected:
	int amount_of_allocations;
	size_t offSet;
	size_t maxSize;
	uintptr_t blockPtrValue;
	void* blockPtr;

public:
	Allocator(size_t maxSize);

	virtual void* allocate(size_t size, size_t alignment) = 0;
	
	virtual inline size_t getMaxSize() const final { return maxSize; }
	virtual inline size_t getAmountOfFreeSpace() const final { return maxSize - offSet; };
	virtual inline int getAmountOfAllocations() const final { return amount_of_allocations; }

	~Allocator();
};
#endif // !1
