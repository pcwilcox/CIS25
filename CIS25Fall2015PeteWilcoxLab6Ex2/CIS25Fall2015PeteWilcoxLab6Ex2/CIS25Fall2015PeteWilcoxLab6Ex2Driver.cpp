/**
  * Program Name: CIS25Fall2015PeteWilcoxLab6Ex2Driver.cpp
  * Discussion:   Lab #6 Exercise #2 - Driver --
  *                 Definition file
  * Written by:   Pete Wilcox
  * Date:         2015/12/01
  */

#include <iostream>
#include "fractionPeteW.h"
#include "PointPeteW.h"
#include "RectanglePeteW.h"
#include "CirclePeteW.h"
#include "CIS25Fall2015PeteWilcoxLab6Ex2Driver.h"

using namespace std;

void displayHeader() {
	cout << "CIS 25 - C++ Programming\n"
		"Laney College\n"
		"Pete Wilcox\n"
		"\n"
		"Assignment Information --\n"
		"  Assignment Number:  Lab 6,\n"
		"                      Exercise #2\n"
		"  Written by:         Pete Wilcox\n"
		"  Due Date:           2015/12/01\n";
}

void userInterface(RectanglePeteW** recA, RectanglePeteW** recB, 
				   CirclePeteW** cirA, CirclePeteW** cirB) {
	int menuChoice;
	do {
		cout << "\nMAIN MENU\n"
			"(1) Rectangle Tasks\n"
			"(2) Circle Tasks\n"
			"(3) Mixed Rectangle and Circle Tasks\n"
			"(4) Quit\n\n"
			"Enter your option (1, 2, 3, or 4): ";

		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			rectangleTasks(recA, recB);
			break;
		case 2:
			circleTasks(cirA, cirB);
			break;
		case 3:
			mixedTasks(recA, recB, cirA, cirB);
			break;
		case 4:
			cout << "\n\n    Have fun...";
			break;
		default:
			cout << "\n\n    WRONG OPTION";
		}
	} while (menuChoice != 4);
}

void rectangleTasks(RectanglePeteW** recA, RectanglePeteW** recB, 
					CirclePeteW** cirA, CirclePeteW** cirB) {
	int menuChoice;
	do {
		cout << "\nRECTANGLE MENU\n"
			"(1) Create two Rectangle objects\n"
			"(2) Compare by volume\n"
			"(3) Compare by area\n"
			"(4) Print two Rectangle objects\n"
			"(5) Quit\n"
			"Enter your option (1 through 5): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			createRectangles(recA, recB);
			break;
		case 2:
			cout << "\nRectangles have no volume.";
			break;
		case 3:
			if (recA != nullptr && recB != nullptr) {
				compareArea(recA, recB);
			} else {
				cout << "\nBoth rectangles must be intialized first!";
			}
			break;
		case 4:
			if (recA != nullptr && recB != nullptr) {
				print(recA, recB);
			} else {
				cout << "\nBoth rectangles must be intialized first!";
			}
			break;
		case 5:
			cout << "\nReturning to main menu.";
			break;
		default:
			cout << "\nWrong option!";
		}
	} while (menuChoice != 5);
}

void circleTasks(CirclePeteW** cirA, CirclePeteW** cirB) {
	int menuChoice;
	do {
		cout << "\nCIRCLE MENU\n"
			"(1) Create two Circle objects\n"
			"(2) Compare by volume\n"
			"(3) Compare by area\n"
			"(4) Print two Circle objects\n"
			"(5) Quit\n"
			"Enter your option (1 through 5): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			createCircles(cirA, cirB);
			break;
		case 2:
			cout << "\nBoth circles have zero volume.";
			break;
		case 3:
			if (cirA != nullptr && cirB != nullptr) {
				compareArea(cirA, cirB);
			} else {
				cout << "\nBoth circles must be intialized first!";
			}
			break;
		case 4:
			if (cirA != nullptr && cirB != nullptr) {
				print(cirA, cirB);
			} else {
				cout << "\nBoth circles must be intialized first!";
			}
			break;
		case 5:
			cout << "\nReturning to main menu.";
			break;
		default:
			cout << "\nWrong option!";
		}
	} while (menuChoice != 5);
}

