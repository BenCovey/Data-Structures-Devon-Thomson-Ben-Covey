#include <iostream>
#include "stack.h"

//S T U F F  F O R  S T A C K N O D E  C P P 
StackNode::StackNode() : nodeCoord(new coord(0,0)), nextNode(NULL) {}

StackNode::StackNode(int inX, int inY, StackNode* next) : nodeCoord(new coord(inX, inY)), nextNode(next) {}

StackNode::~StackNode() {}

coord* StackNode::getData() { return nodeCoord; }

StackNode* StackNode::getNext() { return nextNode; }

void StackNode::setNext(StackNode *next) { nextNode = next; }

//S T U F F  F O R  S T A C K  C P 
coord::coord(int inRow, int inCol) {
	row = inRow; col = inCol;
}

Stack::Stack() : top(NULL) {}

Stack::~Stack() {
	while (top != NULL) {
		Pop();
	}
}

stackStatus Stack::Push(int inRow, int inCol) {
	top = new StackNode(inRow, inCol, top);
	return(success);
}

coord* Stack::Peek() {
	return top->getData();
}

stackStatus Stack::Pop() {
	if (top != NULL) {
		StackNode* node = top;
		top = top->getNext();
		delete node;
		return(success);
	}
	else {
		return(underflow);
	}
}

std::ostream& operator<<(std::ostream& output, Stack& stack){
	StackNode *node = stack.top;
	while (node != NULL) {
		std::cout << node->getData()->row << " " << node->getData()->col << std::endl;
		node = node->getNext();
	}
	return output;
}