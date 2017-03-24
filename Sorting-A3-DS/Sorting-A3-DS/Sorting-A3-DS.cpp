// Sorting-A3-DS.cpp : Defines the entry point for the console application.
//DevBen Sorting Files.
// basic file operations
#include <iostream>
//#include <ifstream>
#include <fstream>
#include <sstream>
#include <streambuf>
#include "stdafx.h"
#include <iostream>
#include <ctime>
#include "time.h"
#include <cstdlib>
#include <regex>
#include <iostream>
#include <fstream>
using namespace std;
//* A L L	A R E	A V E R A G E S		O F		F I V E		R U N S
//* SORT          | 1000  | 25,000 | 50,000 | 75,000 | 100,000 |
//* BUBBLESORT    | 0.002S| 1.491S | 6.250S | 14.164S| 25.419S |
//* SELECTIONSORT | 0.001S| 0.061S | 2.409S | 5.434S | 9.694S  |
//* INSERTIONSORT | 0.001S| 0.051S | 2.212S | 5.001S | 9.0197S |
//* SHELLSORT     | 0.001S| 0.005S | 0.01S  | 0.016S | 0.025S  |
//* MERGESORT     | 0.001S| 0.017S | 0.03S  | 0.06S  | 0.085S  |
//* QUICKSORT     | 0.001S| 0.005S | 0.01S  | 0.015S | 0.02S   |



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

