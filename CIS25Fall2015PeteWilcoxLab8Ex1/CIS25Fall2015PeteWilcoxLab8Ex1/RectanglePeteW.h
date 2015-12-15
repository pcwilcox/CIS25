#pragma once

/**
  * Program Name: RectanglePeteW.h
  * Discussion:   Declaration File --
  *                 RectanglePeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/12/15
  */

#ifndef RECTANGLEPETEW_H
#define RECTANGLEPETEW_H

#include <iostream>
#include "ShapePeteW.h"
#include "fractionPeteW.h"
#include "PointPeteW.h"
#include "CirclePeteW.h"

using namespace std;

class RectanglePeteW : public virtual ShapePeteW {
	public:
	
	// Default constructor
	RectanglePeteW(void);

	// Copy constructor
	RectanglePeteW(const RectanglePeteW&);

	// Other constructors
	RectanglePeteW(const PointPeteW&);

	RectanglePeteW(const PointPeteW&, 
					const PointPeteW&);
	
	// Destructor
	~RectanglePeteW();

	// Getters
	PointPeteW getUpperRight(void) const;
	PointPeteW getLowerLeft(void) const;
	FractionPeteW getLength(void) const;
	FractionPeteW getWidth(void) const;

	virtual FractionPeteW getArea(void) const override;
	virtual FractionPeteW getVolume(void) const override;

	// Setters
	void setUpperRight(const PointPeteW&);

	void setUpperRight(const FractionPeteW&, 
						const FractionPeteW&);

	void setLowerLeft(const PointPeteW&);

	void setLowerLeft(const FractionPeteW&, 
						const FractionPeteW&);

	// Helper function
	virtual void computeArea(void) override;
	virtual void computeVolume(void) override;

	void print(void) override;

	// Operators
	RectanglePeteW& operator=(const RectanglePeteW&);
	
	// Return true if the two rectangles have the same area
	bool operator==(const RectanglePeteW&) const;

	// Comparison is based on area
	bool operator<(const RectanglePeteW&) const;
	bool operator>(const RectanglePeteW&) const;

	bool operator<=(const RectanglePeteW&) const;
	bool operator>=(const RectanglePeteW&) const;

	RectanglePeteW operator+(const RectanglePeteW&);
	
	friend ostream& operator<<(ostream&, const RectanglePeteW&);



	protected:
	PointPeteW upperRight;
	PointPeteW lowerLeft;

	/* Helper function - checkPoints() is called whenever an
	 * operation is performed on the member data points in
	 * order to verify that the data are still valid. If the
	 * data is invalid then the points are adjusted as needed.
	 */
	virtual void checkPoints();
};

#endif