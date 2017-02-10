#pragma once
#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <fstream>
#include <istream>
#include <iostream>

class Maze {
private:
	std::ifstream file;
	char **mazeChars;
	int width;
	int height;
public:
	Maze(char* fileSource);
	char ** getChars();
	int getWidth();
	int getHeight();
};

#endif //MAZE_H