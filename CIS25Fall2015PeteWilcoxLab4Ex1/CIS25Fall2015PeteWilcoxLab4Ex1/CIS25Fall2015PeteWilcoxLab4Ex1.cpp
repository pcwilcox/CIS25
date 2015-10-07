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
		cout << "\n"
			"\n*************************************************"
			"\n*                MENU 04 -- Arrays              *"
			"\n*  (1) Calling arrangeMultipleArrayPeteWilcox() *"
			"\n*  (2) Quit                                     *"
			"\n*************************************************"
			"\nSelect an option (1 or 2): ";
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

	cout << "\nSetting up data before calling"
		" ArrangeMultipleArrayPeteWilcox() --";
	cout << "\n\nHow many arrays of int (treating these as "
		"arrays of int? ";
	cin >> userArraySize;

	userArray = new int*[userArraySize];

	for (i = 0; i < userArraySize; i++) {
		cout << "\nCreating array index # " << i;
		*(userArray + i) = createArray();

		cout << "\nFor array index #" << i << endl;;
		for (j = 0; j < (*(*(userArray + i)) + 1); j++) {
			cout << "  Element index #" << j << " : " <<
				*(*(userArray + i) + j) << endl;
		}
	}


	cout << "\nConfirming before working through with swapping --";
	cout << "\n\nThere is/are " << userArraySize << " array(s).";

	for (i = 0; i < userArraySize; i++) {
		cout << "\n\nThe current array #" << (i + 1) << " has " 
			<< ((*(*(userArray + i))) + 1) << " element(s).\n..";

		for (j = 0; j < ((*(*(userArray + i))) + 1); j++) {
			cout << "Element index #" << j << " : " << 
				*(*(userArray + i) + j) << "\n  ";
		}

	}

	cout << "\nCalling arrangeMultipleArrayPeteWilcox() --\n";
	numSwaps = 
		arrangeMultipleArrayPeteWilcox(userArray, userArraySize);

	cout << "\n\nDisplaying outside of "
		"arrangeMultipleArrayYourName() -\n";

	for (i = 0; i < userArraySize; i++) {
		cout << "\n\nThe updated array #" << (i + 1) << " has " << 
			*(*(userArray + i)) << " element(s).";

		for (j = 0; j <= *(*(userArray + i)); j++) {
			cout << "\n  Element index #" << j << " : " << 
				*(*(userArray + i) + j);
		}
	}

	for (i = 0; i < userArraySize; i++) {
		delete *(userArray + i);
	}

	return;
}

int* createArray() {
	int* newArray;
	int newArraySize;
	int i;

	cout << "\n\n  How many value(s)? ";
	cin >> newArraySize;
	newArray = new int[++newArraySize];
	*(newArray) = (newArraySize - 1);

	for (i = 1; i < newArraySize; i++) {
		cout << "\n    Enter the value for element at index " 
			<< i << " : ";
		cin >> *(newArray + i);
	}

	return newArray;
}


int arrangeMultipleArrayPeteWilcox(int** userArray, 
	int userArraySize) {
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
	bool swapped = false;
	int i;

	for (i = 0; i < userArraySize; i++) {
		maxSwaps += *(*(userArray + i));
	}

	maxSwaps *= 3;

	swapValueLeft = new int[maxSwaps];
	swapValueRight = new int[maxSwaps];

	cout << "\n  Displaying inside "
		"arrangeMultipleArrayPeteWilcox()-";

	swapFromPointer = 1;
	while (swapFromPointer <= *(*(userArray 
			+ swapFromArrayPointer))) {
		// For each element in the array
		swapped = false;

		if (*(*(userArray + swapFromArrayPointer) 
				+ swapFromPointer) % 2 == 0) {
			// If it's even, look for a value to swap with
			swapToArrayPointer = swapFromArrayPointer + 1;
			
			while ((swapToArrayPointer < userArraySize) && 
					(swapped == false)) {
				// For each remaining array
				swapToPointer = 1;
				while ((swapToPointer <= *(*(userArray 
						+ swapToArrayPointer))) 
						&& (swapped == false)) {
					//For each element in that array
					if (*(*(userArray + swapToArrayPointer) 
							+ swapToPointer) % 2 != 0) {
						// If it's odd

						*(swapValueLeft + numSwaps) = 
							swapFromArrayPointer;
						*(swapValueLeft + numSwaps + 1) = 
							swapFromPointer;
						*(swapValueLeft + numSwaps + 2) = 
							*(*(userArray + swapFromArrayPointer) 
								+ swapFromPointer);

						*(swapValueRight + numSwaps) = 
							swapToArrayPointer;
						*(swapValueRight + numSwaps + 1) = 
							swapToPointer;
						*(swapValueRight + numSwaps + 2) = 
							*(*(userArray + swapToArrayPointer) 
								+ swapToPointer);

						numSwaps += 3;

						swapNum = *(*(userArray 
							+ swapFromArrayPointer) 
							+ swapFromPointer);
						*(*(userArray + swapFromArrayPointer) 
							+ swapFromPointer) = 
							*(*(userArray + swapToArrayPointer) 
								+ swapToPointer);
						*(*(userArray + swapToArrayPointer) 
							+ swapToPointer) = swapNum;

						swapped = true;
					}
					swapToPointer++;
				}
				swapToArrayPointer++;
			}
		}
		swapFromPointer++;
	}
	

	cout << "\n\n  Displaying inside "
		"arrangeMultipleArrayPeteWilcox()-";
	for (i = 0; i < numSwaps; i += 3) {
		cout << "\n    Array #" << ((*(swapValueLeft + i)) + 1) << 
			" value " << *(swapValueLeft + i + 2) << " is "
			"swapped with Array #" << (*(swapValueRight + i) + 1) << 
			" value " << *(swapValueRight + i + 2);
	}

	delete swapValueLeft;
	delete swapValueRight;
	return (numSwaps / 3);
}


