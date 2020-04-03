#ifndef STACKALLOCATOR_H
#define STACKALLOCATOR_H
#include "Allocator.h"
class StackAllocator  {
private:
	struct HEADER {uint8_t alignment;};
	HEADER* topHeaderPtr;
public:
	StackAllocator(size_t maxSize);

	~StackAllocator();

};
#endif // !STACKALLOCATOR_H
