/**
  * Program Name: CIS25Fall2015PeteWilcoxLab7Ex1.cpp
  * Discussion:   Lab #7 Exercise #1
  * Written by:   Pete Wilcox
  * Date:         2015/12/10
  */

#include <iostream>
#include "CirclePeteW.h"
#include "RectanglePeteW.h"
#include "CIS25Fall2015PeteWilcoxLab6Ex2Driver.h"

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