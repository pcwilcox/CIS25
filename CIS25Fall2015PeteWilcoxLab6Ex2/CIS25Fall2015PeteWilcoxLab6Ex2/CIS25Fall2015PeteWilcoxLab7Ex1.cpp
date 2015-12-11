/**
  * Program Name: CIS25Fall2015PeteWilcoxLab7Ex1.cpp
  * Discussion:   Lab #7 Exercise #1
  * Written by:   Pete Wilcox
  * Date:         2015/12/10
  */

#include <iostream>
#include "CirclePeteW.h"
#include "RectanglePeteW.h"
#include "CIS25Fall2015PeteWilcoxLab7Ex1Driver.h"

using namespace std;

int main() {
	RectanglePeteW* recA = nullptr;
	RectanglePeteW* recB = nullptr;
	CirclePeteW*    cirA = nullptr;
	CirclePeteW*    cirB = nullptr;

	displayHeader();

	userInterface(&recA, &recB, &cirA, &cirB);

	delete recA;
	delete recB;
	delete cirA;
	delete cirB;
	
	return 0;
}

/* PROGRAM OUTPUT:
CIS 25 - C++ Programming
Laney College
Pete Wilcox

Assignment Information --
  Assignment Number:  Lab 7,
                      Exercise #1
  Written by:         Pete Wilcox
  Due Date:           2015/12/10

MAIN MENU
(1) Rectangle Tasks
(2) Circle Tasks
(3) Mixed Rectangle and Circle Tasks
(4) Quit

Enter your option (1, 2, 3, or 4): 1

RECTANGLE MENU
(1) Create two Rectangle objects
(2) Compare by volume
(3) Compare by area
(4) Print two Rectangle objects
(5) Quit
Enter your option (1 through 5): 1

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
Calling Fraction() on 4/1
Calling Fraction() on 1/1
Calling PointPeteW() on (4/1,1/1)
Calling Fraction() on 1/2
Calling Fraction() on 2/1
Calling PointPeteW() on (1/2,2/1)
Calling Fraction() on 1/2
Calling Fraction() on 4/1
Calling ~Fraction() on 4/1
Calling ~Fraction() on 1/2
Calling Fraction() on 1/2
Calling Fraction() on 4/1
Calling ~Fraction() on 4/1
Calling ~Fraction() on 1/2
Calling Fraction() on 2/1
Calling Fraction() on 1/1
Calling ~Fraction() on 1/1
Calling ~Fraction() on 2/1
Calling Fraction() on 1/1
Calling Fraction() on 2/1
Calling Fraction() on 2/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on 2/1
Calling Fraction() on 1/1
Calling ~Fraction() on 1/1
Calling ~Fraction() on 1/1
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
Calling RectanglePeteW() on [(1/2,1/1), (4/1,2/1)]
Rectangle #1 created:

Rectangle:
  Lower Left: (1/2,1/1)
  Upper Right: (4/1,2/1)
  Area:7/2

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
Calling Fraction() on 2/1
Calling Fraction() on -2/1
Calling PointPeteW() on (2/1,-2/1)
Calling Fraction() on -1/1
Calling Fraction() on -1/2
Calling PointPeteW() on (-1/1,-1/2)
Calling Fraction() on -1/1
Calling Fraction() on 2/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on -1/1
Calling Fraction() on -1/1
Calling Fraction() on 2/1
Calling ~Fraction() on 2/1
Calling ~Fraction() on -1/1
Calling Fraction() on -1/2
Calling Fraction() on -2/1
Calling ~Fraction() on -2/1
Calling ~Fraction() on -1/2
Calling Fraction() on -2/1
Calling Fraction() on -1/2
Calling Fraction() on -1/2
Calling ~Fraction() on -1/2
Calling ~Fraction() on -1/2
Calling Fraction() on -2/1
Calling ~Fraction() on -2/1
Calling ~Fraction() on -2/1
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
Calling RectanglePeteW() on [(-1/1,-2/1), (2/1,-1/2)]
Rectangle #2 created:

Rectangle:
  Lower Left: (-1/1,-2/1)
  Upper Right: (2/1,-1/2)
  Area:9/2

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
RECTANGLE MENU
(1) Create two Rectangle objects
(2) Compare by volume
(3) Compare by area
(4) Print two Rectangle objects
(5) Quit
Enter your option (1 through 5): 2

Rectangles have no volume.
RECTANGLE MENU
(1) Create two Rectangle objects
(2) Compare by volume
(3) Compare by area
(4) Print two Rectangle objects
(5) Quit
Enter your option (1 through 5): 3

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
  Area:9/2
 is larger than
Rectangle:
  Lower Left: (1/2,1/1)
  Upper Right: (4/1,2/1)
  Area:7/2

RECTANGLE MENU
(1) Create two Rectangle objects
(2) Compare by volume
(3) Compare by area
(4) Print two Rectangle objects
(5) Quit
Enter your option (1 through 5): 4

Rectangle:
  Lower Left: (1/2,1/1)
  Upper Right: (4/1,2/1)
  Area:7/2

Rectangle:
  Lower Left: (-1/1,-2/1)
  Upper Right: (2/1,-1/2)
  Area:9/2

RECTANGLE MENU
(1) Create two Rectangle objects
(2) Compare by volume
(3) Compare by area
(4) Print two Rectangle objects
(5) Quit
Enter your option (1 through 5): 5

Returning to main menu.
MAIN MENU
(1) Rectangle Tasks
(2) Circle Tasks
(3) Mixed Rectangle and Circle Tasks
(4) Quit

Enter your option (1, 2, 3, or 4): 2

CIRCLE MENU
(1) Create two Circle objects
(2) Compare by volume
(3) Compare by area
(4) Print two Circle objects
(5) Quit
Enter your option (1 through 5): 1

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
Calling Fraction() on 1/2
Calling Fraction() on 2/1
Calling PointPeteW() on (1/2,2/1)
Calling Fraction() on 4/1
Calling Fraction() on 157/50
Calling Fraction() on 16/1
Calling Fraction() on 2512/50
Calling ~Fraction() on 1256/25
Calling ~Fraction() on 16/1
Calling ~Fraction() on 157/50
Calling CirclePeteW() on Center: (1/2,2/1), Radius: 4/1
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
Calling Fraction() on -1/1
Calling Fraction() on -1/2
Calling PointPeteW() on (-1/1,-1/2)
Calling Fraction() on 2/1
Calling Fraction() on 157/50
Calling Fraction() on 4/1
Calling Fraction() on 628/50
Calling ~Fraction() on 314/25
Calling ~Fraction() on 4/1
Calling ~Fraction() on 157/50
Calling CirclePeteW() on Center: (-1/1,-1/2), Radius: 2/1
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
CIRCLE MENU
(1) Create two Circle objects
(2) Compare by volume
(3) Compare by area
(4) Print two Circle objects
(5) Quit
Enter your option (1 through 5): 2

Both circles have zero volume.
CIRCLE MENU
(1) Create two Circle objects
(2) Compare by volume
(3) Compare by area
(4) Print two Circle objects
(5) Quit
Enter your option (1 through 5): 3

Comparing area --

Calling Fraction() on 314/25
Calling Fraction() on 1256/25
Calling ~Fraction() on 1256/25
Calling ~Fraction() on 314/25
Circle:
  Center: (1/2,2/1)
  Radius: 4/1
  Area: 1256/25 is larger than
Circle:
  Center: (-1/1,-1/2)
  Radius: 2/1
  Area: 314/25
CIRCLE MENU
(1) Create two Circle objects
(2) Compare by volume
(3) Compare by area
(4) Print two Circle objects
(5) Quit
Enter your option (1 through 5): 4

Circle:
  Center: (1/2,2/1)
  Radius: 4/1
  Area: 1256/25
Circle:
  Center: (-1/1,-1/2)
  Radius: 2/1
  Area: 314/25
CIRCLE MENU
(1) Create two Circle objects
(2) Compare by volume
(3) Compare by area
(4) Print two Circle objects
(5) Quit
Enter your option (1 through 5): 5

Returning to main menu.
MAIN MENU
(1) Rectangle Tasks
(2) Circle Tasks
(3) Mixed Rectangle and Circle Tasks
(4) Quit

Enter your option (1, 2, 3, or 4): 3

MIXED RECTANGLE & CIRCLE MENU
(1) Compare by area
(2) Compare by volume
(3) Print ALL objects
(4) QuitEnter your option (1 through 4): 1

  Comparing by area - Select two objects to compare --
Please select the first object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
Please select the first object (1 through 4): 1

Please select the second object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
Please select the first object (1 through 4): 2

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
  Area:9/2
 is larger than
Rectangle:
  Lower Left: (1/2,1/1)
  Upper Right: (4/1,2/1)
  Area:7/2

MIXED RECTANGLE & CIRCLE MENU
(1) Compare by area
(2) Compare by volume
(3) Print ALL objects
(4) QuitEnter your option (1 through 4): 1

  Comparing by area - Select two objects to compare --
Please select the first object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
Please select the first object (1 through 4): 1

Please select the second object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
Please select the first object (1 through 4): 3

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
  Area:7/2

MIXED RECTANGLE & CIRCLE MENU
(1) Compare by area
(2) Compare by volume
(3) Print ALL objects
(4) QuitEnter your option (1 through 4): 1

  Comparing by area - Select two objects to compare --
Please select the first object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
Please select the first object (1 through 4): 1

Please select the second object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
Please select the first object (1 through 4): 4

Comparing area --

Calling Fraction() on 314/25
Calling Fraction() on 7/2
Calling ~Fraction() on 7/2
Calling ~Fraction() on 314/25
Calling Fraction() on 314/25
Calling Fraction() on 7/2
Calling ~Fraction() on 7/2
Calling ~Fraction() on 314/25
Circle:
  Center: (-1/1,-1/2)
  Radius: 2/1
  Area: 314/25 is larger than
Rectangle:
  Lower Left: (1/2,1/1)
  Upper Right: (4/1,2/1)
  Area:7/2

MIXED RECTANGLE & CIRCLE MENU
(1) Compare by area
(2) Compare by volume
(3) Print ALL objects
(4) QuitEnter your option (1 through 4): 1

  Comparing by area - Select two objects to compare --
Please select the first object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
Please select the first object (1 through 4): 2

Please select the second object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
Please select the first object (1 through 4): 3

Comparing area --

Calling Fraction() on 1256/25
Calling Fraction() on 9/2
Calling ~Fraction() on 9/2
Calling ~Fraction() on 1256/25
Calling Fraction() on 1256/25
Calling Fraction() on 9/2
Calling ~Fraction() on 9/2
Calling ~Fraction() on 1256/25
Circle:
  Center: (1/2,2/1)
  Radius: 4/1
  Area: 1256/25 is larger than
Rectangle:
  Lower Left: (-1/1,-2/1)
  Upper Right: (2/1,-1/2)
  Area:9/2

MIXED RECTANGLE & CIRCLE MENU
(1) Compare by area
(2) Compare by volume
(3) Print ALL objects
(4) QuitEnter your option (1 through 4): 1

  Comparing by area - Select two objects to compare --
Please select the first object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
Please select the first object (1 through 4): 2

Please select the second object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
Please select the first object (1 through 4): 4

Comparing area --

Calling Fraction() on 314/25
Calling Fraction() on 9/2
Calling ~Fraction() on 9/2
Calling ~Fraction() on 314/25
Calling Fraction() on 314/25
Calling Fraction() on 9/2
Calling ~Fraction() on 9/2
Calling ~Fraction() on 314/25
Circle:
  Center: (-1/1,-1/2)
  Radius: 2/1
  Area: 314/25 is larger than
Rectangle:
  Lower Left: (-1/1,-2/1)
  Upper Right: (2/1,-1/2)
  Area:9/2

MIXED RECTANGLE & CIRCLE MENU
(1) Compare by area
(2) Compare by volume
(3) Print ALL objects
(4) QuitEnter your option (1 through 4): 1

  Comparing by area - Select two objects to compare --
Please select the first object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
Please select the first object (1 through 4): 3

Please select the second object:
  (1) Rectangle 1
  (2) Rectangle 2
  (3) Circle 1
  (4) Circle 2
Please select the first object (1 through 4): 4

Comparing area --

Calling Fraction() on 314/25
Calling Fraction() on 1256/25
Calling ~Fraction() on 1256/25
Calling ~Fraction() on 314/25
Circle:
  Center: (1/2,2/1)
  Radius: 4/1
  Area: 1256/25 is larger than
Circle:
  Center: (-1/1,-1/2)
  Radius: 2/1
  Area: 314/25
MIXED RECTANGLE & CIRCLE MENU
(1) Compare by area
(2) Compare by volume
(3) Print ALL objects
(4) QuitEnter your option (1 through 4): 2

Rectangles and circles have no volume.
MIXED RECTANGLE & CIRCLE MENU
(1) Compare by area
(2) Compare by volume
(3) Print ALL objects
(4) QuitEnter your option (1 through 4): 3

Rectangle 1: [(1/2,1/1), (4/1,2/1)]
Rectangle 2: [(-1/1,-2/1), (2/1,-1/2)]
Circle 1: Center: (1/2,2/1), Radius: 4/1
Circle 2: Center: (-1/1,-1/2), Radius: 2/1
MIXED RECTANGLE & CIRCLE MENU
(1) Compare by area
(2) Compare by volume
(3) Print ALL objects
(4) QuitEnter your option (1 through 4): 4

Returning to main menu.
MAIN MENU
(1) Rectangle Tasks
(2) Circle Tasks
(3) Mixed Rectangle and Circle Tasks
(4) Quit

Enter your option (1, 2, 3, or 4): 5


    WRONG OPTION
MAIN MENU
(1) Rectangle Tasks
(2) Circle Tasks
(3) Mixed Rectangle and Circle Tasks
(4) Quit

Enter your option (1, 2, 3, or 4): 4


    Have fun...
Calling ~RectanglePeteW() on [(1/2,1/1), (4/1,2/1)]
Calling ~PointPeteW() on (1/2,1/1)
Calling ~Fraction() on 1/1
Calling ~Fraction() on 1/2
Calling ~PointPeteW() on (4/1,2/1)
Calling ~Fraction() on 2/1
Calling ~Fraction() on 4/1
Calling ~Fraction() on 7/2
Calling ~RectanglePeteW() on [(-1/1,-2/1), (2/1,-1/2)]
Calling ~PointPeteW() on (-1/1,-2/1)
Calling ~Fraction() on -2/1
Calling ~Fraction() on -1/1
Calling ~PointPeteW() on (2/1,-1/2)
Calling ~Fraction() on -1/2
Calling ~Fraction() on 2/1
Calling ~Fraction() on 9/2
Calling ~CirclePeteW() on Center: (1/2,2/1), Radius: 4/1
Calling ~Fraction() on 4/1
Calling ~PointPeteW() on (1/2,2/1)
Calling ~Fraction() on 2/1
Calling ~Fraction() on 1/2
Calling ~Fraction() on 1256/25
Calling ~CirclePeteW() on Center: (-1/1,-1/2), Radius: 2/1
Calling ~Fraction() on 2/1
Calling ~PointPeteW() on (-1/1,-1/2)
Calling ~Fraction() on -1/2
Calling ~Fraction() on -1/1
Calling ~Fraction() on 314/25

*/