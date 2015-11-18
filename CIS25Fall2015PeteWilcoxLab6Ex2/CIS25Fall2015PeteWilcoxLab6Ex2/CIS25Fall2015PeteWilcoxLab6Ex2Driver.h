#pragma once

/**
  * Program Name: CIS25Fall2015PeteWilcoxLab6Ex2Driver.h
  * Discussion:   Lab #6 Exercise #2 - Driver --
  *                 Declaration file
  * Written by:   Pete Wilcox
  * Date:         2015/11/24
  */

#ifndef CIS25FALL2015PETEWILCOXLAB6EX2DRIVER_H
#define CIS25FALL2015PETEWILCOXLAB6EX2DRIVER_H

#include <iostream>
#include "fractionPeteW.h"
#include "PointPeteW.h"
#include "CirclePeteW.h"
#include "RectanglePeteW.h"

using namespace std;

// Main interface functions
void displayHeader(void);
void userInterface(RectanglePeteW**, CirclePeteW**);

// Rectangle menu functions
void rectangleTasks(RectanglePeteW**);
void createRectangles(RectanglePeteW**);
void compareArea(RectanglePeteW**);
void print(RectanglePeteW**);

// Circle menu functions
void circleTasks(CirclePeteW**);
void createCircles(CirclePeteW**);
void compareArea(CirclePeteW**);
void print(CirclePeteW**);

// Mixed menu functions
void mixedTasks(RectanglePeteW**, CirclePeteW**);
void compareArea(RectanglePeteW**, CirclePeteW**);
void print(RectanglePeteW**, CirclePeteW**);


#endif