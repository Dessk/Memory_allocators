#ifndef LINEARALLOCATOR_H
#define LINEARALLOCATOR_H
#include "Allocator.h"
class LinearAllocator : public Allocator {
private:
	void* currAddress;
public:
	LinearAllocator(size_t maxSize);
	void* allocate(size_t size,size_t alignment);
	~LinearAllocator();
};
#endif // !LINEARALLOCATOR_H
