/**
* Program Name: cis25Fall2015MTProblem2PeteWilcox.cpp
* Discussion:   Mid-Term 1 Problem 2
* Written by:   Pete Wilcox
* Date:         2015/10/20
*/

#include <iostream>

using namespace std;

int* getUncommonDigitStatsticsPeteWilcox(int*, int);
void displayHeader(void);
void displayMenu(void);
void getInfo(void);

int main() {
	displayMenu();
	return 0;
}

void displayHeader() {
	cout << "Class Information --\n"
		"  CIS 25 - C++ Programming\n"
		"  Laney College\n\n"
		"Assignment Information --\n"
		"  Assignment Number:  Midterm #1 � Exercise #2\n"
		"  Written by:         Pete Wilcox\n"
		"  Due Date:           2015/10/22\n\n";
}

void displayMenu() {
	int menuChoice;
	do {
		cout << "\n****************************************************"
			"\n*                     MENU                         *"
			"\n* 1. Calling getUncommonDigitStatsticsPeteWilcox() *"
			"\n* 2. Quit                                          *"
			"\n****************************************************"
			"\nSelect an option (1 or 2): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			getInfo();
			break;
		case 2:
			cout << "\n  Fun exercize ...";
			break;
		default:
			cout << "\n  WRONG OPTION!";
		}
	} while (menuChoice != 2);

}

void getInfo() {
	int* userArray;
	int* returnedArray;
	int arraySize;
	int evens;
	int odds;
	int oddStart;
	int i = 0;

	cout << "\n  How many integers? ";
	cin >> arraySize;

	userArray = new int[arraySize];

	for (i = 0; i < arraySize; i++) {
		cout << "    Enter integer #" << (i + 1) << ": ";
		cin >> *(userArray + i);
	}

	cout << "\n  The original array:";

	for (i = 0; i < arraySize; i++) {
		cout << "\n    " << *(userArray + i);
	}

	cout << "\n  Calling getUncommonDigitStatsticsPeteWilcox() -";

	returnedArray = getUncommonDigitStatsticsPeteWilcox(userArray,
		arraySize);
	/*
	cout << "\nRETURNED ARRAY: ";
	for (i = 0; i < *(returnedArray); i++) {
		cout << " " <<  *(returnedArray + i);
	}
	cout << "\n";
	*/
	

	if (*(returnedArray) > 0) {
		if (*(returnedArray + 1) > 0) {
			evens = *(returnedArray + 1);
			oddStart = (evens * 2) + 2;
		} else {
			evens = 0;
			oddStart = 2;
		}

		if (*(returnedArray + oddStart) > 0) {
			odds = *(returnedArray + oddStart);
		} else {
			odds = 0;
		}
	}

	cout << "\n\n  Displaying after returning the array -- "
		"\n    There is/are ";
	if (odds + evens > 0) {
		cout << (odds + evens);
	} else {
		cout << "no";
	}
	cout << " uncommon digit(s)";



	if (evens > 0) {
		evens = *(returnedArray + 1);
		oddStart = evens * 3;
		cout << "\n\n    There is/are " << evens << " even uncommon digits.";

		for (i = 2; i < oddStart; i += 2) {
			cout << "\n    The digit " << *(returnedArray + i) << " occurs " << *(returnedArray + i + 1) << " time(s).";
		}
	} else {
		oddStart = 2;
	}



	if (odds > 0) {
		cout << "\n\n    There is/are " << odds <<
			" odd uncommon digits.";
		for (i = oddStart + 1; i < *(returnedArray); i += 2) {
			cout << "\n    The digit " << *(returnedArray + i) << " occurs " << *(returnedArray + i + 1) << " time(s).";
		}
	}


	delete[] userArray;
	delete[] returnedArray;
}

int* getUncommonDigitStatsticsPeteWilcox(int* input, int size) {
	bool isCommon[10] = {false};
	int digitCounter[10] = {0};
	int* uncommonArray;
	int newSize;
	int evens = 0;
	int odds = 0;
	int currentInt;
	int currentDigit;
	int searchInt;
	int searchDigit;
	int i, j;

	for (i = 0; i < size; i++) {
		currentInt = *(input + i);
//		cout << "\nCURRENT INT: " << currentInt;
		if (currentInt < 0) {
			currentInt = -currentInt;
		}

		do {
			currentDigit = currentInt % 10;
//			cout << "\nCURRENT DIGIT: " << currentDigit;
			if (digitCounter[currentDigit] == 0) {
				if (isCommon[currentDigit] == false) {
					for (j = 0; j < size && isCommon[currentDigit] == false; j++) {
						if (j != i) {
							searchInt = *(input + j);
//							cout << "\nSEARCH INT: " << searchInt;
							if (searchInt < 0) {
								searchInt = -searchInt;
							}

							do {
								searchDigit = searchInt % 10;
//								cout << "\nSEARCH DIGIT: " << searchDigit;
								if (currentDigit == searchDigit) {
									isCommon[currentDigit] = true;
//									cout << " - COMMON";
								}

								searchInt /= 10;

							} while ((searchInt > 0) && (isCommon[currentDigit] == false));
						}
					}
				}

				if (isCommon[currentDigit] == false) {
					digitCounter[currentDigit]++;
//					cout << "\nCURRENT DIGIT IS UNCOMMON AND HAS OCCURRED " << digitCounter[currentDigit] << " TIMES";
				}
			} else {
				digitCounter[currentDigit]++;
//				cout << "\nCURRENT DIGIT IS UNCOMMON AND HAS OCCURRED " << digitCounter[currentDigit] << " TIMES";
			}
			currentInt /= 10;
		} while (currentInt > 0);
	}

	for (i = 0; i < 10; i++) {
		if (digitCounter[i] > 0) {
//			cout << "\n DIGITCOUNTER[" << i << "]: ";
			if (i % 2 == 0) {
				evens++;
//				cout << " - EVEN";
			} else {
				odds++;
//				cout << " - ODD";
			}
		}
	}

	newSize = (3 + (evens * 2) + (odds * 2));
	uncommonArray = new int[newSize];
	*(uncommonArray) = newSize;

	j = 2;
	if (evens > 0) {
		*(uncommonArray + 1) = evens;
		for (i = 0; i < 10; i += 2) {
			if (digitCounter[i] > 0) {
				*(uncommonArray + j) = i;
				*(uncommonArray + j + 1) = digitCounter[i];
				j += 2;
			}
		}
	} else {
		*(uncommonArray + 1) = 0;
	}

	*(uncommonArray + j) = odds;
	j++;

	if (odds > 0) {
		for (i = 1; i < 10; i += 2) {
			if (digitCounter[i] > 0) {
				*(uncommonArray + j) = i;
				*(uncommonArray + j + 1) = digitCounter[i];
				j += 2;
			}
		}
	}

	return uncommonArray;
}

/* PROGRAM OUTPUT:

*/

/* COMMENTS:

2015/10/20:
There was not enough time for this. Our lab work has not covered
the concept of 'uncommon digits' at all, nor has it covered any
sort algorithms. One and a half hours to complete two brand new
labs is grueling and the number of students who did not even
complete the assignment is shameful.

When I compiled this program I got an uninitialized variable
error. I initialized evens and odds to fix it. After that, the
program compiles.

I did not implement even/odd tracking correctly. In my haste I
was incrementing the evens/odds counters based on the occurrence
of a particular digit, rather than the digit itself. That has
been corrected.
*/