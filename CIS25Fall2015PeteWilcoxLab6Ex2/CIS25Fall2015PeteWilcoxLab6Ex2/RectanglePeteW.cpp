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

FractionPeteW RectanglePeteW::getArea()  const {
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

RectanglePeteW & RectanglePeteW::operator+(const RectanglePeteW &arg) {
	FractionPeteW newHeight;
	FractionPeteW newWidth;
	PointPeteW newLowerLeft;
	PointPeteW newUpperRight;

	newLowerLeft.setX(FractionPeteW((*this).lowerLeft.getX() + arg.lowerLeft.getX()) / 2);
	newLowerLeft.setY(FractionPeteW((*this).lowerLeft.getY() + arg.lowerLeft.getY()) / 2);
	newWidth = (((*this).upperRight.getX() - (*this).lowerLeft.getX()) + (arg.upperRight.getX() - arg.lowerLeft.getX())) / 2;
	newHeight = (((*this).upperRight.getY() - (*this).lowerLeft.getY()) + (arg.upperRight.getY() - arg.lowerLeft.getY())) / 2;

	newUpperRight.setX(newLowerLeft.getX() + newWidth);
	newUpperRight.setY(newLowerLeft.getY() + newHeight);

	return RectanglePeteW(newLowerLeft, newUpperRight);

}

bool RectanglePeteW::operator==(const RectanglePeteW &arg) {
	if ((*this).upperRight == arg.upperRight &&
		(*this).lowerLeft == arg.lowerLeft) {
		return true;
	} else {
		return false;
	}
}

bool RectanglePeteW::operator<(const RectanglePeteW &arg) {
	if (((*this).upperRight.getY() - (*this).lowerLeft.getY()) * 
		((*this).upperRight.getX() - (*this).lowerLeft.getX()) < 
		(arg.upperRight.getY() - arg.lowerLeft.getY()) * 
		(arg.upperRight.getX() - arg.lowerLeft.getX())) {
		return true;
	}
	return false;
}

bool RectanglePeteW::operator>(const RectanglePeteW &arg) {
	if (((*this).upperRight.getY() - (*this).lowerLeft.getY()) *
		((*this).upperRight.getX() - (*this).lowerLeft.getX()) >
		(arg.upperRight.getY() - arg.lowerLeft.getY()) *
		(arg.upperRight.getX() - arg.lowerLeft.getX())) {
		return true;
	}
	return false;
	return false;
}

bool RectanglePeteW::operator<=(const RectanglePeteW &arg) {
	if (((*this).upperRight.getY() - (*this).lowerLeft.getY()) *
		((*this).upperRight.getX() - (*this).lowerLeft.getX())
		<= (arg.upperRight.getY() - arg.lowerLeft.getY()) *
		   (arg.upperRight.getX() - arg.lowerLeft.getX())) {
		return true;
	}
	return false;
}

bool RectanglePeteW::operator>=(const RectanglePeteW &arg) {
	if (((*this).upperRight.getY() - (*this).lowerLeft.getY()) *
		((*this).upperRight.getX() - (*this).lowerLeft.getX()) 
		>= (arg.upperRight.getY() - arg.lowerLeft.getY()) *
		   (arg.upperRight.getX() - arg.lowerLeft.getX())) {
		return true;
	}
	return false;
}

bool RectanglePeteW::operator<(const CirclePeteW &arg) {
	if (((*this).upperRight.getY() - (*this).lowerLeft.getY()) *
		((*this).upperRight.getX() - (*this).lowerLeft.getX()) <
		arg.getArea()) {
		return true;
	}
	return false;
}

bool RectanglePeteW::operator>(const CirclePeteW &arg) {
	if (((*this).upperRight.getY() - (*this).lowerLeft.getY()) *
		((*this).upperRight.getX() - (*this).lowerLeft.getX()) >
		arg.getArea()) {
		return true;
	}
	return false;
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
	os << "(" << arg.lowerLeft.getX() << ", " <<
		arg.upperRight.getY() << "), " <<
		arg.upperRight << ", (" <<
		arg.upperRight.getX() << ", " <<
		arg.lowerLeft.getY() << "), " << arg.lowerLeft;
	return os;
}