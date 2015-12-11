#pragma once

/**
  * Program Name: CIS25Fall2015PeteWilcoxLab7Ex1Driver.h
  * Discussion:   Lab #7 Exercise #1 - Driver --
  *                 Declaration file
  * Written by:   Pete Wilcox
  * Date:         2015/12/15
  */

#ifndef CIS25FALL2015PETEWILCOXLAB7EX1DRIVER_H
#define CIS25FALL2015PETEWILCOXLAB1EX1DRIVER_H

#include <iostream>
#include "ShapePeteW.h"
#include "fractionPeteW.h"
#include "PointPeteW.h"
#include "CirclePeteW.h"
#include "RectanglePeteW.h"

using namespace std;

// Main interface functions
void displayHeader(void);
void userInterface(RectanglePeteW**, 
				   RectanglePeteW**, 
				   CirclePeteW**, 
				   CirclePeteW**);

// Rectangle menu functions
void rectangleTasks(RectanglePeteW**, RectanglePeteW**);
void createRectangles(RectanglePeteW**, RectanglePeteW**);

// Circle menu functions
void circleTasks(CirclePeteW**, CirclePeteW**);
void createCircles(CirclePeteW**, CirclePeteW**);

// Mixed menu functions
void mixedTasks(RectanglePeteW**, 
				RectanglePeteW**, 
				CirclePeteW**, 
				CirclePeteW**);

ShapePeteW* compareMenu(RectanglePeteW**, 
						RectanglePeteW**, 
						CirclePeteW**, 
						CirclePeteW**);


void compareArea(ShapePeteW**, ShapePeteW**);

#endif