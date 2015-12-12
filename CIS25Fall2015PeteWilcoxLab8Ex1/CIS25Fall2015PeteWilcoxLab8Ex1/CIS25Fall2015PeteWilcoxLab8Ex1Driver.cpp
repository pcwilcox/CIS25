/**
  * Program Name: CIS25Fall2015PeteWilcoxLab8Ex1Driver.cpp
  * Discussion:   Definition File --
  *                 Lab #8, Exercise #1 Driver
  * Written by:   Pete Wilcox
  * Date:         2015/12/15
  */

#include "CIS25Fall2015PeteWilcoxLab8Ex1Driver.h"

void displayHeader() {
	cout << "CIS 25 - C++ Programming\n"
		"Laney College\n"
		"Pete Wilcox\n"
		"\n"
		"Assignment Information --\n"
		"  Assignment Number:  Lab 8,\n"
		"                      Exercise #1\n"
		"  Written by:         Pete Wilcox\n"
		"  Due Date:           2015/12/15\n";
}

int menuMain() {
	int menuChoice;
	cout << "\nMENU"
		"\n----"
		"\n(1)    Create 2 RectanglePeteW objects"
		"\n(2)    Create 2 CirclePeteW objects"
		"\n(3)    Create 2 BoxPeteW objects"
		"\n(4)    Create 2 CylinderPeteW objects"
		"\n(5)    Compare 2 selected objects by area"
		"\n(6)    Compare 2 Selected objects by volume"
		"\n(7)    Print selected objects"
		"\n(8)    Quit"
		"\nEnter your option (1, 2, 3, 4, 5, 6, 7, or 8): ";
	cin >> menuChoice;

	return menuChoice;
}

