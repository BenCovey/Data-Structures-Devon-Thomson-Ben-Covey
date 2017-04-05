// Part1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define ARRAY_SIZE 100000

int binarySearch(int searchFor, int* array) {
	int mid = -1;
	int low = 0;
	int high = ARRAY_SIZE - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		std::cout << mid << "\t";
		if (array[mid] > searchFor) {
			high = mid - 1;
		}
		else if (array[mid] < searchFor) {
			low = mid + 1;
		}
		else {
			std::cout << std::endl << "FOUND:::::::: " << mid + 1 << "\t" << "\n\n";
			return mid + 1;
		}
	}
	return -1;
}

int linearSearch(int searchFor, int* array) {
	int found = -1;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		std::cout << i << "\t";
		if (i == searchFor) {
			std::cout << std::endl << "FOUND:::::::: " << i << "\t" << "\n\n";
			found = i;
			break;
		}
	}
	return found;
}

int main() {
	srand(time(NULL));
	std::cout << time(NULL) << "\n\n";
	//select a random number
	int searchGoal = rand() % ARRAY_SIZE + 1;
	std::cout << "Searching for " << searchGoal << std::endl;
	
	int* sortedArray = new int[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++) {
		sortedArray[i] = i + 1;
	}

	

	//Linear search
	std::cout << "Starting linear search" << std::endl;
	clock_t starttime = clock();
	linearSearch(searchGoal, sortedArray);
	clock_t endtime = clock(); // Timer end
	double time = (endtime - starttime);
	time /= CLOCKS_PER_SEC;
	std::cout << "linear search took " << time << "\n\n";
	//END Linear search

	//Binary search
	std::cout << "Starting binary search" << std::endl;
	starttime = clock();
	binarySearch(searchGoal, sortedArray);
	endtime = clock(); // Timer end
	time = (endtime - starttime);
	time /= CLOCKS_PER_SEC;
	std::cout << "binary search took " << time << "\n\n";
	//END Binary search



	_getch();
    return 0;
}

