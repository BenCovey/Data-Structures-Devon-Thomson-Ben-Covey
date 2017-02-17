
#include <string>
#include <istream>
#include <iostream>
#include <conio.h>

#include "maze.h"
#include "agent.h"
#include "stack.h"

char **maze;
std::ofstream outfile;
int main(int argc, char* argv[]) {
	if (argc > 2) {
		Maze *maze = new Maze(argv[1]);
		Agent agent = Agent();
		agent.navigate(maze);
		std::string solution = agent.showMazePath();
		std::cout << solution;
		outfile.open(argv[2]);
		outfile << solution;
		outfile.close();
		_getch();
	}
	else {
		std::cout << "too few arguments. In and out file locations required";
	}
}
