#pragma once
#ifndef STACK_NODE
#define STACK_NODE

#include "stack.h"

class StackNode {
private:
	coord *nodeCoord;
	StackNode *nextNode;

public:
	StackNode();
	StackNode(int inX, int inY, StackNode* next);
	virtual ~StackNode();

	coord *getData();
	void setData(int inX, int inY);

	StackNode* getNext();
	void setNext(StackNode *next);
};

#endif // STACK_NODE

