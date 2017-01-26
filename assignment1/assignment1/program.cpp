#include <fstream>
#include <iostream>
#include <conio.h>
#include "linkedList.h"
#include <string>
#include <regex>
std::regex inum("i[0-9]+");
std::regex i("i");
std::regex dnumnum("d[0-9]+-[0-9]+");
std::regex dnum("d[0-9]+");
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
int currentpos = 0;
lineList *editor = new lineList();
std::ofstream outfile;
std::ifstream file;
int main(int argc, char* argv[]) {
	if (validateFileName(argv[1]) && validateFileName(argv[2]) && argc == 3) {
		//R E A D lines of file into linked list.
		outfile.open(argv[2]);
		file.open(argv[1]);
		const int LINE_SIZE = editor->LINE_SIZE;
		if (file.is_open()) {
			std::cout << "Welcome to the text editor. To insert a line type i, you can specify line number by typing i# " << std::endl;
			std::cout << "To delete a line type d, or to delete several type d#-#. ";
			std::cout <<  "Type g# to display a certain line. ";
			std::cout << "And type l to list" << std::endl << "current line. You can subtitute the current buffered line using s ";
			std::cout << "Insert e to save and quit, or q to quit without saving" << std::endl;
			
			char line[LINE_SIZE];
			while (!file.eof()) {
				file.getline(line, LINE_SIZE);
				editor->add(line);
			}
			//R E G E X        F U N C T I O N 
			while (file.is_open()) {
				std::cout << "Current line :" << currentpos << std::endl;
				std::cout << "<!--------------------------!>" << std::endl;
				std::cout << *editor;
				char *input = new char;
				std::cin.getline(input, 256);
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
	

	//outfile.write(editor->save, 1000000);


}//E N D main

bool validateFileName(char* fileName) {
	return true;
}


void Regex(char * input) {
	//Insert on line
	if (regex_match(input, inum)) {
		memmove(input, input + 1, strlen(input));
		int line = atoi(input);
		char *text = new char[256];
		std::cout << "Input on line " << input << ":" << std::endl;
		std::cin.clear();
		std::cin.getline(text, 256);
		editor->insert(line, text);
	}//end if
	//Insert on current line
	else if (regex_match(input, i)) {
		std::cout << "Input on current line " << ":" << std::endl;
		char *text = new char[256];
		std::cin.clear();
		std::cin.getline(text, 256);
		editor->insert(currentpos, text);
	}//end else if
	//Delete current line
	else if (regex_match(input, d)) {
		std::cout << "Delete current line " << std::endl;
		editor->deleteNode(currentpos);
	}//end else if
	//Delete specific line
	else if (regex_match(input, dnum)) {
		std::cout << "Delete line " << input << std::endl;
		memmove(input, input + 1, strlen(input)); 
		editor->deleteNode(atoi(input));
	}//end else if
	//Delete series of lines
	else if (regex_match(input, dnumnum)) {
		//use memmmove to delete first char in string (aka letter) 
		memmove(input, input + 1, strlen(input));
		//Create strings for the first and second number in request as well as blank for regex_replace
		std::string num1 = input;
		std::string num2 = input;
		std::string blank;
		//Create regex_replace that will replace what isn't needed in the strings
		num1 = regex_replace(num1, replace2, blank);
		num2 = regex_replace(num2, replace1, blank);
		int n1 = stoi(num1);
		int num = n1;
		int n2 = stoi(num2);
		if (n1 > n2) { return; }
		std::cout << "Delete lines from " << num1 << " to " << num2 << std::endl;
		for(n1; n1 <= n2; n1++){
			editor->deleteNode(num);
		}
	}//end else if
	//Select line as buffer
	else if (regex_match(input, g)) {
		memmove(input, input + 1, strlen(input));
		std::cout << "Display line " << input << std::endl;
		int line = atoi(input);
		currentpos = line;
		std::cout << "Line " << line << " = " << editor->getLine(line) << std::endl << std::endl;
	}//end else if
	//List current buffer
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
		int n1 = stoi(num1);
		int num = n1;
		int n2 = stoi(num2);
		if (n1 > n2) { 
			std::cout << "Display lines from " << num1 << " to " << num2 << std::endl;
			for (n1; n1 >= n2; n1--) {
				std::cout << "Line " << n1 << " = " << editor->getLine(n1) << std::endl;
			}
		}else {
			std::cout << "Display lines from " << num1 << " to " << num2 << std::endl;
			for (n1; n1 <= n2; n1++) {
				std::cout << "Line " << n1 << " = " << editor->getLine(n1) << std::endl;
			}
		}	
		std::cout << std::endl;
	}//end else if
	//Substitute current line
	else if (regex_match(input, s)) {
		std::cout << "Substitute current line in buffer with new line." << std::endl;
		char *text = new char[256];
		std::cin.clear();
		std::cin.getline(text, 256);
		editor->substitude(currentpos, text);
	}//end else if
	//Substitute line number
	else if (regex_match(input, snum)) {
		//use memmmove to delete first char in string (aka letter) 
		memmove(input, input + 1, strlen(input));
		std::cout << "Substitute line " << input << ":" << std::endl;
		int num = atoi(input);
		char *text = new char[256];
		std::cin.clear();
		std::cin.getline(text, 256);
		editor->substitude(num, text);
	}//end else if
	//Save and quit
	else if (regex_match(input, e)) {
		std::cout << "Save and quit" << std::endl;
		outfile << *editor;
		outfile.close();
		file.close();
	}//end else if
	//Quit
	else if (regex_match(input, q)) {
		std::cout << "Quit without saving" << std::endl;
		//Quit using terminate
		std::terminate();
	}//end else if
	else if (regex_match(input, v)) {
		std::cout << "view all";
	}
	else {
		std::cout << "Nothing triggered" << std::endl;
	}//end else
}//end regex