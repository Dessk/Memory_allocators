#ifndef MEMALLOCATIONUTIL_H
#define MEMALLOCATIONUTIL_H
#include <cstdint>
#include <iostream>
namespace AllocationUtil {
	void* alignAddress(const uintptr_t blockValue,size_t alignment) {
		return reinterpret_cast<void*>(blockValue + (alignment - 1) & ~(alignment - 1));
	}
	size_t calculateAdjustment(const uintptr_t blockValue, size_t alignment) {
		size_t adjustment{ alignment - (blockValue & (alignment - 1)) };
		if (adjustment == alignment) return 0;
		return adjustment;
	}

}
#endif // !MEMALLOCATIONUTIL_H
