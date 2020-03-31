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
	~Allocator();
};
#endif // !1
