#include <iostream>
#include "stacknode.h"

StackNode::StackNode() : nodeCoord(new coord(0,0)), nextNode(NULL) {}

StackNode::StackNode(int inX, int inY, StackNode* next) : nodeCoord(new coord(inX, inY)), nextNode(next) {}

StackNode::~StackNode() {}

coord* StackNode::getData() { return nodeCoord; }

void StackNode::setData(int inX, int inY) { nodeCoord = new coord(inX, inY); }

StackNode* StackNode::getNext() { return nextNode; }

void StackNode::setNext(StackNode *next) { nextNode = next; }