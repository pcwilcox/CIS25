#include <iostream>

using namespace std;

// Function prototypes
void header(void);
void menu(void);
void displayDigitInfoUpdatePeteWilcox(void);
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

	// Count digit frequency
	for (i = 0; i < numIntegers; i++) {
		
		tempNum = *(integerArray + i);

		if (tempNum < 0) {
			tempNum = -tempNum;
		}

		do {
			thisDigit = tempNum % 10;
			switch (modeSelection) {
			case 2: // even
				if (thisDigit % 2 == 0) {
					digitCounter[thisDigit]++;
				}
				break;
			case 1: // odd
				if (thisDigit % 2 != 0) {
					digitCounter[thisDigit]++;
				}
				break;
			default: // all
				digitCounter[thisDigit]++;
			}

			tempNum /= 10;
		} while (tempNum != 0);
	}

	cout << endl;
	// Display results
	switch (modeSelection) {
	case 2:
		cout << "\n Occurrence of all existing even digits --";
		break;
	case 1:
		cout << "\n Occurrence of all existing odd digits --";
		break;
	default:
		cout << "\n Occurrence of all existing digits --";
	}

	for (i = 0; i < 10; i++) {
		if (digitCounter[i] != 0) {
			cout << "\n    Digit " << i << " : " << digitCounter[i];
		}
	}

	// In even or odd mode, call displayMostDigit()
	if ((modeSelection == 1) || (modeSelection == 2)) {
		displayMostDigit(digitCounter, numIntegers, modeSelection);
	}

	return;
}

void displayMostDigit(int* digitCounter, int numIntegers, int modeSelection) {
	int countSmall = 50;
	int countLarge = 0;
	int i;
	
	// Count digit frequency

	for (i = 0; i < 10; i++) {
		if (*(digitCounter + i) > countLarge) {
			countLarge = *(digitCounter + i);
		}
		if ((*(digitCounter + i) < countSmall) && (*(digitCounter + i) != 0)) {
			countSmall = *(digitCounter + i);
		}
	}

	if (modeSelection == 2) {
		cout << "\n\n  The even digit(s) that has/have the largest occurrence --";
	} else {
		cout << "\n\n  The odd digit(s) that has/have the largest occurrence --";
	}

	for (i = 0; i < 10; i++) {
		if (*(digitCounter + i) == countLarge) {
			cout << "\n    " << i;
		}
	}
	cout << "\n  With the number of occurrence(s): " << countLarge;

	if (modeSelection == 2) {
		cout << "\n\n  The even digit(s) that has/have the smallest occurrence --";
	} else {
		cout << "\n\n  The odd digit(s) that has/have the smallest occurrence --";
	}

	for (i = 0; i < 10; i++) {
		if (*(digitCounter + i) == countSmall) {
			cout << "\n    " << i;
		}
	}
	cout << "\n  With the number of occurrence(s) : " << countSmall;

	return;
}

