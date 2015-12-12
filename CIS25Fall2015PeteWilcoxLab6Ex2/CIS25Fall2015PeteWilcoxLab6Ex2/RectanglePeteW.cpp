#pragma once

/**
  * Program Name: RectanglePeteW.cpp
  * Discussion:   Definition File --
  *                 RectanglePeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/12/15
  */

#include <iostream>
#include "RectanglePeteW.h"
#include "FractionPeteW.h"
#include "PointPeteW.h"

using namespace std;

// Default constructor
RectanglePeteW::RectanglePeteW() {
	upperRight = PointPeteW(FractionPeteW(0), FractionPeteW(0));
	lowerLeft = PointPeteW(FractionPeteW(0), FractionPeteW(0));
	volume = 0;
	checkPoints();
	computeArea();
	cout << "\nCalling RectanglePeteW() on " << (*this);
}

// Copy constructor
RectanglePeteW::RectanglePeteW(const RectanglePeteW &arg) : 
		upperRight(arg.upperRight), lowerLeft(arg.lowerLeft) {
	volume = 0;
	checkPoints();
	computeArea();
	cout << "\nCalling RectanglePeteW() on " << (*this);
}

// Convert constructor
RectanglePeteW::RectanglePeteW(const PointPeteW &arg) : 
		upperRight(arg), lowerLeft(PointPeteW(0)) {
	volume = 0;
	checkPoints();
	computeArea();
	cout << "\nCalling RectanglePeteW() on " << (*this);
}

// Detailed constructor
RectanglePeteW::RectanglePeteW(const PointPeteW &left, 
							   const PointPeteW &right) : 
		lowerLeft(left), upperRight(right) {
	volume = 0;
	checkPoints();
	computeArea();
	cout << "\nCalling RectanglePeteW() on " << (*this);
}

// Destructor
RectanglePeteW::~RectanglePeteW() {
	cout << "\nCalling ~RectanglePeteW() on " << (*this);
}

// Getters
PointPeteW RectanglePeteW::getUpperRight() const {
	return upperRight;
}

PointPeteW RectanglePeteW::getLowerLeft() const {
	return lowerLeft;
}

FractionPeteW RectanglePeteW::getLength() const {
	return FractionPeteW(upperRight.getY() - lowerLeft.getY());
}

FractionPeteW RectanglePeteW::getWidth() const {
	return FractionPeteW(upperRight.getX() - lowerLeft.getX());
}
FractionPeteW RectanglePeteW::getArea() const {
	return area;
}

FractionPeteW RectanglePeteW::getVolume(void) const {
	return volume;
}

// Setters
void RectanglePeteW::setUpperRight(const PointPeteW &arg) {
	upperRight = arg;
	checkPoints();
	computeArea();
}

void RectanglePeteW::setUpperRight(const FractionPeteW &x, 
								   const FractionPeteW &y) {
	upperRight.setX(x);
	upperRight.setY(y);
	checkPoints();
	computeArea();
}

void RectanglePeteW::setLowerLeft(const PointPeteW &arg) {
	lowerLeft = arg;
	checkPoints();
	computeArea();
}

void RectanglePeteW::setLowerLeft(const FractionPeteW &x, 
								  const FractionPeteW &y) {
	lowerLeft.setX(x);
	lowerLeft.setY(y);
	checkPoints();
	computeArea();
}

// Assignment operator
RectanglePeteW& RectanglePeteW::operator=(const 
		RectanglePeteW &arg) {
	(*this).upperRight = arg.upperRight;
	(*this).lowerLeft = arg.lowerLeft;
	checkPoints();
	computeArea();
	return *this;
}

// Helper functions

void RectanglePeteW::computeArea() {
	(*this).area = (upperRight.getY() - lowerLeft.getY()) *
		(upperRight.getX() - lowerLeft.getX());
}

void RectanglePeteW::computeVolume(void) {
	volume = 0;
}

void RectanglePeteW::print() {
	cout << "\nRectangle:"
		"\n  Lower Left: " << lowerLeft <<
		"\n  Upper Right: " << upperRight <<
		"\n  Area: " << area << endl;
}

void RectanglePeteW::checkPoints() {
	FractionPeteW* temp = nullptr;

	if (lowerLeft.getX() > upperRight.getX()) {
		temp = new FractionPeteW(lowerLeft.getX());
		lowerLeft.setX(upperRight.getX());
		upperRight.setX(*temp);
		delete temp;
	}

	if (lowerLeft.getY() > upperRight.getY()) {
		temp = new FractionPeteW(lowerLeft.getY());
		lowerLeft.setY(upperRight.getY());
		upperRight.setY(*temp);
		delete temp;
	}
}

// Insertion operator
ostream& operator<<(ostream& os, const RectanglePeteW &arg) {
	os << "\nRectangle:"
		"\n  Lower Left: " << arg.lowerLeft <<
		"\n  Upper Right: " << arg.upperRight <<
		"\n  Area: " << arg.area << endl;
	return os;
}