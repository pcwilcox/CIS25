#pragma once

/**
 * Program Name: CirclePeteW.h
 * Discussion:   Declaration File --
 *                 CirclePeteW class
 * Written by:   Pete Wilcox
 * Date:         2015/12/15
 */

#ifndef CIRCLEPETEW_H
#define CIRLCEPETEW_H

#include <iostream>
#include "ShapePeteW.h"
#include "fractionPeteW.h"
#include "PointPeteW.h"
#include "RectanglePeteW.h"

using namespace std;

class CirclePeteW : public ShapePeteW {
	public:
	// Default constructor
	CirclePeteW();

	// Copy constructor
	CirclePeteW(const CirclePeteW&);

	// Convert constructors
	CirclePeteW(const FractionPeteW&);
	CirclePeteW(const PointPeteW&);

	// Detailed constructor
	CirclePeteW(const PointPeteW&, const FractionPeteW&);
	CirclePeteW(const FractionPeteW&, const FractionPeteW&);

	// Destructor
	~CirclePeteW();

	// Getters
	PointPeteW    getCenter() const;
	FractionPeteW getRadius() const;
	FractionPeteW getArea() const override;
	
	// Setters
	void setCenter(const PointPeteW&);
	void setRadius(const FractionPeteW&);
	void setRadius(const int&);

	// Helper function
	void computeArea() override;

	void print(void) override;

	// Operator overloads
	CirclePeteW& operator=(const CirclePeteW&);

	friend ostream& operator<<(ostream&, const CirclePeteW&);

	private:
	PointPeteW center;
	FractionPeteW radius;
};

#endif