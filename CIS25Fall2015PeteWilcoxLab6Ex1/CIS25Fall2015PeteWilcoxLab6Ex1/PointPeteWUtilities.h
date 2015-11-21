#pragma once

/**
  * Program Name: PointPeteWUtilities.h
  * Discussion:   PointPeteW Class --
  *                 Utilities Header file
  * Written by:   Pete Wilcox
  * Date:         2015/11/XX
  */

#ifndef POINTPETEWUTILITIES_H
#define POINTPETEWUTILITIES_H

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