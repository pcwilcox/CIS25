/**
  * Program Name: CIS25Fall2015PeteWilcoxLab5Ex1.cpp
  * Discussion:   Lab #5 Exercise #1
  * Written by:   Pete Wilcox
  * Date:         2015/11/10
  */

#include <iostream>
#include "fractionPeteW.h"

using namespace std;

// Display info
void displayHeader(void);
void displayMainMenu(void);

// Error message
void initBothError(void);

// Init fractions
void init(FractionPeteW**, FractionPeteW**);

// Submenus
void menuAdd(FractionPeteW**, FractionPeteW**, 
	FractionPeteW**);
void menuSubtract(FractionPeteW**, FractionPeteW**, 
	FractionPeteW**);
void menuDivide(FractionPeteW**, FractionPeteW**, 
	FractionPeteW**);
void menuMultiply(FractionPeteW**, FractionPeteW**, 
	FractionPeteW**);
void menuPrint(FractionPeteW**, FractionPeteW**, 
	FractionPeteW**);

// Stand alone functions
void add(FractionPeteW**, FractionPeteW**, FractionPeteW**);
void subtract(FractionPeteW**, FractionPeteW**, 
	FractionPeteW**);
void multiply(FractionPeteW**, FractionPeteW**, 
	FractionPeteW**);
void divide(FractionPeteW**, FractionPeteW**, FractionPeteW**);
void print(FractionPeteW**);

int main() {
	int menuChoice;
	FractionPeteW* fracLeft = nullptr;
	FractionPeteW* fracRight = nullptr;
	FractionPeteW* fracResult = nullptr;

	displayHeader();

	// Menu interface loop
	do {
		displayMainMenu();
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\n  Initializing option --";

			init(&fracLeft, &fracRight);

			break;
		case 2:
			if (fracLeft == nullptr || fracRight == nullptr) {
				initBothError();
			} else {
				cout << "\n\n  ADDING option -";
				menuAdd(&fracLeft, &fracRight, &fracResult);
			}
			break;
		case 3:
			if (fracLeft == nullptr || fracRight == nullptr) {
				initBothError();
			} else {
				cout << "\n\n  SUBTRACTING option -";
				menuSubtract(&fracLeft, 
					&fracRight, &fracResult);
			}
			break;
		case 4:
			if (fracLeft == nullptr || fracRight == nullptr) {
				initBothError();
			} else {
				cout << "\n\n  MULTIPLYING option -";
				menuMultiply(&fracLeft, 
					&fracRight, &fracResult);
			}
			break;
		case 5:
			if ((fracLeft != nullptr) &&
				(fracRight != nullptr)) {
				cout << "\n\n  DIVIDING option -";
				menuDivide(&fracLeft, 
					&fracRight, &fracResult);
			} else {
				initBothError();
			}
			break;
		case 6:
			if (fracLeft == nullptr || fracRight == nullptr) {
				initBothError();
			} else {
				cout << "\n\n  PRINTING option -";
				menuPrint(&fracLeft, 
					&fracRight, &fracResult);
			}
			break;
		case 7:
			// quit
			cout << "\n\nHaving fun ...!\n";
			delete fracLeft;
			delete fracRight;
			delete fracResult;
			break;
		default:
			cout << "\nInvalid option.\n\n";
		}
	} while (menuChoice != 7);

	return 0;
}

// Improve readability in main menu
void initBothError() {
	cout << "\n\n  Please initialize both fractions first.\n\n";
}

void displayHeader() {
	cout << "CIS 25 - C++ Programming\nLaney College"
		"\nPete Wilcox"
		"\n\nAssignment Information --"
		"\n  Assignment Number: Lab 5,"
		"\n                     Exercise #1"
		"\n  Written by: Pete Wilcox"
		"\n  Due Date: 2015/11/10\n\n";
}

void displayMainMenu() {
	cout << "\n*********************"
		"\n*        MENU       *"
		"\n*                   *"
		"\n*  1. Initializing  *"
		"\n*  2. Adding        *"
		"\n*  3. Subtracting   *"
		"\n*  4. Multiplying   *"
		"\n*  5. Dividing      *"
		"\n*  6. Printing      *"
		"\n*  7. Quit          *"
		"\n*********************"
		"\nSelect an option (use integer value only): ";
}

