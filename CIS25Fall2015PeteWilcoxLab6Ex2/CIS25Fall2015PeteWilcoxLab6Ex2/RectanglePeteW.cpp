#pragma once

/**
  * Program Name: RectanglePeteW.cpp
  * Discussion:   Declaration File --
  *                 RectanglePeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/11/XX
  */

#include "RectanglePeteW.h"

RectanglePeteW::RectanglePeteW() {
	upperRight = PointPeteW(FractionPeteW(0), FractionPeteW(0));
	lowerLeft = PointPeteW(FractionPeteW(0), FractionPeteW(0));
	cout << "\nCalling RectanglePeteW() on " << (*this);
}

RectanglePeteW::RectanglePeteW(const RectanglePeteW &arg) : upperRight(arg.upperRight), lowerLeft(arg.lowerLeft) {
	checkPoints();
	cout << "\nCalling RectanglePeteW() on " << (*this);
}

RectanglePeteW::RectanglePeteW(const PointPeteW &arg) : upperRight(arg), lowerLeft(PointPeteW(0)) {
	checkPoints();
	cout << "\nCalling RectanglePeteW() on " << (*this);
}

RectanglePeteW::RectanglePeteW(const PointPeteW &argPoint, const int &argInt) : lowerLeft(argPoint), upperRight(FractionPeteW(argPoint.getX + argInt, argPoint.getY + argInt)) {
	checkPoints();
	cout << "\nCalling RectanglePeteW() on " << (*this);
}

RectanglePeteW::RectanglePeteW(const PointPeteW &left, const PointPeteW &right) : lowerLeft(left), upperRight(right) {
	checkPoints();
	cout << "\nCalling RectanglePeteW() on " << (*this);
}

RectanglePeteW::~RectanglePeteW() {
	cout << "\nCalling ~RectanglePeteW() on " << (*this);
}

PointPeteW RectanglePeteW::getUpperRight() {
	return upperRight;
}

PointPeteW RectanglePeteW::getLowerLeft() {
	return lowerLeft;
}

FractionPeteW RectanglePeteW::getHeight() {
	return FractionPeteW(upperRight.getY() - lowerLeft.getY());
}

FractionPeteW RectanglePeteW::getWidth() {
	return FractionPeteW(upperRight.getX() - lowerLeft.getX());
}

FractionPeteW RectanglePeteW::getArea() {
	return FractionPeteW((upperRight.getY() - lowerLeft.getY()) * (upperRight.getX() - lowerLeft.getX()));
}

void RectanglePeteW::print() {
	cout << "\nUpper left: (" << lowerLeft.getX() 
		<< ", " << upperRight.getY() 
		<< "), Upper right: (" 	<< upperRight 
		<< ", Lower left: " << lowerLeft << 
		", Lower right: (" << upperRight.getX() 
		<< ", " << lowerLeft.getY() << ").";
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

bool RectanglePeteW::operator==(const RectanglePeteW &arg) {
	if ((*this).upperRight == arg.upperRight &&
		(*this).lowerLeft == arg.lowerLeft) {
		return true;
	} else {
		return false;
	}
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

// TODO: Make arg const
ostream& operator<<(ostream& os, RectanglePeteW &arg) {
	os << "(" << arg.lowerLeft.getX() << ", " <<
		arg.upperRight.getY() << "), " <<
		arg.upperRight << ", (" <<
		arg.upperRight.getX() << ", " <<
		arg.lowerLeft.getY() << "), " << arg.lowerLeft;
	return os;
}