#pragma once
/**
  * Program Name: CylinderPeteW.h
  * Discussion:   Declaration File --
  *                 CylinderPeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/12/15
  */

#ifndef CYLINDERPETEW_H
#define CYLINDERPETEW_H

#include <iostream>
#include "CirclePeteW.h"

class CylinderPeteW : public CirclePeteW {
	public:

	// Default constructor
	CylinderPeteW();

	// Convert constructor
	CylinderPeteW(const CirclePeteW&);

	// Copy constructor
	CylinderPeteW(const CylinderPeteW&);

	// Detailed constructor
	CylinderPeteW(const CirclePeteW&, const FractionPeteW&);

	// Destructor
	~CylinderPeteW();

	// Getters
	FractionPeteW getHeight(void) const;
	FractionPeteW getArea(void) const override;
	FractionPeteW getVolume(void) const;

	// Setters
	void setHeight(const FractionPeteW&);

	// Helpers
	void computeArea(void) override;
	void computeVolume(void) override;
	void print(void) override;

	private:
	FractionPeteW h;
};

#endif