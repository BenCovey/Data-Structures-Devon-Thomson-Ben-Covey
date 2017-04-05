// Part2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "avl.h"

void interactWithTree(avlTree*);

int main() {
	avlTree* tree = new avlTree();
	std::ifstream infile("dictionary.txt");
	std::string line;
	while (std::getline(infile, line)) {
		tree->root = tree->insertNode(tree->root, line);
	}
	tree->printTree(tree->root, 1);
	std::cout << "\n\n\n";
	tree->traverse(tree->root);

	bool test = tree->findInTree("your");
	if (test) { std::cout << "\n\nFOUND THAT WORD\n\n"; }

	//tree->findInTree(tree->root, )
	//while (true) {
		//interactWithTree(Tree);
	//}
	_getch();
	return 0;
}

void interactWithTree(avlTree* avl) {
	std::string choice;
	std::cout << "\n---------------------" << std::endl;
	std::cout << "AVL Tree Implementation" << std::endl;
	std::cout << "\n---------------------" << std::endl;
	std::cout << "1.Insert Element into the tree" << std::endl;
	std::cout << "2.Display Balanced AVL Tree" << std::endl;
	std::cout << "3.traverse the tree in order" << std::endl;
	std::cout << "4.Exit" << std::endl;
	std::cout << "Enter your Choice: ";
	std::getline(std::cin, choice);

	if (choice == "1") {
		std::string inLine;
		std::cout << "Enter string to be inserted: ";
		std::cin.clear();
		std::getline(std::cin, inLine);

		avl->root = avl->insertNode(avl->root, inLine);
	}
	else if (choice == "2") {
		if (avl->root == NULL) {
			std::cout << "Tree is Empty" << std::endl;
			return;
		}
		std::cout << "Balanced AVL Tree:" << std::endl;
		avl->printTree(avl->root, 1);
	}
	else if (choice == "3") {
		std::cout << "Inorder Traversal:" << std::endl;
		avl->traverse(avl->root);
		std::cout << std::endl;
	}
	else if (choice == "4") {
		exit(1);
	}
	else {
		std::cout << "Wrong Choice" << std::endl;
	}
}

