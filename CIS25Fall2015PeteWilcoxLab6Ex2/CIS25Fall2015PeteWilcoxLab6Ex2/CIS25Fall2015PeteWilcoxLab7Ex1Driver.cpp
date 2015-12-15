/**
  * Program Name: CIS25Fall2015PeteWilcoxLab7Ex1Driver.cpp
  * Discussion:   Lab #7 Exercise #1 - Driver --
  *                 Definition file
  * Written by:   Pete Wilcox
  * Date:         2015/12/15
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
		"  Due Date:           2015/12/15\n";
}

void userInterface(RectanglePeteW** recA, 
				   RectanglePeteW** recB,
				   CirclePeteW** cirA, 
				   CirclePeteW** cirB) {
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
				cout << 
					"\nAll objects must be initialized first.";
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

void rectangleTasks(RectanglePeteW** recA, 
					RectanglePeteW** recB) {

	ShapePeteW* shapeOne = nullptr;
	ShapePeteW* shapeTwo = nullptr;
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
				shapeOne = *recA;
				shapeTwo = *recB;
				compareArea(&shapeOne, &shapeTwo);
			} else {
				cout << 
					"\nBoth rectangles must be initialized first!";
			}
			break;
		case 4:
			if (recA != nullptr && recB != nullptr) {
				(*recA)->print();
				(*recB)->print();
			} else {
				cout << 
					"\nBoth rectangles must be initialized first!";
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
	ShapePeteW* shapeOne = nullptr;
	ShapePeteW* shapeTwo = nullptr;
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
				shapeOne = *cirA;
				shapeTwo = *cirB;
				compareArea(&shapeOne, &shapeTwo);
			} else {
				cout << 
					"\nBoth circles must be intialized first!";
			}
			break;
		case 4:
			if (cirA != nullptr && cirB != nullptr) {
				(*cirA)->print();
				(*cirB)->print();
			} else {
				cout << 
					"\nBoth circles must be intialized first!";
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

void mixedTasks(RectanglePeteW** recA, 
				RectanglePeteW** recB,
				CirclePeteW** cirA, 
				CirclePeteW** cirB) {
	ShapePeteW* shapeOne = nullptr;
	ShapePeteW* shapeTwo = nullptr;
	int menuChoice;

	do {
		cout << "\nMIXED RECTANGLE & CIRCLE MENU"
			"\n(1) Compare by area"
			"\n(2) Compare by volume"
			"\n(3) Print ALL objects"
			"\n(4) Quit"
			"\nEnter your option (1 through 4): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			do {
				cout << 
					"\n  Comparing by area - Select two objects"
					" to compare --"
					"\nPlease select the first object: ";
				shapeOne = compareMenu(recA, recB, cirA, cirB);

				cout << "\nPlease select the second object: ";
				shapeTwo = compareMenu(recA, recB, cirA, cirB);

				if (shapeOne == shapeTwo) {
					cout << "\nInvalid selection, you cannot " 
						"compare an object with itself.";
				}
			} while (shapeOne == shapeTwo);

			compareArea(&shapeOne, &shapeTwo);
			break;
		case 2:
			cout << "\nRectangles and circles have no volume.";
			break;
		case 3:
			cout << **recA << **recB << **cirA << **cirB;
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

void createRectangles(RectanglePeteW** recA, 
					  RectanglePeteW** recB) {
	
	FractionPeteW* fracX =		nullptr;
	FractionPeteW* fracY =		nullptr;
	PointPeteW* lowerLeft =		nullptr;
	PointPeteW* upperRight =	nullptr;

	int num, denom;
	int menuChoice;

	do {
		cout << "\n  CREATING RECTANGLES MENU"
			"\n(1) Create first rectangle"
			"\n(2) Create second rectangle"
			"\n(3) Quit"
			"\nPlease enter your option (1 through 3): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\nCreating first rectangle -- "
				"\n  Creating lower left point --"
				"\n    X value --"
				"\n      Please enter the numerator: ";
			cin >> num;

			do {
				cout << "      Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			fracX = new FractionPeteW(num, denom);

			cout << "\n    Y value --"
				"\n      Please enter the numerator: ";
			cin >> num;

			do {
				cout << "      Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			fracY = new FractionPeteW(num, denom);
			lowerLeft = new PointPeteW(*fracX, *fracY);

			cout << "\n  Creating upper right point --"
				"\n    X value --"
				"\n      Please enter the numerator: ";
			cin >> num;

			do {
				cout << "      Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			fracX->setBoth(num, denom);

			cout << "\n    Y value --"
				"\n      Please enter the numerator: ";
			cin >> num;

			do {
				cout << "      Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			fracY->setBoth(num, denom);
			upperRight = new PointPeteW(*fracX, *fracY);
			
			if (*recA == nullptr) {
				*recA = 
					new RectanglePeteW(*lowerLeft, *upperRight);
			} else {
				(*recA)->setLowerLeft(*lowerLeft);
				(*recA)->setUpperRight(*upperRight);
			}

			cout << "\nRectangle #1 created: \n";
			(*recA)->print();

			delete fracX;
			delete fracY;
			delete lowerLeft;
			delete upperRight;
			break;
		case 2:
			cout << "\nCreating second rectangle -- "
				"\n  Creating lower left point --"
				"\n    X value --"
				"\n      Please enter the numerator: ";
			cin >> num;

			do {
				cout << "      Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			fracX = new FractionPeteW(num, denom);

			cout << "\n    Y value --"
				"\n      Please enter the numerator: ";
			cin >> num;

			do {
				cout << "      Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			fracY = new FractionPeteW(num, denom);
			lowerLeft = new PointPeteW(*fracX, *fracY);

			cout << "\n  Creating upper right point --"
				"\n    X value --"
				"\n      Please enter the numerator: ";
			cin >> num;

			do {
				cout << "      Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			fracX->setBoth(num, denom);

			cout << "\n    Y value --"
				"\n      Please enter the numerator: ";
			cin >> num;

			do {
				cout << "      Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			fracY->setBoth(num, denom);
			upperRight = new PointPeteW(*fracX, *fracY);

			if (*recB == nullptr) {
				*recB = 
					new RectanglePeteW(*lowerLeft, *upperRight);
			} else {
				(*recB)->setLowerLeft(*lowerLeft);
				(*recB)->setUpperRight(*upperRight);
			}

			cout << "\nRectangle #2 created: \n";
			(*recB)->print();

			delete fracX;
			delete fracY;
			delete lowerLeft;
			delete upperRight;
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
	FractionPeteW* centerX =	nullptr;
	FractionPeteW* centerY =	nullptr;
	FractionPeteW* radius =		nullptr;
	PointPeteW* center =		nullptr;

	int num, denom, menuChoice;

	do {
		cout << "\n  CREATING CIRCLES MENU --"
			"\n  (1) Create first circle"
			"\n  (2) Create second circle"
			"\n  (3) Quit"
			"\nPlease select your option (1 through 3):";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\nCreating first circle --"
				"\n  Creating center point --"
				"\n    X value:"
				"\n      Please enter the numerator: ";
			cin >> num;

			do {
				cout << "\n      Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			centerX = new FractionPeteW(num, denom);

			cout << "\n    Y value:"
				"\n      Please enter the numerator: ";
			cin >> num;

			do {
				cout << "\n      Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			centerY = new FractionPeteW(num, denom);
			center = new PointPeteW(*centerX, *centerY);

			cout << "\n    Creating radius --";

			do {
				cout << "\n      Please enter the numerator: ";
				cin >> num;

				do {
					cout << 
						"\n      Please enter the denominator: ";
					cin >> denom;
					if (denom == 0) {
						cout << "\nDenominator cannot be 0!";
					}
				} while (denom == 0);

				if (radius == nullptr) {
					radius = new FractionPeteW(num, denom);
				} else {
					radius->setBoth(num, denom);
				}
				if (radius->getNum() < 0) {
					cout << "\nRadius cannot be negative!";
				}

			} while (radius->getNum() <= 0);

			if (*cirA == nullptr) {
				*cirA = new CirclePeteW(*center, *radius);
			} else {
				(*cirA)->setCenter(*center);
				(*cirA)->setRadius(*radius);
			}

			cout << "\nCircle #1 created:";
			(*cirA)->print();
			
			delete centerX;
			delete centerY;
			delete radius;
			delete center;

			break;

		case 2:
			cout << "\nCreating second circle --"
				"\n  Creating center point --"
				"\n    X value:"
				"\n      Please enter the numerator: ";
			cin >> num;

			do {
				cout << "\n      Please enter the denominator: ";
				cin >> denom;

				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}

			} while (denom == 0);

			centerX = new FractionPeteW(num, denom);

			cout << "\n    Y value:"
				"\n      Please enter the numerator: ";
			cin >> num;

			do {
				cout << "\n      Please enter the denominator: ";
				cin >> denom;

				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}

			} while (denom == 0);

			centerY = new FractionPeteW(num, denom);
			center = new PointPeteW(*centerX, *centerY);

			cout << "\n    Creating radius --";

			do {
				
				cout << "\n      Please enter the numerator: ";
				cin >> num;

				do {
					cout << "\n      Please enter the denominator: ";
					cin >> denom;

					if (denom == 0) {
						cout << "\nDenominator cannot be 0!";
					}

				} while (denom == 0);

				radius = new FractionPeteW(num, denom);

				if (radius->getNum() <= 0) {
					cout << "\nRadius must be positive!";
					delete radius;
				}
				
			} while (radius->getNum() <= 0);

			if (*cirB == nullptr) {
				*cirB = new CirclePeteW(*center, *radius);
			} else {
				(*cirB)->setCenter(*center);
				(*cirB)->setRadius(*radius);
			}

			cout << "\nCircle #2 created:";
			(*cirB)->print();

			delete centerX;
			delete centerY;
			delete radius;
			delete center;

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

void compareArea(ShapePeteW** shapeOne, ShapePeteW** shapeTwo) {

	cout << "\nComparing area -- \n    ";

	if ((*shapeOne)->getArea() > (*shapeTwo)->getArea()) {
		(*shapeOne)->print();
		cout << " is larger than "; 
		(*shapeTwo)->print();
	} else if ((*shapeOne)->getArea() < (*shapeTwo)->getArea()) {
		(*shapeTwo)->print();
		cout << " is larger than ";
		(*shapeOne)->print();
	} else {
		cout << "Both shapes are the same size.";
	}
}

ShapePeteW* compareMenu(RectanglePeteW** recA, 
						RectanglePeteW** recB, 
						CirclePeteW** cirA, 
						CirclePeteW** cirB) {

	ShapePeteW* shape = nullptr;
	
	int menuChoice;
	do {

		cout << 
			"\n  (1) Rectangle 1"
			"\n  (2) Rectangle 2"
			"\n  (3) Circle 1"
			"\n  (4) Circle 2"
			"\nPlease select your object (1 through 4): ";
		cin >> menuChoice;
		switch (menuChoice) {
		case 1:
			shape = *recA;
			break;
		case 2:
			shape = *recB;
			break;
		case 3:
			shape = *cirA;
			break;
		case 4:
			shape = *cirB;
			break;
		default:
			cout << "\nInvalid selection.";
		}
	} while (shape == nullptr);

	return shape;

}
