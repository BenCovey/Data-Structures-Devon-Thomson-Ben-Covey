#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
struct linkString {
	char stringData[100];
};

struct node {
	node* nextNode;
	linkString lineData;
	node(linkString inData);
};//E N D struct node

class lineList {
private:
	node *head;
public:
	lineList();
	void add(linkString inLineData);
	void deleteNode(int nodeStart, int nodeStop);
	void deleteNode(int node);
	virtual ~lineList();

	friend std::ostream& operator<<(std::ostream& output, lineList& list);

};//E N D class lineList

#endif // !LINKED_LIST_H