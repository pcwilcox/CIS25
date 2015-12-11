/**
  * Program Name: pointPeteW.cpp
  * Discussion:   Definition File --
  *                 pointPeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/12/10
  */

#include <iostream>
#include "PointPeteW.h"
#include "fractionPeteW.h"

using namespace std;

// Default constructor
PointPeteW::PointPeteW() {
	x = FractionPeteW(1,1);
	y = FractionPeteW(1,1);
	cout << "\nCalling PointPeteW() on " << (*this);
}

// Explicit constructor
PointPeteW::PointPeteW(const FractionPeteW& first, 
					   const FractionPeteW& second) : 
					   x(first), y(second) {
	cout << "\nCalling PointPeteW() on " << (*this);
}

// Copy constructor
PointPeteW::PointPeteW(const PointPeteW& old) : 
					   x(old.x), y(old.y) {
	cout << "\nCalling PointPeteW() on " << (*this);
}

// Convert constructor

PointPeteW::PointPeteW(const FractionPeteW & xCoord) :
					   x(xCoord) {
	cout << "\nCalling PointPeteW() on " << (*this);
}

// Destructor
PointPeteW::~PointPeteW() {
	cout << "\nCalling ~PointPeteW() on " << (*this);
}

// Getters
FractionPeteW PointPeteW::getX() const {
	return x;
}

FractionPeteW PointPeteW::getY() const {
	return y;
}

// Setters
void PointPeteW::setX(const FractionPeteW& newX) {
	x = newX;
}

void PointPeteW::setX(const int num, const int denom) {
	x.setBoth(num, denom);
}

void PointPeteW::setX(const int newX) {
	x = FractionPeteW(newX);
}

void PointPeteW::setY(const FractionPeteW& newY) {
	y = FractionPeteW(newY);
}

void PointPeteW::setY(const int num, const int denom) {
	y.setBoth(num, denom);
}

void PointPeteW::setY(const int newY) {
	y = FractionPeteW(newY);
}

// Movers
void PointPeteW::moveByX(const FractionPeteW& delX) {
	x.add(delX);
}

void PointPeteW::moveByY(const FractionPeteW& delY) {
	y += delY;
}

void PointPeteW::moveBy(const FractionPeteW& delX, 
	const FractionPeteW& delY) {
	x.add(delX);
	y.add(delY);
}

void PointPeteW::moveBy(const int delX, const int delY) {
	x += delX;
	y += delY;
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
	return (*this);
}

bool PointPeteW::operator==(const PointPeteW &arg) {
	if ((*this).x == arg.x &&
		(*this).y == arg.y) {
		return true;
	}
	return false;
}
