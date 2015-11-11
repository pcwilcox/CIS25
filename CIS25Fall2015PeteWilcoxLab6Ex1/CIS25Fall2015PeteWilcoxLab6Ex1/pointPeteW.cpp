/**
  * Program Name: pointPeteW.cpp
  * Discussion:   Declaration File --
  *                 pointPeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/11/XX
  */

#include <iostream>
#include "PointPeteW.h"
#include "fractionPeteW.h"

using namespace std;

// Default constructor
PointPeteW::PointPeteW() {
}

// Explicit constructor
PointPeteW::PointPeteW(const FractionPeteW& first, const FractionPeteW& second) : x(first), y(second) {
}

// Copy constructor
PointPeteW::PointPeteW(const PointPeteW& old) : x(old.x), y(old.y) {
}

// Convert constructor
PointPeteW::PointPeteW(const int input) : x(input) {
}

// Destructor
PointPeteW::~PointPeteW() {
	cout << "\nCalling ~PointPeteW() on " << (*this);
}

// Getters
FractionPeteW PointPeteW::getX() {
	return x;
}

FractionPeteW PointPeteW::getY() {
	return y;
}

// Setters
void PointPeteW::setX(const FractionPeteW& newX) {
	x = newX;
}

void PointPeteW::setX(const int newX) {
	x = FractionPeteW(newX);
}

void PointPeteW::setY(const FractionPeteW& newY) {
	y = FractionPeteW(newY);
}

void PointPeteW::setY(const int newY) {
	y = FractionPeteW(newY);
}

// Movers
void PointPeteW::moveBy(const FractionPeteW& delX, const FractionPeteW& delY) {
	/* FIX THIS CODE HERE */

	x = x + delX;
	y = x + delY;
}

void PointPeteW::moveBy(const int delX, const int delY) {
	/* FIX THIS CODE HERE */
	x = x + delX;
	y = y + delY;
}

void PointPeteW::flipByX() {
	x.setNum(-(x.getNum()));
}

void PointPeteW::flipByY() {
	y.setNum(-(y.getNum()));
}

void PointPeteW::flipThroughOrigin() {
	x.setNum(-(x.getNum()));
	y.setNum(-(y.getNum()));
}

// Print
void PointPeteW::print() {
	cout << "\n(" << x << "," << y << ")";
}

// Overloads
ostream& operator<<(ostream& os, const PointPeteW& point) {
	os << "(" << point.x << "," << point.y << ")";
	return os;
}

PointPeteW& PointPeteW::operator=(const PointPeteW& otherPoint) {
	x = otherPoint.x;
	y = otherPoint.y;
}
