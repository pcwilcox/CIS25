/**
  * Program Name: CIS25Fall2015PeteWilcoxLab5Ex1.cpp
  * Discussion:   Lab #5 Exercise #1
  * Written by:   Pete Wilcox
  * Date:         2015/11/06
  */


  /* At some point, refactor the error message somehow */

#include <iostream>
#include "fractionPeteW.h"

using namespace std;

void displayHeader(void);
void displayMenuMain(void);
void initFraction(FractionPeteW**, FractionPeteW**);
void initBothError(void);
void displayMenuAdd(FractionPeteW**, FractionPeteW**, FractionPeteW**);
void displayMenuSubtract(FractionPeteW**, FractionPeteW**, FractionPeteW**);
void displayMenuDivide(FractionPeteW**, FractionPeteW**, FractionPeteW**);
void displayMenuMultiply(FractionPeteW**, FractionPeteW**, FractionPeteW**);
void add(FractionPeteW**, FractionPeteW**, FractionPeteW**);
void subtract(FractionPeteW**, FractionPeteW**, FractionPeteW**);
void multiply(FractionPeteW**, FractionPeteW**, FractionPeteW**);
void divide(FractionPeteW**, FractionPeteW**, FractionPeteW**);
void print(FractionPeteW**, FractionPeteW**, FractionPeteW**);