//External Sort Prototype
void externMergeSort(string fullListFileName);
bool externMerge(fstream& input1, fstream& input2, fstream* output1, fstream* output2, int runsize);

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
	if (std::regex_match(regmatch, std::regex("(1000W)"))) {
		cout << "Write file" << endl;
		int size = 1000;
		cout << "Size of array: " << size << endl;
		int *array = new int[size]; // Create array
		// Insert random integers in new array random sized
		for (int i = 0; i < size; i++) {
			array[i] = rand() % 32768 + 1;
		}
		cout << "Using BubbleSort " << endl;
		bubbleSort(array, size);
		//Write to file
		std::fstream fs;
		fs.open("BubbleSort.csv", std::fstream::out | std::fstream::app);
		for (int i = 0; i <size;i++)
		{
			fs << array[i] << endl; //Outputs array to txtFile
		}
		fs.close();
		//Make New Array
		for (int i = 0; i < size; i++) {
			array[i] = rand() % 32768 + 1;
		}
		cout << "Using SelectionSort " << endl;
		selectionSort(array, size);
		//Write to file
		fs.open("SelectionSort.csv", std::fstream::out | std::fstream::app);
		for (int i = 0; i <size; i++)
		{
			fs << array[i] << endl; //Outputs array to txtFile
		}
		fs.close();
		//Make New Array
		for (int i = 0; i < size; i++) {
			array[i] = rand() % 32768 + 1;
		}
		cout << "Using InsertionSort " << endl;
		insertionSort(array, size);
		//Write to file
		fs.open("InsertionSort.csv", std::fstream::out | std::fstream::app);
		for (int i = 0; i <size; i++)
		{
			fs << array[i] << endl; //Outputs array to txtFile
		}
		fs.close();
		//Make New Array
		for (int i = 0; i < size; i++) {
			array[i] = rand() % 32768 + 1;
		}
		cout << "Using ShellSort " << endl;
		shellSort(array, size);
		//Write to file
		fs.open("ShellSort.csv", std::fstream::out | std::fstream::app);
		for (int i = 0; i <size; i++)
		{
			fs << array[i] << endl; //Outputs array to txtFile
		}
		fs.close();
		//Make New Array
		for (int i = 0; i < size; i++) {
			array[i] = rand() % 32768 + 1;
		}
		cout << "Using MergeSort " << endl;
		//Write to file
		fs.open("MergeSort.csv", std::fstream::out | std::fstream::app);
		for (int i = 0; i <size; i++)
		{
			fs << array[i] << endl; //Outputs array to txtFile
		}
		fs.close();
		mergeSort(array, 0, size - 1); 
		//Make New Array
		for (int i = 0; i < size; i++) {
			array[i] = rand() % 32768 + 1;
		}
		cout << "Using Quicksort " << endl;
		QuickSort(array, 0, size - 1, size);
		//Write to file
		fs.open("QuickSort.csv", std::fstream::out | std::fstream::app);
		for (int i = 0; i <size; i++)
		{
			fs << array[i] << endl; //Outputs array to txtFile
		}
		fs.close();
		cout << "All Files written, press any key to run another sort" << endl;
		cin.get();//To stop the program from closing right after ending
		return main();
	}
	
	if (std::regex_match(regmatch, std::regex("(20000X)"))) {
		size = 20000;
		const string originalFileLocation = "originalArray.txt";
		fstream originalFile = fstream(originalFileLocation, ios::out);
		for (int i = 0; i < size; i++) {
			originalFile << rand() % 32768 + 1 << '\n';
		}
		externMergeSort(originalFileLocation);
		cout << "external merge completed, press any key to run another sort" << endl;
		cin.get();//To stop the program from closing right after ending
		return main();
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	cout << "Size of array: " << size << endl;
	int *array = new int[size]; // Create array
								// Insert random integers in new array random sized
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 32768 + 1;
	}

	//	BUBBLE SORT
	cout << "Starting Sort..." << endl << "Using BubbleSort " << endl;
	clock_t starttime = clock(); // Timer start
	bubbleSort(array, size);
	clock_t endtime = clock(); // Timer end
	double time = (endtime - starttime);
	//time /= CLOCKS_PER_SEC;
	cout << "it took " << time << " seconds to sort an array that was " << size << " long" << endl;
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 32768 + 1;
	}

	//SELECTION SORT
	cout << "Starting Sort..." << endl << "Using SelectionSort ";;
	starttime = clock(); // Timer start
	selectionSort(array, size);
	endtime = clock(); // Timer end
	time = (endtime - starttime);
	//time /= CLOCKS_PER_SEC;
	cout << "it took " << time << " seconds to sort an array that was " << size << " long" << endl;
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 32768 + 1;
	}

	//INSERTION SORT
	cout << "Starting Sort..." << endl << "Using InsertionSort ";;
	starttime = clock(); // Timer start
	insertionSort(array, size);
	endtime = clock(); // Timer end
	time = (endtime - starttime);
	//time /= CLOCKS_PER_SEC;
	cout << "it took " << time << " seconds to sort an array that was " << size << " long" << endl;
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 32768 + 1;
	}

	//SHELLSORT
	cout << "Starting Sort..." << endl << "Using Shellsort ";;
	starttime = clock(); // Timer start
	shellSort(array, size);
	endtime = clock(); // Timer end
	time = (endtime - starttime);
	//time /= CLOCKS_PER_SEC;
	cout << "it took " << time << " seconds to sort an array that was " << size << " long" << endl;
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 32768 + 1;
	}

	//MERGESORT
	cout << "Starting Sort..." << endl << "Using MergeSort ";;
	starttime = clock(); // Timer start
	mergeSort(array, 0, size - 1);
	endtime = clock(); // Timer end
	time = (endtime - starttime);
	//time /= CLOCKS_PER_SEC;
	cout << "it took " << time << " seconds to sort an array that was " << size << " long" << endl;
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 32768 + 1;
	}


	//QUICKSORT
	cout << "Starting Sort..." << endl << "Using Quicksort ";
	starttime = clock(); // Timer start
	QuickSort(array, 0, size - 1, size);
	endtime = clock(); // Timer end
	time = (endtime - starttime);
	//time /= CLOCKS_PER_SEC;
	cout << "it took " << time << " seconds to sort an array that was " << size << " long" << endl;
	delete[] array; // Garbage 
	
	cout << "Sort another size? (y/n)" << endl;

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

