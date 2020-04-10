#ifndef POOLLINKED_H
#define POOLLINKED_H
#include <iostream>
class PoolStack {
public:
	struct StackNode { StackNode* nextPtr; };
private:
	StackNode* head;
public:
	PoolStack() : head{ nullptr } {}
	void push(StackNode* node) {
		StackNode* save{ head };
		head = node;
		head->nextPtr = save;
	}
	StackNode* pop() {
		StackNode* toReturn{ head };
		head = head->nextPtr;
		return toReturn;
	}
	StackNode* getTop() const {
		return head;
	}
	~PoolStack() {}
	
};
#endif // !POOLLINKED_H
