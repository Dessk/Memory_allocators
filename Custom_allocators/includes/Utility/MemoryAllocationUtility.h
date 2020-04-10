#ifndef MEMALLOCATIONUTIL_H
#define MEMALLOCATIONUTIL_H
#include <cstdint>
#include <iostream>
namespace AllocationUtil {
	inline void* alignAddress(const uintptr_t blockValue,size_t alignment) {
		return reinterpret_cast<void*>(blockValue + (alignment - 1) & ~(alignment - 1));
	}
	inline uint8_t calculateAdjustment(const uintptr_t blockValue, uint8_t alignment) {
		uint8_t adjustment{ alignment - (blockValue & (alignment - 1)) };
		if (adjustment == alignment) return 0;
		return adjustment;
	}
	inline uint8_t calculateAdjustmentWithHeader(const uintptr_t blockValue, uint8_t alignment, size_t headerSize) {
		uint8_t blockAdjustment{ calculateAdjustment(blockValue,alignment) };
		size_t requiredSpace{ headerSize };
		if (blockAdjustment < requiredSpace) {
			requiredSpace -= blockAdjustment;
			std::cout << static_cast<uint8_t>(alignment * (requiredSpace / alignment))+0<< static_cast<uint8_t>(alignment * (1 + (requiredSpace / alignment)))+0 << std::endl;
		
			if (!(requiredSpace % alignment)) {
				blockAdjustment += static_cast<uint8_t>(alignment * (requiredSpace / alignment));
			}
			else {
				blockAdjustment += static_cast<uint8_t>(alignment * (1+(requiredSpace / alignment)));
			}
		}
		return blockAdjustment;
	}


	

}
#endif // !MEMALLOCATIONUTIL_H
