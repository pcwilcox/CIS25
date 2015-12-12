#pragma once
/**
  * Program Name: CIS25Fall2015PeteWilcoxLab8Ex1Driver.h
  * Discussion:   Declaration File --
  *                 Lab #8, Exercise #1 Driver
  * Written by:   Pete Wilcox
  * Date:         2015/12/15
  */

#ifndef CIS25FALL2015PETEWILCOXLAB8EX1DRIVER_H
#define CIS25FALL2015PETEWILCOXLAB8EX1DRIVER_H

#include <iostream>
#include "ShapePeteW.h"
#include "BoxPeteW.h"
#include "CylinderPeteW.h"
#include "RectanglePeteW.h"
#include "CirclePeteW.h"

using namespace std;

// Program information
void displayHeader(void);

// Main menu
int menuMain(void);

// Create objects
void createRectangles(RectanglePeteW**, 
					  RectanglePeteW**);

void createCircles(CirclePeteW**, 
				   CirclePeteW**);

void createBoxes(BoxPeteW**, 
				 BoxPeteW**);

void createCylinders(CylinderPeteW**, 
					 CylinderPeteW**);

// Compare objects
ShapePeteW* compareMenu(RectanglePeteW**, 
						 RectanglePeteW**,
						 CirclePeteW**, 
						 CirclePeteW**,
						 BoxPeteW**, 
						 BoxPeteW**, 
						 CylinderPeteW**, 
						 CylinderPeteW**);

void compareArea(ShapePeteW**,
			     ShapePeteW**);

void compareVolume(ShapePeteW**, 
				   ShapePeteW**);

// Print objects
void printMenu(RectanglePeteW**,
			   RectanglePeteW**,
			   CirclePeteW**,
			   CirclePeteW**, 
			   BoxPeteW**,
			   BoxPeteW**, 
			   CylinderPeteW**, 
			   CylinderPeteW**);

#endif