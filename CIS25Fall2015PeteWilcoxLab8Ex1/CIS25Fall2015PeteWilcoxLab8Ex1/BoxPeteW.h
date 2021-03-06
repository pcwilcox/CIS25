#pragma once
/**
  * Program Name: BoxPeteW.h
  * Discussion:   Declaration File --
  *                 BoxPeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/12/15
  */

#ifndef BOXPETEW_H
#define BOXPETEW_H

#include <iostream>
#include "RectanglePeteW.h"

class BoxPeteW : public RectanglePeteW {
	public:

	// Default constructor
	BoxPeteW();

	// Convert constructor
	BoxPeteW(const RectanglePeteW&);

	// Copy constructor
	BoxPeteW(const BoxPeteW&);

	// Detailed constructor
	BoxPeteW(const RectanglePeteW&, const FractionPeteW&);

	// Destructor
	~BoxPeteW();

	// Getters
	FractionPeteW getHeight(void) const;
	FractionPeteW getArea(void) const override;
	FractionPeteW getVolume(void) const override;

	// Setters
	void setHeight(const FractionPeteW&);

	// Helpers
	void computeArea(void) override;
	void computeVolume(void) override;
	void checkPoints(void) override;
	void print(void) override;
	FractionPeteW getBaseArea(void) const;

	// Operators
	friend ostream& operator<<(ostream&, BoxPeteW&);

	BoxPeteW operator+(const BoxPeteW&);

	// Comparisons based on volume
	bool operator==(const BoxPeteW&) const;
	bool operator<(const BoxPeteW&) const;
	bool operator>(const BoxPeteW&) const;
	bool operator<=(const BoxPeteW&) const;
	bool operator>=(const BoxPeteW&) const;

	private:
	FractionPeteW h;
};

#endif