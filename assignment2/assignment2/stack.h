#pragma once
#ifndef STACK_H
#define STACK_H

#include <iostream>

enum stackStatus { success, underflow, overflow };

struct coord {
	int row, col;
	coord(int inRow, int inCol);
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
	StackNode* getNext();
	void setNext(StackNode *next);
};

class Stack {
private:
	StackNode *top;
public:
	Stack();
	virtual ~Stack();
	stackStatus Push(int x, int y);
	coord* Peek();
	stackStatus Pop();
	friend std::ostream& operator<<(std::ostream& output, Stack& stack);
};

#endif // !STACK_H
