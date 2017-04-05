#include "stdafx.h"
#include "avl.h"

/*
--------------- H E I G H T  C A L C ---------------
*/
int avlTree::getHeight(avl_node *branch) {
	int h = 0;
	if (branch != NULL)
	{
		int l_height = getHeight(branch->left);
		int r_height = getHeight(branch->right);
		int max_height = std::max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}
int avlTree::getHeightDiff(avl_node *branch) {
	int l_height = getHeight(branch->left);
	int r_height = getHeight(branch->right);
	int b_factor = l_height - r_height;
	return b_factor;
}
//E N D  H E I G H T  C A L C

/*
--------------- R O T A T I O N S ---------------
*/
avl_node* avlTree::rotateRight(avl_node *parent) {
	avl_node *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

avl_node* avlTree::rotateLeft(avl_node *parent) {
	avl_node *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

avl_node* avlTree::rotateLeftRight(avl_node *parent) {
	avl_node *temp;
	temp = parent->left;
	parent->left = rotateRight(temp);
	return rotateLeft(parent);
}

avl_node* avlTree::rotateRightLeft(avl_node *parent) {
	avl_node *temp;
	temp = parent->right;
	parent->right = rotateLeft(temp);
	return rotateRight(parent);
}
//E N D  R O T A T I O N S


/*
--------------- T R E E  F U N C T I O N S ---------------
*/
avl_node* avlTree::balanceTree(avl_node *branch) {
	int bal_factor = getHeightDiff(branch);
	if (bal_factor > 1)
	{
		if (getHeightDiff(branch->left) > 0)
			branch = rotateLeft(branch);
		else
			branch = rotateLeftRight(branch);
	}
	else if (bal_factor < -1)
	{
		if (getHeightDiff(branch->right) > 0)
			branch = rotateRightLeft(branch);
		else
			branch = rotateRight(branch);
	}
	return branch;
}

avl_node* avlTree::insertNode(avl_node *branch, std::string value) {
	if (branch == NULL) {
		branch = new avl_node;
		branch->data = value;
		branch->left = NULL;
		branch->right = NULL;
		return branch;
	}
	else if (value < branch->data) {
		branch->left = insertNode(branch->left, value);
		branch = balanceTree(branch);
	}
	else if (value >= branch->data) {
		branch->right = insertNode(branch->right, value);
		branch = balanceTree(branch);
	}
	return branch;
}
//E N D  T R E E  F U N C T I O N S

 /*
 --------------- V I E W I N G  F U N C T I O N S ---------------
 */
void avlTree::printTree(avl_node *branch, int level) {
	int i;
	if (branch != NULL)
	{
		printTree(branch->right, level + 1);
		printf("\n");
		if (branch == root)
			std::cout << "Root -> ";
		for (i = 0; i < level && branch != root; i++)
			std::cout << "        ";
		std::cout << branch->data;
		printTree(branch->left, level + 1);
	}
}

void avlTree::traverseInOrder(avl_node *branch) {
	if (branch == NULL) { return; }
	traverseInOrder(branch->left);
	std::cout << branch->data << "  ";
	traverseInOrder(branch->right);
}

void avlTree::traversePreOrder(avl_node *branch) {
	if (branch == NULL) { return; }
	std::cout << branch->data << "  ";
	traversePreOrder(branch->left);
	traversePreOrder(branch->right);
}

void avlTree::traversePostOrder(avl_node *branch) {
	if (branch == NULL) { return; }
	traversePostOrder(branch->left);
	traversePostOrder(branch->right);
	std::cout << branch->data << "  ";
}
//E N D  V I E W I N G  F U N C T I O N S