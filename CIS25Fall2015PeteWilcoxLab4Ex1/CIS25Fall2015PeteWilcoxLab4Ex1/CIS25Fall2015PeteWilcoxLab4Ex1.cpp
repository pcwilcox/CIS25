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
int arrangeMultipleArrayPeteWilcox(int**, int);
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
	int numSwaps;
	int i, j;

	cout << "\nSetting up data before calling ArrangeMultipleArrayPeteWilcox() --";
	cout << "\n\nHow many arrays of int (treating these as arrays of int?";
	cin >> userArraySize;

	userArray = new int*[userArraySize];

	for (i = 0; i < userArraySize; i++) {
		cout << "\nCreating array index # " << i;
		*(userArray + i) = createArray();

		cout << "\nFor array index #" << i;
		for (j = 0; j < (*(*(userArray + i)) + 1); j++) {
			cout << "\n  Element index #" << j << " : " << *(*(userArray + i) + j);
		}
	}


	cout << "\nConfirming before working through with swapping --";
	cout << "\n\nThere is/are " << userArraySize << " array(s).";

	for (i = 0; i < userArraySize; i++) {
		cout << "\n\nThe current array #" << (i + 1) << " has " << *(*(userArray + i)) << " element(s).\n..";

		for (j = 0; j < *(*(userArray + i)); j++) {
			cout << "Element index #" << j << " : " << *(*(userArray + i) + j) << "\n  ";
		}

	}

	cout << "\nCalling arrangeMultipleArrayPeteWilcox() --";
	numSwaps = arrangeMultipleArrayPeteWilcox(userArray, userArraySize);

	cout << "\nDisplaying outside of arrangeMultipleArrayYourName() -\n";

	for (i = 0; i < userArraySize; i++) {
		cout << "\nThe updated array #" << i << " has " << *(*(userArray + i)) << " element(s).";

		for (j = 0; j <= *(*(userArray + i)); j++) {
			cout << "\n  Element index #" << i << " : " << *(*(userArray + i) + j);
		}
	}

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
	newArray = new int[++newArraySize];
	*(newArray) = (newArraySize - 1);

	for (i = 1; i < newArraySize; i++) {
		cout << "\n    Enter the value for element at index " << i << " : ";
		cin >> *(newArray + i);
	}

	return newArray;
}


int arrangeMultipleArrayPeteWilcox(int** userArray, int userArraySize) {
	// Arrange arrays
	
	int* swapValueLeft; 
	int* swapValueRight;
	int maxSwaps = 0;
	int swapFromPointer = 1;
	int swapToPointer = 1;
	int swapFromArrayPointer = 0;
	int swapToArrayPointer = 0;
	int numSwaps = 0;
	int swapNum;
	int i;

	for (i = 0; i < userArraySize; i++) {
		maxSwaps += *(*(userArray + i));
	}

	maxSwaps *= 3;

	swapValueLeft = new int[maxSwaps];
	swapValueRight = new int[maxSwaps];

	cout << "\n  Displaying inside arrangeMultipleArrayPeteWilcox()-";

	while (swapFromArrayPointer < userArraySize) {
		// For each user array
		swapFromPointer = 1;
		while (swapFromPointer <= *(*(userArray + swapFromArrayPointer))) {
			// For each element in the array (not including index 0)
			if (*(*(userArray + swapFromArrayPointer) + swapFromPointer) % 2 == 0) {
				// If it's even, look for a value to swap with
				swapToArrayPointer = swapFromArrayPointer + 1;
				while (swapToArrayPointer < userArraySize) {
					// For each remaining array
					swapToPointer = 1;
					while (swapToPointer <= *(*(userArray + swapToArrayPointer))) {
						//For each element in that array (not including index 0)
						if (*(*(userArray + swapToArrayPointer) + swapToPointer) % 2 != 0) {
							// If it's odd

							*(swapValueLeft + numSwaps) = swapFromArrayPointer;
							*(swapValueLeft + numSwaps + 1) = swapFromPointer;
							*(swapValueLeft + numSwaps + 2) = *(*(userArray + swapFromArrayPointer) + swapFromPointer);

							*(swapValueRight + numSwaps) = swapToArrayPointer;
							*(swapValueRight + numSwaps + 1) = swapToPointer;
							*(swapValueRight + numSwaps + 2) = *(*(userArray + swapToArrayPointer) + swapToPointer);

							numSwaps += 3;

							swapNum = *(*(userArray + swapFromArrayPointer) + swapFromPointer);
							*(*(userArray + swapFromArrayPointer) + swapFromPointer) = *(*(userArray + swapToArrayPointer) + swapToPointer);
							*(*(userArray + swapToArrayPointer) + swapToPointer) = swapNum;

							swapToArrayPointer = userArraySize;
							swapToPointer = (*(*(userArray + swapToArrayPointer))) + 1;
						}
						swapToPointer++;
					}
					swapToArrayPointer++;
				}
			}
			swapFromPointer++;
		}
		swapFromArrayPointer++;
	}

	cout << "\n\n  Displaying inside arrangeMultipleArrayPeteWilcox()-";
	for (i = 0; i < numSwaps; i += 3) {
		cout << "\n  Array #" << *(swapValueLeft + i) << " value " << *(swapValueLeft + i + 2) << " is swapped with Array #" << *(swapValueRight + i) << " value " << *(swapValueRight + i + 2);
	}

	delete swapValueLeft;
	delete swapValueRight;
	return (numSwaps / 3);
}


/* PROGRAM OUTPUT:

*/

/* COMMENTS:

*/