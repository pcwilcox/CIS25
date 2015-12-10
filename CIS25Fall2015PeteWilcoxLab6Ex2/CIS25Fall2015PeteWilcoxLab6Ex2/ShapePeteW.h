#pragma once

/**
  * Program Name: ShapePeteW.h
  * Discussion:   Declaration File --
  *                 ShapePeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/12/01
  */

#ifndef SHAPEPETEW_H
#define SHAPEPETEW_H

#include "fractionPeteW.h"

using namespace std;

class ShapePeteW {
	public:
	virtual void print(void) = 0;
	virtual FractionPeteW computeArea(void) const = 0;
	virtual friend ostream& operator<<(ostream&, ShapePeteW&) = 0;
};

#endif

