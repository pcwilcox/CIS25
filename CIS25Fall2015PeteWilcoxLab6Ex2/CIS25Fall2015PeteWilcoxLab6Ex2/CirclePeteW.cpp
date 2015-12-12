/**
  * Program Name: CirclePeteW.cpp
  * Discussion:   Definition File --
  *                 CirclePeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/12/15
  */

#include <iostream>
#include "fractionPeteW.h"
#include "PointPeteW.h"
#include "CirclePeteW.h"

using namespace std;

// Default constructor
CirclePeteW::CirclePeteW() : 
		center(FractionPeteW(0), FractionPeteW(0)), radius(0) {
	volume = 0;
	computeArea();
	cout << "\nCalling CirclePeteW() on " << *this;
}

// Copy constructor
CirclePeteW::CirclePeteW(const CirclePeteW& arg) : 
		center(arg.center), radius(arg.radius) {
	volume = 0;
	computeArea();
	cout << "\nCalling CirclePeteW() on " << *this;
}

// Convert constructors
CirclePeteW::CirclePeteW(const FractionPeteW& arg) : 
		center(FractionPeteW(0), FractionPeteW(0)), radius(arg) {
	volume = 0;
	computeArea();
	cout << "\nCalling CirclePeteW() on " << *this;
}

CirclePeteW::CirclePeteW(const PointPeteW &arg) : 
		center(arg), radius(0) {
	volume = 0;
	computeArea();
	cout << "\nCalling CirclePeteW() on " << *this;
}

// Detailed constructors
CirclePeteW::CirclePeteW(const PointPeteW &c, 
						 const FractionPeteW &r) : 
						 center(c), radius(r) {
	volume = 0;
	computeArea();
	cout << "\nCalling CirclePeteW() on " << *this;
}

CirclePeteW::CirclePeteW(const FractionPeteW& argX, 
						 const FractionPeteW& argY) : 
						 center(PointPeteW(argX, argY)), 
						 radius(0) {
	volume = 0;
	computeArea();
	cout << "\nCalling CirclePeteW() on " << *this;
}

// Destructor
CirclePeteW::~CirclePeteW() {
	cout << "\nCalling ~CirclePeteW() on " << *this;
}

// Getters
PointPeteW CirclePeteW::getCenter() const {
	return center;
}

FractionPeteW CirclePeteW::getRadius() const {
	return radius;
}

FractionPeteW CirclePeteW::getArea() const {
	return area;
}

FractionPeteW CirclePeteW::getVolume(void) const {
	return volume;
}

void CirclePeteW::computeArea() {
	(*this).area = (radius * radius * FractionPeteW(157,50));
}

void CirclePeteW::computeVolume(void) {
	volume = 0;
}

void CirclePeteW::print() {
	cout << "\nCircle: "
		"\n  Center: " << center << 
		"\n  Radius: " << radius << 
		"\n  Area: " << area;
}

// Setters
void CirclePeteW::setCenter(const PointPeteW& arg) {
	center = arg;
}

void CirclePeteW::setRadius(const FractionPeteW& arg) {
	if (arg >= 0) {
		radius = arg;
	} else {
		cout << "\nRadius cannot be negative!";
	}
}

void CirclePeteW::setRadius(const int& arg) {
	if (arg >= 0) {
		radius = arg;
	} else {
		cout << "\nRadius cannot be negative!";
	}
}

// Operator overloads
CirclePeteW& CirclePeteW::operator=(const CirclePeteW& arg) {
	center = arg.center;
	radius = arg.radius;
	return *this;
}

ostream& operator<<(ostream& os, const CirclePeteW& circle) {
	os << "\nCircle:"
		"\n  Center: " << circle.center << 
		"\n  Radius: " << circle.radius <<
		"\n  Area: " << circle.area;
	return os;
}