void init(FractionPeteW** fracLeft, FractionPeteW** fracRight) {
	int newNum;
	int newDenom;
	int menuChoice;

	do {
		cout << "\n\n********************************"
			"\n*           INIT MENU          *"
			"\n*                              *"
			"\n*  1. Initialize Fraction 1.   *"
			"\n*  2. Initialize Fraction 2.   *"
			"\n*  3. Print fractions.         *"
			"\n*  4. Return to Previous MENU  *"
			"\n********************************"
			"\n\nPlease enter your choice (1, 2, 3, or 4): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\nPlease enter the numerator: ";
			cin >> newNum;
			do {
				cout << "\nPlease enter the denominator: ";
				cin >> newDenom;

				if (newDenom == 0) {
					cout << "\n  Denominator cannot be 0!";
				}
			} while (newDenom == 0);

			if ((*fracLeft) == nullptr) {
				(*fracLeft) = new FractionPeteW(newNum,
					newDenom);
			} else {
				(*fracLeft)->setBoth(newNum, newDenom);
			}
			break;
		case 2:
			cout << "\nPlease enter the numerator: ";
			cin >> newNum;
			do {
				cout << "\nPlease enter the denominator: ";
				cin >> newDenom;

				if (newDenom == 0) {
					cout << "\n  Denominator cannot be 0!";
				}
			} while (newDenom == 0);

			if ((*fracRight) == nullptr) {
				(*fracRight) = new FractionPeteW(newNum,
					newDenom);
			} else {
				(*fracRight)->setBoth(newNum, newDenom);
			}
			break;
		case 3:
			cout << "\n\nCurrent fractions:"
				"\n  Fraction 1: ";
			if ((*fracLeft) == nullptr) {
				cout << "null";
			} else {
				(*fracLeft)->print();
			}
			cout << "\n  Fraction 2: ";

			if ((*fracRight) == nullptr) {
				cout << "null";
			} else {
				(*fracRight)->print();
			}
			break;
		case 4:
			cout << "\nReturning to main menu.";
			break;
		default:
			cout << "\nWRONG OPTION!";
		}

	} while (menuChoice != 4);

}

void menuAdd(FractionPeteW** fracLeft,
	FractionPeteW** fracRight, FractionPeteW** fracResult) {
	int menuChoice;

	do {
		if (*fracResult == nullptr) {
			*fracResult = new FractionPeteW();
		}
		cout << "\n\n********************************"
			"\n*          ADDING MENU         *"
			"\n*                              *"
			"\n*  1. add() - Member           *"
			"\n*  2. add() - Stand Alone      *"
			"\n*  3. operator+() - Member     *"
			"\n*  4. Return to Previous MENU  *"
			"\n********************************"
			"\n Select an option (1, 2, 3,  or 4): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			

			cout << "\n\n  Calling member add()";
			
			(*fracResult)->add(**fracLeft, **fracRight);
			cout << "\n" << (**fracLeft) << " + " <<
				(**fracRight) << " = " << (**fracResult);
			break;
		case 2:
			
			cout << "\n\n  Calling stand alone add()";
			add(fracLeft, fracRight, fracResult);
			cout << "\n" << (**fracLeft) << " + " <<
				(**fracRight) << " = " << (**fracResult);
			break;
		case 3:
			cout << "\n\n  Calling operator+()";
			**fracResult = **fracLeft + **fracRight;
			cout << "\n" << (**fracLeft) << " + " <<
				(**fracRight) << " = " << (**fracResult);
			break;
		case 4:
			cout << "\n\n  Returning to previous menu.";
			break;
		default:
			cout << "\n\n  WRONG OPTION";
		}

	} while (menuChoice != 4);

}

void add(FractionPeteW** fracLeft, FractionPeteW** fracRight,
	FractionPeteW** fracResult) {
	if (*fracResult == nullptr) {
		(*fracResult) = new FractionPeteW(
			(*fracLeft)->getNum() * (*fracRight)->getDenom() +
			(*fracRight)->getNum() * (*fracLeft)->getDenom(),
			(*fracLeft)->getDenom() * (*fracRight)->getDenom());
	} else {
		(*fracResult)->setBoth(
			(*fracLeft)->getNum() * (*fracRight)->getDenom() +
			(*fracRight)->getNum() * (*fracLeft)->getDenom(),
			(*fracLeft)->getDenom() * (*fracRight)->getDenom());
	}
}

void menuSubtract(FractionPeteW** fracLeft,
	FractionPeteW** fracRight, FractionPeteW** fracResult) {
	int menuChoice;

	do {
		if (*fracResult == nullptr) {
			*fracResult = new FractionPeteW();
		}
		cout << "\n\n*********************************"
			"\n*        SUBTRACTING MENU       *"
			"\n*                               *"
			"\n*  1. subtract() - Member       *"
			"\n*  2. subtract() - Stand Alone  *"
			"\n*  3. operator-() - Member      *"
			"\n*  4. Return to Previous MENU   *"
			"\n*********************************"
			"\n Select an option (1, 2, 3, or 4): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\n\n  Calling member subtract()";
			
			(*fracResult)->subtract(**fracLeft, **fracRight);
			cout << "\n" << (**fracLeft) << " - " << 
				(**fracRight) << " = " << (**fracResult);
			break;
		case 2:
			cout << "\n\n  Calling stand alone subtract()";
			subtract(fracLeft, fracRight, fracResult);
			cout << "\n" << (**fracLeft) << " - " <<
				(**fracRight) << " = " << (**fracResult);
			break;
		case 3:
			cout << "\n\n  Calling operator-()";
			**fracResult = **fracLeft - **fracRight;
			cout << "\n" << (**fracLeft) << " - " <<
				(**fracRight) << " = " << (**fracResult);
			break;
		case 4:
			cout << "\n\n  Returning to main menu.";
			break;
		default:
			cout << "\n\n  WRONG OPTION";
		}

	} while (menuChoice != 4);

}

