/**
  * Program Name: CIS25Fall2015PeteWilcoxLab5Ex1.cpp
  * Discussion:   Lab #5 Exercise #1
  * Written by:   Pete Wilcox
  * Date:         2015/11/06
  */

#include <iostream>
#include "fractionPeteW.h"

using namespace std;

void displayHeader(void);
void displayMenu(void);
void initFraction(Fraction**, Fraction**);
void initBothError(void);

int main() {
	int menuChoice;
	Fraction* frac1 = nullptr;
	Fraction* frac2 = nullptr;

	displayHeader();

	do {
		displayMenu();
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\n  Initializing option --";
			
			initFraction(&frac1, &frac2);

			break;
		case 2:
			if ((frac1 != nullptr) && (frac2 != nullptr)) {
				// add
			} else {
				initBothError();
			}
			break;
		case 3:
			if ((frac1 != nullptr) && (frac2 != nullptr)) {
				// subtract
			} else {
				initBothError();
			}
			break;
		case 4:
			if ((frac1 != nullptr) && (frac2 != nullptr)) {
				// multiply
			} else {
				initBothError();
			}			break;
		case 5:
			if ((frac1 != nullptr) && (frac2 != nullptr)) {
				// divide
			} else {
				initBothError();
			}			break;
		case 6:
			if ((frac1 != nullptr) && (frac2 != nullptr)) {
				// print
			} else {
				initBothError();
			}			break;
		case 7:
			// quit
			cout << "\n\nHaving fun ...!\n";
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

void initFraction(Fraction** fracPtr1, Fraction** fracPtr2) {
	int newNum, newDenom;
	bool finished = false;
	while (finished == false) {
		cout << "\n\nCurrent fractions:"
			"\n  Fraction 1: ";
		if (fracPtr1 == nullptr) {
			cout << "null";
		} else {
			(*fracPtr1)->print();
		}
		cout << "\n  Fraction 2: ";

		if (fracPtr2 == nullptr) {
			cout << "null";
		} else {
			(*fracPtr2)->print();
		}


	}

}