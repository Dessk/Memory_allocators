#include <iostream>
#include <string>
#include "includes/LinearAllocator.h"
#include "includes/PoolAllocator.h"
#include "includes/StackAllocator.h"


typedef struct {
	int x, y, z;
}TestStructure;

int main() {
	
	PoolAllocator Pool1{ 1024,sizeof(TestStructure) };

	TestStructure* test1{ static_cast<TestStructure*>(Pool1.allocate(sizeof(TestStructure),12)) };

	test1->x = 1;
	test1->y = 2;

	//std::cout << test1->x << test1->y << '\n';
	Pool1.deallocate(test1);
	//std::cout << test1->x << test1->y << '\n';


	StackAllocator Stack1{ 1024 };
	TestStructure* test2{ (TestStructure*)Stack1.allocate(sizeof TestStructure,32) };

	test2->x = 2;
	test2->y = 3;
	test2->z = 4;

	std::cout << test2->x << " " << test2->y << '\n';



	
}

