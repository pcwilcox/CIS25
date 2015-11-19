/**
  * Program Name: CIS25Fall2015PeteWilcoxLab6Ex1.cpp
  * Discussion:   Lab #6 Exercise #1
  * Written by:   Pete Wilcox
  * Date:         2015/11/XX
  */

#include <iostream>
#include "fractionPeteW.h"
#include "PointPeteW.h"
#include "CIS25Fall2015PeteWilcoxLab6Ex1Driver.h"

void userInterface(PointPeteW**);

int main() {
	PointPeteW* point = nullptr;

	display();

	userInterface(&point);	

	delete point;

	return 0;
}

void userInterface(PointPeteW** point) {
	int menuChoice;
	do {
		menuMain();
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			menuInit(point);
			break;
		case 2:
			if ((*point) == nullptr) {
				cout << "\n\n  Not a proper call as no points"
					" available!";
			} else {
				menuMove(point);
			}
			break;
		case 3:
			if ((*point) == nullptr) {
				cout << "\n\n  Not a proper call as no points"
					" available!";
			} else {
				menuFlip(point);
			}
			break;

		case 4:
			if ((*point) == nullptr) {
				cout << "\n\n  Not a proper call as no points"
					" available!";
			} else {
				menuPrint(point);
			}
			break;
		case 5:
			cout << "\n\n  Having Fun ...";
			break;
		default:
			cout << "\n\n  WRONG OPTION!";
		}

	} while (menuChoice != 5);
}

