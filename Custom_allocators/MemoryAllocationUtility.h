#ifndef MEMALLOCATIONUTIL_H
#define MEMALLOCATIONUTIL_H
#include <cstdint>
#include <iostream>
namespace AllocationUtil {
	size_t calculatePadding(const uintptr_t& blockValue,size_t alignment) {
		if (!(blockValue % alignment)) return 0;
		return (blockValue + (alignment - 1) & ~(alignment - 1)) - blockValue;
	}
}
#endif // !MEMALLOCATIONUTIL_H
