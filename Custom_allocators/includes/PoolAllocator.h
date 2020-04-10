#ifndef POOLA_H
#define POOLA_H
#include "../includes/Allocator.h"
#include "../includes/Utility/PoolStack.h"
class PoolAllocator : public Allocator {
private:
	PoolStack allocatorStack;
	size_t sizeOfPool;
	void fillStack();
public:
	PoolAllocator(size_t allocationSize,size_t poolSize);
	void* allocate(size_t size, uint8_t alignment);
	void deallocate(void* ptr);
	~PoolAllocator();
};
#endif // !POOLA_H
