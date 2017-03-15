// Sorting-A3-DS.cpp : Defines the entry point for the console application.
//DevBen Sorting Files.

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include "time.h"
#include <cstdlib>
#include <regex>
using namespace std;
//* A L L	A R E	A V E R A G E S		O F		F I V E		R U N S
//* SORT          | 1000  | 25,000 | 50,000 | 75,000 | 100,000 |
//* BUBBLESORT    | 0.002S| 1.491S | 6.250S | 14.164S| 25.419S |
//* SELECTIONSORT | 0.001S| 0.061S | 2.409S | 5.434S | 9.694S  |
//* INSERTIONSORT | 0.001S| 0.051S | 2.212S | 5.001S | 9.0197S |
//* SHELLSORT     | 0.001S| 0.005S | 0.01S  | 0.016S | 0.025S  |
//* MERGESORT     | 0.001S| 0.017S | 0.03S  | 0.06S  | 0.085S  |
//* 

//Bubble Sort Prototype
void bubbleSort(int array[], int size);//The Bubble Sort Method

//Selection Sort Prototype
void selectionSort(int array[], int size);//The Selection Sort Method

//Insertion Sort Prototype
void insertionSort(int array[], int size);//The Insertion Sort Method

//Shell Sort Prototype
void shellSort(int array[], int size);//The Shell Sort Method

//Merge Sort Prototype
void mergeSort(int array[], int left, int right);//The Merge Sort Method
void merge(int array[], int left, int middle, int right);//The Merge Method


//Quick Sort Prototype
int Partition(int *array, int beg, int end);
void QuickSort(int *array, int beg, int end, int size);


int main() {
	// Create random size array, filled with random elements: .
	srand((unsigned int)time(NULL));

	int size = 1000; // Size of Array
	string regmatch; // A temp value to take input for validating number.
	//Take input of array size
	cout << "Enter size of array (default is 10000, must be larger than 10)" << endl;

	std::getline(cin, regmatch);

	if (std::regex_match(regmatch, std::regex("[1-9][0-9]+"))) {
		size = stoi(regmatch);
	}
	else {
		size = 10000;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	cout << "Size of array: " << size << endl;
	int *array = new int[size]; // Create array

	// Insert random integers in new array random sized
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 32768 + 1;
	}

	if (size == 11) {
		for (int i = 0; i < size; i++) { cout << array[i] << ","; }
		cout << endl;
	}
	
	cout << "Starting Sort..." << endl;
	clock_t starttime = clock(); // Timer start
		
	/*cout << "Using BubbleSort ";
	bubbleSort(array, size);*/

	/*cout << "Using SelectionSort ";
	selectionSort(array, size);*/

	/*cout << "Using InsertionSort ";
	insertionSort(array, size);*/

	/*cout << "Using ShellSort ";
	shellSort(array, size);*/

	/*cout << "Using MergeSort ";
	mergeSort(array, 0, size - 1); */

	cout << "Using Quicksort ";
	QuickSort(array, 0, size - 1, size);

	clock_t endtime = clock(); // Timer end
	double time = (endtime - starttime);
	time /= CLOCKS_PER_SEC;
	cout << "it took " << time << " seconds to sort an array that was " << size << " long" << endl;
	
	if (size == 11) {
		for (int i = 0; i < size; i++) { cout << array[i] << ","; }
		cout << endl;
	}
		
	delete[] array; // Garbage collection

	cout << "Sort another array? (y/n)" << endl;

	char again;
	cin >> again;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Ignore max stream and stream that just has newline
	std::cin.clear();//Clear stream
	if (again == 'y') {
		main();
	}
	
	
	cout << "End of Sorting" << endl;
	cin.get();//To stop the program from closing right after ending
	return 0;
}

/*
Bubble sort is a simple sorting algorithm. This sorting algorithm is 
comparison-based algorithm in which each pair of adjacent elements is
compared and the elements are swapped if they are not in order.
*/
void bubbleSort(int array[], int size) {
	int outer, inner;
	for (outer = size - 1; outer > 0; outer--) {
		for (inner = 0; inner < outer; inner++) {
			if (array[inner] > array[inner + 1]) {
				int temp = array[inner];
				array[inner] = array[inner + 1];
				array[inner + 1] = temp;
			}
		}
	}
}

