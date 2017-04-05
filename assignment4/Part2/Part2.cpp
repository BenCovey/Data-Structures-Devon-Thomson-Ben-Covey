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
		switch (choice){
		case 1:
			std::cout << "Enter value to be inserted: ";
			std::cin >> item;
			avl.root = avl.insertNode(avl.root, item);
			break;
		case 2:
			if (avl.root == NULL) {
				std::cout << "Tree is Empty" << std::endl;
				continue;
			}
			std::cout << "Balanced AVL Tree:" << std::endl;
			avl.printTree(avl.root, 1);
			break;
		case 3:
			std::cout << "Inorder Traversal:" << std::endl;
			avl.traverseInOrder(avl.root);
			std::cout << std::endl;
			break;
		case 4:
			std::cout << "Preorder Traversal:" << std::endl;
			avl.traversePreOrder(avl.root);
			std::cout << std::endl;
			break;
		case 5:
			std::cout << "Postorder Traversal:" << std::endl;
			avl.traversePostOrder(avl.root);
			std::cout << std::endl;
			break;
		case 6:
			exit(1);
			break;
		default:
			std::cout << "Wrong Choice" << std::endl;
		}
	}
	return 0;
}

