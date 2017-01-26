#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H


class lineList {
public:
	struct node {
		node* nextNode;
		char lineData[256];
		node(char* inData);
	};//E N D struct node
	static const unsigned int LINE_SIZE = 100;
	lineList() {}
	void add(char* inLineData);
	void insert(int beforeNode, char* inLineData);
	void substitude(int nodeToSub, char* inLineData);
	void deleteNode(int node);
	char* save();
	virtual ~lineList();

	friend std::ostream& operator<<(std::ostream& output, lineList& list);

private:
	node *head;
};//E N D class lineList

#endif // !LINKED_LIST_H