/* PROGRAM OUTPUT:

Class Information --
  CIS 25 - C++ Programming
  Laney College

Assignment Information --
  Assignment Number:  Lab 02 - Exercise #1
  Written by:         Pete Wilcox
  Submitted Date:     2015/09/17


***************************************************
*               MENU 02 -- Arrays & Digits        *
*  (1) Calling displayDigitInfoUpdatePeteWilcox() *
*  (2) Quit                                       *
***************************************************
Select an option (1 or 2): 4

WRONG OPTION!


***************************************************
*               MENU 02 -- Arrays & Digits        *
*  (1) Calling displayDigitInfoUpdatePeteWilcox() *
*  (2) Quit                                       *
***************************************************
Select an option (1 or 2): 1

Calling displayDigitInfoUpdatePeteWilcox() --
  How many integers (to be worked on)? 2
    Enter integer #1: 1230476
    Enter integer #2: 10034850


 Occurrence of all existing digits --
    Digit 0 : 4
    Digit 1 : 2
    Digit 2 : 1
    Digit 3 : 2
    Digit 4 : 2
    Digit 5 : 1
    Digit 6 : 1
    Digit 7 : 1
    Digit 8 : 1

 Occurrence of all existing even digits --
    Digit 0 : 4
    Digit 2 : 1
    Digit 4 : 2
    Digit 6 : 1
    Digit 8 : 1

  The even digit(s) that has/have the largest occurrence --
    0
  With the number of occurrence(s): 4

  The even digit(s) that has/have the smallest occurrence --
    2
    6
    8
  With the number of occurrence(s) : 1

 Occurrence of all existing odd digits --
    Digit 1 : 2
    Digit 3 : 2
    Digit 5 : 1
    Digit 7 : 1

  The odd digit(s) that has/have the largest occurrence --
    1
    3
  With the number of occurrence(s): 2

  The odd digit(s) that has/have the smallest occurrence --
    5
    7
  With the number of occurrence(s) : 1

***************************************************
*               MENU 02 -- Arrays & Digits        *
*  (1) Calling displayDigitInfoUpdatePeteWilcox() *
*  (2) Quit                                       *
***************************************************
Select an option (1 or 2): 1

Calling displayDigitInfoUpdatePeteWilcox() --
  How many integers (to be worked on)? 3
    Enter integer #1: 1230476
    Enter integer #2: 10434950
    Enter integer #3: 9023497


 Occurrence of all existing digits --
    Digit 0 : 4
    Digit 1 : 2
    Digit 2 : 2
    Digit 3 : 3
    Digit 4 : 4
    Digit 5 : 1
    Digit 6 : 1
    Digit 7 : 2
    Digit 9 : 3

 Occurrence of all existing even digits --
    Digit 0 : 4
    Digit 2 : 2
    Digit 4 : 4
    Digit 6 : 1

  The even digit(s) that has/have the largest occurrence --
    0
    4
  With the number of occurrence(s): 4

  The even digit(s) that has/have the smallest occurrence --
    6
  With the number of occurrence(s) : 1

 Occurrence of all existing odd digits --
    Digit 1 : 2
    Digit 3 : 3
    Digit 5 : 1
    Digit 7 : 2
    Digit 9 : 3

  The odd digit(s) that has/have the largest occurrence --
    3
    9
  With the number of occurrence(s): 3

  The odd digit(s) that has/have the smallest occurrence --
    5
  With the number of occurrence(s) : 1

***************************************************
*               MENU 02 -- Arrays & Digits        *
*  (1) Calling displayDigitInfoUpdatePeteWilcox() *
*  (2) Quit                                       *
***************************************************
Select an option (1 or 2): 1

Calling displayDigitInfoUpdatePeteWilcox() --
  How many integers (to be worked on)? 4
    Enter integer #1: 1230476
    Enter integer #2: 10434950
    Enter integer #3: 9023497
    Enter integer #4: 5084624


 Occurrence of all existing digits --
    Digit 0 : 5
    Digit 1 : 2
    Digit 2 : 3
    Digit 3 : 3
    Digit 4 : 6
    Digit 5 : 2
    Digit 6 : 2
    Digit 7 : 2
    Digit 8 : 1
    Digit 9 : 3

 Occurrence of all existing even digits --
    Digit 0 : 5
    Digit 2 : 3
    Digit 4 : 6
    Digit 6 : 2
    Digit 8 : 1

  The even digit(s) that has/have the largest occurrence --
    4
  With the number of occurrence(s): 6

  The even digit(s) that has/have the smallest occurrence --
    8
  With the number of occurrence(s) : 1

 Occurrence of all existing odd digits --
    Digit 1 : 2
    Digit 3 : 3
    Digit 5 : 2
    Digit 7 : 2
    Digit 9 : 3

  The odd digit(s) that has/have the largest occurrence --
    3
    9
  With the number of occurrence(s): 3

  The odd digit(s) that has/have the smallest occurrence --
    1
    5
    7
  With the number of occurrence(s) : 2

***************************************************
*               MENU 02 -- Arrays & Digits        *
*  (1) Calling displayDigitInfoUpdatePeteWilcox() *
*  (2) Quit                                       *
***************************************************
Select an option (1 or 2): 2

Having fun...
*/

/* COMMENTS:

2015/09/17:
My first version of this program used a separate function for each
desired output - displayMostDigitEven() and so on. I decided to 
simplify the code by condensing it and adding an argument to the
functions that sets whether it is operating in even/odd/all mode.
This cleans up the code significantly and makes it easier to read.

*/