/**************************************
*           PROGRAM OUTPUT:           *
***************************************

CIS 25 - C++ Programming
Laney College
Pete Wilcox

Assignment Information --
  Assignment Number:  Lab 6,
                      Exercise #1
  Written by:         Pete Wilcox
  Due Date:           2015/11/XX


********************
*    MENU Point    *
*  1. Initializing *
*  2. Moving       *
*  3. Flipping     *
*  4. Printing     *
*  5. Quitting     *
********************
Select an option (use integer value only): 8


  WRONG OPTION!

********************
*    MENU Point    *
*  1. Initializing *
*  2. Moving       *
*  3. Flipping     *
*  4. Printing     *
*  5. Quitting     *
********************
Select an option (use integer value only): 2


  Not a proper call as no points available!

********************
*    MENU Point    *
*  1. Initializing *
*  2. Moving       *
*  3. Flipping     *
*  4. Printing     *
*  5. Quitting     *
********************
Select an option (use integer value only): 1


  ******************************
  * MENU InitPoint             *
  *  1. Set point X-coordinate *
  *  2. Set point Y-coordinate *
  *  3. Printing               *
  *  4. Returning              *
  ******************************
  Please select an option (integer value only): 1

  Please enter the numerator: 1

  Please enter the denominator: 2

Calling Fraction()
Calling Fraction()
Calling Fraction()
Calling PointPeteW() on (1/2,0/1)
Calling ~Fraction() on 1/2

  ******************************
  * MENU InitPoint             *
  *  1. Set point X-coordinate *
  *  2. Set point Y-coordinate *
  *  3. Printing               *
  *  4. Returning              *
  ******************************
  Please select an option (integer value only): 2

  Please enter the numerator: 2

  Please enter the denominator: 1


  ******************************
  * MENU InitPoint             *
  *  1. Set point X-coordinate *
  *  2. Set point Y-coordinate *
  *  3. Printing               *
  *  4. Returning              *
  ******************************
  Please select an option (integer value only): 3

  The point is currently at (1/2,2/1)

  ******************************
  * MENU InitPoint             *
  *  1. Set point X-coordinate *
  *  2. Set point Y-coordinate *
  *  3. Printing               *
  *  4. Returning              *
  ******************************
  Please select an option (integer value only): 4

  Returning to "MENU Point"

********************
*    MENU Point    *
*  1. Initializing *
*  2. Moving       *
*  3. Flipping     *
*  4. Printing     *
*  5. Quitting     *
********************
Select an option (use integer value only): 2


  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 1

  Enter the numerator for frX: 2

  Enter the denominator for frX: 3

  Enter the numerator for frY: 3

  Enter the denominator for frY: 4

Calling Fraction()
Calling Fraction()
Calling ~Fraction() on 2/3
Calling ~Fraction() on 3/4

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 3

  The point is currently at (7/6,11/4)

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 4

  Returning to "MENU Point"

********************
*    MENU Point    *
*  1. Initializing *
*  2. Moving       *
*  3. Flipping     *
*  4. Printing     *
*  5. Quitting     *
********************
Select an option (use integer value only): 3


  ***********************
  * MENU FlippingPoint  *
  *  1. By Y            *
  *  2. By X            *
  *  3. By Origin       *
  *  4. Printing        *
  *  5. Returning       *
  ***********************
  Select an option (use integer value only): 1


  ***********************
  * MENU FlippingPoint  *
  *  1. By Y            *
  *  2. By X            *
  *  3. By Origin       *
  *  4. Printing        *
  *  5. Returning       *
  ***********************
  Select an option (use integer value only): 4

  The point is currently at (7/6,-11/4)

  ***********************
  * MENU FlippingPoint  *
  *  1. By Y            *
  *  2. By X            *
  *  3. By Origin       *
  *  4. Printing        *
  *  5. Returning       *
  ***********************
  Select an option (use integer value only): 2


  ***********************
  * MENU FlippingPoint  *
  *  1. By Y            *
  *  2. By X            *
  *  3. By Origin       *
  *  4. Printing        *
  *  5. Returning       *
  ***********************
  Select an option (use integer value only): 4

  The point is currently at (-7/6,-11/4)

  ***********************
  * MENU FlippingPoint  *
  *  1. By Y            *
  *  2. By X            *
  *  3. By Origin       *
  *  4. Printing        *
  *  5. Returning       *
  ***********************
  Select an option (use integer value only): 3


  ***********************
  * MENU FlippingPoint  *
  *  1. By Y            *
  *  2. By X            *
  *  3. By Origin       *
  *  4. Printing        *
  *  5. Returning       *
  ***********************
  Select an option (use integer value only): 4

  The point is currently at (7/6,11/4)

  ***********************
  * MENU FlippingPoint  *
  *  1. By Y            *
  *  2. By X            *
  *  3. By Origin       *
  *  4. Printing        *
  *  5. Returning       *
  ***********************
  Select an option (use integer value only): 5

  Returning to "MENU Point"

********************
*    MENU Point    *
*  1. Initializing *
*  2. Moving       *
*  3. Flipping     *
*  4. Printing     *
*  5. Quitting     *
********************
Select an option (use integer value only): 4


 *******************************
  * MENU PrintingPoint          *
  *  1. By member print()       *
  *  2. By stand alone print()  *
  *  3. By operator<<           *
  *  4. Returning               *
  *******************************
  Select an option (use integer value only): 1

(7/6,11/4)

 *******************************
  * MENU PrintingPoint          *
  *  1. By member print()       *
  *  2. By stand alone print()  *
  *  3. By operator<<           *
  *  4. Returning               *
  *******************************
  Select an option (use integer value only): 2

Calling Fraction()
Calling Fraction()

  X: 7/6, Y: 11/4
Calling ~Fraction() on 7/6
Calling ~Fraction() on 11/4

 *******************************
  * MENU PrintingPoint          *
  *  1. By member print()       *
  *  2. By stand alone print()  *
  *  3. By operator<<           *
  *  4. Returning               *
  *******************************
  Select an option (use integer value only): 3

  The point is currently at (7/6,11/4)

 *******************************
  * MENU PrintingPoint          *
  *  1. By member print()       *
  *  2. By stand alone print()  *
  *  3. By operator<<           *
  *  4. Returning               *
  *******************************
  Select an option (use integer value only): 4

  Returning to "MENU Point"

********************
*    MENU Point    *
*  1. Initializing *
*  2. Moving       *
*  3. Flipping     *
*  4. Printing     *
*  5. Quitting     *
********************
Select an option (use integer value only): 5


  Having Fun ...
Calling ~PointPeteW() on (7/6,11/4)
Calling ~Fraction() on 11/4
Calling ~Fraction() on 7/6

******************************************/