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
	cout << "\nClass Information --"
		"\n  CIS 25 - C++ Programming"
		"\n  Laney College"
		"\n"
		"\nAssignment Information -- "
		"\n  Assignment Number:  Lab 04 - Exercise #1"
		"\n  Written by:         Pete Wilcox"
		"\n  Submitted Date:     2015/10/08"
		"\n";
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


	cout << "\nConfirming before working through with "
		"swapping --";
	cout << "\n\nThere is/are " << userArraySize <<
		" array(s).";

	for (i = 0; i < userArraySize; i++) {
		cout << "\n\nThe current array #" << (i + 1) << " has "
			<< ((*(*(userArray + i))) + 1) <<
			" element(s).\n..";

		for (j = 0; j < ((*(*(userArray + i))) + 1); j++) {
			cout << "Element index #" << j << " : " <<
				*(*(userArray + i) + j) << "\n  ";
		}

	}

	cout << "\nCalling arrangeMultipleArrayPeteWilcox() --\n";
	numSwaps =
		arrangeMultipleArrayPeteWilcox(userArray,
			userArraySize);

	cout << "\n\nDisplaying outside of "
		"arrangeMultipleArrayYourName() -\n";

	for (i = 0; i < userArraySize; i++) {
		cout << "\n\nThe updated array #" << (i + 1) << " has "
			<< *(*(userArray + i)) << " element(s).";

		for (j = 0; j <= *(*(userArray + i)); j++) {
			cout << "\n  Element index #" << j << " : " <<
				*(*(userArray + i) + j);
		}
	}

	if (numSwaps > 0) {
		cout << "\n\nThere is/are " << numSwaps << " swap(s).";
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

	int numSwaps = 0;
	int swapNum;
	bool swapped = false;
	int swapFromPointer;
	int swapToArrayPointer = 1;
	int swapToPointer = 1;
	int i;

	for (i = 1; i <= **userArray; i++) {
		if (*(*userArray + i) % 2 == 0) {
			numSwaps++;
		}
	}

	if (numSwaps > 0) {
		cout << "\n  Displaying inside "
			"arrangeMultipleArrayPeteWilcox()-";


		for (swapFromPointer = 1; swapFromPointer <= **userArray; swapFromPointer++) {
			swapped = false;

			if (*(*(userArray + swapFromPointer)) % 2 == 0) {
				while ((swapToArrayPointer < userArraySize) && (swapped == false)) {
					while ((swapToPointer <= (*(*userArray) + swapToArrayPointer)) && (swapped == false)) {

						if (*(*(userArray + swapToPointer) + swapToArrayPointer) % 2 != 0) {
							cout << "\n    Array #1 value " << *(*(userArray + swapFromPointer)) << " is swapped with Array #" << (swapToArrayPointer + 1) << " value " << 
								*(*(userArray + swapToPointer) + swapToArrayPointer);

							swapNum = *(*(userArray + swapFromPointer));
							*(*(userArray + swapFromPointer)) = *(*(userArray + swapToPointer) + swapToArrayPointer);
							*(*(userArray + swapToPointer) + swapToArrayPointer) = swapNum;

							swapped = true;
						}
						swapToPointer++;
					}
					swapToPointer = 1;
					swapToArrayPointer++;
				}

			}


		}
	}
	return numSwaps;
}


/* PROGRAM OUTPUT:



*/

/* COMMENTS:
2015/10/08:
The scope seems limited - why not move all the odd values to
one side with all the even values moved to the other side?
*/