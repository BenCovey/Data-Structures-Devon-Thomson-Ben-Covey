#include <fstream>
#include <iostream>
#include <conio.h>
#include "linkedList.h"
#include <string>
#include <regex>
std::regex inum("i[0-9]+");
std::regex i("i");
std::regex dnum("d[0-9]+-[0-9]+");
std::regex d("d");
std::regex v("v");
std::regex g("g[0-9]+");
std::regex l("l[0-9]+-[0-9]+");
std::regex s("s");
std::regex snum("s[0-9]+");
std::regex e("e");
std::regex q("q");
std::regex replace1("[0-9]+-");
std::regex replace2("-[0-9]+");

//Added comment for push test
//P R O T O T Y P E S
bool validateFileName(char* fileName);
void Regex(char *input);

int main(int argc, char* argv[]) {
	if (validateFileName(argv[1]) && validateFileName(argv[2]) && argc == 3) {
		lineList *editor = new lineList();
		//R E A D lines of file into linked list.
		std::ifstream file;
		file.open(argv[1]);
		const int LINE_SIZE = editor->LINE_SIZE;
		if (file.is_open()) {
			std::cout << "Welcome to the text editor. To insert a line type i, you can specify line number by typing i# " << std::endl;
			std::cout << "To delete a line type d, or to delete several type d#-#. ";
			std::cout << "Insert v to display the entire file, " << std::endl << "g# to display a certain line. ";
			std::cout << "And type l#-# to display a group of lines. You can subtitute the " << std::endl << "current buffered line using s ";
			std::cout << "Insert e to save and quit, or q to quit without saving." << std::endl;
			char line[LINE_SIZE];
			while (!file.eof()) {
				file.getline(line, LINE_SIZE);
				//linkString temp = linkString();
				//memcpy(&line, &temp.stringData, LINE_SIZE);
				//for (int i = 0; i < LINE_SIZE; i++) { temp.stringData[i] = line[i]; }
				editor->add(line);
			}
			std::cout << *editor;
			std::cout << std::endl;

			editor->deleteNode(1);//delete a bunch of stuff
			editor->deleteNode(1);
			editor->deleteNode(1);
			editor->deleteNode(1000);//this should do nothing
			std::cout << *editor;
			std::cout << std::endl;

			editor->insert(2, "I got inserted before node 2");
			std::cout << *editor;
			std::cout << std::endl;

			editor->insert(100, "THIS SHOULD GO AT THE END BY DEFAULT");
			std::cout << *editor;
			std::cout << std::endl;

			editor->substitude(2, "I got inserted and then I got switched to this bull");
			std::cout << *editor;
			std::cout << std::endl;

			//R E G E X		F U N C T I O N 
			while (true) {
				char *input = new char;
				std::cin >> input;
				Regex(input);
			}
		}
		else {
			std::cout << "File of wrong type - or file does not exist" << std::endl;
		}
		_getch();
	}
	else if (argc != 2) {
		std::cout << "TextEditor requires an in file and an out file" << std::endl;
		_getch();
		return 0;
	}
	else {
		std::cout << "Please input valid file names" << std::endl;
		_getch();
		return 0;
	}




}//E N D main

bool validateFileName(char* fileName) {
	return true;
}


void Regex(char * input) {
	if (regex_match(input, inum)) {
		memmove(input, input + 1, strlen(input));
		std::cout << "Input on line " << input << std::endl;
	}//end if
	else if (regex_match(input, i)) {
		std::cout << "Input on current line " << std::endl;
	}//end else if
	else if (regex_match(input, d)) {
		std::cout << "Delete current line " << std::endl;
	}//end else if
	else if (regex_match(input, dnum)) {
		//use memmmove to delete first char in string (aka letter) 
		memmove(input, input + 1, strlen(input));
		//Create strings for the first and second number in request as well as blank for regex_replace
		std::string num1 = input;
		std::string num2 = input;
		std::string blank;
		//Create regex_replace that will replace what isn't needed in the strings
		num1 = regex_replace(num1, replace2, blank);
		num2 = regex_replace(num2, replace1, blank);
		std::cout << "Delete lines from " << num1 << " to " << num2 << std::endl;
	}//end else if
	else if (regex_match(input, v)) {
		std::cout << "Display entire buffer" << std::endl;
	}//end else if
	else if (regex_match(input, g)) {
		memmove(input, input + 1, strlen(input));
		std::cout << "Display line " << input << std::endl;
	}//end else if
	else if (regex_match(input, l)) {
		//use memmmove to delete first char in string (aka letter) 
		memmove(input, input + 1, strlen(input));
		//Create strings for the first and second number in request as well as blank for regex_replace
		std::string num1 = input;
		std::string num2 = input;
		std::string blank;
		//Create regex_replace that will replace what isn't needed in the strings
		num1 = regex_replace(num1, replace2, blank);
		num2 = regex_replace(num2, replace1, blank);
		std::cout << "Display buffer from " << num1 << " to " << num2 << std::endl;
	}//end else if
	else if (regex_match(input, s)) {
		std::cout << "Substitute current line in buffer with new line." << std::endl;
	}//end else if
	else if (regex_match(input, e)) {
		std::cout << "Save and quit" << std::endl;
	}//end else if
	else if (regex_match(input, q)) {
		std::cout << "Save without quitting" << std::endl;
	}//end else if
	else {
		std::cout << "Nothing triggered" << std::endl;
	}//end else
}//end regex