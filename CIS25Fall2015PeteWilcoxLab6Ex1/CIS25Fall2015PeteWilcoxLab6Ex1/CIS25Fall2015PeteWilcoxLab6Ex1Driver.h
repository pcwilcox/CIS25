#pragma once

/**
  * Program Name: CIS25Fall2015PeteWilcoxLab6Ex1Driver.h
  * Discussion:   Lab #6 Exercise #1 --
  *                 Driver - Header file
  * Written by:   Pete Wilcox
  * Date:         2015/11/XX
  */

#ifndef CIS25FALL2015PETEWILCOXLAB6EX1DRIVER_H
#define CIS25FALL2015PETEWILCOXLAB6EX1DRIVER_H

#include <iostream>
#include "fractionPeteW.h"
#include "PointPeteW.h"

using namespace std;

void displayHeader(void);

void menuMain(void);

void menuInit(PointPeteW**);

void menuMove(PointPeteW**);

void menuFlip(PointPeteW**);

void menuPrint(PointPeteW**);

void print(PointPeteW** point);

#endif