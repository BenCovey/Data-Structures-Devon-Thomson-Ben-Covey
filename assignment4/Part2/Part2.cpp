// Part2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "avl.h"

void interactWithTree(avlTree*);

int main() {
	//Load  d i c t i o n a r y  into AVL tree
	avlTree* dictionary = new avlTree();
	std::ifstream infile("dictionary.txt");
	std::string line;
	while (std::getline(infile, line)) {
		dictionary->root = dictionary->insertNode(dictionary->root, line);
	}
	std::cout << "--------------- AVL TREE --------------- \n\n";
	dictionary->printTree(dictionary->root, 1);
	std::cout << "\n\n";
	std::cout << "--------------- ORDERED DICTIONARY --------------- \n\n";
	dictionary->traverse(dictionary->root);
	
	//Load  p a r a g r a p h  to array of words
	std::ifstream paragraph("checkText.txt");
	std::istream_iterator<std::string> in{ paragraph }, end;
	int wordsNum = std::distance(in, end);
	paragraph = std::ifstream("checkText.txt");
	std::string* paragraphWords = new std::string[wordsNum];
	std::string currentWord;
	std::cout << "\n\n--------------- SAMPLE TO CHECK --------------- \n\n";
	for (int i = 0; i < wordsNum; i++) {
		paragraph >> currentWord;
		std::cout << currentWord + " ";
		currentWord.erase(std::remove_if(currentWord.begin(), currentWord.end(), [](const unsigned &c) { return !isalpha(c); }), currentWord.end());
		paragraphWords[i] = currentWord;
	}

	//run each word through s p e l l c h e c k and print words that are misspelled
	std::cout << "\n\n--------------- MISSPELLED WORDS --------------- \n\n";
	for (int i = 0; i < wordsNum; i++) {
		if (paragraphWords[i] != "" && !dictionary->findInTree(paragraphWords[i])) {
			std::cout << paragraphWords[i] << " ";
		}
	}	
		
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

