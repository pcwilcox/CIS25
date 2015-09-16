#include <iostream>

using namespace std;

// Function prototypes
void header(void);
void menu(void);
void displayDigitInfoUpdatePeteWilcox(void);
int *makeIntegerArrays(int);
void displayDigits(int*, int, int);
void displayMostDigit(int*, int, int);

int main() {

	header(); // Display program header information.
	menu();   // Display user interface.

	return 0;
}

void header() {
	cout << "\nClass Information --";
	cout << "\n  CIS 25 - C++ Programming";
	cout << "\n  Laney College";
	cout << "\n";
	cout << "\nAssignment Information -- ";
	cout << "\n  Assignment Number:  Lab 02 - Exercise #1";
	cout << "\n  Written by:         Pete Wilcox";
	cout << "\n  Submitted Date:     2015/09/17";
	cout << "\n";
	return;
}

void menu() {
	// Declare variables for the menu and for the integer input.
	int menuChoice = 0;

	// Create a loop for the main menu function.
	do {
		cout << "\n";
		cout << "\n***************************************************";
		cout << "\n*               MENU 02 -- Arrays & Digits        *";
		cout << "\n*  (1) Calling displayDigitInfoUpdatePeteWilcox() *";
		cout << "\n*  (2) Quit                                       *";
		cout << "\n***************************************************";
		cout << "\nSelect an option (1 or 2): ";
		cin >> menuChoice;

		// Get input from user if option (1) is chosen, then call 
		// getMostOccurredDigit function and display result.
		switch (menuChoice) {
		case 1:
			cout << "\nCalling displayDigitInfoUpdatePeteWilcox() --";

			displayDigitInfoUpdatePeteWilcox();
			break;
		case 2:
			// Quit message.
			cout << "\nHaving fun..." << endl;
			break;
		default:
			cout << "\nWRONG OPTION!\n";
		}
	} while (menuChoice != 2);

	return;
}

void displayDigitInfoUpdatePeteWilcox() {
	int numIntegers = 0;
	int* integerArray;
	int i;

	cout << "\n  How many integers (to be worked on)? ";
	cin >> numIntegers;

	integerArray = new int[numIntegers];
	
	for (i = 0; i < numIntegers; i++) {
		cout << "    Enter integer #" << (i + 1) << ": ";
		cin >> *(integerArray + i);
	}

	// Call the functions to display required information
	displayDigits(integerArray, numIntegers, 0);
	displayDigits(integerArray, numIntegers, 2);
	displayDigits(integerArray, numIntegers, 1);
	
	// Free up memory
	delete integerArray;

	return;
}

void displayDigits(int *integerArray, int numIntegers, int modeSelection) {
	// Function to display total occurrence of each digit

	// Declare variables
	int digitCounter[10] = {0};
	int thisDigit;
	int tempNum;
	int i;

	// Add digits to the digitCounter array
	for (i = 0; i < numIntegers; i++) {
		
		tempNum = *(integerArray + i);

		if (tempNum < 0) {
			tempNum = -tempNum;
		}

		do {
			if (modeSelection == 0) {
				thisDigit = tempNum % 10;
				digitCounter[thisDigit]++;
			} else if ((modeSelection == 2) && (thisDigit % 2 == 0)) {
				thisDigit = tempNum % 10;
				digitCounter[thisDigit]++;
			} else if ((modeSelection == 1) && (thisDigit % 2 != 0)) {
				thisDigit = tempNum % 10;
				digitCounter[thisDigit]++;
			} else {			
				// nothing
			}
			tempNum /= 10;
		} while (tempNum != 0);
	}

	// Display results
	cout << "\n  Occurrence of all existing ";

	if (modeSelection == 2) {
		cout << "even ";
	} else if (modeSelection == 1) {
		cout << "odd ";
	} else {
		// all
	} cout << "digits --";

	for (i = 0; i < 10; i++) {
		if (digitCounter[i] != 0) {
			cout << "\n    Digit " << i << " : " << digitCounter[i];
		}
	}

	if ((modeSelection == 1) || (modeSelection == 2)) {
		displayMostDigit(digitCounter, numIntegers, modeSelection);
	}

	return;
}

void displayMostDigit(int digitCounter[], int numIntegers, int modeSelection) {
	int countSmall = 50;
	int countLarge = 0;
	int i;
	
	// Count digit frequency

	for (i = 0; i < 10; i++) {
		if (digitCounter[i] > countLarge) {
			countLarge = digitCounter[i];
		}
		if ((digitCounter[i] < countSmall) && (digitCounter[i] != 0)) {
			countSmall = digitCounter[i];
		}
	}

	if (modeSelection == 2) {
		cout << "\n\n  The even digit(s) that has/have the largest occurrence --";
	} else {
		cout << "\n\n  The odd digit(s) that has/have the largest occurrence --";
	}

	for (i = 0; i < 10; i++) {
		if (digitCounter[i] == countLarge) {
			cout << "\n    " << i;
		}
	}
	cout << "\n  With the number of occurrence(s): " << countLarge;

	if (modeSelection == 2) {
		cout << "\n\n  The even digit(s) that has/have the smallest occurrence --";
	}
	else {
		cout << "\n\n  The odd digit(s) that has/have the smallest occurrence --";
	}
	for (i = 0; i < 10; i++) {
		if (digitCounter[i] == countSmall) {
			cout << "\n    " << i;
		}
	}
	cout << "\n  With the number of occurrence(s) : " << countSmall;

	return;
}

/* PROGRAM OUTPUT:

*/

/* COMMENTS:

*/