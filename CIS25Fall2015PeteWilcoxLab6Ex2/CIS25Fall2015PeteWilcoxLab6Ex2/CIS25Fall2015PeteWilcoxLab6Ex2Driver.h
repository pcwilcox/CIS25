#pragma once

/**
  * Program Name: CIS25Fall2015PeteWilcoxLab6Ex2Driver.h
  * Discussion:   Lab #6 Exercise #2 - Driver --
  *                 Declaration file
  * Written by:   Pete Wilcox
  * Date:         2015/12/01
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
void userInterface(RectanglePeteW**, RectanglePeteW**, CirclePeteW**, CirclePeteW**);

// Rectangle menu functions
void rectangleTasks(RectanglePeteW**, RectanglePeteW**);
void createRectangles(RectanglePeteW**, RectanglePeteW**);
void compareArea(RectanglePeteW**, RectanglePeteW**);
void print(RectanglePeteW**, RectanglePeteW**);

// Circle menu functions
void circleTasks(CirclePeteW**, CirclePeteW**);
void createCircles(CirclePeteW**, CirclePeteW**);
void compareArea(CirclePeteW**, CirclePeteW**);
void print(CirclePeteW**, CirclePeteW**);

// Mixed menu functions
void mixedTasks(RectanglePeteW**, RectanglePeteW**, CirclePeteW**, CirclePeteW**);
void compareArea(RectanglePeteW**, RectanglePeteW**, CirclePeteW**, CirclePeteW**);
void print(RectanglePeteW**, RectanglePeteW**, CirclePeteW**, CirclePeteW**);


#endif