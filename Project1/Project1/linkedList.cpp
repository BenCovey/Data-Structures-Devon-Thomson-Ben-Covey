#include <string.h>
#include <iostream>
#include "linkedList.h"

//Default C O N S T R U C T O R
lineList::lineList() {
	head = NULL;
}

//Virtual D E S T R U C T O R
lineList::~lineList() {
	node *currentNode = head;
	while (currentNode != NULL){
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
			//std::cout << "\t\t " << currentNode->lineData << std::endl;
		}
		currentNode->nextNode = nodeToAdd;
	}
}//E N D lineList::add

std::ostream& operator<< (std::ostream& output, lineList& list) {
	node *currentNode = list.head;
	while (currentNode != NULL){
		output << currentNode->lineData.stringData << std::endl;
		currentNode = currentNode->nextNode;
	}
	return output;
}