void subtract(FractionPeteW** fracLeft, 
	FractionPeteW** fracRight, FractionPeteW** fracResult) {
	if (fracResult == nullptr) {
		(*fracResult) = new FractionPeteW(
			(*fracLeft)->getNum() * (*fracRight)->getDenom() - 
			(*fracRight)->getNum() * (*fracLeft)->getDenom(), 
			(*fracLeft)->getDenom() * (*fracRight)->getDenom());
	} else {
		(*fracResult)->setBoth(
			(*fracLeft)->getNum() * (*fracRight)->getDenom() - 
			(*fracRight)->getNum() * (*fracLeft)->getDenom(), 
			(*fracLeft)->getDenom() * (*fracRight)->getDenom());
	}
}

void menuMultiply(FractionPeteW** fracLeft, 
	FractionPeteW** fracRight, FractionPeteW** fracResult) {
	int menuChoice;

	do {
		if (*fracResult == nullptr) {
			*fracResult = new FractionPeteW();
		}
		cout << "\n\n*********************************"
			"\n*        MULTIPLYING MENU       *"
			"\n*                               *"
			"\n*  1. multiply() - Member       *"
			"\n*  2. multiply() - Stand Alone  *"
			"\n*  3. operator*() - Member      *"
			"\n*  4. Return to Previous MENU   *"
			"\n*********************************"
			"\n Select an option (1, 2, 3, 4): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\n\n  Calling member multiply()";
		
			(*fracResult)->multiply(**fracLeft, **fracRight);
			cout << "\n" << (**fracLeft) << " * " << 
				(**fracRight) << " = " << (**fracResult);
			break;
		case 2:
			cout << "\n\n  Calling stand alone multiply()";
			multiply(fracLeft, fracRight, fracResult);
			cout << "\n" << (**fracLeft) << " * " << 
				(**fracRight) << " = " << (**fracResult);
			break;
		case 3:
			cout << "\n\n  Calling operator*()";
			**fracResult = **fracLeft * **fracRight;
			cout << "\n" << (**fracLeft) << " * " << 
				(**fracRight) << " = " << (**fracResult);
			break;
		case 4:
			cout << "\n\n  Returning to previous menu.";
			break;
		default:
			cout << "\n\n  WRONG OPTION";
		}

	} while (menuChoice != 4);

}

void multiply(FractionPeteW** fracLeft, 
	FractionPeteW** fracRight, FractionPeteW** fracResult) {
	if (fracResult == nullptr) {
		(*fracResult) = new FractionPeteW(
			(*fracLeft)->getNum() * (*fracRight)->getNum(), 
			(*fracLeft)->getDenom() * (*fracRight)->getDenom());
	} else {
		(*fracResult)->setBoth(
			(*fracLeft)->getNum() * (*fracRight)->getNum(), 
			(*fracLeft)->getDenom() * (*fracRight)->getDenom());
	}
}

void menuDivide(FractionPeteW** fracLeft, 
	FractionPeteW** fracRight, FractionPeteW** fracResult) {
	int menuChoice;

	do {
		if (*fracResult == nullptr) {
			*fracResult = new FractionPeteW();
		}
		cout << "\n\n********************************"
			"\n*        DIVIDING MENU         *"
			"\n*                              *"
			"\n*  1. divide() - Member        *"
			"\n*  2. divide() - Stand Alone   *"
			"\n*  3. operator/() - Member     *"
			"\n*  4. Return to Previous MENU  *"
			"\n********************************"
			"\n Select an option (1, 2, 3, or 4): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\n\n  Calling member divide()";
		
			(*fracResult)->divide(**fracLeft, **fracRight);
			cout << "\n" << (**fracLeft) << " / " << 
				(**fracRight) << " = " << (**fracResult);
			break;
		case 2:
			cout << "\n\n  Calling stand alone divide()";
			divide(fracLeft, fracRight, fracResult);
			cout << "\n" << (**fracLeft) << " / " << 
				(**fracRight) << " = " << (**fracResult);
			break;
		case 3:
			cout << "\n\n  Calling operator/()";
			**fracResult = **fracLeft / **fracRight;
			cout << "\n" << (**fracLeft) << " / " << 
				(**fracRight) << " = " << (**fracResult);
			break;
		case 4:
			cout << "\n\n  Returning to previous menu.";
			break;
		default:
			cout << "\n\n  WRONG OPTION";
		}

	} while (menuChoice != 4);

}

void divide(FractionPeteW** fracLeft, 
	FractionPeteW** fracRight, FractionPeteW** fracResult) {
	if (fracResult == nullptr) {
		(*fracResult) = new FractionPeteW(
			(*fracLeft)->getNum() * (*fracRight)->getDenom(), 
			(*fracLeft)->getDenom() * (*fracRight)->getNum());
	} else {
		(*fracResult)->setBoth(
			(*fracLeft)->getNum() * (*fracRight)->getDenom(), 
			(*fracLeft)->getDenom() * (*fracRight)->getNum());
	}
}

