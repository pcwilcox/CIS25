/**
  * Program Name: CIS25Fall2015PeteWilcoxLab7Ex1Driver.cpp
  * Discussion:   Lab #7 Exercise #1 - Driver --
  *                 Definition file
  * Written by:   Pete Wilcox
  * Date:         2015/12/10
  */

#include <iostream>
#include "fractionPeteW.h"
#include "PointPeteW.h"
#include "RectanglePeteW.h"
#include "CirclePeteW.h"
#include "CIS25Fall2015PeteWilcoxLab7Ex1Driver.h"

using namespace std;

void displayHeader() {
	cout << "CIS 25 - C++ Programming\n"
		"Laney College\n"
		"Pete Wilcox\n"
		"\n"
		"Assignment Information --\n"
		"  Assignment Number:  Lab 7,\n"
		"                      Exercise #1\n"
		"  Written by:         Pete Wilcox\n"
		"  Due Date:           2015/12/10\n";
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
			if (*recA == nullptr ||
				*recB == nullptr ||
				*cirA == nullptr ||
				*cirB == nullptr) {
				cout << "\nAll objects must be initialized first.";
			} else {
				mixedTasks(recA, recB, cirA, cirB);
			}
			break;
		case 4:
			cout << "\n\n    Have fun...";
			break;
		default:
			cout << "\n\n    WRONG OPTION";
		}
	} while (menuChoice != 4);
}

