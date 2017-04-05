// Part1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int I_BinarySearch(int value, int size, int* array) {
	int mid;
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (array[mid] > value)
			high = mid - 1;
		else if (array[mid] < value)
			low = mid + 1;
		else
			return mid; //found
	}
	return -1; //not found
}

int main() {
	const int ARRAY_SIZE = 100000;
	srand(time(NULL));

	int sortedArray[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++) {
		sortedArray[i] = i;
	}

	//select a random number
	int searchGoal = 1 + (rand() % ARRAY_SIZE);
	std::cout << "Searching for " << searchGoal << std::endl;

	//Linear search
	std::cout << "Starting linear search" << std::endl;
	clock_t starttime = clock();
	for (int i = 0; i < sizeof(sortedArray) / sizeof(sortedArray[0]); i++) {
		//std::cout << i << "\t";
		if (i == searchGoal) {
			clock_t endtime = clock(); // Timer end
			double time = (endtime - starttime);
			time /= CLOCKS_PER_SEC;
			std::cout << "linear search took " << time << std::endl;
			break;
		}
	}
	_getch();
    return 0;
}

