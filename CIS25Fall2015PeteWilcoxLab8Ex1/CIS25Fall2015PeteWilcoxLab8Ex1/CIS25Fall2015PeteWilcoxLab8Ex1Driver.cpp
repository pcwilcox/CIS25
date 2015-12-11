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

int menuMain(void) {
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

void createRectangles(RectanglePeteW **rectangleOne,
	RectanglePeteW **rectangleTwo) {
}

void createCircles(CirclePeteW **circleOne,
	CirclePeteW **circleTwo) {
}

void createBoxes(BoxPeteW **boxOne,
	BoxPeteW **boxTwo) {
}

void createCylinders(CylinderPeteW **cylinderOne,
	CylinderPeteW **cylinderTwo) {
}

void compareAreaMenu(RectanglePeteW** rectangleOne,
	RectanglePeteW** rectangleTwo,
	CirclePeteW** circleOne,
	CirclePeteW** circleTwo,
	BoxPeteW **boxOne,
	BoxPeteW **boxTwo,
	CylinderPeteW **cylinderOne,
	CylinderPeteW **cylinderTwo) {
}

void compareVolumeMenu(BoxPeteW **boxOne,
	BoxPeteW **boxTwo,
	CylinderPeteW **cylinderOne,
	CylinderPeteW **cylinderTwo) {
}

void compareArea(ShapePeteW **shapeOne,
	ShapePeteW **shapeTwo) {
}

void compareVolume(ShapePeteW **shapeOne,
	ShapePeteW **shapeTwo) {
}

void printMenu(RectanglePeteW** rectangleOne,
	RectanglePeteW** rectangleTwo,
	CirclePeteW** circleOne,
	CirclePeteW** circleTwo,
	BoxPeteW **boxOne,
	BoxPeteW **boxTwo,
	CylinderPeteW **cylinderOne,
	CylinderPeteW **cylinderTwo) {
}

