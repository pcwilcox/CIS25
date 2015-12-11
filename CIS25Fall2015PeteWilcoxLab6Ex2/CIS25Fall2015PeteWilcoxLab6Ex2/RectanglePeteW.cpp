#pragma once

/**
  * Program Name: RectanglePeteW.cpp
  * Discussion:   Definition File --
  *                 RectanglePeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/12/10
  */

#include <iostream>
#include "RectanglePeteW.h"
#include "FractionPeteW.h"
#include "PointPeteW.h"

using namespace std;

RectanglePeteW::RectanglePeteW() {
	upperRight = PointPeteW(FractionPeteW(0), FractionPeteW(0));
	lowerLeft = PointPeteW(FractionPeteW(0), FractionPeteW(0));
	computeArea();
	cout << "\nCalling RectanglePeteW() on " << (*this);
}

RectanglePeteW::RectanglePeteW(const RectanglePeteW &arg) : upperRight(arg.upperRight), lowerLeft(arg.lowerLeft) {
	checkPoints();
	computeArea();
	cout << "\nCalling RectanglePeteW() on " << (*this);
}

RectanglePeteW::RectanglePeteW(const PointPeteW &arg) : upperRight(arg), lowerLeft(PointPeteW(0)) {
	checkPoints();
	computeArea();
	cout << "\nCalling RectanglePeteW() on " << (*this);
}

RectanglePeteW::RectanglePeteW(const PointPeteW &left, const PointPeteW &right) : lowerLeft(left), upperRight(right) {
	checkPoints();
	computeArea();
	cout << "\nCalling RectanglePeteW() on " << (*this);
}

RectanglePeteW::~RectanglePeteW() {
	cout << "\nCalling ~RectanglePeteW() on " << (*this);
}

PointPeteW RectanglePeteW::getUpperRight()  const {
	return upperRight;
}

PointPeteW RectanglePeteW::getLowerLeft()  const {
	return lowerLeft;
}

FractionPeteW RectanglePeteW::getHeight()  const {
	return FractionPeteW(upperRight.getY() - lowerLeft.getY());
}

FractionPeteW RectanglePeteW::getWidth()  const {
	return FractionPeteW(upperRight.getX() - lowerLeft.getX());
}
FractionPeteW RectanglePeteW::getArea() const {
	return area;
}

void RectanglePeteW::computeArea() {
	(*this).area = (upperRight.getY() - lowerLeft.getY()) * (upperRight.getX() - lowerLeft.getX());
}

void RectanglePeteW::print() {
	cout << "\nRectangle:"
		"\n  Lower Left: " << lowerLeft << 
		"\n  Upper Right: " << upperRight <<
		"\n  Area: " << area << endl;
}

void RectanglePeteW::setUpperRight(const PointPeteW &arg) {
	upperRight = arg;
	checkPoints();
}

void RectanglePeteW::setUpperRight(const FractionPeteW &x, const FractionPeteW &y) {
	upperRight.setX(x);
	upperRight.setY(y);
	checkPoints();
}

void RectanglePeteW::setLowerLeft(const PointPeteW &arg) {
	lowerLeft = arg;
	checkPoints();
}

void RectanglePeteW::setLowerLeft(const FractionPeteW &x, const FractionPeteW &y) {
	lowerLeft.setX(x);
	lowerLeft.setY(y);
	checkPoints();
}

RectanglePeteW & RectanglePeteW::operator=(const RectanglePeteW &arg) {
	(*this).upperRight = arg.upperRight;
	(*this).lowerLeft = arg.lowerLeft;
	checkPoints();
	return *this;
}

void RectanglePeteW::checkPoints() {
	FractionPeteW* swapX = nullptr;
	FractionPeteW* swapY = nullptr;

	if (upperRight.getX() < lowerLeft.getX() && upperRight.getY() < lowerLeft.getY()) {
		swapX = new FractionPeteW(upperRight.getX());
		swapY = new FractionPeteW(upperRight.getY());
		upperRight.setX(lowerLeft.getX());
		upperRight.setY(lowerLeft.getY());
		lowerLeft.setX(*swapX);
		lowerLeft.setY(*swapY);
		delete swapX;
		delete swapY;
	} else if (upperRight.getX() < lowerLeft.getX()) {
		swapX = new FractionPeteW(upperRight.getX());
		upperRight.setX(lowerLeft.getX());
		lowerLeft.setX(*swapX);
		delete swapX;

	} else if (upperRight.getY() < lowerLeft.getY()) {
		swapY = new FractionPeteW(upperRight.getY());
		upperRight.setY(lowerLeft.getY());
		lowerLeft.setY(*swapY);
		delete swapY;
	}
}

ostream& operator<<(ostream& os, const RectanglePeteW &arg) {
	os << "[" << arg.lowerLeft << ", " << arg.upperRight << "]";
	return os;
}