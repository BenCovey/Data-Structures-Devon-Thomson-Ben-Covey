#include "agent.h";
#include <windows.h>

Agent::Agent() {
	pathStack = new Stack();
	rowPos = 1; colPos = 1;
	pathStack->Push(1, 0);
}

void Agent::navigate(Maze *inMaze) {//sets the maze reference and contains the loop of moves
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	maze = inMaze;
	while (rowPos < maze->getHeight() - 1 && colPos < maze->getWidth() - 1) {
		showMazePath();
		SetConsoleCursorPosition(hConsole, { 0, 0 });
		move();
	}
	std::cout << "SOMETHING FINISHED" << std::endl;
}//E N D  M E T H O D Agent::navigate(Maze *inMaze)

void Agent::move() {//contains the logic for each move, as well as dropping poison pills.
	//if there is a blank space in the search that was not agent's last move. move to that space.
	int destRow = -1, destCol = -1;
	//look at each point
	for (int move = 0; move < 4; move++) {
		int row, col;
		if(move == 0){ row = rowPos - 1; col = colPos; }
		else if (move == 1) { row = rowPos; col = colPos + 1; }
		else if (move == 2) { row = rowPos + 1; col = colPos; }
		else if (move == 3) { row = rowPos; col = colPos - 1; }
		if (maze->getChars()[row][col] == ' ' && (pathStack->Peek()->row != row || pathStack->Peek()->col != col)) {
			destRow = row; destCol = col;
			break;
		}
	}
	if (destRow > 0 && destCol > 0) {
		pathStack->Push(rowPos, colPos);
		rowPos = destRow; colPos = destCol;
		//std::cout << "made a move to " << destRow << " " << destCol << std::endl;
		return;
	}else {
		maze->getChars()[rowPos][colPos] = '.';//drop the poison pill
		rowPos = pathStack->Peek()->row; colPos = pathStack->Peek()->col;
		pathStack->Pop();
		//std::cout << "went back" << std::endl;
	}
}//E N D  M E T H O D Agent::move()

std::string Agent::showMazePath() {//should not be called until after the navigate method
	for (int row = 0; row < maze->getHeight(); row++) {
		for (int col = 0; col < maze->getWidth(); col++) {
			if (row == rowPos && col == colPos) {
				std::cout << 'M';
			}else {
				std::cout << maze->getChars()[row][col];
			}
		}
		std::cout << std::endl;
	}
	return "testReturn";
}//E N D  M E T H O D Agent::showMazePath()