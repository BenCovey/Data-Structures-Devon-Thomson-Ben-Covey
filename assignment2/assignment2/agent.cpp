#include "agent.h";

Agent::Agent() {
	pathStack = new Stack();
	rowPos = 1; colPos = 1;
	pathStack->Push(1, 0);
}

void Agent::navigate(Maze *inMaze) {//sets the maze reference and contains the loop of moves
	maze = inMaze;
	while (rowPos < maze->getHeight() - 1 && colPos < maze->getWidth() - 1) {
		move();
	}
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
		return;
	}else {
		maze->getChars()[rowPos][colPos] = '.';//drop the poison pill
		rowPos = pathStack->Peek()->row; colPos = pathStack->Peek()->col;
		pathStack->Pop();
	}
}//E N D  M E T H O D Agent::move()

std::string Agent::showMazePath() {//should not be called until after the navigate method
	std::string mazeString, currentLine;
	StackNode *currentNode;
	for (int row = maze->getHeight() - 1; row > 0; row--) {
		currentLine = "";
		for (int col = maze->getWidth() - 1; col > 0; col--) {
			bool pathFound = false;
			currentNode = pathStack->top;
			//SEARCH through stack to find this square in the move history
			while (currentNode->getNext() != NULL) {
				if (row == currentNode->getData()->row && col == currentNode->getData()->col) {
					pathFound = true;
					currentLine = '#' + currentLine;
					break;
				}
				currentNode = currentNode->getNext();
			}
			if (!pathFound) {
				if (row == rowPos && col == colPos) {
					currentLine = 'M' + currentLine;
				}else {
					if(maze->getChars()[row][col] == '.'){ currentLine = ' ' + currentLine; }
					else { currentLine = maze->getChars()[row][col] + currentLine; }
				}
			}
		}
		mazeString = currentLine + "\n" + mazeString;
	}
	return mazeString;
}//E N D  M E T H O D Agent::showMazePath()