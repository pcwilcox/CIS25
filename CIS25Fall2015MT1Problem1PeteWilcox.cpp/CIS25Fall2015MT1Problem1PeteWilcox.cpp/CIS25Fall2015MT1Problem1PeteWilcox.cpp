/**
  * Program Name: cis25Fall2015MTProblem1PeteWilcox.cpp
  * Discussion:   Mid-Term 1 Problem 1
  * Written by:   Pete Wilcox
  * Date:         2015/10/20
  */

#include <iostream>

using namespace std;

int* extractUncommonDigitPeteWilcox(int*, int);
void displayMenu(void);
void getInfo(void);

int main() {
	displayMenu();
	return 0;
}

void displayMenu() {
	int menuChoice;
	do {
		cout << "\n***********************************************"
			"\n*                     MENU                    *"
			"\n* 1. Calling ExtractUncommonDigitPeteWilcox() *"
			"\n* 2. Quit                                     *"
			"\n***********************************************"
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

	cout << "\n  Calling extractUncommonDigitPeteWilcox() -";

	returnedArray = extractUncommonDigitPeteWilcox(userArray,
		arraySize);

	cout << "\n\n  Displaying after returning the array -- The "
		"uncommon digits:";
	cout << "\n    There is/are ";
	if (*(returnedArray) > 0) {
		cout << *(returnedArray);
	} else {
		cout << "no";
	}
	cout << " uncommon digit(s)";

	for (i = 0; i < *(returnedArray); i++) {
		cout << "\n    " << (*(returnedArray + i + 1));
	}

	cout << endl;

	delete[] userArray;
	delete[] returnedArray;
}

int* extractUncommonDigitPeteWilcox(int* userArray, int size) {
	int* uncommonArray;         // Return array
	int uncommonCount = 0;		// # of uncommon digits
	int uncommon = 0;			// Holder for digits
	int evens = 0;				// Number of evens
	int currentDigit;			// Temps used for search
	int currentInt;
	int searchInt;
	int searchDigit;
	int i, j;
	bool isCommon[10] = {false};// Track when to stop

	for (i = 0; i < size; i++) { // For each int
		currentInt = *(userArray + i);

		if (currentInt < 0) {
			currentInt = -currentInt;
		}

		do {
			currentDigit = currentInt % 10; // Search each digit

			if (isCommon[currentDigit] == false) {
				// if it's uncommon


				for (j = 0; j < size; j++) {
					if (j != i) {
						searchInt = *(userArray + j);

						if (searchInt < 0) {
							searchInt = -searchInt;
						}

						do {
							searchDigit = searchInt % 10;


							if (currentDigit == searchDigit) {
								// Found it
								isCommon[currentDigit] = true;
							}

							searchInt /= 10;
						} while ((isCommon[currentDigit] == false)
							&& (searchInt > 0));
					}
				}
			}

			if (isCommon[currentDigit] == false) {
				uncommonCount++;
				uncommon *= 10;
				uncommon += currentDigit;
				isCommon[currentDigit] = true;
				// Don't look for this value again
			}

			currentInt /= 10;

		} while (currentInt > 0);
	}

	uncommonArray = new int[uncommonCount + 1];
	*(uncommonArray) = uncommonCount;

	// Modified code
	for (i = 1; i < (uncommonCount + 1); i++) {
		*(uncommonArray + i) = uncommon % 10;
		uncommon /= 10;
	}


	/* Original version:
	for (i = 1; i < (uncommonCount + 1); i++) {
		*(uncommonArray + i) = uncommonDigits % 10;
		uncommonDigits /= 10;
	}

	Changed variable name.
	*/


	for (i = 1; i < (uncommonCount + 1); i++) {
		if (*(uncommonArray + i) % 2 == 0) {
			evens++; // Count evens
		}
	}

	// Modified code
	if (evens > 0) {
		for (i = 1; i <= evens; i++) {
			// Sort for evens/odds
			while (*(uncommonArray + i) % 2 != 0) {
				j = i + 1;
				if (*(uncommonArray + j) % 2 == 0) {
					currentDigit = *(uncommonArray + i);
					*(uncommonArray + i) = *(uncommonArray + j);
					*(uncommonArray + j) = currentDigit;
				}
				j++;
			}
		}
	}
	/* Original version:
	for (i = 1; i <= evens; i++) {
		// Sort for evens/odds
		while (*(uncommonDigits + i) % 2 != 0) {
			j = i + 1;
			if (*(uncommonArray + j) % 2 == 0) {
				currentDigit = *(uncommonArray + i);
				*(uncommonArray + i) = *(uncommonArray + j);
				*(uncommonArray + j) = currentDigit;
			}
			j++;
		}
	}

	Changed variable name.
	*/


	// Modified code:
	if (evens > 0) {
		for (i = 1; i < evens; i++) {
			for (j = i + 1; j <= evens; j++) {
				if (*(uncommonArray + i) > *(uncommonArray + j)) {
					currentDigit = *(uncommonArray + i);
					*(uncommonArray + i) = *(uncommonArray + j);
					*(uncommonArray + j) = currentDigit;
				}
			}
		}
	}

	for (i = evens + 1; i < uncommonCount; i++) {
		for (j = i + 1; j <= uncommonCount; j++) {
			if (*(uncommonArray + i) > *(uncommonArray + j)) {
				currentDigit = *(uncommonArray + i);
				*(uncommonArray + i) = *(uncommonArray + j);
				*(uncommonArray + j) = currentDigit;
			}
		}
	}

	/* Original code:
	for (i = 1; i < evens; i++) {
		// Sort evens
		j = i + 1;
		while (*(uncommonArray + i) < *(uncommonArray + j)
		&& (j <= evens)) {
			currentDigit = *(uncommonArray + i);
			*(uncommonArray + i) = *(uncommonArray + j);
			*(uncommonArray + j) = currentDigit;
			j++;
		}
	}

	for (i = evens + 1; i < uncommonCount; i++) {
		// Sort odds
		j = i + 1;
		while ((*(uncommonArray + i) < *(uncommonArray + j))
		&& (j <= uncommonCount)) {
			currentDigit = *(uncommonArray + i);
			*(uncommonArray + i) = *(uncommonArray + j);
			*(uncommonArray + j) = currentDigit;
			j++;
		}
	}
	*/

	return uncommonArray;

}

/* PROGRAM OUTPUT:

Original version doesn't compile.

After fixing the variable name errors:


***********************************************
*                     MENU                    *
* 1. Calling ExtractUncommonDigitPeteWilcox() *
* 2. Quit                                     *
***********************************************
Select an option (1 or 2): 1

How many integers? 3
Enter integer #1: 32965
Enter integer #2: -275721
Enter integer #3: 3028063

The original array:
32965
-275721
3028063
Calling extractUncommonDigitPeteWilcox() -

Displaying after returning the array -- The uncommon digits:
There is/are 5 uncommon digit(s)
8
0
7
9
1
***********************************************
*                     MENU                    *
* 1. Calling ExtractUncommonDigitPeteWilcox() *
* 2. Quit                                     *
***********************************************
Select an option (1 or 2): 2

Fun exercize ...

**************************************************
After modifications:


***********************************************
*                     MENU                    *
* 1. Calling ExtractUncommonDigitPeteWilcox() *
* 2. Quit                                     *
***********************************************
Select an option (1 or 2): 1

  How many integers? 3
    Enter integer #1: 32965
    Enter integer #2: -275721
    Enter integer #3: 3028063

  The original array:
    32965
    -275721
    3028063
  Calling extractUncommonDigitPeteWilcox() -

  Displaying after returning the array -- The uncommon digits:
    There is/are 5 uncommon digit(s)
    0
    8
    1
    7
    9

***********************************************
*                     MENU                    *
* 1. Calling ExtractUncommonDigitPeteWilcox() *
* 2. Quit                                     *
***********************************************
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
  Calling extractUncommonDigitPeteWilcox() -

  Displaying after returning the array -- The uncommon digits:
    There is/are no uncommon digit(s)

***********************************************
*                     MENU                    *
* 1. Calling ExtractUncommonDigitPeteWilcox() *
* 2. Quit                                     *
***********************************************
Select an option (1 or 2): 1

  How many integers? 4
    Enter integer #1: 2965
    Enter integer #2: -7571
    Enter integer #3: 2806
    Enter integer #4: 789

  The original array:
    2965
    -7571
    2806
    789
  Calling extractUncommonDigitPeteWilcox() -

  Displaying after returning the array -- The uncommon digits:
    There is/are 2 uncommon digit(s)
    0
    1

***********************************************
*                     MENU                    *
* 1. Calling ExtractUncommonDigitPeteWilcox() *
* 2. Quit                                     *
***********************************************
Select an option (1 or 2): 2

  Fun exercize ...

*/

/* COMMENTS:

2015/10/20:
The version I wrote in class will not compile, because I
inadvertently used the variable name 'uncommonDigits' instead of
'uncommons' - this is because at the time I was writing this,
you pointed out that we had used up an hour of the allotted time
for the test.

After changing the variable names to the original values, the
expected output is close but not quite correct - the sort is
not performed correctly because I used the incorrect comparison
operator.

I added some further checks in case there were no even uncommon
digits, as I was getting unexpected behavior without them - I'm
not sure why.
*/