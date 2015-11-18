#pragma once

/**
  * Program Name: CirclePeteW.cpp
  * Discussion:   Definition File --
  *                 CirclePeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/11/24
  */

#include <iostream>
#include "fractionPeteW.h"
#include "PointPeteW.h"
#include "CirclePeteW.h"

using namespace std;

// Define a constant PI for use in getArea() and getVolume()
const FractionPeteW CirclePeteW::PI = FractionPeteW(314159, 100000);

// Default constructor
CirclePeteW::CirclePeteW() : center(FractionPeteW(0), FractionPeteW(0)), radius(0) {
	cout << "\nCalling CirclePeteW on " << *this;
}

// Copy constructor
CirclePeteW::CirclePeteW(const CirclePeteW& arg) : center(arg.center), radius(arg.radius) {
	cout << "\nCalling CirclePeteW on " << *this;
}

// Convert constructors
CirclePeteW::CirclePeteW(const FractionPeteW& arg) : center(FractionPeteW(0), FractionPeteW(0)), radius(arg) {
	cout << "\nCalling CirclePeteW on " << *this;
}

CirclePeteW::CirclePeteW(const int& arg) : center(FractionPeteW(0), FractionPeteW(0)), radius(FractionPeteW(arg)) {
	cout << "\nCalling CirclePeteW on " << *this;
}

// Detailed constructor
CirclePeteW::CirclePeteW(const FractionPeteW& argX, const FractionPeteW& argY) : center(PointPeteW(argX, argY)), radius(0) {
	cout << "\nCalling CirclePeteW on " << *this;
}

// Getters
PointPeteW CirclePeteW::getCenter() const {
	return center;
}

FractionPeteW CirclePeteW::getRadius() const {
	return radius;
}

FractionPeteW CirclePeteW::getArea() const {
	return FractionPeteW(radius * radius * PI);
}

void CirclePeteW::print() {
	cout << "\nCenter: " << center << ", radius: " << radius << ", area: " << getArea();
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

bool CirclePeteW::operator==(const CirclePeteW& arg) {
	if (center == arg.center && radius == arg.radius) {
		return true;
	} else {
		return false;
	}
}

ostream& operator<<(ostream& os, const CirclePeteW& circle) {
	os << "Center: " << circle.center << ", Radius: " << circle.radius;
	return os;
}
