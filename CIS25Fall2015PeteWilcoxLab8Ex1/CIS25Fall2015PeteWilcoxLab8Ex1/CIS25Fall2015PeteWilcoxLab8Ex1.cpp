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

	return 0;
}

/* PROGRAM OUTPUT:
CIS 25 - C++ Programming
Laney College
Pete Wilcox

Assignment Information --
  Assignment Number:  Lab 8,
                      Exercise #1
  Written by:         Pete Wilcox
  Due Date:           2015/12/15

MENU
----
(1)    Create 2 RectanglePeteW objects
(2)    Create 2 CirclePeteW objects
(3)    Create 2 BoxPeteW objects
(4)    Create 2 CylinderPeteW objects
(5)    Compare 2 selected objects by area
(6)    Compare 2 Selected objects by volume
(7)    Print selected objects
(8)    Quit
Enter your option (1, 2, 3, 4, 5, 6, 7, or 8): 1

  CREATING RECTANGLES MENU
(1) Create first rectangle
(2) Create second rectangle
(3) Quit
Please enter your option (1 through 3): 1

Creating first rectangle --
  Creating lower left point --
    X value --
      Please enter the numerator: 1
      Please enter the denominator: 2

Calling Fraction() on 1/2
    Y value --
      Please enter the numerator: 2
      Please enter the denominator: 1

Calling Fraction() on 2/1
Calling Fraction() on 1/2
Calling Fraction() on 2/1
Calling PointPeteW() on (1/2,2/1)
  Creating upper right point --
    X value --
      Please enter the numerator: 4
      Please enter the denominator: 1

    Y value --
      Please enter the numerator: 1
      Please enter the denominator: 1

Calling Fraction() on 4/1
Calling Fraction() on 1/1
Calling PointPeteW() on (4/1,1/1)
Calling Fraction() on 0/1
Calling Fraction() on 0/1
Calling Fraction() on 4/1
Calling Fraction() on 1/1
Calling PointPeteW() on (4/1,1/1)
Calling Fraction() on 1/2
Calling Fraction() on 2/1
Calling PointPeteW() on (1/2,2/1)
Calling Fraction() on 0/1
Calling ~Fraction() on 0/1
Calling Fraction() on 4/1
Calling Fraction() on 1/2
Calling ~Fraction() on 1/2
Calling ~Fraction() on 4/1
Calling Fraction() on 1/1
Calling Fraction() on 2/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on 1/1
Calling Fraction() on 2/1
Calling Fraction() on 1/1
Calling Fraction() on 1/1
Calling ~Fraction() on 1/1
Calling ~Fraction() on 1/1
Calling Fraction() on 2/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on 2/1
Calling Fraction() on 1/2
Calling Fraction() on 4/1
Calling Fraction() on 7/2
Calling Fraction() on 1/1
Calling Fraction() on 2/1
Calling Fraction() on 1/1
Calling Fraction() on 7/2
Calling ~Fraction() on 7/2
Calling ~Fraction() on 1/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on 1/1
Calling ~Fraction() on 7/2
Calling ~Fraction() on 4/1
Calling ~Fraction() on 1/2
Calling RectanglePeteW() on
Rectangle:
  Lower Left: (1/2,1/1)
  Upper Right: (4/1,2/1)
  Area: 7/2

Rectangle #1 created:

Rectangle:
  Lower Left: (1/2,1/1)
  Upper Right: (4/1,2/1)
  Area: 7/2

Calling ~Fraction() on 4/1
Calling ~Fraction() on 1/1
Calling ~PointPeteW() on (1/2,2/1)
Calling ~Fraction() on 2/1
Calling ~Fraction() on 1/2
Calling ~PointPeteW() on (4/1,1/1)
Calling ~Fraction() on 1/1
Calling ~Fraction() on 4/1
  CREATING RECTANGLES MENU
(1) Create first rectangle
(2) Create second rectangle
(3) Quit
Please enter your option (1 through 3): 2

Creating second rectangle --
  Creating lower left point --
    X value --
      Please enter the numerator: -1
      Please enter the denominator: 1

Calling Fraction() on -1/1
    Y value --
      Please enter the numerator: -1
      Please enter the denominator: 2

Calling Fraction() on -1/2
Calling Fraction() on -1/1
Calling Fraction() on -1/2
Calling PointPeteW() on (-1/1,-1/2)
  Creating upper right point --
    X value --
      Please enter the numerator: 2
      Please enter the denominator: 1

    Y value --
      Please enter the numerator: -2
      Please enter the denominator: 1

Calling Fraction() on 2/1
Calling Fraction() on -2/1
Calling PointPeteW() on (2/1,-2/1)
Calling Fraction() on 0/1
Calling Fraction() on 0/1
Calling Fraction() on 2/1
Calling Fraction() on -2/1
Calling PointPeteW() on (2/1,-2/1)
Calling Fraction() on -1/1
Calling Fraction() on -1/2
Calling PointPeteW() on (-1/1,-1/2)
Calling Fraction() on 0/1
Calling ~Fraction() on 0/1
Calling Fraction() on 2/1
Calling Fraction() on -1/1
Calling ~Fraction() on -1/1
Calling ~Fraction() on 2/1
Calling Fraction() on -2/1
Calling Fraction() on -1/2
Calling ~Fraction() on -1/2
Calling ~Fraction() on -2/1
Calling Fraction() on -1/2
Calling Fraction() on -2/1
Calling Fraction() on -2/1
Calling ~Fraction() on -2/1
Calling ~Fraction() on -2/1
Calling Fraction() on -1/2
Calling ~Fraction() on -1/2
Calling ~Fraction() on -1/2
Calling Fraction() on -1/1
Calling Fraction() on 2/1
Calling Fraction() on 3/1
Calling Fraction() on -2/1
Calling Fraction() on -1/2
Calling Fraction() on 3/2
Calling Fraction() on 9/2
Calling ~Fraction() on 9/2
Calling ~Fraction() on 3/2
Calling ~Fraction() on -1/2
Calling ~Fraction() on -2/1
Calling ~Fraction() on 3/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on -1/1
Calling RectanglePeteW() on
Rectangle:
  Lower Left: (-1/1,-2/1)
  Upper Right: (2/1,-1/2)
  Area: 9/2

Rectangle #2 created:

Rectangle:
  Lower Left: (-1/1,-2/1)
  Upper Right: (2/1,-1/2)
  Area: 9/2

Calling ~Fraction() on 2/1
Calling ~Fraction() on -2/1
Calling ~PointPeteW() on (-1/1,-1/2)
Calling ~Fraction() on -1/2
Calling ~Fraction() on -1/1
Calling ~PointPeteW() on (2/1,-2/1)
Calling ~Fraction() on -2/1
Calling ~Fraction() on 2/1
  CREATING RECTANGLES MENU
(1) Create first rectangle
(2) Create second rectangle
(3) Quit
Please enter your option (1 through 3): 3

Returning to main menu.
MENU
----
(1)    Create 2 RectanglePeteW objects
(2)    Create 2 CirclePeteW objects
(3)    Create 2 BoxPeteW objects
(4)    Create 2 CylinderPeteW objects
(5)    Compare 2 selected objects by area
(6)    Compare 2 Selected objects by volume
(7)    Print selected objects
(8)    Quit
Enter your option (1, 2, 3, 4, 5, 6, 7, or 8): 2

  CREATING CIRCLES MENU --
  (1) Create first circle
  (2) Create second circle
  (3) Quit
Please select your option (1 through 3):1

Creating first circle --
  Creating center point --
    X value:
      Please enter the numerator: 1

      Please enter the denominator: 2

Calling Fraction() on 1/2
    Y value:
      Please enter the numerator: 2

      Please enter the denominator: 1

Calling Fraction() on 2/1
Calling Fraction() on 1/2
Calling Fraction() on 2/1
Calling PointPeteW() on (1/2,2/1)
    Creating radius --
      Please enter the numerator: 4

      Please enter the denominator: 1

Calling Fraction() on 4/1
Calling Fraction() on 0/1
Calling Fraction() on 0/1
Calling Fraction() on 1/2
Calling Fraction() on 2/1
Calling PointPeteW() on (1/2,2/1)
Calling Fraction() on 4/1
Calling Fraction() on 0/1
Calling ~Fraction() on 0/1
Calling Fraction() on 157/50
Calling Fraction() on 16/1
Calling Fraction() on 1256/25
Calling ~Fraction() on 1256/25
Calling ~Fraction() on 16/1
Calling ~Fraction() on 157/50
Calling CirclePeteW() on
Circle:
  Center: (1/2,2/1)
  Radius: 4/1
  Area: 1256/25
Circle #1 created:
Circle:
  Center: (1/2,2/1)
  Radius: 4/1
  Area: 1256/25
Calling ~Fraction() on 1/2
Calling ~Fraction() on 2/1
Calling ~Fraction() on 4/1
Calling ~PointPeteW() on (1/2,2/1)
Calling ~Fraction() on 2/1
Calling ~Fraction() on 1/2
  CREATING CIRCLES MENU --
  (1) Create first circle
  (2) Create second circle
  (3) Quit
Please select your option (1 through 3):2

Creating second circle --
  Creating center point --
    X value:
      Please enter the numerator: -1

      Please enter the denominator: 1

Calling Fraction() on -1/1
    Y value:
      Please enter the numerator: -1

      Please enter the denominator: 2

Calling Fraction() on -1/2
Calling Fraction() on -1/1
Calling Fraction() on -1/2
Calling PointPeteW() on (-1/1,-1/2)
    Creating radius --
      Please enter the numerator: 2

      Please enter the denominator: 1

Calling Fraction() on 2/1
Calling Fraction() on 0/1
Calling Fraction() on 0/1
Calling Fraction() on -1/1
Calling Fraction() on -1/2
Calling PointPeteW() on (-1/1,-1/2)
Calling Fraction() on 2/1
Calling Fraction() on 0/1
Calling ~Fraction() on 0/1
Calling Fraction() on 157/50
Calling Fraction() on 4/1
Calling Fraction() on 314/25
Calling ~Fraction() on 314/25
Calling ~Fraction() on 4/1
Calling ~Fraction() on 157/50
Calling CirclePeteW() on
Circle:
  Center: (-1/1,-1/2)
  Radius: 2/1
  Area: 314/25
Circle #2 created:
Circle:
  Center: (-1/1,-1/2)
  Radius: 2/1
  Area: 314/25
Calling ~Fraction() on -1/1
Calling ~Fraction() on -1/2
Calling ~Fraction() on 2/1
Calling ~PointPeteW() on (-1/1,-1/2)
Calling ~Fraction() on -1/2
Calling ~Fraction() on -1/1
  CREATING CIRCLES MENU --
  (1) Create first circle
  (2) Create second circle
  (3) Quit
Please select your option (1 through 3):3

Returning to main menu.
MENU
----
(1)    Create 2 RectanglePeteW objects
(2)    Create 2 CirclePeteW objects
(3)    Create 2 BoxPeteW objects
(4)    Create 2 CylinderPeteW objects
(5)    Compare 2 selected objects by area
(6)    Compare 2 Selected objects by volume
(7)    Print selected objects
(8)    Quit
Enter your option (1, 2, 3, 4, 5, 6, 7, or 8): 3

  CREATING BOXES MENU
(1) Create first box
(2) Create second box
(3) Quit
Please enter your option (1 through 3): 1

Creating first box --
  Creating base rectangle --
    Creating lower left point --
      X value --
        Please enter the numerator: 1
        Please enter the denominator: 2

Calling Fraction() on 1/2
      Y value --
        Please enter the numerator: 2
        Please enter the denominator: 1

Calling Fraction() on 2/1
Calling Fraction() on 1/2
Calling Fraction() on 2/1
Calling PointPeteW() on (1/2,2/1)
    Creating upper right point --
      X value --
        Please enter the numerator: 4
        Please enter the denominator: 1

      Y value --
        Please enter the numerator: 1
        Please enter the denominator: 1

Calling Fraction() on 4/1
Calling Fraction() on 1/1
Calling PointPeteW() on (4/1,1/1)
Calling Fraction() on 0/1
Calling Fraction() on 0/1
Calling Fraction() on 4/1
Calling Fraction() on 1/1
Calling PointPeteW() on (4/1,1/1)
Calling Fraction() on 1/2
Calling Fraction() on 2/1
Calling PointPeteW() on (1/2,2/1)
Calling Fraction() on 0/1
Calling ~Fraction() on 0/1
Calling Fraction() on 4/1
Calling Fraction() on 1/2
Calling ~Fraction() on 1/2
Calling ~Fraction() on 4/1
Calling Fraction() on 1/1
Calling Fraction() on 2/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on 1/1
Calling Fraction() on 2/1
Calling Fraction() on 1/1
Calling Fraction() on 1/1
Calling ~Fraction() on 1/1
Calling ~Fraction() on 1/1
Calling Fraction() on 2/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on 2/1
Calling Fraction() on 1/2
Calling Fraction() on 4/1
Calling Fraction() on 7/2
Calling Fraction() on 1/1
Calling Fraction() on 2/1
Calling Fraction() on 1/1
Calling Fraction() on 7/2
Calling ~Fraction() on 7/2
Calling ~Fraction() on 1/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on 1/1
Calling ~Fraction() on 7/2
Calling ~Fraction() on 4/1
Calling ~Fraction() on 1/2
Calling RectanglePeteW() on
Rectangle:
  Lower Left: (1/2,1/1)
  Upper Right: (4/1,2/1)
  Area: 7/2

  Base rectangle created:
Rectangle:
  Lower Left: (1/2,1/1)
  Upper Right: (4/1,2/1)
  Area: 7/2

  Creating height fraction --
    Please enter the numerator: 3

    Please enter the denominator: 4

Calling Fraction() on 3/4
  Height fraction created: 3/4
Calling Fraction() on 0/1
Calling Fraction() on 0/1
Calling Fraction() on 4/1
Calling Fraction() on 2/1
Calling PointPeteW() on (4/1,2/1)
Calling Fraction() on 1/2
Calling Fraction() on 1/1
Calling PointPeteW() on (1/2,1/1)
Calling Fraction() on 0/1
Calling ~Fraction() on 0/1
Calling Fraction() on 4/1
Calling Fraction() on 1/2
Calling ~Fraction() on 1/2
Calling ~Fraction() on 4/1
Calling Fraction() on 2/1
Calling Fraction() on 1/1
Calling ~Fraction() on 1/1
Calling ~Fraction() on 2/1
Calling Fraction() on 1/2
Calling Fraction() on 4/1
Calling Fraction() on 7/2
Calling Fraction() on 1/1
Calling Fraction() on 2/1
Calling Fraction() on 1/1
Calling Fraction() on 7/2
Calling ~Fraction() on 7/2
Calling ~Fraction() on 1/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on 1/1
Calling ~Fraction() on 7/2
Calling ~Fraction() on 4/1
Calling ~Fraction() on 1/2
Calling RectanglePeteW() on
Rectangle:
  Lower Left: (1/2,1/1)
  Upper Right: (4/1,2/1)
  Area: 7/2

Calling Fraction() on 3/4
Calling Fraction() on 4/1
Calling Fraction() on 1/2
Calling ~Fraction() on 1/2
Calling ~Fraction() on 4/1
Calling Fraction() on 2/1
Calling Fraction() on 1/1
Calling ~Fraction() on 1/1
Calling ~Fraction() on 2/1
Calling Fraction() on 1/2
Calling Fraction() on 4/1
Calling Fraction() on 7/2
Calling ~Fraction() on 4/1
Calling ~Fraction() on 1/2
Calling Fraction() on 1/1
Calling Fraction() on 2/1
Calling Fraction() on 1/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on 1/1
Calling Fraction() on 2/1
Calling Fraction() on 2/1
Calling Fraction() on 2/1
Calling Fraction() on 3/4
Calling Fraction() on 3/2
Calling Fraction() on 21/8
Calling Fraction() on 21/4
Calling Fraction() on 7/2
Calling Fraction() on 14/2
Calling Fraction() on 49/4
Calling Fraction() on 55/4
Calling ~Fraction() on 55/4
Calling ~Fraction() on 49/4
Calling ~Fraction() on 14/2
Calling ~Fraction() on 7/2
Calling ~Fraction() on 21/4
Calling ~Fraction() on 21/8
Calling ~Fraction() on 3/2
Calling ~Fraction() on 3/4
Calling ~Fraction() on 2/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on 1/1
Calling ~Fraction() on 7/2
Calling Fraction() on 1/2
Calling Fraction() on 4/1
Calling Fraction() on 7/2
Calling Fraction() on 1/1
Calling Fraction() on 2/1
Calling Fraction() on 1/1
Calling Fraction() on 7/2
Calling Fraction() on 21/8
Calling ~Fraction() on 21/8
Calling ~Fraction() on 7/2
Calling ~Fraction() on 1/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on 1/1
Calling ~Fraction() on 7/2
Calling ~Fraction() on 4/1
Calling ~Fraction() on 1/2
Calling BoxPeteW() on
Box:
  Lower left:   (1/2,1/1)
  Upper right:  (4/1,2/1)
  Height:               3/4
  Area:                 55/4
  Volume:               21/8
Box #1 created:

Box:
  Lower left:   (1/2,1/1)
  Upper right:  (4/1,2/1)
  Height:               3/4
  Area:                 55/4
  Volume:               21/8
Calling ~Fraction() on 4/1
Calling ~Fraction() on 1/1
Calling ~PointPeteW() on (1/2,2/1)
Calling ~Fraction() on 2/1
Calling ~Fraction() on 1/2
Calling ~PointPeteW() on (4/1,1/1)
Calling ~Fraction() on 1/1
Calling ~Fraction() on 4/1
Calling ~RectanglePeteW() on
Rectangle:
  Lower Left: (1/2,1/1)
  Upper Right: (4/1,2/1)
  Area: 7/2

Calling ~PointPeteW() on (1/2,1/1)
Calling ~Fraction() on 1/1
Calling ~Fraction() on 1/2
Calling ~PointPeteW() on (4/1,2/1)
Calling ~Fraction() on 2/1
Calling ~Fraction() on 4/1
Calling ~Fraction() on 0/1
Calling ~Fraction() on 7/2
Calling ~Fraction() on 3/4
  CREATING BOXES MENU
(1) Create first box
(2) Create second box
(3) Quit
Please enter your option (1 through 3): 2

Creating second box --
  Creating base rectangle --
    Creating lower left point --
      X value --
        Please enter the numerator: -1
        Please enter the denominator: 1

Calling Fraction() on -1/1
      Y value --
        Please enter the numerator: -1
        Please enter the denominator: 2

Calling Fraction() on -1/2
Calling Fraction() on -1/1
Calling Fraction() on -1/2
Calling PointPeteW() on (-1/1,-1/2)
    Creating upper right point --
      X value --
        Please enter the numerator: 2
        Please enter the denominator: 1

      Y value --
        Please enter the numerator: -2
        Please enter the denominator: 1

Calling Fraction() on 2/1
Calling Fraction() on -2/1
Calling PointPeteW() on (2/1,-2/1)
Calling Fraction() on 0/1
Calling Fraction() on 0/1
Calling Fraction() on 2/1
Calling Fraction() on -2/1
Calling PointPeteW() on (2/1,-2/1)
Calling Fraction() on -1/1
Calling Fraction() on -1/2
Calling PointPeteW() on (-1/1,-1/2)
Calling Fraction() on 0/1
Calling ~Fraction() on 0/1
Calling Fraction() on 2/1
Calling Fraction() on -1/1
Calling ~Fraction() on -1/1
Calling ~Fraction() on 2/1
Calling Fraction() on -2/1
Calling Fraction() on -1/2
Calling ~Fraction() on -1/2
Calling ~Fraction() on -2/1
Calling Fraction() on -1/2
Calling Fraction() on -2/1
Calling Fraction() on -2/1
Calling ~Fraction() on -2/1
Calling ~Fraction() on -2/1
Calling Fraction() on -1/2
Calling ~Fraction() on -1/2
Calling ~Fraction() on -1/2
Calling Fraction() on -1/1
Calling Fraction() on 2/1
Calling Fraction() on 3/1
Calling Fraction() on -2/1
Calling Fraction() on -1/2
Calling Fraction() on 3/2
Calling Fraction() on 9/2
Calling ~Fraction() on 9/2
Calling ~Fraction() on 3/2
Calling ~Fraction() on -1/2
Calling ~Fraction() on -2/1
Calling ~Fraction() on 3/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on -1/1
Calling RectanglePeteW() on
Rectangle:
  Lower Left: (-1/1,-2/1)
  Upper Right: (2/1,-1/2)
  Area: 9/2

  Base rectangle created:
Rectangle:
  Lower Left: (-1/1,-2/1)
  Upper Right: (2/1,-1/2)
  Area: 9/2

  Creating height fraction --
    Please enter the numerator: 5

    Please enter the denominator: 6

Calling Fraction() on 5/6
  Height fraction created: 5/6
Calling Fraction() on 0/1
Calling Fraction() on 0/1
Calling Fraction() on 2/1
Calling Fraction() on -1/2
Calling PointPeteW() on (2/1,-1/2)
Calling Fraction() on -1/1
Calling Fraction() on -2/1
Calling PointPeteW() on (-1/1,-2/1)
Calling Fraction() on 0/1
Calling ~Fraction() on 0/1
Calling Fraction() on 2/1
Calling Fraction() on -1/1
Calling ~Fraction() on -1/1
Calling ~Fraction() on 2/1
Calling Fraction() on -1/2
Calling Fraction() on -2/1
Calling ~Fraction() on -2/1
Calling ~Fraction() on -1/2
Calling Fraction() on -1/1
Calling Fraction() on 2/1
Calling Fraction() on 3/1
Calling Fraction() on -2/1
Calling Fraction() on -1/2
Calling Fraction() on 3/2
Calling Fraction() on 9/2
Calling ~Fraction() on 9/2
Calling ~Fraction() on 3/2
Calling ~Fraction() on -1/2
Calling ~Fraction() on -2/1
Calling ~Fraction() on 3/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on -1/1
Calling RectanglePeteW() on
Rectangle:
  Lower Left: (-1/1,-2/1)
  Upper Right: (2/1,-1/2)
  Area: 9/2

Calling Fraction() on 5/6
Calling Fraction() on 2/1
Calling Fraction() on -1/1
Calling ~Fraction() on -1/1
Calling ~Fraction() on 2/1
Calling Fraction() on -1/2
Calling Fraction() on -2/1
Calling ~Fraction() on -2/1
Calling ~Fraction() on -1/2
Calling Fraction() on -1/1
Calling Fraction() on 2/1
Calling Fraction() on 3/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on -1/1
Calling Fraction() on -2/1
Calling Fraction() on -1/2
Calling Fraction() on 3/2
Calling ~Fraction() on -1/2
Calling ~Fraction() on -2/1
Calling Fraction() on 2/1
Calling Fraction() on 2/1
Calling Fraction() on 2/1
Calling Fraction() on 5/4
Calling Fraction() on 5/2
Calling Fraction() on 5/2
Calling Fraction() on 10/2
Calling Fraction() on 9/2
Calling Fraction() on 18/2
Calling Fraction() on 28/2
Calling Fraction() on 33/2
Calling ~Fraction() on 33/2
Calling ~Fraction() on 28/2
Calling ~Fraction() on 18/2
Calling ~Fraction() on 9/2
Calling ~Fraction() on 10/2
Calling ~Fraction() on 5/2
Calling ~Fraction() on 5/2
Calling ~Fraction() on 5/4
Calling ~Fraction() on 2/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on 3/2
Calling ~Fraction() on 3/1
Calling Fraction() on -1/1
Calling Fraction() on 2/1
Calling Fraction() on 3/1
Calling Fraction() on -2/1
Calling Fraction() on -1/2
Calling Fraction() on 3/2
Calling Fraction() on 9/2
Calling Fraction() on 15/4
Calling ~Fraction() on 15/4
Calling ~Fraction() on 9/2
Calling ~Fraction() on 3/2
Calling ~Fraction() on -1/2
Calling ~Fraction() on -2/1
Calling ~Fraction() on 3/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on -1/1
Calling BoxPeteW() on
Box:
  Lower left:   (-1/1,-2/1)
  Upper right:  (2/1,-1/2)
  Height:               5/6
  Area:                 33/2
  Volume:               15/4
Box #2 created:

Box:
  Lower left:   (-1/1,-2/1)
  Upper right:  (2/1,-1/2)
  Height:               5/6
  Area:                 33/2
  Volume:               15/4
Calling ~Fraction() on 2/1
Calling ~Fraction() on -2/1
Calling ~PointPeteW() on (-1/1,-1/2)
Calling ~Fraction() on -1/2
Calling ~Fraction() on -1/1
Calling ~PointPeteW() on (2/1,-2/1)
Calling ~Fraction() on -2/1
Calling ~Fraction() on 2/1
Calling ~RectanglePeteW() on
Rectangle:
  Lower Left: (-1/1,-2/1)
  Upper Right: (2/1,-1/2)
  Area: 9/2

Calling ~PointPeteW() on (-1/1,-2/1)
Calling ~Fraction() on -2/1
Calling ~Fraction() on -1/1
Calling ~PointPeteW() on (2/1,-1/2)
Calling ~Fraction() on -1/2
Calling ~Fraction() on 2/1
Calling ~Fraction() on 0/1
Calling ~Fraction() on 9/2
Calling ~Fraction() on 5/6
  CREATING BOXES MENU
(1) Create first box
(2) Create second box
(3) Quit
Please enter your option (1 through 3): 3

Returning to main menu.
MENU
----
(1)    Create 2 RectanglePeteW objects
(2)    Create 2 CirclePeteW objects
(3)    Create 2 BoxPeteW objects
(4)    Create 2 CylinderPeteW objects
(5)    Compare 2 selected objects by area
(6)    Compare 2 Selected objects by volume
(7)    Print selected objects
(8)    Quit
Enter your option (1, 2, 3, 4, 5, 6, 7, or 8): 4

  CREATING CYLINDERS MENU --
  (1) Create first cylinder
  (2) Create second cylinder
  (3) Quit
Please select your option (1 through 3):1

Creating first cylinder --
  Creating base circle --
    Creating center point --
      X value:
        Please enter the numerator: 1

        Please enter the denominator: 2

Calling Fraction() on 1/2
      Y value:
        Please enter the numerator: 2

        Please enter the denominator: 1

Calling Fraction() on 2/1
Calling Fraction() on 1/2
Calling Fraction() on 2/1
Calling PointPeteW() on (1/2,2/1)
      Creating radius --
        Please enter the numerator: 4

        Please enter the denominator: 1

Calling Fraction() on 4/1
Calling Fraction() on 0/1
Calling Fraction() on 0/1
Calling Fraction() on 1/2
Calling Fraction() on 2/1
Calling PointPeteW() on (1/2,2/1)
Calling Fraction() on 4/1
Calling Fraction() on 0/1
Calling ~Fraction() on 0/1
Calling Fraction() on 157/50
Calling Fraction() on 16/1
Calling Fraction() on 1256/25
Calling ~Fraction() on 1256/25
Calling ~Fraction() on 16/1
Calling ~Fraction() on 157/50
Calling CirclePeteW() on
Circle:
  Center: (1/2,2/1)
  Radius: 4/1
  Area: 1256/25
  Base circle created:
Circle:
  Center: (1/2,2/1)
  Radius: 4/1
  Area: 1256/25
  Creating height fraction --
    Please enter the numerator: 3

    Please enter the denominator: 4

Calling Fraction() on 3/4
  Height fraction created: 3/4
Calling Fraction() on 0/1
Calling Fraction() on 0/1
Calling Fraction() on 1/2
Calling Fraction() on 2/1
Calling PointPeteW() on (1/2,2/1)
Calling Fraction() on 4/1
Calling Fraction() on 0/1
Calling ~Fraction() on 0/1
Calling Fraction() on 157/50
Calling Fraction() on 16/1
Calling Fraction() on 1256/25
Calling ~Fraction() on 1256/25
Calling ~Fraction() on 16/1
Calling ~Fraction() on 157/50
Calling CirclePeteW() on
Circle:
  Center: (1/2,2/1)
  Radius: 4/1
  Area: 1256/25
Calling Fraction() on 3/4
Calling Fraction() on 157/50
Calling Fraction() on 2/1
Calling Fraction() on 19/4
Calling Fraction() on 314/25
Calling Fraction() on 628/25
Calling Fraction() on 2983/25
Calling ~Fraction() on 2983/25
Calling ~Fraction() on 628/25
Calling ~Fraction() on 314/25
Calling ~Fraction() on 19/4
Calling ~Fraction() on 2/1
Calling ~Fraction() on 157/50
Calling Fraction() on 157/50
Calling Fraction() on 2/1
Calling Fraction() on 314/25
Calling Fraction() on 1256/25
Calling Fraction() on 942/25
Calling Fraction() on 1884/25
Calling ~Fraction() on 1884/25
Calling ~Fraction() on 942/25
Calling ~Fraction() on 1256/25
Calling ~Fraction() on 314/25
Calling ~Fraction() on 2/1
Calling ~Fraction() on 157/50
Calling CylinderPeteW() on
Cylinder:
  Center:       (1/2,2/1)
  Radius:       4/1
  Height:       3/4
  Area:         2983/25
  Volume:       1884/25

Cylinder #1 created:
Cylinder:
  Center:       (1/2,2/1)
  Radius:       4/1
  Height:       3/4
  Area:         2983/25
  Volume:       1884/25

Calling ~Fraction() on 1/2
Calling ~Fraction() on 2/1
Calling ~Fraction() on 4/1
Calling ~PointPeteW() on (1/2,2/1)
Calling ~Fraction() on 2/1
Calling ~Fraction() on 1/2
Calling ~CirclePeteW() on
Circle:
  Center: (1/2,2/1)
  Radius: 4/1
  Area: 1256/25
Calling ~Fraction() on 4/1
Calling ~PointPeteW() on (1/2,2/1)
Calling ~Fraction() on 2/1
Calling ~Fraction() on 1/2
Calling ~Fraction() on 0/1
Calling ~Fraction() on 1256/25
Calling ~Fraction() on 3/4
  CREATING CYLINDERS MENU --
  (1) Create first cylinder
  (2) Create second cylinder
  (3) Quit
Please select your option (1 through 3):3

Returning to main menu.
MENU
----
(1)    Create 2 RectanglePeteW objects
(2)    Create 2 CirclePeteW objects
(3)    Create 2 BoxPeteW objects
(4)    Create 2 CylinderPeteW objects
(5)    Compare 2 selected objects by area
(6)    Compare 2 Selected objects by volume
(7)    Print selected objects
(8)    Quit
Enter your option (1, 2, 3, 4, 5, 6, 7, or 8): 4

  CREATING CYLINDERS MENU --
  (1) Create first cylinder
  (2) Create second cylinder
  (3) Quit
Please select your option (1 through 3):2

Creating second cylinder --
  Creating base circle --
    Creating center point --
      X value:
        Please enter the numerator: 1

        Please enter the denominator: -1

Calling Fraction() on -1/1
      Y value:
        Please enter the numerator: -1

        Please enter the denominator: 2

Calling Fraction() on -1/2
Calling Fraction() on -1/1
Calling Fraction() on -1/2
Calling PointPeteW() on (-1/1,-1/2)
      Creating radius --
        Please enter the numerator: 2

        Please enter the denominator: 1

Calling Fraction() on 2/1
Calling Fraction() on 0/1
Calling Fraction() on 0/1
Calling Fraction() on -1/1
Calling Fraction() on -1/2
Calling PointPeteW() on (-1/1,-1/2)
Calling Fraction() on 2/1
Calling Fraction() on 0/1
Calling ~Fraction() on 0/1
Calling Fraction() on 157/50
Calling Fraction() on 4/1
Calling Fraction() on 314/25
Calling ~Fraction() on 314/25
Calling ~Fraction() on 4/1
Calling ~Fraction() on 157/50
Calling CirclePeteW() on
Circle:
  Center: (-1/1,-1/2)
  Radius: 2/1
  Area: 314/25
  Base circle created:
Circle:
  Center: (-1/1,-1/2)
  Radius: 2/1
  Area: 314/25
  Creating height fraction --
    Please enter the numerator: 5

    Please enter the denominator: 6

Calling Fraction() on 5/6
  Height fraction created: 5/6
Calling Fraction() on 0/1
Calling Fraction() on 0/1
Calling Fraction() on -1/1
Calling Fraction() on -1/2
Calling PointPeteW() on (-1/1,-1/2)
Calling Fraction() on 2/1
Calling Fraction() on 0/1
Calling ~Fraction() on 0/1
Calling Fraction() on 157/50
Calling Fraction() on 4/1
Calling Fraction() on 314/25
Calling ~Fraction() on 314/25
Calling ~Fraction() on 4/1
Calling ~Fraction() on 157/50
Calling CirclePeteW() on
Circle:
  Center: (-1/1,-1/2)
  Radius: 2/1
  Area: 314/25
Calling Fraction() on 5/6
Calling Fraction() on 157/50
Calling Fraction() on 2/1
Calling Fraction() on 17/6
Calling Fraction() on 157/25
Calling Fraction() on 314/25
Calling Fraction() on 2669/75
Calling ~Fraction() on 2669/75
Calling ~Fraction() on 314/25
Calling ~Fraction() on 157/25
Calling ~Fraction() on 17/6
Calling ~Fraction() on 2/1
Calling ~Fraction() on 157/50
Calling Fraction() on 157/50
Calling Fraction() on 2/1
Calling Fraction() on 157/25
Calling Fraction() on 314/25
Calling Fraction() on 157/15
Calling Fraction() on 314/15
Calling ~Fraction() on 314/15
Calling ~Fraction() on 157/15
Calling ~Fraction() on 314/25
Calling ~Fraction() on 157/25
Calling ~Fraction() on 2/1
Calling ~Fraction() on 157/50
Calling CylinderPeteW() on
Cylinder:
  Center:       (-1/1,-1/2)
  Radius:       2/1
  Height:       5/6
  Area:         2669/75
  Volume:       314/15

Cylinder #2 created:
Cylinder:
  Center:       (-1/1,-1/2)
  Radius:       2/1
  Height:       5/6
  Area:         2669/75
  Volume:       314/15

Calling ~Fraction() on -1/1
Calling ~Fraction() on -1/2
Calling ~Fraction() on 2/1
Calling ~PointPeteW() on (-1/1,-1/2)
Calling ~Fraction() on -1/2
Calling ~Fraction() on -1/1
Calling ~CirclePeteW() on
Circle:
  Center: (-1/1,-1/2)
  Radius: 2/1
  Area: 314/25
Calling ~Fraction() on 2/1
Calling ~PointPeteW() on (-1/1,-1/2)
Calling ~Fraction() on -1/2
Calling ~Fraction() on -1/1
Calling ~Fraction() on 0/1
Calling ~Fraction() on 314/25
Calling ~Fraction() on 5/6
  CREATING CYLINDERS MENU --
  (1) Create first cylinder
  (2) Create second cylinder
  (3) Quit
Please select your option (1 through 3):3

Returning to main menu.
MENU
----
(1)    Create 2 RectanglePeteW objects
(2)    Create 2 CirclePeteW objects
(3)    Create 2 BoxPeteW objects
(4)    Create 2 CylinderPeteW objects
(5)    Compare 2 selected objects by area
(6)    Compare 2 Selected objects by volume
(7)    Print selected objects
(8)    Quit
Enter your option (1, 2, 3, 4, 5, 6, 7, or 8): 5

  Comparing by area - Select two objects to compare --
Please select the first object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
  (5) Box 1
  (6) Box 2
  (7) Cylinder 1
  (8) Cylinder 2
Please select your object (1 through 8): 1

Please select the second object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
  (5) Box 1
  (6) Box 2
  (7) Cylinder 1
  (8) Cylinder 2
Please select your object (1 through 8): 2

Comparing area --

Calling Fraction() on 9/2
Calling Fraction() on 7/2
Calling ~Fraction() on 7/2
Calling ~Fraction() on 9/2
Calling Fraction() on 9/2
Calling Fraction() on 7/2
Calling ~Fraction() on 7/2
Calling ~Fraction() on 9/2
Rectangle:
  Lower Left: (-1/1,-2/1)
  Upper Right: (2/1,-1/2)
  Area: 9/2
 is larger than
Rectangle:
  Lower Left: (1/2,1/1)
  Upper Right: (4/1,2/1)
  Area: 7/2

MENU
----
(1)    Create 2 RectanglePeteW objects
(2)    Create 2 CirclePeteW objects
(3)    Create 2 BoxPeteW objects
(4)    Create 2 CylinderPeteW objects
(5)    Compare 2 selected objects by area
(6)    Compare 2 Selected objects by volume
(7)    Print selected objects
(8)    Quit
Enter your option (1, 2, 3, 4, 5, 6, 7, or 8): 5

  Comparing by area - Select two objects to compare --
Please select the first object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
  (5) Box 1
  (6) Box 2
  (7) Cylinder 1
  (8) Cylinder 2
Please select your object (1 through 8): 1

Please select the second object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
  (5) Box 1
  (6) Box 2
  (7) Cylinder 1
  (8) Cylinder 2
Please select your object (1 through 8): 3

Comparing area --

Calling Fraction() on 1256/25
Calling Fraction() on 7/2
Calling ~Fraction() on 7/2
Calling ~Fraction() on 1256/25
Calling Fraction() on 1256/25
Calling Fraction() on 7/2
Calling ~Fraction() on 7/2
Calling ~Fraction() on 1256/25
Circle:
  Center: (1/2,2/1)
  Radius: 4/1
  Area: 1256/25 is larger than
Rectangle:
  Lower Left: (1/2,1/1)
  Upper Right: (4/1,2/1)
  Area: 7/2

MENU
----
(1)    Create 2 RectanglePeteW objects
(2)    Create 2 CirclePeteW objects
(3)    Create 2 BoxPeteW objects
(4)    Create 2 CylinderPeteW objects
(5)    Compare 2 selected objects by area
(6)    Compare 2 Selected objects by volume
(7)    Print selected objects
(8)    Quit
Enter your option (1, 2, 3, 4, 5, 6, 7, or 8): 5

  Comparing by area - Select two objects to compare --
Please select the first object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
  (5) Box 1
  (6) Box 2
  (7) Cylinder 1
  (8) Cylinder 2
Please select your object (1 through 8): 2

Please select the second object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
  (5) Box 1
  (6) Box 2
  (7) Cylinder 1
  (8) Cylinder 2
Please select your object (1 through 8): 5

Comparing area --

Calling Fraction() on 55/4
Calling Fraction() on 9/2
Calling ~Fraction() on 9/2
Calling ~Fraction() on 55/4
Calling Fraction() on 55/4
Calling Fraction() on 9/2
Calling ~Fraction() on 9/2
Calling ~Fraction() on 55/4
Box:
  Lower left:   (1/2,1/1)
  Upper right:  (4/1,2/1)
  Height:               3/4
  Area:                 55/4
  Volume:               21/8 is larger than
Rectangle:
  Lower Left: (-1/1,-2/1)
  Upper Right: (2/1,-1/2)
  Area: 9/2

MENU
----
(1)    Create 2 RectanglePeteW objects
(2)    Create 2 CirclePeteW objects
(3)    Create 2 BoxPeteW objects
(4)    Create 2 CylinderPeteW objects
(5)    Compare 2 selected objects by area
(6)    Compare 2 Selected objects by volume
(7)    Print selected objects
(8)    Quit
Enter your option (1, 2, 3, 4, 5, 6, 7, or 8): 5

  Comparing by area - Select two objects to compare --
Please select the first object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
  (5) Box 1
  (6) Box 2
  (7) Cylinder 1
  (8) Cylinder 2
Please select your object (1 through 8): 6

Please select the second object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
  (5) Box 1
  (6) Box 2
  (7) Cylinder 1
  (8) Cylinder 2
Please select your object (1 through 8): 8

Comparing area --

Calling Fraction() on 2669/75
Calling Fraction() on 33/2
Calling ~Fraction() on 33/2
Calling ~Fraction() on 2669/75
Calling Fraction() on 2669/75
Calling Fraction() on 33/2
Calling ~Fraction() on 33/2
Calling ~Fraction() on 2669/75
Cylinder:
  Center:       (-1/1,-1/2)
  Radius:       2/1
  Height:       5/6
  Area:         2669/75
  Volume:       314/15
 is larger than
Box:
  Lower left:   (-1/1,-2/1)
  Upper right:  (2/1,-1/2)
  Height:               5/6
  Area:                 33/2
  Volume:               15/4
MENU
----
(1)    Create 2 RectanglePeteW objects
(2)    Create 2 CirclePeteW objects
(3)    Create 2 BoxPeteW objects
(4)    Create 2 CylinderPeteW objects
(5)    Compare 2 selected objects by area
(6)    Compare 2 Selected objects by volume
(7)    Print selected objects
(8)    Quit
Enter your option (1, 2, 3, 4, 5, 6, 7, or 8): 6

  Comparing by volume - Select two objects to compare --
Please select the first object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
  (5) Box 1
  (6) Box 2
  (7) Cylinder 1
  (8) Cylinder 2
Please select your object (1 through 8): 1

Please select the second object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
  (5) Box 1
  (6) Box 2
  (7) Cylinder 1
  (8) Cylinder 2
Please select your object (1 through 8): 7

Comparing volume --

Calling Fraction() on 1884/25
Calling Fraction() on 0/1
Calling ~Fraction() on 0/1
Calling ~Fraction() on 1884/25
Calling Fraction() on 1884/25
Calling Fraction() on 0/1
Calling ~Fraction() on 0/1
Calling ~Fraction() on 1884/25
Cylinder:
  Center:       (1/2,2/1)
  Radius:       4/1
  Height:       3/4
  Area:         2983/25
  Volume:       1884/25
 is larger than
Rectangle:
  Lower Left: (1/2,1/1)
  Upper Right: (4/1,2/1)
  Area: 7/2

MENU
----
(1)    Create 2 RectanglePeteW objects
(2)    Create 2 CirclePeteW objects
(3)    Create 2 BoxPeteW objects
(4)    Create 2 CylinderPeteW objects
(5)    Compare 2 selected objects by area
(6)    Compare 2 Selected objects by volume
(7)    Print selected objects
(8)    Quit
Enter your option (1, 2, 3, 4, 5, 6, 7, or 8): 6

  Comparing by volume - Select two objects to compare --
Please select the first object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
  (5) Box 1
  (6) Box 2
  (7) Cylinder 1
  (8) Cylinder 2
Please select your object (1 through 8): 6

Please select the second object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
  (5) Box 1
  (6) Box 2
  (7) Cylinder 1
  (8) Cylinder 2
Please select your object (1 through 8): 7

Comparing volume --

Calling Fraction() on 1884/25
Calling Fraction() on 15/4
Calling ~Fraction() on 15/4
Calling ~Fraction() on 1884/25
Calling Fraction() on 1884/25
Calling Fraction() on 15/4
Calling ~Fraction() on 15/4
Calling ~Fraction() on 1884/25
Cylinder:
  Center:       (1/2,2/1)
  Radius:       4/1
  Height:       3/4
  Area:         2983/25
  Volume:       1884/25
 is larger than
Box:
  Lower left:   (-1/1,-2/1)
  Upper right:  (2/1,-1/2)
  Height:               5/6
  Area:                 33/2
  Volume:               15/4
MENU
----
(1)    Create 2 RectanglePeteW objects
(2)    Create 2 CirclePeteW objects
(3)    Create 2 BoxPeteW objects
(4)    Create 2 CylinderPeteW objects
(5)    Compare 2 selected objects by area
(6)    Compare 2 Selected objects by volume
(7)    Print selected objects
(8)    Quit
Enter your option (1, 2, 3, 4, 5, 6, 7, or 8): 7

Printing existing objects --

Rectangle:
  Lower Left: (1/2,1/1)
  Upper Right: (4/1,2/1)
  Area: 7/2

Rectangle:
  Lower Left: (-1/1,-2/1)
  Upper Right: (2/1,-1/2)
  Area: 9/2

Circle:
  Center: (1/2,2/1)
  Radius: 4/1
  Area: 1256/25
Circle:
  Center: (1/2,2/1)
  Radius: 4/1
  Area: 1256/25
Box:
  Lower left:   (1/2,1/1)
  Upper right:  (4/1,2/1)
  Height:               3/4
  Area:                 55/4
  Volume:               21/8
Box:
  Lower left:   (-1/1,-2/1)
  Upper right:  (2/1,-1/2)
  Height:               5/6
  Area:                 33/2
  Volume:               15/4
Cylinder:
  Center:       (1/2,2/1)
  Radius:       4/1
  Height:       3/4
  Area:         2983/25
  Volume:       1884/25

Cylinder:
  Center:       (-1/1,-1/2)
  Radius:       2/1
  Height:       5/6
  Area:         2669/75
  Volume:       314/15

MENU
----
(1)    Create 2 RectanglePeteW objects
(2)    Create 2 CirclePeteW objects
(3)    Create 2 BoxPeteW objects
(4)    Create 2 CylinderPeteW objects
(5)    Compare 2 selected objects by area
(6)    Compare 2 Selected objects by volume
(7)    Print selected objects
(8)    Quit
Enter your option (1, 2, 3, 4, 5, 6, 7, or 8): 8


  Have fun!
Calling ~BoxPeteW() on
Box:
  Lower left:   (1/2,1/1)
  Upper right:  (4/1,2/1)
  Height:               3/4
  Area:                 55/4
  Volume:               21/8
Calling ~Fraction() on 3/4
Calling ~RectanglePeteW() on
Rectangle:
  Lower Left: (1/2,1/1)
  Upper Right: (4/1,2/1)
  Area: 55/4

Calling ~PointPeteW() on (1/2,1/1)
Calling ~Fraction() on 1/1
Calling ~Fraction() on 1/2
Calling ~PointPeteW() on (4/1,2/1)
Calling ~Fraction() on 2/1
Calling ~Fraction() on 4/1
Calling ~Fraction() on 21/8
Calling ~Fraction() on 55/4
Calling ~BoxPeteW() on
Box:
  Lower left:   (-1/1,-2/1)
  Upper right:  (2/1,-1/2)
  Height:               5/6
  Area:                 33/2
  Volume:               15/4
Calling ~Fraction() on 5/6
Calling ~RectanglePeteW() on
Rectangle:
  Lower Left: (-1/1,-2/1)
  Upper Right: (2/1,-1/2)
  Area: 33/2

Calling ~PointPeteW() on (-1/1,-2/1)
Calling ~Fraction() on -2/1
Calling ~Fraction() on -1/1
Calling ~PointPeteW() on (2/1,-1/2)
Calling ~Fraction() on -1/2
Calling ~Fraction() on 2/1
Calling ~Fraction() on 15/4
Calling ~Fraction() on 33/2
Calling ~CirclePeteW() on
Circle:
  Center: (1/2,2/1)
  Radius: 4/1
  Area: 1256/25
Calling ~Fraction() on 4/1
Calling ~PointPeteW() on (1/2,2/1)
Calling ~Fraction() on 2/1
Calling ~Fraction() on 1/2
Calling ~Fraction() on 0/1
Calling ~Fraction() on 1256/25
Calling ~CirclePeteW() on
Circle:
  Center: (-1/1,-1/2)
  Radius: 2/1
  Area: 314/25
Calling ~Fraction() on 2/1
Calling ~PointPeteW() on (-1/1,-1/2)
Calling ~Fraction() on -1/2
Calling ~Fraction() on -1/1
Calling ~Fraction() on 0/1
Calling ~Fraction() on 314/25
Calling ~CylinderPeteW() on
Cylinder:
  Center:       (1/2,2/1)
  Radius:       4/1
  Height:       3/4
  Area:         2983/25
  Volume:       1884/25

Calling ~Fraction() on 3/4
Calling ~CirclePeteW() on
Circle:
  Center: (1/2,2/1)
  Radius: 4/1
  Area: 2983/25
Calling ~Fraction() on 4/1
Calling ~PointPeteW() on (1/2,2/1)
Calling ~Fraction() on 2/1
Calling ~Fraction() on 1/2
Calling ~Fraction() on 1884/25
Calling ~Fraction() on 2983/25
Calling ~CylinderPeteW() on
Cylinder:
  Center:       (-1/1,-1/2)
  Radius:       2/1
  Height:       5/6
  Area:         2669/75
  Volume:       314/15

Calling ~Fraction() on 5/6
Calling ~CirclePeteW() on
Circle:
  Center: (-1/1,-1/2)
  Radius: 2/1
  Area: 2669/75
Calling ~Fraction() on 2/1
Calling ~PointPeteW() on (-1/1,-1/2)
Calling ~Fraction() on -1/2
Calling ~Fraction() on -1/1
Calling ~Fraction() on 314/15
Calling ~Fraction() on 2669/75
Calling ~RectanglePeteW() on
Rectangle:
  Lower Left: (1/2,1/1)
  Upper Right: (4/1,2/1)
  Area: 7/2

Calling ~PointPeteW() on (1/2,1/1)
Calling ~Fraction() on 1/1
Calling ~Fraction() on 1/2
Calling ~PointPeteW() on (4/1,2/1)
Calling ~Fraction() on 2/1
Calling ~Fraction() on 4/1
Calling ~Fraction() on 0/1
Calling ~Fraction() on 7/2
Calling ~RectanglePeteW() on
Rectangle:
  Lower Left: (-1/1,-2/1)
  Upper Right: (2/1,-1/2)
  Area: 9/2

Calling ~PointPeteW() on (-1/1,-2/1)
Calling ~Fraction() on -2/1
Calling ~Fraction() on -1/1
Calling ~PointPeteW() on (2/1,-1/2)
Calling ~Fraction() on -1/2
Calling ~Fraction() on 2/1
Calling ~Fraction() on 0/1
Calling ~Fraction() on 9/2
*/