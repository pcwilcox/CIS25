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
			"\n***********************************************";
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
	cout << "\n    There is/are " << *(returnedArray) <<
		"uncommon digit(s)";

	for (i = 0; i < *(returnedArray); i++) {
		cout << "\n    " << (*(returnedArray + i + 1));
	}

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

			searchInt /= 10;

		} while (currentInt > 0);
	}

	uncommonArray = new int[uncommonCount + 1];
	*(uncommonArray) = uncommonCount;

	for (i = 1; i < (uncommonCount + 1); i++) {
		*(uncommonArray + i) = uncommonDigits % 10;
		uncommonDigits /= 10;
	}

	for (i = 1; i < (uncommonCount + 1); i++) {
		if (*(uncommonArray + i) % 2 == 0) {
			evens++; // Count evens
		}
	}

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

	for (i = 1; i < evens; i++) { 
		// Sort evens
		j = i + 1;
		while (*(uncommonArray + i) < *(uncommonArray + j) && (j <= evens)) {
			currentDigit = *(uncommonArray + i);
			*(uncommonArray + i) = *(uncommonArray + j);
			*(uncommonArray + j) = currentDigit;
			j++;
		}
	}

	for (i = evens + 1; i < uncommonCount; i++) {
		// Sort odds
		j = i + 1;
		while ((*(uncommonArray + i) < *(uncommonArray + j)) && (j <= uncommonCount)) {
			currentDigit = *(uncommonArray + i);
			*(uncommonArray + i) = *(uncommonArray + j);
			*(uncommonArray + j) = currentDigit;
			j++;
		}
	}

	return uncommonArray;

}

/* PROGRAM OUTPUT:

*/

/* COMMENTS:

2015/10/20:
The version I wrote in class will not compile, because I
inadvertently used the variable name 'uncommonDigits' instead of
'uncommons' - this is because at the time I was writing this,
you pointed out that we had used up an hour of the allotted time
for the test. 

*/