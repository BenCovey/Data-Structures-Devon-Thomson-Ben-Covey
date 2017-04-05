// Part2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "avl.h"

int main() {
	int choice, item;
	avlTree avl;
	while (true)
	{
		std::cout << "\n---------------------" << std::endl;
		std::cout << "AVL Tree Implementation" << std::endl;
		std::cout << "\n---------------------" << std::endl;
		std::cout << "1.Insert Element into the tree" << std::endl;
		std::cout << "2.Display Balanced AVL Tree" << std::endl;
		std::cout << "3.InOrder traversal" << std::endl;
		std::cout << "4.PreOrder traversal" << std::endl;
		std::cout << "5.PostOrder traversal" << std::endl;
		std::cout << "6.Exit" << std::endl;
		std::cout << "Enter your Choice: ";
		std::cin >> choice;

		if (choice == 1) {
			std::string inLine;

			std::string name;
			std::cout << "Please, enter your full name: ";
			std::getline(std::cin, name);
			std::cout << "Hello, " << name << "!\n";

			std::cout << "Enter string to be inserted: ";
			std::getline(std::cin, inLine);
			avl.root = avl.insertNode(avl.root, inLine);
		}
		else if (choice == 2) {
			if (avl.root == NULL) {
				std::cout << "Tree is Empty" << std::endl;
				continue;
			}
			std::cout << "Balanced AVL Tree:" << std::endl;
			avl.printTree(avl.root, 1);
		}
		else if (choice == 3) {
			std::cout << "Inorder Traversal:" << std::endl;
			avl.traverseInOrder(avl.root);
			std::cout << std::endl;
		}
		else if (choice == 4) {
			std::cout << "Preorder Traversal:" << std::endl;
			avl.traversePreOrder(avl.root);
			std::cout << std::endl;
		}
		else if (choice == 5) {
			std::cout << "Postorder Traversal:" << std::endl;
			avl.traversePostOrder(avl.root);
			std::cout << std::endl;
		}
		else if (choice == 6) {
			exit(1);
		}
		else {
			std::cout << "Wrong Choice" << std::endl;
		}
	}
	return 0;
}

