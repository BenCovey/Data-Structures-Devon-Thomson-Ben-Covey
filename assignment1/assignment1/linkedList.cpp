#include <string.h>
#include <iostream>
#include "linkedList.h"
#include <vector>

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
lineList::node::node(char* inData) {
	memmove(lineData, inData, LINE_SIZE);
	nextNode = NULL;
}

//-------------------------------------------------
//M E T H O D definitions for L I N E L I S T class
//-------------------------------------------------
char* lineList::save() {
	node *currentNode = head;
	char *output = new char[5000];
	int num = 0;
	while (currentNode != NULL) {
		num++;
	}
	int i = 0;

	while (currentNode != NULL) {
		output = currentNode->lineData;
		currentNode = currentNode->nextNode;
		i++;
	}
	
	return output;
}
void lineList::add(char* inLineData) {
	node * nodeToAdd = new node(inLineData);
	if (head == NULL) { head = nodeToAdd; return; }//return early if the list is empty.
	else {
		node *currentNode = head; //otherwise loop through until the end of the list is found
		while (currentNode->nextNode != NULL) {currentNode = currentNode->nextNode;}
		currentNode->nextNode = nodeToAdd;
	}
}//E N D lineList::add

void lineList::insert(int beforeNode, char* inLineData) {
	int index = 0;
	node *currentNode = head;
	while (index < beforeNode -1) {
		if (currentNode->nextNode == NULL) {
			add(inLineData); //call the add function and
			return;//return early if the node given is outside the range of the existing list
		}
		currentNode = currentNode->nextNode;
		index++;
	}
	node *insertedNode = new node(inLineData);
	insertedNode->nextNode = currentNode->nextNode;
	currentNode->nextNode = insertedNode;
}//E N D lineList::insert

void lineList::substitude(int nodeToSub, char* inLineData) {
	int index = 0;
	node *currentNode = head;
	while (index < nodeToSub) {
		if (currentNode->nextNode == NULL) {
			add(inLineData); //call the add function and
			return;//return early if the node given is outside the range of the existing list
		}
		currentNode = currentNode->nextNode;
		index++;
	}
	memmove(currentNode->lineData, inLineData, LINE_SIZE);
}//E N D lineList::substitute

//D E L E T I N G
void lineList::deleteNode(int delNode) {
	int index = 0;
	node *currentNode = head;
	while (index < delNode -1 ) {
		if (currentNode->nextNode == NULL) {return; }//if we get to the end return without deleting anything.
		currentNode = currentNode->nextNode;
		index++;
	}
	node *nodeToDel = currentNode->nextNode;
	node *nodeAfterDel = nodeToDel->nextNode;
	delete nodeToDel;
	currentNode->nextNode = nodeAfterDel;
}//E N D lineList::deleteNode

std::ostream& operator<< (std::ostream& output, lineList& list) {
	lineList::node *currentNode = list.head;
	int i = 0;

	while (currentNode != NULL) {
		output << i << ": " << currentNode->lineData << std::endl;
		currentNode = currentNode->nextNode;
		i++;
	}
	return output;
}//E N D lineList::operator<<






