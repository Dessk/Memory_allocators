#ifndef LINEARALLOCATOR_H
#define LINEARALLOCATOR_H
#include "Allocator.h"
class LinearAllocator : public Allocator {
public:
	LinearAllocator(size_t maxSize);
	void* allocate(size_t size, uint8_t alignment);
	~LinearAllocator();
};
#endif // !LINEARALLOCATOR_H