/* PROGRAM OUTPUT:

*****************************************UPDATE THIS***************************************


Class Information --
  CIS 25 - C++ Programming
  Laney College

Assignment Information --
  Assignment Number:  Lab 04 - Exercise #1
  Written by:         Pete Wilcox
  Submitted Date:     2015/10/08


*************************************************
*                MENU 04 -- Arrays              *
*  (1) Calling arrangeMultipleArrayPeteWilcox() *
*  (2) Quit                                     *
*************************************************
Select an option (1 or 2): 4

WRONG OPTION!


*************************************************
*                MENU 04 -- Arrays              *
*  (1) Calling arrangeMultipleArrayPeteWilcox() *
*  (2) Quit                                     *
*************************************************
Select an option (1 or 2): 1

Setting up data before calling ArrangeMultipleArrayPeteWilcox() --

How many arrays of int (treating these as arrays of int?3

Creating array index # 0
  How many value(s)?6

    Enter the value for element at index 1 : 1

    Enter the value for element at index 2 : -23

    Enter the value for element at index 3 : 18

    Enter the value for element at index 4 : 27

    Enter the value for element at index 5 : -36

    Enter the value for element at index 6 : 45

For array index #0
  Element index #0 : 6
  Element index #1 : 1
  Element index #2 : -23
  Element index #3 : 18
  Element index #4 : 27
  Element index #5 : -36
  Element index #6 : 45
Creating array index # 1
  How many value(s)?3

    Enter the value for element at index 1 : 4

    Enter the value for element at index 2 : -17

    Enter the value for element at index 3 : 8

For array index #1
  Element index #0 : 3
  Element index #1 : 4
  Element index #2 : -17
  Element index #3 : 8
Creating array index # 2
  How many value(s)?2

    Enter the value for element at index 1 : -1

    Enter the value for element at index 2 : -3

For array index #2
  Element index #0 : 2
  Element index #1 : -1
  Element index #2 : -3
Confirming before working through with swapping --

There is/are 3 array(s).

The current array #1 has 7 element(s).
..Element index #0 : 6
  Element index #1 : 1
  Element index #2 : -23
  Element index #3 : 18
  Element index #4 : 27
  Element index #5 : -36
  Element index #6 : 45


The current array #2 has 4 element(s).
..Element index #0 : 3
  Element index #1 : 4
  Element index #2 : -17
  Element index #3 : 8


The current array #3 has 3 element(s).
..Element index #0 : 2
  Element index #1 : -1
  Element index #2 : -3

Calling arrangeMultipleArrayPeteWilcox() --
  Displaying inside arrangeMultipleArrayPeteWilcox()-

  Displaying inside arrangeMultipleArrayPeteWilcox()-
  Array #0 value 18 is swapped with Array #1 value -17
  Array #0 value -36 is swapped with Array #2 value -1
Displaying outside of arrangeMultipleArrayYourName() -

The updated array #0 has 6 element(s).
  Element index #0 : 6
  Element index #0 : 1
  Element index #0 : -23
  Element index #0 : -17
  Element index #0 : 27
  Element index #0 : -1
  Element index #0 : 45
The updated array #1 has 3 element(s).
  Element index #1 : 3
  Element index #1 : 4
  Element index #1 : 18
  Element index #1 : 8
The updated array #2 has 2 element(s).
  Element index #2 : 2
  Element index #2 : -36
  Element index #2 : -3

*************************************************
*                MENU 04 -- Arrays              *
*  (1) Calling arrangeMultipleArrayPeteWilcox() *
*  (2) Quit                                     *
*************************************************
Select an option (1 or 2): 2

Having fun...



*/

/* COMMENTS:

*/