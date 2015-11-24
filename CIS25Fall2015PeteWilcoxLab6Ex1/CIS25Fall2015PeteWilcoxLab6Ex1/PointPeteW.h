/**
  * Program Name: pointPeteW.h
  * Discussion:   Declaration File --
  *                 pointPeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/11/24
  */

#pragma once

#ifndef POINTPETEW_H
#define POINTPETEW_H

#include <iostream>
#include "fractionPeteW.h"

using namespace std;

class PointPeteW {
	public:

	// Default constructor
	PointPeteW();
	
	// Explicit constructor
	PointPeteW(const FractionPeteW&, const FractionPeteW&);

	// Copy constructor
	PointPeteW(const PointPeteW&);

	// Convert constructors
	PointPeteW(const int);
	PointPeteW(const FractionPeteW&);

	// Destructor
	~PointPeteW();

	// Getters
	FractionPeteW getX() const;
	FractionPeteW getY() const;

	// Setters
	void setX(const FractionPeteW&);
	void setY(const FractionPeteW&);

	void setX(const int, const int);
	void setY(const int, const int);

	void setX(const int);
	void setY(const int);

	

	// Movers
	void moveByX(const FractionPeteW &);
	void moveByY(const FractionPeteW &);

	void moveBy(const FractionPeteW&, const FractionPeteW&);
	void moveBy(const int, const int);

	void flipByX();
	void flipByY();

	void flipThroughOrigin();

	// Print
	void print();

	// Overloads
	friend ostream& operator<<(ostream&, const PointPeteW&);

	PointPeteW& operator=(const PointPeteW&);

	bool operator==(const PointPeteW&);

	private:
	FractionPeteW x;
	FractionPeteW y;
};



#endif