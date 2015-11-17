#pragma once

/**
  * Program Name: fractionPeteW.h
  * Discussion:   Declaration File --
  *                 RectanglePeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/11/XX
  */

#ifndef RECTANGLEPETEW_H
#define RECTANGLEPETEW_H

#include <iostream>
#include "fractionPeteW.h"
#include "PointPeteW.h"

using namespace std;

class RectanglePeteW {
	public:
	
	// Default constructor
	RectanglePeteW();

	// Copy constructor
	RectanglePeteW(const RectanglePeteW&);

	// Other constructors
	RectanglePeteW(const PointPeteW&);
	RectanglePeteW(const PointPeteW&, const int&);
	RectanglePeteW(const PointPeteW&, const PointPeteW&);
	
	// Destructor
	~RectanglePeteW();

	// Getters
	PointPeteW getUpperRight();
	PointPeteW getLowerLeft();
	FractionPeteW getHeight();
	FractionPeteW getWidth();
	FractionPeteW getArea();

	void print();
	
	// Setters
	void setUpperRight(const PointPeteW&);
	void setUpperRight(const FractionPeteW&, const FractionPeteW&);
	void setLowerLeft(const PointPeteW&);
	void setLowerLeft(const FractionPeteW&, const FractionPeteW&);

	// Operators
	RectanglePeteW& operator=(const RectanglePeteW&);
	
	bool operator==(const RectanglePeteW&);

	friend ostream& operator<<(ostream&, const RectanglePeteW&);

	private:
	PointPeteW upperRight;
	PointPeteW lowerLeft;
};


#endif