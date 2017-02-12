#include <iostream>
#include "stacknode.h"
#include "stack.h"

using namespace std;


coord::coord(int inX, int inY) {
	x = inX; y = inY;
}

Stack::Stack() : _top(NULL){}

Stack::~Stack(){
	while (_top != NULL){
		Pop();
	}
}

stackStatus Stack::Push(int inX, int inY){
	_top = new StackNode(inX, inY, _top);
	return(success);
}

coord Stack::Peek(){
	return _top->getData();
}

stackStatus Stack::Pop(){
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

ostream& operator<<(ostream& output, Stack& stack)
{
	StackNode *node = stack._top;

	while (node != NULL){
		cout << node->getData() << endl;
		node = node->getNext();
	}

	return output;
}
