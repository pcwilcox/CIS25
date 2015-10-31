/**
  * Program Name: CIS25Fall2015PeteWilcoxLab5Ex1.cpp
  * Discussion:   Lab #5 Exercise #2
  * Written by:   Pete Wilcox
  * Date:         2015/11/06
  */

#include <iostream>
#include "fractionPeteW.h"

using namespace std;

void displayHeader(void);
void displayMenu(void);

void createArrays(FractionPeteW**);

int arrangeMultiArraysPeteWilcox(FractionPeteW**, int);

int main() {
	int menuChoice;
	int numArrays = 0;
	int numSwaps;
	int i, j;

	FractionPeteW** fractionArray = nullptr;

	displayHeader();

	do {
		displayMenu();

		cin >> menuChoice;

		switch (menuChoice) {
		case 1:

			cout << "\nSetting up data before calling ArrangeMultiArraysPeteWilcox() --\n\nHow many arrays of fractions? ";
			cin >> numArrays;

			fractionArray = new FractionPeteW*[numArrays];

			for (i = 0; i < numArrays; i++) {
				cout << "\nCreating array # " << (i + 1);

				createArrays((fractionArray + i));
			}

			cout << "\nConfirming before working through with swapping --\n\nThere is/are " << numArrays << " array(s).";

			for (i = 0; i < numArrays; i++) {
				cout << "\n\nThe current array #" << (i + 1) << " has "	<< ((*fractionArray) + i)->getNum() << " element(s).\n..";

				for (j = 0; j < ((*fractionArray) + i)->getNum(); j++) {
					cout << "Element index #" << j << " : " << *(*(fractionArray + i) + j) << "\n  ";
				}

			}

			cout << "\nCalling arrangeMultiArraysPeteWilcox() --\n";
			numSwaps =
				arrangeMultiArraysPeteWilcox(fractionArray, numArrays);

			cout << "\n\nDisplaying outside of arrangeMultiArraysPeteWilcox() -\n";

			for (i = 0; i < numArrays; i++) {
				cout << "\n\nThe updated array #" << (i + 1) << " has "	<< ((*fractionArray) + i)->getNum() << " element(s).";

				for (j = 0; j <= (*(fractionArray) + i)->getNum(); j++) {
					cout << "\n  Element index #" << j << " : " << *(*(fractionArray + i) + j);
				}
			}

			if (numSwaps > 0) {
				cout << "\n\nThere is/are " << numSwaps << " swap(s).";
			}

			for (i = 0; i < numArrays; i++) {
				delete[] * (fractionArray + i);
			}

			delete[] fractionArray;

			break;
		case 2:
			cout << "\nHaving fun..." << endl;
			break;
		default:
			cout << "\nWRONG OPTION!\n";
		}


	} while (menuChoice != 2);



	return 0;
}

void createArray(FractionPeteW** fracArray) {
	int num;
	int denom;
	int newArraySize;
	int i;

	cout << "\n\n  How many value(s)? ";
	cin >> newArraySize;


	*fracArray = new FractionPeteW[++newArraySize];
	((*fracArray))->setBoth((newArraySize - 1), 1);

	for (i = 1; i < newArraySize; i++) {
		cout << "\n    Enter the numerator for element at index"
			" " << i << " : ";
		cin >> num;
		do {


			cout << "\n    Enter the denominator for element at"
				" index " << i << " : ";
			cin >> denom;
			if (denom == 0) {
				cout << "\nDenominator cannot be 0.";
			}
		} while (denom == 0);

		((*fracArray) + i)->setBoth(num, denom);
	}
}


void displayHeader() {
	cout << "CIS 25 - C++ Programming\nLaney College"
		"\nPete Wilcox \n\nAssignment Information --"
		"\n  Assignment Number: Lab 5,"
		"\n                     Exercise #2"
		"\n  Written by: Pete Wilcox"
		"\n  Due Date: 2015/11/06\n\n";
}

void displayMenu() {
	cout << "\n\n****************************************"
		"******"
		"\n*                Fraction Arrays             *"
		"\n* (1) Calling arrangeMultiArraysPeteWilcox() *"
		"\n* (2) Quit                                   *"
		"\n**********************************************"
		"\nSelect an option (1 or 2): ";
}


/* reusing as much of this as we can

void getInput() {



	int** userArray;
	int arraySize;
	int numSwaps;
	int i, j;

	cout << "\n\nHow many arrays of int (treating these as "
		"arrays of int? ";
	cin >> arraySize;

	userArray = new int*[arraySize];

	for (i = 0; i < arraySize; i++) {
		//*(userArray + i) = createArray();

		cout << "\nFor array index #" << i << endl;
		for (j = 0; j < (*(*(userArray + i)) + 1); j++) {
			cout << "  Element index #" << j << " : " <<
				*(*(userArray + i) + j) << endl;
		}
	}


	cout << "\nConfirming before working through with "
		"swapping --";
	cout << "\n\nThere is/are " << arraySize <<
		" array(s).";

	for (i = 0; i < arraySize; i++) {
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
		arrangeMultipleArrayPeteWilcox(userArray, arraySize);

	cout << "\n\nDisplaying outside of "
		"arrangeMultipleArrayYourName() -\n";

	for (i = 0; i < arraySize; i++) {
		cout << "\n\nThe updated array #" << (i + 1) << " has "
			<< (*(*(userArray + i)) + 1) << " element(s).";

		for (j = 0; j <= *(*(userArray + i)); j++) {
			cout << "\n  Element index #" << j << " : " <<
				*(*(userArray + i) + j);
		}
	}

	if (numSwaps > 0) {
		cout << "\n\nThere is/are " << numSwaps << " swap(s).";
	}

	for (i = 0; i < arraySize; i++) {
		delete[] * (userArray + i);
	}

	delete[] userArray;

	return;
}

*/

/* this is gonna need to be refactored

int arrangeMultipleArrayPeteWilcox(int** input, int size) {
	// Arrange arrays

	int maxSwaps = 0;
	int numSwaps = 0;
	int temp;
	bool swapped = false;
	int i, k;
	int j = 1;

	// Count the number of swaps to be made
	for (i = 1; i <= **input; i++) {
		if ((*(*input) + i) % 2 == 0) {
			maxSwaps++;
		}
	}

	if (maxSwaps > 0) {
		cout << "\n  Displaying inside "
			"arrangeMultipleArrayPeteWilcox()-";


		for (i = 1; i <= **input; i++) {
			swapped = false;
			// For each value in Array #1

			if (*((*input) + i) % 2 == 0) {
				// If it's even

				while ((j < size) && (!swapped)) {
					// Iterate through each other array
					k = 1;
					while ((k <= *(*(input + j))) &&
						(!swapped)) {

						if (*(*(input + j) + k) % 2 != 0) {
							// Until an odd value is found

							cout << "\n    Array #1 value " <<
								*((*input) + i) <<
								" is swapped with Array #"
								<< (j + 1) << " value " <<
								*(*(input + j) + k);

							// And swap it
							temp = *((*input) + i);
							*((*input) + i) =
								*(*(input + j) + k);
							*(*(input + j) + k) = temp;

							numSwaps++;
							swapped = true;
						}
						k++;
					}
					// If we've looked through every value
					if (k > *(*(input + j))) {
						// Move to the next array
						j++;
					}
				}

			}


		}
	}
	return numSwaps;
}
*/