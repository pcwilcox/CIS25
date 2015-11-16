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

int main() {
	int menuChoice;
	PointPeteW* point = nullptr;

	display();

	userInterface(&point);	

	delete point;

	return 0;
}