int main() {
	int menuChoice;
	FractionPeteW* fracLeft = nullptr;
	FractionPeteW* fracRight = nullptr;
	FractionPeteW* fracResult = nullptr;

	displayHeader();

	do {
		displayMenuMain();
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\n  Initializing option --";

			initFraction(&fracLeft, &fracRight);

			break;
		case 2:
			if ((fracLeft != nullptr) && (fracRight != nullptr)) {
				cout << "\n\n  ADDING option -";
				displayMenuAdd(&fracLeft, &fracRight, &fracResult);
			} else {
				initBothError();
			}
			break;
		case 3:
			if ((fracLeft != nullptr) && (fracRight != nullptr)) {
				cout << "\n\n  SUBTRACTING option -";
				subtract(&fracLeft, &fracRight, &fracResult);
			} else {
				initBothError();
			}
			break;
		case 4:
			if ((fracLeft != nullptr) && (fracRight != nullptr)) {
				cout << "\n\n  MULTIPLYING option -";
				multiply(&fracLeft, &fracRight, &fracResult);
			} else {
				initBothError();
			}			break;
		case 5:
			if ((fracLeft != nullptr) && (fracRight != nullptr)) {
				cout << "\n\n  DIVIDING option -";
				divide(&fracLeft, &fracRight, &fracResult);
			} else {
				initBothError();
			}			break;
		case 6:
			if ((fracLeft != nullptr) && (fracRight != nullptr)) {
				cout << "\n\n  PRINTING option -";
				print(&fracLeft, &fracRight, &fracResult);
			} else {
				initBothError();
			}			break;
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

void initBothError() {
	cout << "\n\n  Please initialize both fractions"
		" first.\n\n";
}

void displayHeader() {
	cout << "CIS 25 – C++ Programming\nLaney College"
		"\nPete Wilcox"
		"\n\nAssignment Information --"
		"\n  Assignment Number: Lab 5,"
		"\n                     Exercise #1"
		"\n  Written by: Pete Wilcox"
		"\n  Due Date: 2015/11/06";
}

void displayMenuMain() {
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

void initFraction(FractionPeteW** fracLeft, FractionPeteW** fracRight) {
	int newNum;
	int newDenom;
	int choice;

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
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "\nPlease enter the numerator: ";
			cin >> newNum;
			cout << "\nPlease enter the denominator: ";
			cin >> newDenom;

			if ((*fracLeft) == nullptr) {
				(*fracLeft) = new FractionPeteW(newNum, newDenom);
			} else {
				(*fracLeft)->setNum(newNum);
				(*fracRight)->setDenom(newDenom);
			}
			break;
		case 2:
			cout << "\nPlease enter the numerator: ";
			cin >> newNum;
			cout << "\nPlease enter the denominator: ";
			cin >> newDenom;

			if ((*fracRight) == nullptr) {
				(*fracRight) = new FractionPeteW(newNum, newDenom);
			} else {
				(*fracRight)->setNum(newNum);
				(*fracRight)->setDenom(newDenom);
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

		case 4:
			cout << "\nReturning to main menu.";
			break;
		default:
			cout << "\nWRONG OPTION!";
		}

	} while (choice != 4);

}

void displayMenuAdd(FractionPeteW** fracLeft, FractionPeteW** fracRight,
	FractionPeteW** fracResult) {
	int menuChoice;

	do {
		cout << "\n\n********************************"
			"\n*          ADDING MENU         *"
			"\n*                              *"
			"\n*  1. add() - Member           *"
			"\n*  2. add() - Stand Alone      *"
			"\n*  3. operator+() - Member     *"
			"\n*  4. Print                    *"
			"\n*  5. Return to Previous MENU  *"
			"\n********************************"
			"\n Select an option (1, 2, 3, 4, or 5): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\n\n  Calling member add()";
			if (*fracResult == nullptr) {
				*fracResult = new FractionPeteW();
			}

			(*fracResult)->add(**fracLeft, **fracRight);
			break;
		case 2:
			cout << "\n\n  Calling stand alone add()";
			add(fracLeft, fracRight, fracResult);
			break;
		case 3:
			cout << "\n\n  Calling operator+()";
			**fracResult = **fracLeft + **fracRight;
			break;
		case 4:
			cout << endl << **fracResult;
			break;
		case 5:
			break;
		default:
			cout << "\n\n  WRONG OPTION";
		}

	} while (menuChoice != 5);

}

void add(FractionPeteW** fracLeft, FractionPeteW** fracRight,
	FractionPeteW** fracResult) {
	if (fracResult == nullptr) {
		(*fracResult) = new FractionPeteW((*fracLeft)->getNum() * (*fracRight)->getDenom() + (*fracRight)->getNum() * (*fracLeft)->getDenom(), (*fracLeft)->getDenom() * (*fracRight)->getDenom());
	} else {
		(*fracResult)->setNum((*fracLeft)->getNum() * (*fracRight)->getDenom() + (*fracRight)->getNum() * (*fracLeft)->getDenom());
		(*fracResult)->setDenom((*fracLeft)->getDenom() * (*fracRight)->getDenom());
	}
}

void subtract(FractionPeteW** fracLeft, FractionPeteW** fracRight,
	FractionPeteW** fracResult) {
	if (fracResult == nullptr) {
		(*fracResult) = new FractionPeteW((*fracLeft)->getNum() * (*fracRight)->getDenom() - (*fracRight)->getNum() * (*fracLeft)->getDenom(), (*fracLeft)->getDenom() * (*fracRight)->getDenom());
	} else {
		(*fracResult)->setNum((*fracLeft)->getNum() * (*fracRight)->getDenom() - (*fracRight)->getNum() * (*fracLeft)->getDenom());
		(*fracResult)->setDenom((*fracLeft)->getDenom() * (*fracRight)->getDenom());
	}
}

void multiply(FractionPeteW** fracLeft, FractionPeteW** fracRight,
	FractionPeteW** fracResult) {
	if (fracResult == nullptr) {
		(*fracResult) = new FractionPeteW((*fracLeft)->getNum() * (*fracRight)->getNum(), (*fracLeft)->getDenom() * (*fracRight)->getDenom());
	} else {
		(*fracResult)->setNum((*fracLeft)->getNum() * (*fracRight)->getNum());
		(*fracResult)->setDenom((*fracLeft)->getDenom() * (*fracRight)->getDenom());
	}
}

void divide(FractionPeteW** fracLeft, FractionPeteW** fracRight,
	FractionPeteW** fracResult) {
	if (fracResult == nullptr) {
		(*fracResult) = new FractionPeteW((*fracLeft)->getNum() * (*fracRight)->getDenom(), (*fracLeft)->getDenom() * (*fracRight)->getNum());
	} else {
		(*fracResult)->setNum((*fracLeft)->getNum() * (*fracRight)->getDenom());
		(*fracResult)->setDenom((*fracLeft)->getDenom() * (*fracRight)->getNum());
	}
}

void print(FractionPeteW** fracLeft, FractionPeteW** fracRight,
	FractionPeteW** fracResult) {
	int menuChoice;

	do {
		cout << "\n\n********************************"
			"\n*         PRINTING MENU        *"
			"\n*  (leftOp, rightOp, result)   *"
			"\n*  1. print() - Member         *"
			"\n*  2. print() - Stand Alone    *"
			"\n*  3. ostream << - Stand Alone *"
			"\n*  4. Return to Previous MENU  *"
			"\n********************************"
			"\nSelect an option *1, 2, 3, or 4): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\n\n Calling member print()";
				"\n  leftOp: ";
			(*fracLeft)->print();
			cout << "\n  rightOp: ";
			(*fracRight)->print();
			cout << "\n  result: ";
			(*fracResult)->print();
			break;
		case 2:

		}
	}

}