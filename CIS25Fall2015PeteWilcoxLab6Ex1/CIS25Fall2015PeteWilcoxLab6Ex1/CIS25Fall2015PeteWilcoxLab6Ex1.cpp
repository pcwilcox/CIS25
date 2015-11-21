/**
  * Program Name: CIS25Fall2015PeteWilcoxLab6Ex1.cpp
  * Discussion:   Lab #6 Exercise #1
  * Written by:   Pete Wilcox
  * Date:         2015/11/24
  */

#include <iostream>
#include "fractionPeteW.h"
#include "PointPeteW.h"
#include "PointPeteWUtilities.h"

void userInterface(PointPeteW**);

int main() {
	PointPeteW* point = nullptr;

	displayHeader();

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

/* PROGRAM OUTPUT: 

CIS 25 - C++ Programming
Laney College
Pete Wilcox

Assignment Information --
  Assignment Number:  Lab 6,
                      Exercise #1
  Written by:         Pete Wilcox
  Due Date:           2015/11/24


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

  Enter the numerator for frX: 4

  Enter the denominator for frX: 1

  Enter the numerator for frY: 1

  Enter the denominator for frY: 1

Calling Fraction()
Calling Fraction()
Calling ~Fraction() on 4/1
Calling ~Fraction() on 1/1

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 3

  The point is currently at (9/2,3/1)

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 2


  Please select the axis for movement (1 for X-axis, 2 for Y-axis): 1

  Enter the numerator: -1

  Enter the denominator: 1

Calling Fraction()
Calling Fraction()
Calling ~Fraction() on -1/1
Calling ~Fraction() on 0/1

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 3

  The point is currently at (7/2,3/1)

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 2


  Please select the axis for movement (1 for X-axis, 2 for Y-axis): 2

  Enter the numerator: 1

  Enter the denominator: 1

Calling Fraction()
Calling Fraction()
Calling ~Fraction() on 0/1
Calling ~Fraction() on 1/1

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 3

  The point is currently at (7/2,4/1)

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

  The point is currently at (7/2,-4/1)

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

  The point is currently at (-7/2,-4/1)

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

  The point is currently at (7/2,4/1)

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

(7/2,4/1)

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

  X: 7/2, Y: 4/1
Calling ~Fraction() on 7/2
Calling ~Fraction() on 4/1

 *******************************
  * MENU PrintingPoint          *
  *  1. By member print()       *
  *  2. By stand alone print()  *
  *  3. By operator<<           *
  *  4. Returning               *
  *******************************
  Select an option (use integer value only): 3

  The point is currently at (7/2,4/1)

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
Select an option (use integer value only): 1


  ******************************
  * MENU InitPoint             *
  *  1. Set point X-coordinate *
  *  2. Set point Y-coordinate *
  *  3. Printing               *
  *  4. Returning              *
  ******************************
  Please select an option (integer value only): 1

  Please enter the numerator: 4

  Please enter the denominator: 1


  ******************************
  * MENU InitPoint             *
  *  1. Set point X-coordinate *
  *  2. Set point Y-coordinate *
  *  3. Printing               *
  *  4. Returning              *
  ******************************
  Please select an option (integer value only): 2

  Please enter the numerator: 1

  Please enter the denominator: 1


  ******************************
  * MENU InitPoint             *
  *  1. Set point X-coordinate *
  *  2. Set point Y-coordinate *
  *  3. Printing               *
  *  4. Returning              *
  ******************************
  Please select an option (integer value only): 3

  The point is currently at (4/1,1/1)

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

  Enter the denominator for frX: 1

  Enter the numerator for frY: -2

  Enter the denominator for frY: 1

Calling Fraction()
Calling Fraction()
Calling ~Fraction() on 2/1
Calling ~Fraction() on -2/1

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 3

  The point is currently at (6/1,-1/1)

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 2


  Please select the axis for movement (1 for X-axis, 2 for Y-axis): 1

  Enter the numerator: 1

  Enter the denominator: 2

Calling Fraction()
Calling Fraction()
Calling ~Fraction() on 1/2
Calling ~Fraction() on 0/1

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 3

  The point is currently at (13/2,-1/1)

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 2


  Please select the axis for movement (1 for X-axis, 2 for Y-axis): 3


 Invalid choice. Please choose 1 for X-axis, 2 for Y-axis.

  Please select the axis for movement (1 for X-axis, 2 for Y-axis): -2


 Invalid choice. Please choose 1 for X-axis, 2 for Y-axis.

  Please select the axis for movement (1 for X-axis, 2 for Y-axis): 1

  Enter the numerator: -2

  Enter the denominator: 1

Calling Fraction()
Calling Fraction()
Calling ~Fraction() on -2/1
Calling ~Fraction() on 0/1

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 3

  The point is currently at (9/2,-1/1)

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

  The point is currently at (9/2,1/1)

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

  The point is currently at (-9/2,1/1)

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

  The point is currently at (9/2,-1/1)

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

(9/2,-1/1)

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

  X: 9/2, Y: -1/1
Calling ~Fraction() on 9/2
Calling ~Fraction() on -1/1

 *******************************
  * MENU PrintingPoint          *
  *  1. By member print()       *
  *  2. By stand alone print()  *
  *  3. By operator<<           *
  *  4. Returning               *
  *******************************
  Select an option (use integer value only): 3

  The point is currently at (9/2,-1/1)

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
Select an option (use integer value only): 1


  ******************************
  * MENU InitPoint             *
  *  1. Set point X-coordinate *
  *  2. Set point Y-coordinate *
  *  3. Printing               *
  *  4. Returning              *
  ******************************
  Please select an option (integer value only): 1

  Please enter the numerator: -1

  Please enter the denominator: 1


  ******************************
  * MENU InitPoint             *
  *  1. Set point X-coordinate *
  *  2. Set point Y-coordinate *
  *  3. Printing               *
  *  4. Returning              *
  ******************************
  Please select an option (integer value only): 2

  Please enter the numerator: -1

  Please enter the denominator: 2


  ******************************
  * MENU InitPoint             *
  *  1. Set point X-coordinate *
  *  2. Set point Y-coordinate *
  *  3. Printing               *
  *  4. Returning              *
  ******************************
  Please select an option (integer value only): 3

  The point is currently at (-1/1,-1/2)

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

  Enter the numerator for frX: 3

  Enter the denominator for frX: 4

  Enter the numerator for frY: 5

  Enter the denominator for frY: 6

Calling Fraction()
Calling Fraction()
Calling ~Fraction() on 3/4
Calling ~Fraction() on 5/6

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 3

  The point is currently at (-1/4,1/3)

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 2


  Please select the axis for movement (1 for X-axis, 2 for Y-axis): 1

  Enter the numerator: 13

  Enter the denominator: 15

Calling Fraction()
Calling Fraction()
Calling ~Fraction() on 13/15
Calling ~Fraction() on 0/1

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 3

  The point is currently at (37/60,1/3)

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 2


  Please select the axis for movement (1 for X-axis, 2 for Y-axis): 2

  Enter the numerator: 23

  Enter the denominator: 74

Calling Fraction()
Calling Fraction()
Calling ~Fraction() on 0/1
Calling ~Fraction() on 23/74

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 3

  The point is currently at (37/60,143/222)

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

  The point is currently at (37/60,-143/222)

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

  The point is currently at (-37/60,-143/222)

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

  The point is currently at (37/60,143/222)

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
Select an option (use integer value only): 1


  ******************************
  * MENU InitPoint             *
  *  1. Set point X-coordinate *
  *  2. Set point Y-coordinate *
  *  3. Printing               *
  *  4. Returning              *
  ******************************
  Please select an option (integer value only): 1

  Please enter the numerator: 2

  Please enter the denominator: 1


  ******************************
  * MENU InitPoint             *
  *  1. Set point X-coordinate *
  *  2. Set point Y-coordinate *
  *  3. Printing               *
  *  4. Returning              *
  ******************************
  Please select an option (integer value only): 2

  Please enter the numerator: -2

  Please enter the denominator: 1


  ******************************
  * MENU InitPoint             *
  *  1. Set point X-coordinate *
  *  2. Set point Y-coordinate *
  *  3. Printing               *
  *  4. Returning              *
  ******************************
  Please select an option (integer value only): 3

  The point is currently at (2/1,-2/1)

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

  Enter the numerator for frX: 5

  Enter the denominator for frX: 6

  Enter the numerator for frY: 7

  Enter the denominator for frY: 8

Calling Fraction()
Calling Fraction()
Calling ~Fraction() on 5/6
Calling ~Fraction() on 7/8

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 3

  The point is currently at (17/6,-9/8)

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 2


  Please select the axis for movement (1 for X-axis, 2 for Y-axis): 1

  Enter the numerator: 9

  Enter the denominator: 10

Calling Fraction()
Calling Fraction()
Calling ~Fraction() on 9/10
Calling ~Fraction() on 0/1

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 3

  The point is currently at (56/15,-9/8)

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 2


  Please select the axis for movement (1 for X-axis, 2 for Y-axis): 2

  Enter the numerator: 11

  Enter the denominator: 12

Calling Fraction()
Calling Fraction()
Calling ~Fraction() on 0/1
Calling ~Fraction() on 11/12

  *********************
  * MENU MovingPoint  *
  *  1. By (frX, frY) *
  *  2. By fr         *
  *  3. Printing      *
  *  4. Returning     *
  *********************
  Select an option (use integer value only): 3

  The point is currently at (56/15,-5/24)

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

  The point is currently at (56/15,5/24)

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

  The point is currently at (-56/15,5/24)

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

  The point is currently at (56/15,-5/24)

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

(56/15,-5/24)

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

  X: 56/15, Y: -5/24
Calling ~Fraction() on 56/15
Calling ~Fraction() on -5/24

 *******************************
  * MENU PrintingPoint          *
  *  1. By member print()       *
  *  2. By stand alone print()  *
  *  3. By operator<<           *
  *  4. Returning               *
  *******************************
  Select an option (use integer value only): 3

  The point is currently at (56/15,-5/24)

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
Calling ~PointPeteW() on (56/15,-5/24)
Calling ~Fraction() on -5/24
Calling ~Fraction() on 56/15

*/

/* COMMENTS:
2015/11/24:
This assignment was not very clear, so I provided member,
operator, and stand-alone functions to do most things. It's
pretty easy to see how you can expand on this to create two-
and three-dimensional shapes. Planning ahead for that I added
quite a few features to the PointPeteW and FractionPeteW classes
to support further development, such as various operator 
overloads that were not specified. I did this because it seemed
intuitively clear that, for instance, since Fraction objects are
numbers, you should be able to perform arithmetic on them, to
include using them with integers.
*/