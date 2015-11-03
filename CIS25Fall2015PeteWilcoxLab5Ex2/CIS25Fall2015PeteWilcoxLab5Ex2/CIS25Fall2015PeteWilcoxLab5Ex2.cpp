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

int arrangeMultiArraysPeteWilcox(FractionPeteW**, int);

int main() {
	int menuChoice;
	int numArrays = 0;
	int numSwaps;
	int num;
	int denom;
	int newArraySize;
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
				cout << "\nCreating array index # " << i;

				cout << "\n\n  How many value(s)? ";
				cin >> newArraySize;

				*(fractionArray + i) = new FractionPeteW[++newArraySize];
				(*(fractionArray + i))->setNum(newArraySize);

//				cout << "\n\n  array index 0: " << *(*(fractionArray + i));

				for (j = 1; j < newArraySize; j++) {
					cout << "\n\n    Enter the numerator for element at index " << j << " : ";
					cin >> num;
//					do {
//						cout << "\n    Enter the denominator for element at index " << j << " : ";
//						cin >> denom;
//						if (denom == 0) {
//							cout << "\nDenominator cannot be 0.";
//						}
//					} while (denom == 0);

					((*(fractionArray + i)) + j)->setNum(num);

					//Testing
					//cout << "\n last fraction: " << *((*(fractionArray + i)) + j);
				}

				cout << "\n\nFor array index #" << i;

				for (j = 0; j < newArraySize; j++) {
					cout << "\n  Element index #" << j << ": " << *((*(fractionArray + i)) + j);
				}

			}
				cout << "\n\nConfirming before working through with swapping --\n\nThere is/are " << numArrays << " array(s).";

				for (i = 0; i < numArrays; i++) {
					cout << "\n\nThe current array #" << (i + 1) << " has " << (*(fractionArray + i))->getNum() << " element(s).\n..";

					for (j = 0; j < (*(fractionArray + i))->getNum(); j++) {
						cout << "Element index #" << j << " : " << *((*(fractionArray + i)) + j) << "\n  ";
					}

				}

				cout << "\nCalling arrangeMultiArraysPeteWilcox() --\n";
				numSwaps =
					arrangeMultiArraysPeteWilcox(fractionArray, numArrays);

				cout << "\n\nDisplaying outside of arrangeMultiArraysPeteWilcox() -\n";

				for (i = 0; i < numArrays; i++) {
					cout << "\n\nThe updated array #" << (i + 1) << " has " << (*(fractionArray + i))->getNum() << " element(s).";

					for (j = 0; j < (*(fractionArray + i))->getNum(); j++) {
						cout << "\n  Element index #" << j << " : " << *((*(fractionArray + i)) + j);
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

	void displayHeader() {
		cout << "CIS 25 - C++ Programming\nLaney College"
			"\nPete Wilcox \n\nAssignment Information --"
			"\n  Assignment Number: Lab 5,"
			"\n                     Exercise #2"
			"\n  Written by: Pete Wilcox"
			"\n  Due Date: 2015/11/06\n\n";
	}

	void displayMenu() {
		cout << "\n\n**********************************************"
			"\n*                Fraction Arrays             *"
			"\n* (1) Calling arrangeMultiArraysPeteWilcox() *"
			"\n* (2) Quit                                   *"
			"\n**********************************************"
			"\nSelect an option (1 or 2): ";
	}

	int arrangeMultiArraysPeteWilcox(FractionPeteW** fractionArray, int size) {
		int numSwaps = 0;
		int maxSwaps = 0;
		FractionPeteW temp;
		bool swapped = false;
		int i, k, j = 1;

		// Count the number of swaps to be made
		for (i = 0; i < (*(fractionArray + 0))->getNum(); i++) {
			if ((*(fractionArray + 0) + i)->getNum() % 2 == 0) {
				maxSwaps++;
			}
		}
		cout << "\nmaxSwaps: " << maxSwaps;

		if (maxSwaps > 0) {
			cout << "\n  Displaying inside arrangeMultiArraysPeteWilcox()-";

			for (i = 0; i < (*(fractionArray + i))->getNum(); i++) {
				// For each value in array #1
				if ((*(fractionArray + i))->getNum() % 2 == 0) {
					// If it's even

					while ((j < size) && (!swapped)) {
						// Iterate through each other array

						k = 1;
						while ((k < (*(fractionArray + j))->getNum()) && (!swapped)) {

							if (((*(fractionArray + j)) + k)->getNum() % 2 != 0) {
								// When an odd value is found

								cout << "\n    Array #1 value " << *(*(fractionArray + i)) << " is swapped with Array #" << (j + 1) << " value " << (*(*(fractionArray + j) + k));

								// Swap it
								temp = *(*(fractionArray + i));
								*(*(fractionArray + i)) = (*(*(fractionArray + j) + k));
								(*(*(fractionArray + j) + k)) = temp;

								numSwaps++;
								swapped = true;
							}
							k++;
						}
						// If we've looked through every value
						if (k == ((*fractionArray) + j)->getNum()) {
							// Move to the next array
							j++;
						}
					}
				}
			}
		}

		return numSwaps;
	}