void createRectangles(RectanglePeteW** recA, RectanglePeteW** recB) {
	int menuChoice;
	int numX;
	int denomX;
	int numY;
	int denomY;

	do {
		cout << "\n  CREATING RECTANGLES MENU"
			"\n(1) Create first rectangle"
			"\n(2) Create second rectangle"
			"\n(3) Quit"
			"\nPlease enter your option (1 through 3): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\nCreating lower left point - X value"
				"\n  Please enter the numerator: ";
			cin >> numX;
			do {
				cout << "\n  Please enter the denominator: ";
				cin >> denomX;
				if (denomX == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denomX == 0);

			cout << "\nCreating lower left point - Y value"
				"\n  Please enter the numerator: ";
			cin >> numY;
			do {
				cout << "\n  Please enter the denominator: ";
				cin >> denomY;
				if (denomY == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denomY == 0);
			
			if (*recA == nullptr) {
				*recA = new RectanglePeteW(PointPeteW(FractionPeteW(numX, denomX), FractionPeteW(numY, denomY)));
			} else {
				(*recA)->setLowerLeft(PointPeteW(FractionPeteW(numX, denomX), FractionPeteW(numY, denomY)));
			}

			cout << "\nCreating upper right point - X value"
				"\n  Please enter the numerator: ";
			cin >> numX;
			do {
				cout << "\n  Please enter the denominator: ";
				cin >> denomX;
				if (denomX == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denomX == 0);
			cout << "\nCreating upper right point - Y value"
				"\n  Please enter the numerator: ";
			cin >> numY;
			do {
				cout << "\n  Please enter the denominator: ";
				cin >> denomY;
				if (denomY == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denomY == 0);	

			(*recA)->setUpperRight(PointPeteW(FractionPeteW(numX, denomX), FractionPeteW(numY, denomY)));
			break;
		case 2:
			cout << "\nCreating lower left point - X value"
				"\n  Please enter the numerator: ";
			cin >> numX;
			do {
				cout << "\n  Please enter the denominator: ";
				cin >> denomX;
				if (denomX == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denomX == 0);

			cout << "\nCreating lower left point - Y value"
				"\n  Please enter the numerator: ";
			cin >> numY;
			do {
				cout << "\n  Please enter the denominator: ";
				cin >> denomY;
				if (denomY == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denomY == 0);

			if (*recB == nullptr) {
				*recB = new RectanglePeteW(PointPeteW(FractionPeteW(numX, denomX), FractionPeteW(numY, denomY)));
			} else {
				(*recB)->setLowerLeft(PointPeteW(FractionPeteW(numX, denomX), FractionPeteW(numY, denomY)));
			}

			cout << "\nCreating upper right point - X value"
				"\n  Please enter the numerator: ";
			cin >> numX;
			do {
				cout << "\n  Please enter the denominator: ";
				cin >> denomX;
				if (denomX == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denomX == 0);
			cout << "\nCreating upper right point - Y value"
				"\n  Please enter the numerator: ";
			cin >> numY;
			do {
				cout << "\n  Please enter the denominator: ";
				cin >> denomY;
				if (denomY == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denomY == 0);

			(*recB)->setUpperRight(PointPeteW(FractionPeteW(numX, denomX), FractionPeteW(numY, denomY)));

			break;
		case 3:
			cout << "\nReturning to main menu.";
			break;
		default:
			cout << "\nWRONG OPTION!";
			break;
		}
	} while (menuChoice != 3);
}

void compareArea(RectanglePeteW** recA, RectanglePeteW** recB) {
	if ((*recA)->getArea() > (*recB)->getArea()) {
		cout << endl << "Rectangle " << **recA << " is larger than rectangle " << **recB;
	} else if ((*recA)->getArea() < (*recB)->getArea()) {
		cout << endl << "Rectangle " << **recA << " is smaller than rectangle " << **recB;
	} else {
		cout << endl << "Both rectangles are the same size.";
	}
}