#pragma once
#ifndef AVL_H
#define AVL_H

#include "stdafx.h"
struct avl_node
{
	std::string data;
	struct avl_node *left;
	struct avl_node *right;
};

/*
* Class Declaration
*/
class avlTree
{
public:
	avl_node *root;
	int getHeight(avl_node *);
	int getHeightDiff(avl_node *);
	//rotations
	avl_node *rotateRight(avl_node *);
	avl_node *rotateLeft(avl_node *);
	avl_node *rotateLeftRight(avl_node *);
	avl_node *rotateRightLeft(avl_node *);
	avl_node* balanceTree(avl_node *);
	avl_node* insertNode(avl_node *, std::string);
	bool findInTree(avl_node *, std::string);
	bool findInTree(std::string);
	//viewing
	void printTree(avl_node *, int);
	void traverse(avl_node *);
	
	avlTree() {
		root = NULL;
	}
};

#endif // !AVL_H
