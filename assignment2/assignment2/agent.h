#pragma once
#ifndef AGENT_H
#define AGENT_H

#include "stack.h"
#include "maze.h"
#include <string>

class Agent {
public:
	Agent();
	Stack *pathStack;
	void navigate(Maze *inMaze);//sets the maze reference and contains the loop of moves
	std::string showMazePath();//should not be called until after the navigate method
private:
	void move();//contains the logic for finding a move, as well as dropping poison pills.
	Maze *maze;
	int rowPos, colPos;
};

#endif // !AGENT_H
