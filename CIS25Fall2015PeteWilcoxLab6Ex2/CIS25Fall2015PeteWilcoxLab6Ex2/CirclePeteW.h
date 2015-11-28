#pragma once

/**
* Program Name: CirclePeteW.h
* Discussion:   Declaration File --
*                 CirclePeteW class
* Written by:   Pete Wilcox
* Date:         2015/12/01
*/

#ifndef CIRCLEPETEW_H
#define CIRLCEPETEW_H

#include <iostream>
#include "fractionPeteW.h"
#include "PointPeteW.h"

using namespace std;

class CirclePeteW {
	public:
	// Default constructor
	CirclePeteW();

	// Copy constructor
	CirclePeteW(const CirclePeteW&);

	// Convert constructors
	CirclePeteW(const FractionPeteW&);
	CirclePeteW(const int&);

	// Detailed constructor
	CirclePeteW(const FractionPeteW&, const FractionPeteW&);

	// Getters
	PointPeteW getCenter() const;
	FractionPeteW getRadius() const;
	FractionPeteW getArea() const;

	void print();

	// Setters
	void setCenter(const PointPeteW&);
	void setRadius(const FractionPeteW&);
	void setRadius(const int&);

	// Operator overloads
	CirclePeteW& operator=(const CirclePeteW&);

	bool operator==(const CirclePeteW&);

	bool operator< (const CirclePeteW&);
	bool operator> (const CirclePeteW&);

	bool operator<=(const CirclePeteW&);
	bool operator>=(const CirclePeteW&);

	friend ostream& operator<<(ostream&, const CirclePeteW&);

	private:
	PointPeteW center;
	FractionPeteW radius;
	const static FractionPeteW PI;
};

#endif