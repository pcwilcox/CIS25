#pragma once

/**
  * Program Name: RectanglePeteW.h
  * Discussion:   Declaration File --
  *                 RectanglePeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/12/10
  */

#ifndef RECTANGLEPETEW_H
#define RECTANGLEPETEW_H

#include <iostream>
#include "ShapePeteW.h"
#include "fractionPeteW.h"
#include "PointPeteW.h"
#include "CirclePeteW.h"

using namespace std;

class RectanglePeteW : public ShapePeteW {
	public:
	
	// Default constructor
	RectanglePeteW(void);

	// Copy constructor
	RectanglePeteW(const RectanglePeteW&);

	// Other constructors
	RectanglePeteW(const PointPeteW&);
	RectanglePeteW(const PointPeteW&, const PointPeteW&);
	
	// Destructor
	~RectanglePeteW();

	// Getters
	PointPeteW getUpperRight(void) const;
	PointPeteW getLowerLeft(void) const;
	FractionPeteW getHeight(void) const;
	FractionPeteW getWidth(void) const;
	FractionPeteW getArea(void) const override;

	void computeArea(void) override;

	void print(void) override;
	
	// Setters
	void setUpperRight(const PointPeteW&);
	void setUpperRight(const FractionPeteW&, const FractionPeteW&);
	void setLowerLeft(const PointPeteW&);
	void setLowerLeft(const FractionPeteW&, const FractionPeteW&);

	// Operators
	RectanglePeteW& operator=(const RectanglePeteW&);
	
	friend ostream& operator<<(ostream&, const RectanglePeteW&);

	private:
	PointPeteW upperRight;
	PointPeteW lowerLeft;

	// Helper method to check that the points are in the right position
	void checkPoints();
};


#endif