#include "maze.h"
#include <string>
#include <fstream>
#include <istream>
#include <iostream>

Maze::Maze(char* fileSource) {
	width = 0; height = 1;
	file = std::ifstream(fileSource);
	if (file.good()) {
		std::string line;
		std::getline(file, line);
		//getting S I Z E of maze
		width = line.length();
		while (std::getline(file, line)) { height++; }
		//clear and reset file before filling
		file.clear(); file.seekg(0, std::ios::beg);
		//F I L L I N G mazeChars variable
		mazeChars = new char*[height];
		for (int row = 0; row < height; row++) {
			mazeChars[row] = new char[width];
			std::string tempLine;
			getline(file, tempLine);
			for (int col = 0; col < width; col++) {
				mazeChars[row][col] = tempLine.at(col);
			}
		}
	}
}

char** Maze::getChars() { return mazeChars; }
int Maze::getWidth() { return width; }
int Maze::getHeight() { return height; }