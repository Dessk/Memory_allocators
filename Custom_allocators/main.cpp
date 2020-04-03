#include <iostream>
#include "LinearAllocator.h"
#include "StackAllocator.h"

typedef struct {
	int x, y;
}TestStructure;

int main() {
	LinearAllocator allocator{ 128 };
	TestStructure* test1{ (TestStructure*)allocator.allocate(sizeof(TestStructure),16) };
	if ((reinterpret_cast<uintptr_t>(test1) % 16)) std::cout << "B³¹d" << '\n';
	test1->x = 1;
	test1->y = 2;
	std::cout << test1->x << " " << test1->y << '\n';

	TestStructure* test2{ (TestStructure*)allocator.allocate(sizeof(TestStructure),32) };
	if ((reinterpret_cast<uintptr_t>(test2) % 32)) std::cout << "B³¹d" << '\n';
	test2->x = 3;
	test2->y = 4;
	std::cout << test2->x << " " << test2->y << '\n';

	StackAllocator stackAllocator{ 128 };
	TestStructure* test3{ (TestStructure*)stackAllocator.allocate(sizeof(TestStructure),4) };
	if ((reinterpret_cast<uintptr_t>(test3) % 4)) std::cout << "B³¹d" << '\n';
	test3->x = 5;
	test3->y = 6;
	//std::cout << test3<< '\n';
	stackAllocator.deallocate();
	TestStructure* test4{ (TestStructure*)stackAllocator.allocate(sizeof(TestStructure),4) };
	//std::cout << test4 << '\n';



}

