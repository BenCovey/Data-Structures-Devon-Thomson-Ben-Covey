#include<iostream>
#include<string>
#include<fstream>
#include <conio.h>

using namespace std;

//PROTOTYPES
string toLower(string word);
bool checkNumber(string word);
string removeSpecialChars(string word);
class LinkedList;
class HashTable;
struct Node;

struct Node { // Node for a List
	string word = "";
	Node * nextNode = NULL;
};


class LinkedList { // Linked List basically same one as used previously
public:
	Node *head;

	LinkedList() { // Constructor
		head = NULL;
	}

	bool push_back(Node node) { // Inserting in a linked List
		Node *e = new Node;
		*e = node; // Temp
		if (head == NULL) {
			head = e;
			return true;
		}
		else {
			Node* current = head; //Set head
			while (current->nextNode != NULL) {//Move through
				current = current->nextNode;
			}
			current->nextNode = e;
			return true;
		}
	}

	bool remove(int index) { // Removing elements from List
		Node *current = head;
		if (index == 1) {
			Node * temp = head;
			head = head->nextNode;
			delete temp;
			return true;
		}
		int count = 1;
		while (count < index - 1) {
			current = current->nextNode;
			count++;
		}
		Node *temp = current->nextNode;
		current->nextNode = current->nextNode->nextNode;
		delete temp;
		return true;
	}
	Node *begin() { // giving address of start of List
		return head;
	}
	int size() { // return size of List
		int count = 0;
		Node * current = head;
		while (current != NULL) {
			count++;
			current = current->nextNode;
		}
		return count;
	}
	void display() { // displaying linked List
		Node * current = head;
		while (current != NULL) {
			cout << current->word << " ";
			current = current->nextNode;
		}
		cout << endl;
	}
	bool find(string s) { // searching for a string in a list
		Node * current = head;
		while (current != NULL)
		{
			if (current->word == s)
			{
				return true;
			}
			current = current->nextNode;
		}
		return false;
	}
};

class HashTable {
public:
	/*
	Algorithm Rules
	1.From the rightmost digit, which is the check digit, and moving left, double the value of every second digit.
	If the result of this doubling operation is greater than 9 (e.g., 8 × 2 = 16), then add the digits of the product
	(e.g., 16: 1 + 6 = 7, 18: 1 + 8 = 9) or alternatively subtract 9 from the product (e.g., 16: 16 - 9 = 7, 18: 18 - 9 = 9).
	2.Take the sum of all the digits.
	3.If the total modulo 10 is equal to 0 (if the total ends in zero) then the number is valid according to the Luhn formula;
	else it is not valid.
	Referencing http://www.eecs.wsu.edu/~ananth/CptS223/Lectures/hashing.pdf
	*/
	LinkedList *hashes;
	int size;
	int num_collisions;

	HashTable() { // Constructor
		size = 19; //Prime Number for minor collision removal
		num_collisions = 0;
		hashes = new LinkedList[size];
	}

	int hash_function(char c) { // based on  Luhn algorithm
		int x = c;
		return c % size; // size is 10.
	}

	bool insert(string s) { // Inserting to hash table
		int pos = hash_function(s[0]);
		if (hashes[pos].size() > 0) { 
			//Would implement Open Addressing, except its time benefits are neutral, and requires
			//larger hashing table
			num_collisions++;
		}
		Node temp;
		temp.word = s;
		hashes[pos].push_back(temp);
		return true;
	}

	bool search(string s) { // Find in hash table
		int pos = hash_function(s[0]);
		return hashes[pos].find(s);
	}

	void display() {
		for (int i = 0; i < size; i++) {
			cout << i << ":";
			hashes[i].display();
			cout << endl;
		}
	}
};
int main() {

	fstream dictFile; // Dictionary File
	string currentWord = ""; // Current Word From File
	Node word;
	fstream misFile; // Mispelled.txt File
	int misspelt = 0;
	LinkedList mispelled;
	HashTable *hashTable;
	HashTable dictionary; // Using Luhn Algorithm (mod 10 basically)

	dictFile.open("dictionary.txt", ios::in); // Open Dictionary.txt
	
	while (getline(dictFile, currentWord)) {//Insert into Hash Table, while there are lines to read.
		if (currentWord != "") {//Preventing weird bug I had..
			dictionary.insert(currentWord);
		}
	}

	cout << "Hashing Contents" << endl;
	dictionary.display(); // Display Hash
	misFile.open("mispelled.txt", ios::in); // Open Mispelled.txt
	while (getline(misFile, currentWord, ' ')) { // reading mispelled words file on basis of spaces
		currentWord = removeSpecialChars(currentWord); // Remove special Chars 
		word.word = currentWord; // Writing to a Node
		mispelled.push_back(word); // inserting into a List
	}

	cout << "\nMisspelt words are";
	Node *iteratorNode = mispelled.begin(); // iterator to traverse through List
	cout << endl;

	while (iteratorNode != NULL) { // Loop while there are nodes to traverse
		string currentWord = iteratorNode->word;
		currentWord = toLower(currentWord);

		if (!checkNumber(currentWord)) { // skip if it's a number
			if (!dictionary.search(currentWord)) { // dislay the word if not found in dictionary hashes table
				cout << endl << "      " << iteratorNode->word ;
				misspelt++;
			}
		}
		iteratorNode = iteratorNode->nextNode; // nextNode Node
	}


	cout << "\n\nTotal number of collisions: " << dictionary.num_collisions << endl;
	cout << "Total number of Misspelt words: " << misspelt << endl;
	_getch();
}


string toLower(string word) { // Lower case strings for comparisons
	string currentWord = word;
	for (int i = 0; i < word.length(); i++) { // Loop through string and check each char
		currentWord[i] = tolower(word[i]);
	}
	return currentWord;
}

bool checkNumber(string word) { // Check if the string is a number 
	for (int i = 0; i < word.length(); i++) {
		int code = word[i];
		if (code < 48 || code > 57) // If ASCII code is not between 48 - 57 -> not a number
			return false;
	}
	return true;
}

string removeSpecialChars(string word) { // Remove special characters from strings
	string currentWord = word;
	for (int i = 0; i < currentWord.length(); i++) { // Remove these characters
		if (currentWord[i] == ',' || currentWord[i] == '"' || currentWord[i] == '(' || currentWord[i] == ')' || currentWord[i] == '#' || currentWord[i] == '&' || currentWord[i] == '.' || currentWord[i] == '\n') {
			currentWord.erase(i, 1); // Delete the character
			i--;
		}
	}
	return currentWord;
}



