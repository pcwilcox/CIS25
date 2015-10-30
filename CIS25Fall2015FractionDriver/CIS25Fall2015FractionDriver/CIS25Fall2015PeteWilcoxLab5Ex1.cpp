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
void displayMenu(void);
void initFraction(Fraction**, Fraction**);
void initBothError(void);
void displayMenuAdd(Fraction**, Fraction**, Fraction**);
void displayMenuSubtract(Fraction**, Fraction**, Fraction**);
void displayMenuDivide(Fraction**, Fraction**, Fraction**);
void displayMenuMultiply(Fraction**, Fraction**, Fraction**);
void add(Fraction**, Fraction**, Fraction**);
void subtract(Fraction**, Fraction**, Fraction**);
void multiply(Fraction**, Fraction**, Fraction**);
void divide(Fraction**, Fraction**, Fraction**);
void print(Fraction**, Fraction**, Fraction**);

int main() {
	int menuChoice;
	Fraction* fracLeft = nullptr;
	Fraction* fracRight = nullptr;
	Fraction* fracResult = nullptr;

	displayHeader();

	do {
		displayMenu();
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\n  Initializing option --";
			
			initFraction(&fracLeft, &fracRight);

			break;
		case 2:
			if ((fracLeft != nullptr) && (fracRight != nullptr)) {
				cout << "\n\n  ADDING option -";
				add(&fracLeft, &fracRight, &fracResult);
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

void displayMenu() {
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

void initFraction(Fraction** fracLeft, Fraction** fracRight) {
	int newNum;
	int newDenom;
	int choice;
	bool finished = false;

	while (finished == false) {
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

		cout << "\nWhich fraction would you like to initialize?"
			"\n  1. Initialize Fraction 1."
			"\n  2. Initialize Fraction 2."
			"\n  3. Return to previous menu."
			"\n\nPlease enter your choice: ";
		cin >> choice;
		
		switch (choice) {
		case 1:
			cout << "\nPlease enter the numerator: ";
			cin >> newNum;
			cout << "\nPlease enter the denominator: ";
			cin >> newDenom;

			if ((*fracLeft) == nullptr) {
				(*fracLeft) = new Fraction(newNum, newDenom);
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
				(*fracRight) = new Fraction(newNum, newDenom);
			} else {
				(*fracRight)->setNum(newNum);
				(*fracRight)->setDenom(newDenom);
			}
			break;
		case 3:
			cout << "\nReturning to main menu.";
			finished = true;
			break;
		default:
			cout << "\nInvalid option.";
		}

	}

}

void displayMenuAdd(Fraction** fracLeft, Fraction** fracRight,
	Fraction** fracResult) {
	int menuChoice;

	do {
		cout << "\n\n********************************"
			"\n*          ADDING MENU         *"
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

		}
	} while (menuChoice != 5);
	
}

void subtract(Fraction** fracLeft, Fraction** fracRight,
	Fraction** fracResult) {

}

void multiply(Fraction** fracLeft, Fraction** fracRight,
	Fraction** fracResult) {

}

void divide(Fraction** fracLeft, Fraction** fracRight,
	Fraction** fracResult) {

}

void print(Fraction** fracLeft, Fraction** fracRight,
	Fraction** fracResult) {

}