#ifndef STACKALLOCATOR_H
#define STACKALLOCATOR_H
#include "Allocator.h"
class StackAllocator : public Allocator  {
private:
	struct HEADER { uint8_t adjustment; void* prevAllocation; };
	void* savedAddress;
public:
	StackAllocator(size_t maxSize);
	void* allocate(size_t size, uint8_t alignment);
	void deallocate();
	~StackAllocator();

};
#endif // !STACKALLOCATOR_H
