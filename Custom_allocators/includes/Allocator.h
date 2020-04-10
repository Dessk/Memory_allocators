#ifndef ALLOCATOR_H
#define ALLOCATOR_H
#include <cstdint>
class Allocator {
protected:
	size_t maxSize;
	size_t used;

	uintptr_t blockPtrValue;
	uintptr_t currentPtr;
	void* blockPtr;

	virtual inline void initBlock() final;

public:
	Allocator(size_t maxSize);

	virtual void* allocate(size_t size, uint8_t alignment) = 0;
	virtual inline size_t getMaxSize() const final { return maxSize; }
	virtual inline size_t getAmountOfFreeSpace() const final { return used; }

	~Allocator();
};
#endif // !1
