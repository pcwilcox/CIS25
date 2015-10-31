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

void createArray(FractionPeteW**);

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

				createArray((fractionArray + i));
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

int arrangeMultiArraysPeteWilcox(FractionPeteW** fracArray, int size) {
	int numSwaps = 0;
	int maxSwaps = 0;
	FractionPeteW temp;
	bool swapped = false;
	int i, k, j = 1;

	// Count the number of swaps to be made
	for (i = 1; i <= (*(fracArray) + i)->getNum(); i++) {
		if ((*(fracArray)+i)->getNum() % 2 == 0) {
			maxSwaps++;
		}
	}

	if (maxSwaps > 0) {
		cout << "\n  Displaying inside arrangeMultiArraysPeteWilcox()-";

		for (i = 1; i <= (*fracArray)->getNum(); i++) {
			// For each value in array #1
			if (((*fracArray) + i)->getNum() % 2 == 0) {
				// If it's even

				while ((j < size) && (!swapped)) {
					// Iterate through each other array

					k = 1;
					while ((k <= ((*fracArray + j))->getNum()) && (!swapped)) {

						if (((*fracArray + j) + k)->getNum() % 2 != 0) {
							// When an odd value is found

							cout << "\n    Array #1 value " << ((*fracArray) + i) << "is swapped with Array #" << (j + 1) << " value " << (*(*(fracArray + j) + k));

							// Swap it
							temp = *(*(fracArray + j) + k);
							*(*(fracArray + j) + k) = *(*(fracArray + i));
							*(*(fracArray + i)) = temp;

							numSwaps++;
							swapped = true;
						}
						k++;
					}
					// If we've looked through every value
					if (k > ((*fracArray) + j)->getNum()) {
						// Move to the next array
						j++;
					}
				}
			}
		}
	}

	return numSwaps;
}
