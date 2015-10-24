/**
 * Program Name: cis25Fall2015MTProblem2PeteWilcox.cpp
 * Discussion:   Mid-Term 1 Problem 2
 * Written by:   Pete Wilcox
 * Date:         2015/10/23
 */

#include <iostream>

using namespace std;

int* getUncommonDigitStatsticsPeteWilcox(int*, int);
void displayHeader(void);
void displayMenu(void);

int main() {
	int menuChoice;
	int* userArray;
	int* returnedArray;
	int arraySize;
	int evens;
	int odds;
	int oddStart;
	int i = 0;

	displayHeader();

	do {
		displayMenu();

		cin >> menuChoice;

		switch (menuChoice) {
		case 1:

			cout << "\n  How many integers? ";
			cin >> arraySize;

			userArray = new int[arraySize];

			for (i = 0; i < arraySize; i++) {
				cout << "    Enter integer #" << (i + 1) 
					<< ": ";
				cin >> *(userArray + i);
			}

			cout << "\n  The original array:";

			for (i = 0; i < arraySize; i++) {
				cout << "\n    " << *(userArray + i);
			}

			cout << "\n\n  Calling "
				"getUncommonDigitStatsticsPeteWilcox() -";

			returnedArray = 
				getUncommonDigitStatsticsPeteWilcox(userArray,
				arraySize);

			if (*(returnedArray) > 0) {
				// Assign evens, odds, oddstart values 
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

			cout << "\n\n  Displaying after returning the array"
				" -- The statistics:\n    There is/are ";
			if (odds + evens > 0) {
				cout << (odds + evens);
			} else {
				cout << "no";
			}
			cout << " uncommon digit(s)";

			if (odds + evens > 0) {
				cout << " with";
			}



			if (evens > 0) {
				evens = *(returnedArray + 1);
				oddStart = evens * 3;
				cout << "\n\n      Number of odd uncommon "
					"digits: " << evens;

				for (i = 2; i < oddStart; i += 2) {
					cout << "\n        Digit " << 
						*(returnedArray + i) << " occurs " << 
						*(returnedArray + i + 1) << " time(s)";
				}
			} else {
				oddStart = 2;
			}



			if (odds > 0) {
				cout << "\n\n      Number of odd uncommon "
					"digits: " << odds;
				for (i = oddStart + 1; i < *(returnedArray); 
					i += 2) {
					
					cout << "\n        Digit " << 
						*(returnedArray + i) << " occurs " << 
						*(returnedArray + i + 1) << " time(s)";
				}
			}


			delete[] userArray;
			delete[] returnedArray;

			break;
		case 2:
			cout << "\n  Fun exercise ...";
			break;
		default:
			cout << "\n  WRONG OPTION!";
		}
	} while (menuChoice != 2);

	return 0;
}

void displayHeader() {
	cout << "Class Information --\n"
		"  CIS 25 - C++ Programming\n"
		"  Laney College\n\n"
		"Assignment Information --\n"
		"  Assignment Number:  Midterm #1 - Problem #2\n"
		"  Written by:         Pete Wilcox\n"
		"  Due Date:           2015/10/23\n\n";
}

void displayMenu() {
	cout << "\n\n********************************"
		"********************"
		"\n*                     MENU                         *"
		"\n* 1. Calling getUncommonDigitStatsticsPeteWilcox() *"
		"\n* 2. Quit                                          *"
		"\n****************************************************"
		"\nSelect an option (1 or 2): ";
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
		// For each integer
		currentInt = *(input + i);
		if (currentInt < 0) {
			currentInt = -currentInt;
		}

		do {
			currentDigit = currentInt % 10;
			// Search each digit
			if (digitCounter[currentDigit] == 0) {
				// If we haven't looked already
				if (isCommon[currentDigit] == false) {
					// If it has not already been found common
					for (j = 0; j < size &&
						isCommon[currentDigit] == false; j++) {
						//Search each other integer
						if (j != i) {
							// Don't search the same one!
							searchInt = *(input + j);
							if (searchInt < 0) {
								searchInt = -searchInt;
							}

							do {
								searchDigit = searchInt % 10;
								// Check each digit
								if (currentDigit == searchDigit) {
									isCommon[currentDigit] = true;
								}

								searchInt /= 10;

							} while ((searchInt > 0) &&
								(isCommon[currentDigit] ==
									false));
						}
					}
				}

				if (isCommon[currentDigit] == false) {
					// We didn't find it
					digitCounter[currentDigit]++;
				}
			} else {
				// We've already determined it's uncommon
				digitCounter[currentDigit]++;
			}
			currentInt /= 10;
		} while (currentInt > 0);
	}

	for (i = 0; i < 10; i++) {
		// Count evens/odds. This should have been done in the
		// previous step.
		if (digitCounter[i] > 0) {
			if (i % 2 == 0) {
				evens++;
			} else {
				odds++;
			}
		}
	}

	newSize = (3 + (evens * 2) + (odds * 2));
	uncommonArray = new int[newSize];
	*(uncommonArray) = newSize;

	j = 2;
	if (evens > 0) {
		// Assign values for even digits
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
		// Assign values for odd digits
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
Class Information --
  CIS 25 - C++ Programming
  Laney College

Assignment Information --
  Assignment Number:  Midterm #1 - Problem #2
  Written by:         Pete Wilcox
  Due Date:           2015/10/23



****************************************************
*                     MENU                         *
* 1. Calling getUncommonDigitStatsticsPeteWilcox() *
* 2. Quit                                          *
****************************************************
Select an option (1 or 2): 1

  How many integers? 3
    Enter integer #1: 32965
    Enter integer #2: -275721
    Enter integer #3: 3028063

  The original array:
    32965
    -275721
    3028063

  Calling getUncommonDigitStatsticsPeteWilcox() -

  Displaying after returning the array -- The statistics:
    There is/are 5 uncommon digit(s) with

      Number of odd uncommon digits: 2
        Digit 0 occurs 2 time(s)
        Digit 8 occurs 1 time(s)

      Number of odd uncommon digits: 3
        Digit 1 occurs 1 time(s)
        Digit 7 occurs 2 time(s)
        Digit 9 occurs 1 time(s)

****************************************************
*                     MENU                         *
* 1. Calling getUncommonDigitStatsticsPeteWilcox() *
* 2. Quit                                          *
****************************************************
Select an option (1 or 2): 1

  How many integers? 4
    Enter integer #1: 32965
    Enter integer #2: -275721
    Enter integer #3: 3028063
    Enter integer #4: 10789

  The original array:
    32965
    -275721
    3028063
    10789

  Calling getUncommonDigitStatsticsPeteWilcox() -

  Displaying after returning the array -- The statistics:
    There is/are no uncommon digit(s)

****************************************************
*                     MENU                         *
* 1. Calling getUncommonDigitStatsticsPeteWilcox() *
* 2. Quit                                          *
****************************************************
Select an option (1 or 2): 1

  How many integers? 3
    Enter integer #1: 3296
    Enter integer #2: -2757
    Enter integer #3: 107

  The original array:
    3296
    -2757
    107

  Calling getUncommonDigitStatsticsPeteWilcox() -

  Displaying after returning the array -- The statistics:
    There is/are 6 uncommon digit(s) with

      Number of odd uncommon digits: 2
        Digit 0 occurs 1 time(s)
        Digit 6 occurs 1 time(s)

      Number of odd uncommon digits: 4
        Digit 1 occurs 1 time(s)
        Digit 3 occurs 1 time(s)
        Digit 5 occurs 1 time(s)
        Digit 9 occurs 1 time(s)

****************************************************
*                     MENU                         *
* 1. Calling getUncommonDigitStatsticsPeteWilcox() *
* 2. Quit                                          *
****************************************************
Select an option (1 or 2): 4

  WRONG OPTION!

****************************************************
*                     MENU                         *
* 1. Calling getUncommonDigitStatsticsPeteWilcox() *
* 2. Quit                                          *
****************************************************
Select an option (1 or 2): 2

  Fun exercise ...
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

I also forgot to set the first element of the array to actually
contain the number of elements - I created the variable but
neglected to assign it.
*/

/* ORIGINAL CODE:

 int* getUncommonDigitStatisticsPeteWilcox(int* input, int size) {
	 bool isCommon[10] = {false};
	 int digitCounter[10] = {0};
	 int* uncommonArray;
	 int newSize;
	 int evens;
	 int odds;
	 int currentInt;
	 int currentDigit;
	 int searchDigit;
	 int searchInt;
	 int i, j;

	 for (i = 0; i < size; i++) {
		 currentInt = *(input + i);

		 if (currentInt < 0) {
			 currentInt = -currentInt;
		 }

		 do {
			 currentDigit = currentInt % 10;

			 if (digitCounter[currentDigit] == 0) {
				 if (isCommon[currentDigit] == false) {
					 for (j = 0; j < size; j++) {
						 if (j != 0) {
							 searchInt = *(input + j);
							 if (searchInt < 0) {
								 searchInt = -searchInt;
							 }

							 do {
								 searchDigit = searchInt % 10;
								 if (currentDigit == searchDigit) {
									 isCommon[currentDigit] = true;
								 }
								 searchInt /= 10;
							 } while ((searchInt > 0) && (isCommon[currentDigit] == true));

						 }
					 }
				 }
				 if (isCommon[currentDigit] == false) {
					 digitCounter[currentDigit]++;
				 }
			 } else {
				 isCommon[currentDigit]++;
			 }
			 currentInt /= 10;
		 } while (currentInt > 0);
	 }

	 for (i = 0; i < 10; i++) {
		 if (digitCounter[i] > 0) {
			 if (digitCounter[i] % 2 == 0) {
				 evens++;
			 } else {
				 odds++;
			 }
		 }
	 }

	 newSize = (3 + (evens * 2) + (odds * 2));
	 uncommonArray = new int[newSize];

	 *(uncommonArray) = newSize;

	 j = 2;

	 if (evens > 0) {
		 *(uncommonArray + i) = evens;
		 for (i = 0; i < 10; i++) {
			 if (digitCounter[i] > 0) {
				 *(uncommonArray + j) = i;
				 *(uncommonArray + j + 1) = digitCounter[i];
				 j += 2;
			 }
		 }
	 } else {
		 *(uncommonArray + i) = 0;
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
 */