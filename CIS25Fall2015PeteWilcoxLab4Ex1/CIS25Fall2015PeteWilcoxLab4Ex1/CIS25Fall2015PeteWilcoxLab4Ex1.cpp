/**
* Program Name: cis25Fall2015PeteWilcoxLab4Ex1.cpp
* Discussion:   Lab #4 Exercise #1
* Written by:   Pete Wilcox
* Date:         2015/10/08
*/

#include <iostream>

using namespace std;

void header(void);
void menu(void);
void arrangeMultipleArrayPeteWilcox(int**, int);
void start(void);
int* createArray(void);


int main() {

	header(); 
	menu();   

	return 0;
}

void header() {
	cout << "\nClass Information --";
	cout << "\n  CIS 25 - C++ Programming";
	cout << "\n  Laney College";
	cout << "\n";
	cout << "\nAssignment Information -- ";
	cout << "\n  Assignment Number:  Lab 04 - Exercise #1";
	cout << "\n  Written by:         Pete Wilcox";
	cout << "\n  Submitted Date:     2015/10/08";
	cout << "\n";
	return;
}

void menu() {
	int menuChoice = 0;

	do {
		cout << "\n";
		cout << "\n*************************************************";
		cout << "\n*                MENU 04 -- Arrays              *";
		cout << "\n*  (1) Calling arrangeMultipleArrayPeteWilcox() *";
		cout << "\n*  (2) Quit                                     *";
		cout << "\n*************************************************";
		cout << "\nSelect an option (1 or 2): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			start();
			break;
		case 2:
			cout << "\nHaving fun..." << endl;
			break;
		default:
			cout << "\nWRONG OPTION!\n";
		}
	} while (menuChoice != 2);

	return;
}

void start() {
	int** userArray;
	int userArraySize;
	int i, j;

	cout << "\nSetting up data before calling ArrangeMultipleArrayPeteWilcox() --";
	cout << "\n\nHow many arrays of int (treating these as arrays of int?";
	cin >> userArraySize;

	int** userArray = new int*[userArraySize];

	for (i = 0; i < userArraySize; i++) {
		cout << "\nCreating array index # " << i;
		*(userArray + i) = createArray();

		cout << "\nFor array index #" << i;
		for (j = 0; j < *(*(userArray + i)); j++) {
			cout << "\n  Element index #" << j << " : " << *(*(userArray + i) + j);
		}
	}


//	arrangeMultipleArrayPeteWilcox(userArray, userArraySize);


	for (i = 0; i < userArraySize; i++) {
		delete *(userArray + i);
	}

	delete userArray;
	return;
}

int* createArray() {
	int* newArray;
	int newArraySize;
	int i;

	cout << "\n  How many value(s)?";
	cin >> newArraySize;
	newArray = new int[newArraySize + 1];
	*(newArray) = newArraySize;

	for (i = 1; i < newArraySize; i++) {
		cout << "\n    Enter the value for element at index " << i;
		cin >> *(newArray + i);
	}

	return newArray;
}

/*
void createArrays() {
	// Create arrays and pass their information to arrangeArray()
	int* firstArray = nullptr;
	int* secondArray = nullptr;
	int firstArraySize;
	int secondArraySize;
	int i;

	// Get user data and assign to arrays
	cout << "\nCreating the first array -";
	cout << "\nEnter the array size: ";
	cin >> firstArraySize;

	firstArray = new int[firstArraySize];

	cout << "\nEnter value for";
	for (i = 0; i < firstArraySize; i++) {
		cout << "  Index " << i << " : ";
		cin >> *(firstArray + i);
	}

	cout << "\nCreating the second array -";
	cout << "\nEnter the array size: ";
	cin >> secondArraySize;

	secondArray = new int[secondArraySize];

	cout << "\nEnter value for";
	for (i = 0; i < secondArraySize; i++) {
		cout << "  Index " << i << " : ";
		cin >> *(secondArray + i);
	}

	// Call arrangeArray() with user data
	cout << "\nCalling arrangeArraysPeteWilcox() --";
	arrangeArrayPeteWilcox(firstArray, firstArraySize, secondArray, secondArraySize);

	// Cleanup
	delete firstArray;
	delete secondArray;
	return;
}

*/

/*
void arrangeArrayPeteWilcox(int* firstArray, int firstArraySize,
	int* secondArray, int secondArraySize) {
	// Arrange arrays

	int* swapFromFirst = new int[firstArraySize];
	int* swapFromSecond = new int[secondArraySize];
	int numSwaps = 0;
	int i, j, temp;
	bool swapped;

	// Display original arrays
	cout << "\n\n  Original Arrays";
	cout << "\n    Array #1:";

	for (i = 0; i < firstArraySize; i++) {
		cout << "  " << *(firstArray + i);
	}

	cout << "\n    Array #2:";

	for (i = 0; i < secondArraySize; i++) {
		cout << "  " << *(secondArray + i);
	}


	// Iterate through array #1
	for (i = 0; i < firstArraySize; i++) {
		swapped = false;

		// If value is even
		if (*(firstArray + i) % 2 == 0) {
			j = 0;
			do {

				// Iterate through array #2
				if (*(secondArray + j) % 2 != 0) {

					// Track which values were swapped
					*(swapFromFirst + numSwaps) = *(firstArray + i);
					*(swapFromSecond + numSwaps) = *(secondArray + j);
					numSwaps++;

					// Swap values
					temp = *(firstArray + i);
					*(firstArray + i) = *(secondArray + j);
					*(secondArray + j) = temp;

					// Move to next element of array #1
					swapped = true;
				}
				j++;
			} while ((swapped == false) && (j < secondArraySize));
		}
	}

	// Display updated arrays
	cout << "\n\n  Updated Arrays";
	cout << "\n    Array #1:";

	for (i = 0; i < firstArraySize; i++) {
		cout << "  " << *(firstArray + i);
	}

	cout << "\n    Array #2:";

	for (i = 0; i < secondArraySize; i++) {
		cout << "  " << *(secondArray + i);
	}

	// Display swap info
	if (numSwaps > 0) {
		cout << "\n\n  Swapping info -";
		for (i = 0; i < numSwaps; i++) {
			cout << "\n    Array #1 value " << *(swapFromFirst + i)
				<< " swapped with Array #2 value " << *(swapFromSecond + i);
		}
	}

	cout << "\n\nThere is/are " << numSwaps << " swap(s)." << endl;

	// Cleanup
	delete swapFromFirst;
	delete swapFromSecond;

	return;
}

*/

/* PROGRAM OUTPUT:

*/

/* COMMENTS:

*/