bool externMerge(fstream& inFile1, fstream& inFile2, fstream* outFile1, fstream* outFile2, int runsize) {
	int leftCounter = 0, currentLeftInt = 0, rightCounter = 0, currentRightInt = 0;

	fstream* currentOutput = outFile1;
	fstream* otherOutput = outFile2;

	int mergesPerformed = 0;

	//B E G I N loop of all runs this merge
	while (true){
		//if the file ran out of ints, break.
		if (!(inFile1 >> currentLeftInt)) { break; }
		else if (!(inFile2 >> currentRightInt)){//if file 2 ran out of ints, break and dump into its file
			*currentOutput << currentLeftInt << '\n';
			break;
		}

		//reset counters
		leftCounter = 1; rightCounter = 1;
		// B E G I N  run loop
		while (true){
			if (currentLeftInt < currentRightInt){
				*currentOutput << currentLeftInt << '\n';
				leftCounter++;
				if (leftCounter > runsize || !(inFile1 >> currentLeftInt)){
					*currentOutput << currentRightInt << '\n';
					rightCounter++;
					break;
				}
			}
			else {
				*currentOutput << currentRightInt << '\n';
				rightCounter++;
				if (rightCounter > runsize || !(inFile2 >> currentRightInt)) {
					*currentOutput << currentLeftInt << '\n';
					leftCounter++;
					break;
				}
			}
		}//E N D  per run loop

		//D U M P leftovers
		while (leftCounter < runsize && inFile1 >> currentLeftInt){
			*currentOutput << currentLeftInt << '\n';
			leftCounter++;
		}
		while (rightCounter < runsize && inFile2 >> currentRightInt){
			*currentOutput << currentRightInt << '\n';
			rightCounter++;
		}
		swap(currentOutput, otherOutput);
		mergesPerformed++;
	}
	//D U M P any remainders
	while (inFile1 >> currentLeftInt) { *currentOutput << currentLeftInt << '\n'; }
	while (inFile2 >> currentRightInt) { *currentOutput << currentRightInt << '\n'; }
	return (mergesPerformed != 0);
}

void externMergeSort(string fullListFileName) {
	fstream originalFile, File1, File2, File3, File4;
	int currentInt1, currentInt2, runsize = 2;
	string sublist1 = "externSublist1.txt",	sublist2 = "externSublist2.txt", increment1 = "externIncrement1.txt", increment2 = "externIncrement2.txt";

	originalFile = fstream(fullListFileName, ios::in);
	File1 = fstream(sublist1, ios::out);
	File2 = fstream(sublist2, ios::out);
	
	//D I V I D E file into runs
	int i = 0;
	while (originalFile >> currentInt1){
		if (originalFile >> currentInt2){
			//swap current ints if out of order
			if (currentInt1 > currentInt2) { swap(currentInt1, currentInt2); }
			//place into alternating files
			if (i % 2 == 0) { File1 << currentInt1 << '\n' << currentInt2 << '\n'; }
			else { File2 << currentInt1 << '\n' << currentInt2 << '\n'; }
		}
		else {
			if (i % 2 == 0) { File1 << currentInt1 << '\n'; }
			else { File2 << currentInt1 << '\n'; }
		}
		i++;
	}
	File1 = fstream(sublist1, ios::in);
	File2 = fstream(sublist2, ios::in);
	File3 = fstream(increment1, ios::out);
	File4 = fstream(increment2, ios::out);

	//M E R G E the files until the sort is complete
	while (externMerge(File1, File2, &File3, &File4, runsize)){
		swap(sublist1, increment1);
		swap(sublist2, increment2);
		//reset files
		File1 = fstream(sublist1, ios::in);	File2 = fstream(sublist2, ios::in);	File3 = fstream(increment1, ios::out);	File4 = fstream(increment2, ios::out);
		runsize *= 2;
	}
	//close all files
	File1.close(); File2.close(); File3.close();	File4.close();
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

