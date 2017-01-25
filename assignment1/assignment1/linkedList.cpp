#include <string.h>
#include <iostream>
#include "linkedList.h"
//Added comment for push test
//Default C O N S T R U C T O R
lineList::lineList() {
	head = NULL;
}

//Virtual D E S T R U C T O R
lineList::~lineList() {
	node *currentNode = head;
	while (currentNode != NULL) {
		node *temp = currentNode;
		currentNode = currentNode->nextNode;
		delete temp;
	}
}

//node C O N S T R U C T O R
node::node(linkString inData) {
	lineData = inData;
	nextNode = NULL;
}

//-------------------------------------------------
//M E T H O D definitions for L I N E L I S T class
//-------------------------------------------------

//A D D I N G
void lineList::add(linkString inLineData) {
	node * nodeToAdd = new node(inLineData);
	nodeToAdd->nextNode = NULL;
	if (head == NULL) {
		head = nodeToAdd;
	}
	else {
		node *currentNode = head;
		while (currentNode->nextNode != NULL) {
			currentNode = currentNode->nextNode;
		}
		currentNode->nextNode = nodeToAdd;
	}
}//E N D lineList::add

 //D E L E T I N G
void lineList::deleteNode(int nodeStart, int nodeStop) {

}

void lineList::deleteNode(int delNode) {
	int index = 0;
	node *currentNode = head;
	while (index < delNode - 1) {
		currentNode = currentNode->nextNode;
		index++;
	}
	node *nodeToDel = currentNode->nextNode;
	node *nodeAfterDel = nodeToDel->nextNode;
	delete nodeToDel;
	currentNode->nextNode = nodeAfterDel;
}

void lineList::deleteNode(int nodeStart, int nodeStop) {
	int index = 0;
	node *currentNode = head;
	while (index < nodeStart - 1) {
		currentNode = currentNode->nextNode;
		index++;
	}
	node *preDelNode = currentNode;
	while (index < nodeStop) {
		node *nodeToDel = currentNode;
		currentNode = currentNode->nextNode;
		delete nodeToDel;
		node *postDelNode = currentNode->nextNode;
	}
	//currentNode->nextNode = nodeAfterDel;
}

std::ostream& operator<< (std::ostream& output, lineList& list) {
	node *currentNode = list.head;
	while (currentNode != NULL) {
		output << currentNode->lineData.stringData << std::endl;
		currentNode = currentNode->nextNode;
	}
	return output;
}//E N D lineList::operator<<



