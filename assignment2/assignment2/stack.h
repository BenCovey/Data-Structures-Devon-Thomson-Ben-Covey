#pragma once
#ifndef STACK_H
#define STACK_H

#include <iostream>

enum stackStatus { success, underflow, overflow };

struct coord {
	int x, y;
	coord(int x, int y);
};

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

class Stack {
private:
	StackNode *_top;
public:
	Stack();
	virtual ~Stack();
	stackStatus Push(int x, int y);
	coord Peek();
	stackStatus Pop();
	friend std::ostream& operator<<(std::ostream& output, Stack& stack);
};

#endif // !STACK_H
