/**
  * Program Name: PointPeteWUtilities.cpp
  * Discussion:   PointPeteW Class --
  *                 Driver CPP
  * Written by:   Pete Wilcox
  * Date:         2015/11/24
  */

#include <iostream>
#include "fractionPeteW.h"
#include "PointPeteW.h"
#include "PointPeteWUtilities.h"

using namespace std;

void displayHeader() {
	cout << "CIS 25 - C++ Programming\n"
		"Laney College\n"
		"Pete Wilcox\n"
		"\n"
		"Assignment Information --\n"
		"  Assignment Number:  Lab 6,\n"
		"                      Exercise #1\n"
		"  Written by:         Pete Wilcox\n"
		"  Due Date:           2015/11/24\n";
}

void menuMain() {
	cout << "\n\n********************\n"
		"*    MENU Point    *\n"
		"*  1. Initializing *\n"
		"*  2. Moving       *\n"
		"*  3. Flipping     *\n"
		"*  4. Printing     *\n"
		"*  5. Quitting     *\n"
		"********************\n"
		"Select an option (use integer value only): ";
}

void menuInit(PointPeteW** point) {
	int menuChoice;
	int num;
	int denom;

	do {
		cout << "\n\n  ******************************\n"
			"  * MENU InitPoint             *\n"
			"  *  1. Set point X-coordinate *\n"
			"  *  2. Set point Y-coordinate *\n"
			"  *  3. Printing               *\n"
			"  *  4. Returning              *\n"
			"  ******************************\n"
			"  Please select an option (integer value only): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\n  Please enter the numerator: ";
			cin >> num;
			do {
				cout << "\n  Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\n    Denominator cannot be 0!";
				}
			} while (denom == 0);

			if ((*point) == nullptr) {
				(*point) = new 
					PointPeteW(FractionPeteW(num, denom));
			} else {
				(*point)->setX(num, denom);
			}
			break;
		case 2:
			cout << "\n  Please enter the numerator: ";
			cin >> num;
			do {
				cout << "\n  Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\n    Denominator cannot be 0!";
				}
			} while (denom == 0);

			if ((*point) == nullptr) {
				(*point) = new 
					PointPeteW(FractionPeteW(num, denom));
			} else {
				(*point)->setY(num, denom);
			}
			break;
		case 3:
			if ((*point) == nullptr) {
				cout << "\n  The point is uninitialized.";
			} else {
				cout << "\n  The point is currently at " <<
					(**point);
			}
			break;
		case 4:
			cout << "\n  Returning to \"MENU Point\"";
			break;
		default:
			cout << "\n  WRONG OPTION!";
		}
	} while (menuChoice != 4);
}

void menuMove(PointPeteW** point) {
	int menuChoice;
	int axis;
	int numX, numY, denomX, denomY;

	do {
		cout << "\n\n  *********************\n"
			"  * MENU MovingPoint  *\n"
			"  *  1. By (frX, frY) *\n"
			"  *  2. By fr         *\n"
			"  *  3. Printing      *\n"
			"  *  4. Returning     *\n"
			"  *********************\n"
			"  Select an option (use integer value only): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\n  Enter the numerator for frX: ";
			cin >> numX;
			do {
				cout << "\n  Enter the denominator for frX: ";
				cin >> denomX;
				if (denomX == 0) {
					cout << "\n  Denominator cannot be 0!";
				}
			} while (denomX == 0);

			cout << "\n  Enter the numerator for frY: ";
			cin >> numY;
			do {
				cout << "\n  Enter the denominator for frY: ";
				cin >> denomY;
				if (denomY == 0) {
					cout << "\n  Denominator cannot be 0!";
				}
			} while (denomY == 0);

			(*point)->moveBy(FractionPeteW(numX, denomX),
				FractionPeteW(numY, denomY));
			break;
		case 2:
			// Set these to default values - whichever the user
			// does not select will not have an impact.
			numX = 0;
			numY = 0;
			denomX = 1;
			denomY = 1;

			do {
				cout << "\n\n  Please select the axis for "
					"movement (1 for X-axis, 2 for Y-axis): ";
				cin >> axis;
				if (axis != 1 && axis != 2) {
					cout << "\n\n Invalid choice. Please choose"
						" 1 for X-axis, 2 for Y-axis.";
				}
			} while (axis != 1 && axis != 2);

			if (axis == 1) {
				cout << "\n  Enter the numerator: ";
				cin >> numX;
				do {
					cout << "\n  Enter the denominator: ";
					cin >> denomX;
					if (denomX == 0) {
						cout << "\n  Denominator cannot be 0!";
					}
				} while (denomX == 0);
			} else {
				cout << "\n  Enter the numerator: ";
				cin >> numY;
				do {
					cout << "\n  Enter the denominator: ";
					cin >> denomY;
					if (denomY == 0) {
						cout << "\n  Denominator cannot be 0!";
					}
				} while (denomY == 0);
			}
			(*point)->moveBy(FractionPeteW(numX, denomX), 
				             FractionPeteW(numY, denomY));
			break;
		case 3:
			if ((*point) == nullptr) {
				cout << "\n  The point is uninitialized.";
			} else {
				cout << "\n  The point is currently at " <<
					(**point);
			}
			break;
		case 4:
			cout << "\n  Returning to \"MENU Point\"";
			break;
		default:
			cout << "\n  WRONG OPTION!";
		}
	} while (menuChoice != 4);
}

void menuFlip(PointPeteW** point) {

	int menuChoice;

	do {
		cout << "\n\n  ***********************\n"
			"  * MENU FlippingPoint  *\n"
			"  *  1. By Y            *\n"
			"  *  2. By X            *\n"
			"  *  3. By Origin       *\n"
			"  *  4. Printing        *\n"
			"  *  5. Returning       *\n"
			"  ***********************\n"
			"  Select an option (use integer value only): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			(*point)->flipByY();
			break;
		case 2:
			(*point)->flipByX();
			break;
		case 3:
			(*point)->flipThroughOrigin();
			break;
		case 4:
			if ((*point) == nullptr) {
				cout << "\n  The point is uninitialized.";
			} else {
				cout << "\n  The point is currently at " <<
					(**point);
			}
			break;
		case 5:
			cout << "\n  Returning to \"MENU Point\"";
			break;
		default:
			cout << "\n  WRONG OPTION!";
		}
	} while (menuChoice != 5);
}

void menuPrint(PointPeteW** point) {
	int menuChoice;

	do {
		cout << "\n\n *******************************\n"
			"  * MENU PrintingPoint          *\n"
			"  *  1. By member print()       *\n"
			"  *  2. By stand alone print()  *\n"
			"  *  3. By operator<<           *\n"
			"  *  4. Returning               *\n"
			"  *******************************\n"
			"  Select an option (use integer value only): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			if ((*point) == nullptr) {
				cout << "\n  The point is uninitialized.";
			} else {
				(*point)->print();
			}
			break;
		case 2:
			if ((*point) == nullptr) {
				cout << "\n  The point is uninitialized.";
			} else {
				print(point);
			}
			break;
		case 3:
			if ((*point) == nullptr) {
				cout << "\n  The point is uninitialized.";
			} else {
				cout << "\n  The point is currently at " <<
					(**point);
			}
			break;
		case 4:
			cout << "\n  Returning to \"MENU Point\"";
			break;
		default:
			cout << "\n  WRONG OPTION!";
		}
	} while (menuChoice != 4);
}

void print(PointPeteW** point) {
	cout << "\n\n  X: " << (*point)->getX() << ", Y: " <<
		(*point)->getY();
}

