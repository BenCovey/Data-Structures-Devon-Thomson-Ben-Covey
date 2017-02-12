#pragma once
#ifndef _STACK_H
#define _STACK_H

#include <iostream>
#include "stacknode.h"

enum stackStatus { success, underflow, overflow };

struct coord {
	int x, y; 
	coord(int x, int y);
};

class Stack{
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


#endif