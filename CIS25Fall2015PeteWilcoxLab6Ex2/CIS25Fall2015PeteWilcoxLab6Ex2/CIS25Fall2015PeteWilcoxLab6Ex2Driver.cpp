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

void userInterface(RectanglePeteW** recA, RectanglePeteW** recB, CirclePeteW** cirA, CirclePeteW** cirB) {
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

void rectangleTasks(RectanglePeteW** recA, RectanglePeteW** recB, CirclePeteW** cirA, CirclePeteW** cirB) {
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
			cout << "\nBoth rectangles have zero volume.";
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

void circleTasks(CirclePeteW** circles) {
	int menuChoice;
	do {
		cout << "\nRECTANGLE MENU\n"
			"(1) Create two Circle objects\n"
			"(2) Compare by volume\n"
			"(3) Compare by area\n"
			"(4) Print two Circle objects\n"
			"(5) Quit\n"
			"Enter your option (1 through 5): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			createCircles(circles);
			break;
		case 2:
			cout << "\nBoth circles have zero volume.";
			break;
		case 3:
			if (circles != nullptr) {
				if (*(*(circles + 0)) > *(*(circles + 1))) {
					cout << "\Circle " << *(*(circles + 0)) << " is larger than " << *(*(circles + 1));
				} else if (*(*(circles + 0)) < *(*(circles + 1))) {
					cout << "\Circle " << *(*(circles + 1)) << " is larger than " << *(*(circles + 0));
				} else {
					cout << "\nBoth circles have equal area.";
				}
			} else {
				cout << "\nBoth circles must be intialized first!";
			}
			break;
		case 4:
			if (circles != nullptr) {
				cout << "\nCircle 1: " << *(*(circles + 0));
				cout << "\nCircle 2: " << *(*(circles + 1));
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

void createRectangles(RectanglePeteW** rectangles) {
	if (rectangles == nullptr) {
		// no rectangles yet
	} else {
		// change old rectangles
	}
	
}