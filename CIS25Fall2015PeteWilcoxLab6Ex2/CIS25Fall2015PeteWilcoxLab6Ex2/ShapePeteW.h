#pragma once

/**
  * Program Name: ShapePeteW.h
  * Discussion:   Declaration File --
  *                 ShapePeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/12/15
  */

#ifndef SHAPEPETEW_H
#define SHAPEPETEW_H

#include "fractionPeteW.h"

using namespace std;

class ShapePeteW {
	public:
	virtual void print(void) = 0;
	virtual void computeArea(void) = 0;
	virtual void computeVolume(void) = 0;
	virtual FractionPeteW getArea(void) const = 0;
	virtual FractionPeteW getVolume(void) const = 0;
	friend ostream& operator<<(ostream&, ShapePeteW&);

	protected:
	FractionPeteW area;
	FractionPeteW volume;
};

#endif

