/**
  * Program Name: CIS25Fall2015PeteWilcoxLab5Ex1.cpp
  * Discussion:   Lab #5 Exercise #1
  * Written by:   Pete Wilcox
  * Date:         2015/11/06
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
	cout << "CIS 25 � C++ Programming\nLaney College"
		"\nPete Wilcox"
		"\n\nAssignment Information --"
		"\n  Assignment Number: Lab 5,"
		"\n                     Exercise #1"
		"\n  Written by: Pete Wilcox"
		"\n  Due Date: 2015/11/06\n\n";
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
			if (*fracResult == nullptr) {
				*fracResult = new FractionPeteW();
			}

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
			if (*fracResult == nullptr) {
				*fracResult = new FractionPeteW();
			}

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
			if (*fracResult == nullptr) {
				*fracResult = new FractionPeteW();
			}

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
			if (*fracResult == nullptr) {
				*fracResult = new FractionPeteW();
			}

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


*/

/* COMMENTS:

2015/11/06:

*/