void rectangleTasks(RectanglePeteW** recA, RectanglePeteW** recB) {
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

void mixedTasks(RectanglePeteW** recA, RectanglePeteW** recB,
	CirclePeteW** cirA, CirclePeteW** cirB) {
	int menuChoice;
	int compareFirst, compareSecond, compareTotal;
	do {
		cout << "\nMIXED RECTANGLE & CIRCLE MENU"
			"\n(1) Compare by area"
			"\n(2) Compare by volume"
			"\n(3) Print ALL objects"
			"\n(4) Quit"
			"Enter your option (1 through 4): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\n  Comparing by area - Select two objects"
				" to compare --"
				"\n  (1) Rectangle 1: " << (*recA)->getArea() <<
				"\n  (2) Rectangle 2: " << (*recB)->getArea() <<
				"\n  (3) Circle 1: " << (*cirA)->getArea() <<
				"\n  (4) Circle 2: " << (*cirB)->getArea() <<
				"\nPlease select the first object (1 through 4): ";
				cin >> compareFirst;
				cout << "\nPlease select the second object (1 through 4): ";
				cin >> compareSecond;
				compareTotal = compareFirst * compareSecond;
				switch (compareTotal) {
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 6:
					break;
				case 8:
					break;
				case 12:
					break;
				default:
					cout << "\nInvalid selection, you cannot compare an object with itself.";
				}

			break;
		case 2:
			cout << "\nRectangles and circles have no volume.";
			break;
		case 3:
			cout << "\nRectangle 1: " << **recA <<
				"\nRectangle 2: " << **recB <<
				"\nCircle 1: " << **cirA <<
				"\nCircle 2: " << **cirB;
			break;
		case 4:
			cout << "\nReturning to main menu.";
			break;
		default:
			cout << "\nWRONG OPTION";
			break;
		}
	} while (menuChoice != 4);
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

void createCircles(CirclePeteW** cirA, CirclePeteW** cirB) {
	int numX;
	int numY;
	int denomX;
	int denomY;
	int numR;
	int denomR;
	int menuChoice;

	do {
		cout << "\n  CREATING CIRCLES MENU"
			"\n(1) Create first circle"
			"\n(2) Create second circle"
			"\n(3) Quit"
			"\nPlease enter your option (1 through 3): ";
		cin >> menuChoice;
		switch (menuChoice) {
		case 1:
			cout << "\nCreating center point - X value"
				"\n  Please enter the numerator: ";
			cin >> numX;
			do {
				cout << "\n  Please enter the denominator: ";
				cin >> denomX;
				if (denomX == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denomX == 0);

			cout << "\nCreating center point - Y value"
				"\n  Please enter the numerator: ";
			cin >> numY;
			do {
				cout << "\n  Please enter the denominator: ";
				cin >> denomY;
				if (denomY == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denomY == 0);

			if (*cirA == nullptr) {
				*cirA = new CirclePeteW(PointPeteW(FractionPeteW(numX, denomX), FractionPeteW(numY, denomY)));
			} else {
				(*cirA)->setCenter(PointPeteW(FractionPeteW(numX, denomX), FractionPeteW(numY, denomY)));
			}

			cout << "\n  Creating radius - please enter the numerator: ";
			cin >> numR;
			do {
				cout << "\n  Please enter the denominator: ";
				cin >> denomR;
				if (denomR == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denomR == 0);
			(*cirA)->setRadius(FractionPeteW(numR, denomR));
			break;
		case 2:
			cout << "\nCreating center point - X value"
				"\n  Please enter the numerator: ";
			cin >> numX;
			do {
				cout << "\n  Please enter the denominator: ";
				cin >> denomX;
				if (denomX == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denomX == 0);

			cout << "\nCreating center point - Y value"
				"\n  Please enter the numerator: ";
			cin >> numY;
			do {
				cout << "\n  Please enter the denominator: ";
				cin >> denomY;
				if (denomY == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denomY == 0);

			if (*cirB == nullptr) {
				*cirB = new CirclePeteW(PointPeteW(FractionPeteW(numX, denomX), FractionPeteW(numY, denomY)));
			} else {
				(*cirB)->setCenter(PointPeteW(FractionPeteW(numX, denomX), FractionPeteW(numY, denomY)));
			}

			cout << "\n  Creating radius - please enter the numerator: ";
			cin >> numR;
			do {
				cout << "\n  Please enter the denominator: ";
				cin >> denomR;
				if (denomR == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denomR == 0);
			(*cirB)->setRadius(FractionPeteW(numR, denomR));
			break;
		case 3:
			cout << "\nReturning to main menu.";
			break;
		default:
			cout << "\nWRONG OPTION";
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

void compareArea(CirclePeteW** cirA, CirclePeteW** cirB) {
	if ((*cirA)->getArea() > (*cirB)->getArea()) {
		cout << endl << "Cricle " << **cirA << " is larger than circle " << **cirB;
	} else if ((*cirA)->getArea() < (*cirB)->getArea()) {
		cout << endl << "Circle " << **cirA << " is smaller than circle " << **cirB;
	} else {
		cout << endl << "Both circles are the same size.";
	}
}

void print(RectanglePeteW** recA, RectanglePeteW** recB) {
	int menuChoice;
	do {
		cout << "\n  PRINT RECTANGLES"
			"\n(1) Print first rectangle"
			"\n(2) Print second rectangle"
			"\n(3) Quit"
			"\nPlease enter your option (1 through 3): ";
		cin >> menuChoice;
		switch (menuChoice) {
		case 1:
			cout << **recA;
			break;
		case 2:
			cout << **recB;
			break;
		case 3:
			cout << "\n  Returning to main menu";
			break;
		default:
			cout << "\nWRONG OPTION";
			break;
		}
	} while (menuChoice != 3);
}

void print(CirclePeteW** cirA, CirclePeteW** cirB) {
	int menuChoice;
	do {
		cout << "\n  PRINT CIRCLES"
			"\n(1) Print first circle"
			"\n(2) Print second circle"
			"\n(3) Quit"
			"\nPlease enter your option (1 through 3): ";
		cin >> menuChoice;
		switch (menuChoice) {
		case 1:
			cout << **cirA;
			break;
		case 2:
			cout << **cirB;
			break;
		case 3:
			cout << "\n  Returning to main menu";
			break;
		default:
			cout << "\nWRONG OPTION";
			break;
		}
	} while (menuChoice != 3);
}