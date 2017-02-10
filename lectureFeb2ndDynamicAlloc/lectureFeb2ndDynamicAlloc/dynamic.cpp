#include <iostream>
#include <conio.h>

int main() {
	int **maze;
	int row = 10;
	int col = 5;
	// dynamically allocate an array
	// row = number of maze rows
	// col = line length

	maze = new int *[row];
	for (int count = 0; count < row; count++)
	{
		maze[count] = new int[col];
	}

	// load the elements in to the maze
	std::cout << std::endl << "Now enter the element for the maze...";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << std::endl << "Row " << (i + 1) << " Col " << (j + 1) << " :";
			std::cin >> maze[i][j];
		}
	}

	// To free the dynamically allocated memory
	// Delete each row pointer before deleting the array of pointers
	for (int i = 0; i < row; i++)
	{
		delete[] maze[i];
	}
	delete[] maze;

	return 0;
}

