#include <iostream>
#include "stack.h"

//S T U F F  F O R  S T A C K N O D E  C P P 
StackNode::StackNode() : nodeCoord(new coord(0,0)), nextNode(NULL) {}

StackNode::StackNode(int inX, int inY, StackNode* next) : nodeCoord(new coord(inX, inY)), nextNode(next) {}

StackNode::~StackNode() {}

coord* StackNode::getData() { return nodeCoord; }

void StackNode::setData(int inX, int inY) { nodeCoord = new coord(inX, inY); }

StackNode* StackNode::getNext() { return nextNode; }

void StackNode::setNext(StackNode *next) { nextNode = next; }

//S T U F F  F O R  S T A C K  C P 
coord::coord(int inX, int inY) {
	x = inX; y = inY;
}

Stack::Stack() : _top(NULL) {}

Stack::~Stack() {
	while (_top != NULL) {
		Pop();
	}
}

stackStatus Stack::Push(int inX, int inY) {
	_top = new StackNode(inX, inY, _top);
	return(success);
}

coord Stack::Peek() {
	return *_top->getData();
}

stackStatus Stack::Pop() {
	if (_top != NULL) {
		StackNode* node = _top;
		_top = _top->getNext();
		delete node;
		return(success);
	}
	else {
		return(underflow);
	}
}

std::ostream& operator<<(std::ostream& output, Stack& stack){
	StackNode *node = stack._top;
	while (node != NULL) {
		std::cout << node->getData() << std::endl;
		node = node->getNext();
	}
	return output;
}