void createRectangles(RectanglePeteW **rectangleOne, RectanglePeteW **rectangleTwo) {
	FractionPeteW* fracX	= nullptr;
	FractionPeteW* fracY	= nullptr;
	PointPeteW* lowerLeft	= nullptr;
	PointPeteW* upperRight	= nullptr;

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

			if (*rectangleOne == nullptr) {
				*rectangleOne =
					new RectanglePeteW(*lowerLeft, *upperRight);
			} else {
				(*rectangleOne)->setLowerLeft(*lowerLeft);
				(*rectangleOne)->setUpperRight(*upperRight);
			}

			cout << "\nRectangle #1 created: \n";
			(*rectangleOne)->print();

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

			if (*rectangleTwo == nullptr) {
				*rectangleTwo = new RectanglePeteW(*lowerLeft, *upperRight);
			} else {
				(*rectangleTwo)->setLowerLeft(*lowerLeft);
				(*rectangleTwo)->setUpperRight(*upperRight);
			}

			cout << "\nRectangle #2 created: \n";
			(*rectangleTwo)->print();

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

void createCircles(CirclePeteW **circleOne, CirclePeteW **circleTwo) {
	FractionPeteW* centerX	= nullptr;
	FractionPeteW* centerY	= nullptr;
	FractionPeteW* radius	= nullptr;
	PointPeteW* center		= nullptr;

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

			if (*circleOne == nullptr) {
				*circleOne = new CirclePeteW(*center, *radius);
			} else {
				(*circleOne)->setCenter(*center);
				(*circleOne)->setRadius(*radius);
			}

			cout << "\nCircle #1 created:";
			(*circleOne)->print();

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

			if (*circleTwo == nullptr) {
				*circleTwo = new CirclePeteW(*center, *radius);
			} else {
				(*circleTwo)->setCenter(*center);
				(*circleTwo)->setRadius(*radius);
			}

			cout << "\nCircle #2 created:";
			(*circleTwo)->print();

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

void createBoxes(BoxPeteW **boxOne,	BoxPeteW **boxTwo) {
	FractionPeteW* fracX	= nullptr;
	FractionPeteW* fracY	= nullptr;
	FractionPeteW* height	= nullptr;
	PointPeteW* lowerLeft	= nullptr;
	PointPeteW* upperRight	= nullptr;
	RectanglePeteW* base	= nullptr;

	int num, denom;
	int menuChoice;

	do {
		cout << "\n  CREATING BOXES MENU"
			"\n(1) Create first box"
			"\n(2) Create second box"
			"\n(3) Quit"
			"\nPlease enter your option (1 through 3): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\nCreating first box -- "
				"\n  Creating base rectangle --"
				"\n    Creating lower left point --"
				"\n      X value --"
				"\n        Please enter the numerator: ";
			cin >> num;

			do {
				cout << "        Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			fracX = new FractionPeteW(num, denom);

			cout << "\n      Y value --"
				"\n        Please enter the numerator: ";
			cin >> num;

			do {
				cout << "        Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			fracY = new FractionPeteW(num, denom);
			lowerLeft = new PointPeteW(*fracX, *fracY);

			cout << "\n    Creating upper right point --"
				"\n      X value --"
				"\n        Please enter the numerator: ";
			cin >> num;

			do {
				cout << "        Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			fracX->setBoth(num, denom);

			cout << "\n      Y value --"
				"\n        Please enter the numerator: ";
			cin >> num;

			do {
				cout << "        Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			fracY->setBoth(num, denom);
			upperRight = new PointPeteW(*fracX, *fracY);

			base = new RectanglePeteW(*lowerLeft, *upperRight);
			
			cout << "\n  Base rectangle created: ";
			base->print();

			cout << "\n  Creating height fraction --"
				"\n    Please enter the numerator: ";
			cin >> num;
			do {
				cout << "\n    Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			if (num * denom < 0) {
				cout << "\nHeight cannot be negative, converting --";
				num = -num;
			}

			height = new FractionPeteW(num, denom);

			cout << "\n  Height fraction created: " << *height;

			if (*boxOne == nullptr) {
				*boxOne = new BoxPeteW(*base, *height);
			} else {
				(*boxOne)->setLowerLeft(*lowerLeft);
				(*boxOne)->setUpperRight(*upperRight);
				(*boxOne)->setHeight(*height);
			}

			cout << "\nBox #1 created: \n";
			(*boxOne)->print();

			delete fracX;
			delete fracY;
			delete lowerLeft;
			delete upperRight;
			delete base;
			delete height;
			break;
		case 2:
			cout << "\nCreating second box -- "
				"\n  Creating base rectangle --"
				"\n    Creating lower left point --"
				"\n      X value --"
				"\n        Please enter the numerator: ";
			cin >> num;

			do {
				cout << "        Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			fracX = new FractionPeteW(num, denom);

			cout << "\n      Y value --"
				"\n        Please enter the numerator: ";
			cin >> num;

			do {
				cout << "        Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			fracY = new FractionPeteW(num, denom);
			lowerLeft = new PointPeteW(*fracX, *fracY);

			cout << "\n    Creating upper right point --"
				"\n      X value --"
				"\n        Please enter the numerator: ";
			cin >> num;

			do {
				cout << "        Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			fracX->setBoth(num, denom);

			cout << "\n      Y value --"
				"\n        Please enter the numerator: ";
			cin >> num;

			do {
				cout << "        Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			fracY->setBoth(num, denom);
			upperRight = new PointPeteW(*fracX, *fracY);

			base = new RectanglePeteW(*lowerLeft, *upperRight);

			cout << "\n  Base rectangle created: ";
			base->print();

			cout << "\n  Creating height fraction --"
				"\n    Please enter the numerator: ";
			cin >> num;
			do {
				cout << "\n    Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			if (num * denom < 0) {
				cout << "\nHeight cannot be negative, converting --";
				num = -num;
			}

			height = new FractionPeteW(num, denom);

			cout << "\n  Height fraction created: " << *height;

			if (*boxTwo == nullptr) {
				*boxTwo = new BoxPeteW(*base, *height);
			} else {
				(*boxTwo)->setLowerLeft(*lowerLeft);
				(*boxTwo)->setUpperRight(*upperRight);
				(*boxTwo)->setHeight(*height);
			}

			cout << "\nBox #2 created: \n";
			(*boxTwo)->print();

			delete fracX;
			delete fracY;
			delete lowerLeft;
			delete upperRight;
			delete base;
			delete height;
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

void createCylinders(CylinderPeteW **cylinderOne, CylinderPeteW **cylinderTwo) {
	FractionPeteW* centerX	= nullptr;
	FractionPeteW* centerY	= nullptr;
	FractionPeteW* radius	= nullptr;
	FractionPeteW* height	= nullptr;
	PointPeteW* center		= nullptr;
	CirclePeteW* base		= nullptr;

	int num, denom, menuChoice;

	do {
		cout << "\n  CREATING CYLINDERS MENU --"
			"\n  (1) Create first cylinder"
			"\n  (2) Create second cylinder"
			"\n  (3) Quit"
			"\nPlease select your option (1 through 3):";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			cout << "\nCreating first cylinder --"
				"\n  Creating base circle --"
				"\n    Creating center point --"
				"\n      X value:"
				"\n        Please enter the numerator: ";
			cin >> num;

			do {
				cout << "\n        Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			centerX = new FractionPeteW(num, denom);

			cout << "\n      Y value:"
				"\n        Please enter the numerator: ";
			cin >> num;

			do {
				cout << "\n        Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			centerY = new FractionPeteW(num, denom);
			center = new PointPeteW(*centerX, *centerY);

			cout << "\n      Creating radius --";

			do {
				cout << "\n        Please enter the numerator: ";
				cin >> num;

				do {
					cout <<
						"\n        Please enter the denominator: ";
					cin >> denom;
					if (denom == 0) {
						cout << "\nDenominator cannot be 0!";
					}
				} while (denom == 0);

				radius = new FractionPeteW(num, denom);
				
				if (radius->getNum() < 0) {
					cout << "\nRadius cannot be negative!";
				}

			} while (radius->getNum() <= 0);

			base = new CirclePeteW(*center, *radius);
			
			cout << "\n  Base circle created:";
			base->print();

			cout << "\n  Creating height fraction --"
				"\n    Please enter the numerator: ";
			cin >> num;
			do {
				cout << "\n    Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			if (num * denom < 0) {
				cout << "\nHeight cannot be negative, converting --";
				num = -num;
			}

			height = new FractionPeteW(num, denom);

			cout << "\n  Height fraction created: " << *height;

			if (*cylinderOne == nullptr) {
				*cylinderOne = new CylinderPeteW(*base, *height);
			} else {
				(*cylinderOne)->setCenter(*center);
				(*cylinderOne)->setRadius(*radius);
				(*cylinderOne)->setHeight(*height);
			}

			cout << "\nCylinder #1 created:";

			(*cylinderOne)->print();

			delete centerX;
			delete centerY;
			delete radius;
			delete center;
			delete base;
			delete height;
			break;

		case 2:
			cout << "\nCreating second cylinder --"
				"\n  Creating base circle --"
				"\n    Creating center point --"
				"\n      X value:"
				"\n        Please enter the numerator: ";
			cin >> num;

			do {
				cout << "\n        Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			centerX = new FractionPeteW(num, denom);

			cout << "\n      Y value:"
				"\n        Please enter the numerator: ";
			cin >> num;

			do {
				cout << "\n        Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			centerY = new FractionPeteW(num, denom);
			center = new PointPeteW(*centerX, *centerY);

			cout << "\n      Creating radius --";

			do {
				cout << "\n        Please enter the numerator: ";
				cin >> num;

				do {
					cout <<
						"\n        Please enter the denominator: ";
					cin >> denom;
					if (denom == 0) {
						cout << "\nDenominator cannot be 0!";
					}
				} while (denom == 0);

				radius = new FractionPeteW(num, denom);

				if (radius->getNum() < 0) {
					cout << "\nRadius cannot be negative!";
				}

			} while (radius->getNum() <= 0);

			base = new CirclePeteW(*center, *radius);

			cout << "\n  Base circle created:";
			base->print();

			cout << "\n  Creating height fraction --"
				"\n    Please enter the numerator: ";
			cin >> num;
			do {
				cout << "\n    Please enter the denominator: ";
				cin >> denom;
				if (denom == 0) {
					cout << "\nDenominator cannot be 0!";
				}
			} while (denom == 0);

			if (num * denom < 0) {
				cout << "\nHeight cannot be negative, converting --";
				num = -num;
			}

			height = new FractionPeteW(num, denom);

			cout << "\n  Height fraction created: " << *height;

			if (*cylinderTwo == nullptr) {
				*cylinderTwo = new CylinderPeteW(*base, *height);
			} else {
				(*cylinderTwo)->setCenter(*center);
				(*cylinderTwo)->setRadius(*radius);
				(*cylinderTwo)->setHeight(*height);
			}

			cout << "\nCylinder #2 created:";

			(*cylinderTwo)->print();

			delete centerX;
			delete centerY;
			delete radius;
			delete center;
			delete base;
			delete height;
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

ShapePeteW* compareMenu(RectanglePeteW** rectangleOne,
	RectanglePeteW** rectangleTwo,
	CirclePeteW** circleOne,
	CirclePeteW** circleTwo,
	BoxPeteW **boxOne,
	BoxPeteW **boxTwo,
	CylinderPeteW **cylinderOne,
	CylinderPeteW **cylinderTwo) {
	ShapePeteW* shape = nullptr;

	int menuChoice;
	do {

		cout <<
			"\n  (1) Rectangle 1"
			"\n  (2) Rectangle 2"
			"\n  (3) Circle 1"
			"\n  (4) Circle 2"
			"\n  (5) Box 1"
			"\n  (6) Box 2"
			"\n  (7) Cylinder 1"
			"\n  (8) Cylinder 2"
			"\nPlease select your object (1 through 8): ";
		cin >> menuChoice;
		switch (menuChoice) {
		case 1:
			if (*rectangleOne == nullptr) {
				cout << "\nInvalid option - this shape has not been initiliazed yet!";
			} else {
				shape = *rectangleOne;
			}
			break;
		case 2:
			if (*rectangleTwo == nullptr) {
				cout << "\nInvalid option - this shape has not been initiliazed yet!";
			} else {
				shape = *rectangleTwo;
			}
			break;
		case 3:
			if (*circleOne == nullptr) {
				cout << "\nInvalid option - this shape has not been initiliazed yet!";
			} else {
				shape = *circleOne;
			}
			break;
		case 4:
			if (*circleTwo == nullptr) {
				cout << "\nInvalid option - this shape has not been initiliazed yet!";
			} else {
				shape = *circleTwo;
			}
			break;
		case 5:
			if (*boxOne == nullptr) {
				cout << "\nInvalid option - this shape has not been initiliazed yet!";
			} else {
				shape = *boxOne;
			}
			break;
		case 6:
			if (*boxTwo == nullptr) {
				cout << "\nInvalid option - this shape has not been initiliazed yet!";
			} else {
				shape = *boxTwo;
			}
			break;
		case 7:
			if (*cylinderOne == nullptr) {
				cout << "\nInvalid option - this shape has not been initiliazed yet!";
			} else {
				shape = *cylinderOne;
			}
			break;
		case 8:
			if (*cylinderTwo == nullptr) {
				cout << "\nInvalid option - this shape has not been initiliazed yet!";
			} else {
				shape = *cylinderTwo;
			}
			break;
		default:
			cout << "\nInvalid selection.";
		}
	} while (shape == nullptr);

	return shape;
}

void compareArea(ShapePeteW **shapeOne,
	ShapePeteW **shapeTwo) {
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

void compareVolume(ShapePeteW **shapeOne,
	ShapePeteW **shapeTwo) {
	cout << "\nComparing volume -- \n    ";

	if ((*shapeOne)->getVolume() > (*shapeTwo)->getVolume()) {
		(*shapeOne)->print();
		cout << " is larger than ";
		(*shapeTwo)->print();
	} else if ((*shapeOne)->getVolume() < (*shapeTwo)->getVolume()) {
		(*shapeTwo)->print();
		cout << " is larger than ";
		(*shapeOne)->print();
	} else {
		cout << "Both shapes are the same size.";
	}
}

void printMenu(RectanglePeteW** rectangleOne,
	RectanglePeteW** rectangleTwo,
	CirclePeteW** circleOne,
	CirclePeteW** circleTwo,
	BoxPeteW **boxOne,
	BoxPeteW **boxTwo,
	CylinderPeteW **cylinderOne,
	CylinderPeteW **cylinderTwo) {

	cout << "\nPrinting existing objects --" << endl;

	if (*rectangleOne != nullptr) {
		(*rectangleOne)->print();
	}

	if (*rectangleTwo != nullptr) {
		(*rectangleTwo)->print();
	}

	if (*circleOne != nullptr) {
		(*circleOne)->print();
	}

	if (*circleTwo != nullptr) {
		(*circleOne)->print();
	}

	if (*boxOne != nullptr) {
		(*boxOne)->print();
	}

	if (*boxTwo != nullptr) {
		(*boxTwo)->print();
	}

	if (*cylinderOne != nullptr) {
		(*cylinderOne)->print();
	}

	if (*cylinderTwo != nullptr) {
		(*cylinderTwo)->print();
	}
}

