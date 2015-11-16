/**
  * Program Name: CIS25Fall2015PeteWilcoxLab6Ex1Driver.cpp
  * Discussion:   Lab #6 Exercise #1 --
  *                 Driver file
  * Written by:   Pete Wilcox
  * Date:         2015/11/XX
  */

#include <iostream>
#include "fractionPeteW.h"
#include "PointPeteW.h"

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
		"  Due Date:           2015/11/XX\n";
}

void displayMenuMain() {
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

void displayMenuInit() {
	cout << "\n\n  ******************************\n"
		"  * MENU InitPoint             *\n"
		"  *  1. Set point X-coordinate *\n"
		"  *  2. Set point Y-coordinate *\n"
		"  *  3. Printing               *\n"
		"  *  4. Returning              *\n"
		"  ******************************\n"
		"  Please select an option (integer value only): ";
}

void displayMenuMove() {
	cout << "\n\n  *********************\n"
		"  * MENU MovingPoint  *\n"
		"  *  1. By (frX, frY) *\n"
		"  *  2. By fr         *\n"
		"  *  3. Printing      *\n"
		"  *  4. Returning     *\n"
		"  *********************\n"
		"  Select an option (use integer value only): ";
}

void displayMenuFlip() {
	cout << "\n\n  ***********************\n"
		"  * MENU FlippingPoint  *\n"
		"  *  1. By Y            *\n"
		"  *  2. By X            *\n"
		"  *  3. By Origin       *\n"
		"  *  4. Printing        *\n"
		"  *  5. Returning       *\n"
		"  ***********************\n"
		"  Select an option (use integer value only): ";
}

void displayMenuPrint() {
	cout << "\n\n *******************************\n"
		"  * MENU PrintingPoint          *\n"
		"  *  1. By member print()       *\n"
		"  *  2. By stand alone print()  *\n"
		"  *  3. By operator<<           *\n"
		"  *  4. Returning               *\n"
		"  *******************************\n"
		"  Select an option (use integer value only): ";
}