void menuPrint(FractionPeteW** fracLeft,
	FractionPeteW** fracRight, FractionPeteW** fracResult) {
	int menuChoice;

	do {
		cout << "\n\n********************************"
			"\n*         PRINTING MENU        *"
			"\n*  (leftOp, rightOp, Result)   *"
			"\n*  1. print() - Member         *"
			"\n*  2. print() - Stand Alone    *"
			"\n*  3. ostream << - Stand Alone *"
			"\n*  4. Return to Previous MENU  *"
			"\n********************************"
			"\nSelect an option (1, 2, 3, or 4): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\n\n Calling member print()\n  leftOp: ";
			(*fracLeft)->print();
			cout << "\n  rightOp: ";
			(*fracRight)->print();
			if (*fracResult != nullptr) {
				cout << "\n  Result: ";
				(*fracResult)->print();
			}
			break;
		case 2:
			cout << "\n\n Calling stand alone print()"
				"\n  leftOp: ";
			print(fracLeft);
			cout << "\n  rightOp: ";
			print(fracRight);
			if (*fracResult != nullptr) {
				cout << "\n  Result: ";
				print(fracResult);
			}
			break;
		case 3:
			cout << "\n\n Calling operator<<()\n  leftOp: "
				<< **fracLeft << "\n  rightOp: "
				<< **fracRight;
			if (*fracResult != nullptr) {
				cout << "\n  Result: " << **fracResult;
			}
			break;
		case 4:
			cout << "\n\n Returning to previous MENU";
			break;
		default:
			cout << "\n\n WRONG OPTION!";

		}
	} while (menuChoice != 4);

}

void print(FractionPeteW** f) {
	cout << (*f)->getNum() << "/" << (*f)->getDenom();
}

