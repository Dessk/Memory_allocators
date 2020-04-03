#ifndef MEMALLOCATIONUTIL_H
#define MEMALLOCATIONUTIL_H
#include <cstdint>
#include <iostream>
namespace AllocationUtil {
	inline void* alignAddress(const uintptr_t blockValue,size_t alignment) {
		return reinterpret_cast<void*>(blockValue + (alignment - 1) & ~(alignment - 1));
	}
	inline size_t calculateAdjustment(const uintptr_t blockValue, size_t alignment) {
		size_t adjustment{ alignment - (blockValue & (alignment - 1)) };
		if (adjustment == alignment) return 0;
		return adjustment;
	}
	inline size_t calculateAdjustmentWithHeader(const uintptr_t blockValue, size_t alignment, size_t headerSize) {
		size_t blockAdjustment{ calculateAdjustment(blockValue,alignment) };
		size_t requiredSpace{ headerSize };
		if (blockAdjustment < requiredSpace) {
			requiredSpace -= blockAdjustment;
			if (!(requiredSpace % alignment)) {
				blockAdjustment += alignment * (requiredSpace / alignment);
			}
			else {
				 blockAdjustment += alignment * (1+(requiredSpace / alignment));
			}
		}
		return blockAdjustment;
	}


	

}
#endif // !MEMALLOCATIONUTIL_H