/*
The selection sort is a combination of searching and sorting. During each pass, 
the unsorted element with the smallest (or largest) value is moved to its proper
position in the array. The number of times the sort passes through the array
is one less than the number of items in the array.
*/
void selectionSort(int array[], int size) {
	int outer, inner, min;
	for (outer = 0; outer < size - 1; outer++) {
		min = outer;
		for (inner = outer + 1; inner < size; inner++) {
			if (array[inner] < array[min]) {
				min = inner;
			}
		}
		int temp = array[outer];
		array[outer] = array[min];
		array[min] = temp;
	}
}

/*
The selection sort is a combination of searching and sorting. 
During each pass, the unsorted element with the smallest (or largest)
value is moved to its proper position in the array. The number of times
the sort passes through the array is one less than the number of items in the array.
cforbeginners.com/insertionsort.html
*/
void insertionSort(int array[], int size) {
	int i, j, temp;
	for (i = 1; i < size; i++) {
		j = i;
		while (j > 0 && array[j - 1] > array[j]) {
			temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j--;
		}
	}
}

/*
Shellsort, also known as Shell sort or Shell's method, is an in-place comparison
sort. It can be seen as either a generalization of sorting by exchange (bubble sort)
or sorting by insertion (insertion sort).
*/
void shellSort(int array[], int size){
	int i, j, increment, temp;
	for (increment = size / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i<size; i++)
		{
			temp = array[i];
			for (j = i; j >= increment; j -= increment)
			{
				if (temp < array[j - increment])
				{
					array[j] = array[j - increment];
				}
				else
				{
					break;
				}
			}
			array[j] = temp;
		}
	}
}

/*
Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, calls 
\itself for the two halves and then merges the two sorted halves.he merge() function is used 
for merging two halves. The merge(arr, l, m, r) is key process that assumes that arr[l..m]
and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.
*/
void merge(int array[], int left, int middle, int right){
	int leftArrayLength = middle - left + 1;
	int rightArrayLength = right - middle;

	/* c r e a t e  &  f i l l  temp arrays */
	int* leftArray = new int[leftArrayLength];
	int* rightArray = new int[rightArrayLength];
	for (int i = 0; i < leftArrayLength; i++) { leftArray[i] = array[left + i]; }
	for (int i = 0; i < rightArrayLength; i++) { rightArray[i] = array[middle + 1 + i]; }

	/* s o r t  a r r a y */
	int leftIndex = 0;
	int rightIndex = 0;
	int fullIndex = left;
	while (leftIndex < leftArrayLength && rightIndex < rightArrayLength){
		if (leftArray[leftIndex] <= rightArray[rightIndex]){
			array[fullIndex] = leftArray[leftIndex];
			leftIndex++;
		}
		else{
			array[fullIndex] = rightArray[rightIndex];
			rightIndex++;
		}
		fullIndex++;
	}
	
	/*F i l l  a n y  r e m a i n d e r s*/
	//left array
	while (leftIndex < leftArrayLength){
		array[fullIndex] = leftArray[leftIndex];
		leftIndex++;
		fullIndex++;
	}
	//right array
	while (rightIndex < rightArrayLength){
		array[fullIndex] = rightArray[rightIndex];
		rightIndex++;
		fullIndex++;
	}
	delete leftArray; delete rightArray;
}
void mergeSort(int array[], int left, int right){
	if (left < right){
		int middle = left + (right - left) / 2;
		mergeSort(array, left, middle);
		mergeSort(array, middle + 1, right);
		merge(array, left, middle, right);
	}
}

/*
Quicksort is a comparison sort, meaning that it can sort items of any type for which a "less-than" 
relation (formally, a total order) is defined. In efficient implementations it is not a stable sort,
meaning that the relative order of equal sort items is not preserved. Quicksort can operate in-place 
on an array, requiring small additional amounts of memory to perform the sorting.
*/
void QuickSort(int *array, int beg, int end, int size){
	if (beg < end){
		int pivot = Partition(array, beg, end);
		QuickSort(array, beg, pivot - 1, size);
		QuickSort(array, pivot + 1, end, size);
	}
}

int Partition(int *array, int beg, int end){
	int p = beg, pivot = array[beg], location;
	for (location = beg + 1; location <= end; location++)
	{
		if (pivot>array[location])
		{
			array[p] = array[location];
			array[location] = array[p + 1];
			array[p + 1] = pivot;

			p++;
		}
	}
	return p;
}

