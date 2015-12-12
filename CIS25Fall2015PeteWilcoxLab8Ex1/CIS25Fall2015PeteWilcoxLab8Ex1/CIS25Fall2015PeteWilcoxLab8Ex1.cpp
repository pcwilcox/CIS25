/**
  * Program Name: CIS25Fall2015PeteWilcoxLab8Ex1.cpp
  * Discussion:   Lab #8 Exercise #1
  * Written by:   Pete Wilcox
  * Date:         2015/12/15
  */

#include <iostream>
#include "CIS25Fall2015PeteWilcoxLab8Ex1Driver.h"
#include "BoxPeteW.h"
#include "CirclePeteW.h"
#include "CylinderPeteW.h"
#include "fractionPeteW.h"
#include "PointPeteW.h"
#include "RectanglePeteW.h"
#include "ShapePeteW.h"

using namespace std;

int main() {
	BoxPeteW* boxOne				= nullptr;
	BoxPeteW* boxTwo				= nullptr;
	CirclePeteW* circleOne			= nullptr;
	CirclePeteW* circleTwo			= nullptr;
	CylinderPeteW* cylinderOne		= nullptr;
	CylinderPeteW* cylinderTwo		= nullptr;
	RectanglePeteW* rectangleOne	= nullptr;
	RectanglePeteW* rectangleTwo	= nullptr;
	ShapePeteW* shapeOne			= nullptr;
	ShapePeteW* shapeTwo			= nullptr;

	int menuChoice;

	displayHeader();

	do {
		menuChoice = menuMain();

		switch (menuChoice) {
		case 1:
			createRectangles(&rectangleOne, &rectangleTwo);
			break;
		case 2:
			createCircles(&circleOne, &circleTwo);
			break;
		case 3:
			createBoxes(&boxOne, &boxTwo);
			break;
		case 4:
			createCylinders(&cylinderOne, &cylinderTwo);
			break;
		case 5:
			do {
				cout <<
					"\n  Comparing by area - Select two objects"
					" to compare --"
					"\nPlease select the first object: ";
				shapeOne = compareMenu(&rectangleOne, &rectangleTwo, &circleOne, &circleTwo, &boxOne, &boxTwo, &cylinderOne, &cylinderTwo);

				cout << "\nPlease select the second object: ";
				shapeTwo = compareMenu(&rectangleOne, &rectangleTwo, &circleOne, &circleTwo, &boxOne, &boxTwo, &cylinderOne, &cylinderTwo);

				if (shapeOne == shapeTwo) {
					cout << "\nInvalid selection, you cannot "
						"compare an object with itself.";
				}
			} while (shapeOne == shapeTwo);

			compareArea(&shapeOne, &shapeTwo);
			break;
		case 6:
			do {
				cout <<
					"\n  Comparing by volume - Select two objects"
					" to compare --"
					"\nPlease select the first object: ";
				shapeOne = compareMenu(&rectangleOne, &rectangleTwo, &circleOne, &circleTwo, &boxOne, &boxTwo, &cylinderOne, &cylinderTwo);

				cout << "\nPlease select the second object: ";
				shapeTwo = compareMenu(&rectangleOne, &rectangleTwo, &circleOne, &circleTwo, &boxOne, &boxTwo, &cylinderOne, &cylinderTwo);

				if (shapeOne == shapeTwo) {
					cout << "\nInvalid selection, you cannot "
						"compare an object with itself.";
				}
			} while (shapeOne == shapeTwo);

			compareVolume(&shapeOne, &shapeTwo);
			break;
		case 7:
			printMenu(&rectangleOne, &rectangleTwo, &circleOne, &circleTwo,	&boxOne, &boxTwo,	&cylinderOne, &cylinderTwo);
			break;
		case 8:
			cout << "\n\n  Have fun!";
			break;
		default:
			cout << "\nWRONG OPTION";
		}

	} while (menuChoice != 8);

	delete boxOne;
	delete boxTwo;
	delete circleOne;
	delete circleTwo;
	delete cylinderOne;
	delete cylinderTwo;
	delete rectangleOne;
	delete rectangleTwo;
	delete shapeOne;
	delete shapeTwo;

	return 0;
}