/* PROGRAM OUTPUT:
CIS 25 - C++ Programming
Laney College
Pete Wilcox

Assignment Information --
  Assignment Number: Lab 5,
                     Exercise #1
  Written by: Pete Wilcox
  Due Date: 2015/11/10

*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 8

Invalid option.


*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 2


  Please initialize both fractions first.


*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 1

  Initializing option --

********************************
*           INIT MENU          *
*                              *
*  1. Initialize Fraction 1.   *
*  2. Initialize Fraction 2.   *
*  3. Print fractions.         *
*  4. Return to Previous MENU  *
********************************

Please enter your choice (1, 2, 3, or 4): 1

Please enter the numerator: 1

Please enter the denominator: 2

Calling Fraction()

********************************
*           INIT MENU          *
*                              *
*  1. Initialize Fraction 1.   *
*  2. Initialize Fraction 2.   *
*  3. Print fractions.         *
*  4. Return to Previous MENU  *
********************************

Please enter your choice (1, 2, 3, or 4): 2

Please enter the numerator: 3

Please enter the denominator: 4

Calling Fraction()

********************************
*           INIT MENU          *
*                              *
*  1. Initialize Fraction 1.   *
*  2. Initialize Fraction 2.   *
*  3. Print fractions.         *
*  4. Return to Previous MENU  *
********************************

Please enter your choice (1, 2, 3, or 4): 3


Current fractions:
  Fraction 1: 1/2
  Fraction 2: 3/4

********************************
*           INIT MENU          *
*                              *
*  1. Initialize Fraction 1.   *
*  2. Initialize Fraction 2.   *
*  3. Print fractions.         *
*  4. Return to Previous MENU  *
********************************

Please enter your choice (1, 2, 3, or 4): 4

Returning to main menu.
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 2


ADDING option -

********************************
*          ADDING MENU         *
*                              *
*  1. add() - Member           *
*  2. add() - Stand Alone      *
*  3. operator+() - Member     *
*  4. Return to Previous MENU  *
********************************
Select an option (1, 2, 3,  or 4): 1


Calling member add()
Calling Fraction()
1/2 + 3/4 = 5/4

********************************
*          ADDING MENU         *
*                              *
*  1. add() - Member           *
*  2. add() - Stand Alone      *
*  3. operator+() - Member     *
*  4. Return to Previous MENU  *
********************************
Select an option (1, 2, 3,  or 4): 2


Calling stand alone add()
1/2 + 3/4 = 5/4

********************************
*          ADDING MENU         *
*                              *
*  1. add() - Member           *
*  2. add() - Stand Alone      *
*  3. operator+() - Member     *
*  4. Return to Previous MENU  *
********************************
Select an option (1, 2, 3,  or 4): 3


Calling operator+()
Calling Fraction()
Calling ~Fraction() on 5/4
1/2 + 3/4 = 5/4

********************************
*          ADDING MENU         *
*                              *
*  1. add() - Member           *
*  2. add() - Stand Alone      *
*  3. operator+() - Member     *
*  4. Return to Previous MENU  *
********************************
Select an option (1, 2, 3,  or 4): 4


Returning to previous menu.
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 3


  SUBTRACTING option -

*********************************
*        SUBTRACTING MENU       *
*                               *
*  1. subtract() - Member       *
*  2. subtract() - Stand Alone  *
*  3. operator-() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, or 4): 1


  Calling member subtract()
1/2 - 3/4 = -1/4

*********************************
*        SUBTRACTING MENU       *
*                               *
*  1. subtract() - Member       *
*  2. subtract() - Stand Alone  *
*  3. operator-() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, or 4): 2


  Calling stand alone subtract()
1/2 - 3/4 = -1/4

*********************************
*        SUBTRACTING MENU       *
*                               *
*  1. subtract() - Member       *
*  2. subtract() - Stand Alone  *
*  3. operator-() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, or 4): 3


  Calling operator-()
Calling Fraction()
Calling ~Fraction() on -1/4
1/2 - 3/4 = -1/4

*********************************
*        SUBTRACTING MENU       *
*                               *
*  1. subtract() - Member       *
*  2. subtract() - Stand Alone  *
*  3. operator-() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, or 4): 4


  Returning to main menu.
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 4


  MULTIPLYING option -

*********************************
*        MULTIPLYING MENU       *
*                               *
*  1. multiply() - Member       *
*  2. multiply() - Stand Alone  *
*  3. operator*() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, 4): 1


  Calling member multiply()
1/2 * 3/4 = 3/8

*********************************
*        MULTIPLYING MENU       *
*                               *
*  1. multiply() - Member       *
*  2. multiply() - Stand Alone  *
*  3. operator*() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, 4): 2


  Calling stand alone multiply()
1/2 * 3/4 = 3/8

*********************************
*        MULTIPLYING MENU       *
*                               *
*  1. multiply() - Member       *
*  2. multiply() - Stand Alone  *
*  3. operator*() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, 4): 3


  Calling operator*()
Calling Fraction()
Calling ~Fraction() on 3/8
1/2 * 3/4 = 3/8

*********************************
*        MULTIPLYING MENU       *
*                               *
*  1. multiply() - Member       *
*  2. multiply() - Stand Alone  *
*  3. operator*() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, 4): 4


  Returning to previous menu.
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 5


  DIVIDING option -

********************************
*        DIVIDING MENU         *
*                              *
*  1. divide() - Member        *
*  2. divide() - Stand Alone   *
*  3. operator/() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3, or 4): 1


  Calling member divide()
1/2 / 3/4 = 2/3

********************************
*        DIVIDING MENU         *
*                              *
*  1. divide() - Member        *
*  2. divide() - Stand Alone   *
*  3. operator/() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3, or 4): 2


  Calling stand alone divide()
1/2 / 3/4 = 2/3

********************************
*        DIVIDING MENU         *
*                              *
*  1. divide() - Member        *
*  2. divide() - Stand Alone   *
*  3. operator/() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3, or 4): 3


  Calling operator/()
Calling Fraction()
Calling ~Fraction() on 2/3
1/2 / 3/4 = 2/3

********************************
*        DIVIDING MENU         *
*                              *
*  1. divide() - Member        *
*  2. divide() - Stand Alone   *
*  3. operator/() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3, or 4): 4


  Returning to previous menu.
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only):6


  PRINTING option -

********************************
*         PRINTING MENU        *
*  (leftOp, rightOp, Result)   *
*  1. print() - Member         *
*  2. print() - Stand Alone    *
*  3. ostream << - Stand Alone *
*  4. Return to Previous MENU  *
********************************
Select an option (1, 2, 3, or 4): 1


 Calling member print()
  leftOp: 1/2
  rightOp: 3/4
  Result: 2/3

********************************
*         PRINTING MENU        *
*  (leftOp, rightOp, Result)   *
*  1. print() - Member         *
*  2. print() - Stand Alone    *
*  3. ostream << - Stand Alone *
*  4. Return to Previous MENU  *
********************************
Select an option (1, 2, 3, or 4): 2


 Calling stand alone print()
  leftOp: 1/2
  rightOp: 3/4
  Result: 2/3

********************************
*         PRINTING MENU        *
*  (leftOp, rightOp, Result)   *
*  1. print() - Member         *
*  2. print() - Stand Alone    *
*  3. ostream << - Stand Alone *
*  4. Return to Previous MENU  *
********************************
Select an option (1, 2, 3, or 4): 3


 Calling operator<<()
  leftOp: 1/2
  rightOp: 3/4
  Result: 2/3

********************************
*         PRINTING MENU        *
*  (leftOp, rightOp, Result)   *
*  1. print() - Member         *
*  2. print() - Stand Alone    *
*  3. ostream << - Stand Alone *
*  4. Return to Previous MENU  *
********************************
Select an option (1, 2, 3, or 4): 4


 Returning to previous MENU
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 1

  Initializing option --

********************************
*           INIT MENU          *
*                              *
*  1. Initialize Fraction 1.   *
*  2. Initialize Fraction 2.   *
*  3. Print fractions.         *
*  4. Return to Previous MENU  *
********************************

Please enter your choice (1, 2, 3, or 4): 1

Please enter the numerator: -5

Please enter the denominator: 9


********************************
*           INIT MENU          *
*                              *
*  1. Initialize Fraction 1.   *
*  2. Initialize Fraction 2.   *
*  3. Print fractions.         *
*  4. Return to Previous MENU  *
********************************

Please enter your choice (1, 2, 3, or 4): 2

Please enter the numerator: 7

Please enter the denominator: 11


********************************
*           INIT MENU          *
*                              *
*  1. Initialize Fraction 1.   *
*  2. Initialize Fraction 2.   *
*  3. Print fractions.         *
*  4. Return to Previous MENU  *
********************************

Please enter your choice (1, 2, 3, or 4): 3


Current fractions:
  Fraction 1: -5/9
  Fraction 2: 7/11

********************************
*           INIT MENU          *
*                              *
*  1. Initialize Fraction 1.   *
*  2. Initialize Fraction 2.   *
*  3. Print fractions.         *
*  4. Return to Previous MENU  *
********************************

Please enter your choice (1, 2, 3, or 4): 4

Returning to main menu.
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 2


  ADDING option -

********************************
*          ADDING MENU         *
*                              *
*  1. add() - Member           *
*  2. add() - Stand Alone      *
*  3. operator+() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3,  or 4): 1


  Calling member add()
-5/9 + 7/11 = 8/99

********************************
*          ADDING MENU         *
*                              *
*  1. add() - Member           *
*  2. add() - Stand Alone      *
*  3. operator+() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3,  or 4): 2


  Calling stand alone add()
-5/9 + 7/11 = 8/99

********************************
*          ADDING MENU         *
*                              *
*  1. add() - Member           *
*  2. add() - Stand Alone      *
*  3. operator+() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3,  or 4): 3


  Calling operator+()
Calling Fraction()
Calling ~Fraction() on 8/99
-5/9 + 7/11 = 8/99

********************************
*          ADDING MENU         *
*                              *
*  1. add() - Member           *
*  2. add() - Stand Alone      *
*  3. operator+() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3,  or 4): 4


  Returning to previous menu.
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 3


  SUBTRACTING option -

*********************************
*        SUBTRACTING MENU       *
*                               *
*  1. subtract() - Member       *
*  2. subtract() - Stand Alone  *
*  3. operator-() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, or 4): 1


  Calling member subtract()
-5/9 - 7/11 = -118/99

*********************************
*        SUBTRACTING MENU       *
*                               *
*  1. subtract() - Member       *
*  2. subtract() - Stand Alone  *
*  3. operator-() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, or 4): 2


  Calling stand alone subtract()
-5/9 - 7/11 = -118/99

*********************************
*        SUBTRACTING MENU       *
*                               *
*  1. subtract() - Member       *
*  2. subtract() - Stand Alone  *
*  3. operator-() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, or 4): 3


  Calling operator-()
Calling Fraction()
Calling ~Fraction() on -118/99
-5/9 - 7/11 = -118/99

*********************************
*        SUBTRACTING MENU       *
*                               *
*  1. subtract() - Member       *
*  2. subtract() - Stand Alone  *
*  3. operator-() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, or 4): 4


  Returning to main menu.
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 4


  MULTIPLYING option -

*********************************
*        MULTIPLYING MENU       *
*                               *
*  1. multiply() - Member       *
*  2. multiply() - Stand Alone  *
*  3. operator*() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, 4): 1


  Calling member multiply()
-5/9 * 7/11 = -35/99

*********************************
*        MULTIPLYING MENU       *
*                               *
*  1. multiply() - Member       *
*  2. multiply() - Stand Alone  *
*  3. operator*() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, 4): 2


  Calling stand alone multiply()
-5/9 * 7/11 = -35/99

*********************************
*        MULTIPLYING MENU       *
*                               *
*  1. multiply() - Member       *
*  2. multiply() - Stand Alone  *
*  3. operator*() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, 4): 3


  Calling operator*()
Calling Fraction()
Calling ~Fraction() on -35/99
-5/9 * 7/11 = -35/99

*********************************
*        MULTIPLYING MENU       *
*                               *
*  1. multiply() - Member       *
*  2. multiply() - Stand Alone  *
*  3. operator*() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, 4): 4


  Returning to previous menu.
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 5


  DIVIDING option -

********************************
*        DIVIDING MENU         *
*                              *
*  1. divide() - Member        *
*  2. divide() - Stand Alone   *
*  3. operator/() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3, or 4): 1


  Calling member divide()
-5/9 / 7/11 = -55/63

********************************
*        DIVIDING MENU         *
*                              *
*  1. divide() - Member        *
*  2. divide() - Stand Alone   *
*  3. operator/() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3, or 4): 2


  Calling stand alone divide()
-5/9 / 7/11 = -55/63

********************************
*        DIVIDING MENU         *
*                              *
*  1. divide() - Member        *
*  2. divide() - Stand Alone   *
*  3. operator/() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3, or 4): 3


  Calling operator/()
Calling Fraction()
Calling ~Fraction()

-5/9 / 7/11 = -55/63

********************************
*        DIVIDING MENU         *
*                              *
*  1. divide() - Member        *
*  2. divide() - Stand Alone   *
*  3. operator/() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3, or 4): 4


  Returning to previous menu.
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 6


  PRINTING option -

********************************
*         PRINTING MENU        *
*  (leftOp, rightOp, Result)   *
*  1. print() - Member         *
*  2. print() - Stand Alone    *
*  3. ostream << - Stand Alone *
*  4. Return to Previous MENU  *
********************************
Select an option (1, 2, 3, or 4): 1


 Calling member print()
  leftOp: -5/9
  rightOp: 7/11
  Result: -55/63

********************************
*         PRINTING MENU        *
*  (leftOp, rightOp, Result)   *
*  1. print() - Member         *
*  2. print() - Stand Alone    *
*  3. ostream << - Stand Alone *
*  4. Return to Previous MENU  *
********************************
Select an option (1, 2, 3, or 4): 2


 Calling stand alone print()
  leftOp: -5/9
  rightOp: 7/11
  Result: -55/63

********************************
*         PRINTING MENU        *
*  (leftOp, rightOp, Result)   *
*  1. print() - Member         *
*  2. print() - Stand Alone    *
*  3. ostream << - Stand Alone *
*  4. Return to Previous MENU  *
********************************
Select an option (1, 2, 3, or 4): 3


 Calling operator<<()
  leftOp: -5/9
  rightOp: 7/11
  Result: -55/63

********************************
*         PRINTING MENU        *
*  (leftOp, rightOp, Result)   *
*  1. print() - Member         *
*  2. print() - Stand Alone    *
*  3. ostream << - Stand Alone *
*  4. Return to Previous MENU  *
********************************
Select an option (1, 2, 3, or 4): 4


 Returning to previous MENU
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 1

  Initializing option --

********************************
*           INIT MENU          *
*                              *
*  1. Initialize Fraction 1.   *
*  2. Initialize Fraction 2.   *
*  3. Print fractions.         *
*  4. Return to Previous MENU  *
********************************

Please enter your choice (1, 2, 3, or 4): 1

Please enter the numerator: 8

Please enter the denominator: 17


********************************
*           INIT MENU          *
*                              *
*  1. Initialize Fraction 1.   *
*  2. Initialize Fraction 2.   *
*  3. Print fractions.         *
*  4. Return to Previous MENU  *
********************************

Please enter your choice (1, 2, 3, or 4): 2

Please enter the numerator: 6

Please enter the denominator: 23


********************************
*           INIT MENU          *
*                              *
*  1. Initialize Fraction 1.   *
*  2. Initialize Fraction 2.   *
*  3. Print fractions.         *
*  4. Return to Previous MENU  *
********************************

Please enter your choice (1, 2, 3, or 4): 3


Current fractions:
  Fraction 1: 8/17
  Fraction 2: 6/23

********************************
*           INIT MENU          *
*                              *
*  1. Initialize Fraction 1.   *
*  2. Initialize Fraction 2.   *
*  3. Print fractions.         *
*  4. Return to Previous MENU  *
********************************

Please enter your choice (1, 2, 3, or 4): 4

Returning to main menu.
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 2


  ADDING option -

********************************
*          ADDING MENU         *
*                              *
*  1. add() - Member           *
*  2. add() - Stand Alone      *
*  3. operator+() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3,  or 4): 1


  Calling member add()
8/17 + 6/23 = 286/391

********************************
*          ADDING MENU         *
*                              *
*  1. add() - Member           *
*  2. add() - Stand Alone      *
*  3. operator+() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3,  or 4): 2


  Calling stand alone add()
8/17 + 6/23 = 286/391

********************************
*          ADDING MENU         *
*                              *
*  1. add() - Member           *
*  2. add() - Stand Alone      *
*  3. operator+() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3,  or 4): 3


  Calling operator+()
Calling Fraction()
Calling ~Fraction() on 286/391
8/17 + 6/23 = 286/391

********************************
*          ADDING MENU         *
*                              *
*  1. add() - Member           *
*  2. add() - Stand Alone      *
*  3. operator+() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3,  or 4): 4


  Returning to previous menu.
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 3


  SUBTRACTING option -

*********************************
*        SUBTRACTING MENU       *
*                               *
*  1. subtract() - Member       *
*  2. subtract() - Stand Alone  *
*  3. operator-() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, or 4): 1


  Calling member subtract()
8/17 - 6/23 = 82/391

*********************************
*        SUBTRACTING MENU       *
*                               *
*  1. subtract() - Member       *
*  2. subtract() - Stand Alone  *
*  3. operator-() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, or 4): 2


  Calling stand alone subtract()
8/17 - 6/23 = 82/391

*********************************
*        SUBTRACTING MENU       *
*                               *
*  1. subtract() - Member       *
*  2. subtract() - Stand Alone  *
*  3. operator-() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, or 4): 3


  Calling operator-()
Calling Fraction()
Calling ~Fraction() on 82/391
8/17 - 6/23 = 82/391

*********************************
*        SUBTRACTING MENU       *
*                               *
*  1. subtract() - Member       *
*  2. subtract() - Stand Alone  *
*  3. operator-() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, or 4): 4


  Returning to main menu.
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 4


  MULTIPLYING option -

*********************************
*        MULTIPLYING MENU       *
*                               *
*  1. multiply() - Member       *
*  2. multiply() - Stand Alone  *
*  3. operator*() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, 4): 1


  Calling member multiply()
8/17 * 6/23 = 48/391

*********************************
*        MULTIPLYING MENU       *
*                               *
*  1. multiply() - Member       *
*  2. multiply() - Stand Alone  *
*  3. operator*() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, 4): 2


  Calling stand alone multiply()
8/17 * 6/23 = 48/391

*********************************
*        MULTIPLYING MENU       *
*                               *
*  1. multiply() - Member       *
*  2. multiply() - Stand Alone  *
*  3. operator*() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, 4): 3


  Calling operator*()
Calling Fraction()
Calling ~Fraction() on 48/391
8/17 * 6/23 = 48/391

*********************************
*        MULTIPLYING MENU       *
*                               *
*  1. multiply() - Member       *
*  2. multiply() - Stand Alone  *
*  3. operator*() - Member      *
*  4. Return to Previous MENU   *
*********************************
 Select an option (1, 2, 3, 4): 4


  Returning to previous menu.
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 5


  DIVIDING option -

********************************
*        DIVIDING MENU         *
*                              *
*  1. divide() - Member        *
*  2. divide() - Stand Alone   *
*  3. operator/() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3, or 4): 1


  Calling member divide()
8/17 / 6/23 = 92/51

********************************
*        DIVIDING MENU         *
*                              *
*  1. divide() - Member        *
*  2. divide() - Stand Alone   *
*  3. operator/() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3, or 4): 2


  Calling stand alone divide()
8/17 / 6/23 = 92/51

********************************
*        DIVIDING MENU         *
*                              *
*  1. divide() - Member        *
*  2. divide() - Stand Alone   *
*  3. operator/() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3, or 4): 3


  Calling operator/()
Calling Fraction()
Calling ~Fraction() on 92/51
8/17 / 6/23 = 92/51

********************************
*        DIVIDING MENU         *
*                              *
*  1. divide() - Member        *
*  2. divide() - Stand Alone   *
*  3. operator/() - Member     *
*  4. Return to Previous MENU  *
********************************
 Select an option (1, 2, 3, or 4): 4


  Returning to previous menu.
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 6


  PRINTING option -

********************************
*         PRINTING MENU        *
*  (leftOp, rightOp, Result)   *
*  1. print() - Member         *
*  2. print() - Stand Alone    *
*  3. ostream << - Stand Alone *
*  4. Return to Previous MENU  *
********************************
Select an option (1, 2, 3, or 4): 1


 Calling member print()
  leftOp: 8/17
  rightOp: 6/23
  Result: 92/51

********************************
*         PRINTING MENU        *
*  (leftOp, rightOp, Result)   *
*  1. print() - Member         *
*  2. print() - Stand Alone    *
*  3. ostream << - Stand Alone *
*  4. Return to Previous MENU  *
********************************
Select an option (1, 2, 3, or 4): 2


 Calling stand alone print()
  leftOp: 8/17
  rightOp: 6/23
  Result: 92/51

********************************
*         PRINTING MENU        *
*  (leftOp, rightOp, Result)   *
*  1. print() - Member         *
*  2. print() - Stand Alone    *
*  3. ostream << - Stand Alone *
*  4. Return to Previous MENU  *
********************************
Select an option (1, 2, 3, or 4): 3


 Calling operator<<()
  leftOp: 8/17
  rightOp: 6/23
  Result: 92/51

********************************
*         PRINTING MENU        *
*  (leftOp, rightOp, Result)   *
*  1. print() - Member         *
*  2. print() - Stand Alone    *
*  3. ostream << - Stand Alone *
*  4. Return to Previous MENU  *
********************************
Select an option (1, 2, 3, or 4): 4


 Returning to previous MENU
*********************
*        MENU       *
*                   *
*  1. Initializing  *
*  2. Adding        *
*  3. Subtracting   *
*  4. Multiplying   *
*  5. Dividing      *
*  6. Printing      *
*  7. Quit          *
*********************
Select an option (use integer value only): 7


Having fun ...!

Calling ~Fraction() on 8/17

Calling ~Fraction() on 6/23

Calling ~Fraction() on 92/51
*/

/* COMMENTS:

2015/11/10:
This project was not very inspired. Fractions are a very
unimaginative way to introduce classes when easier-to-understand
objects exist. Performing the operations in the lab assignment
necessitate forgetting how math properly functions - it doesn't
make sense that the program would output 4/1 when the user puts
that in, what makes sense is for the fraction to be reduced to
a whole number, but instead we are required to carry around the
inane num/denom configuration despite it not being appropriate.

The specification for the output was poorly written and obviously
not a lot of thought was put into it. It's quite astonishing to
see the chair of the department operate a 4-credit course that
supposedly transfers to the U.C. system in this fashion, and it
does not speak well of Laney's CIS department.

I don't know what intelligent comments could be made about the
logic of this code. It is very basic stuff and does not reflect
the abilities someone should have once they have progressed to
this level. Having to spend the time required to complete this 
lab assignment is extremely frustrating.
*/