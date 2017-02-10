
#include <string>
#include <istream>
#include <iostream>
#include <conio.h>

#include "maze.h"

char **maze;

int main(int argc, char* argv[]) {
	if (argc > 1) {
		Maze maze = Maze(argv[1]);
		//P R I N T the maze
		for (int row = 0; row < maze.getHeight(); row++) {
			for (int col = 0; col < maze.getWidth(); col++) {
				std::cout << maze.getChars()[row][col];
			}
			std::cout << std::endl;
		}
		_getch();
	}
}
