/**
  * Program Name: BoxPeteW.cpp
  * Discussion:   Definition File --
  *                 BoxPeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/12/15
  */

#include "BoxPeteW.h"

using namespace std;

// Default constructor
BoxPeteW::BoxPeteW() {
}

// Convert constructor
BoxPeteW::BoxPeteW(const RectanglePeteW &base) {
}

// Copy constructor
BoxPeteW::BoxPeteW(const BoxPeteW &) {
}

// Detailed constructor
BoxPeteW::BoxPeteW(const RectanglePeteW &base, const FractionPeteW &height) {
}

// Destructor
BoxPeteW::~BoxPeteW() {
}

// Getters
FractionPeteW BoxPeteW::getHeight() const {
	return h;
}

FractionPeteW BoxPeteW::getArea() const {
	return area;
}

FractionPeteW BoxPeteW::getVolume() const {
	return volume;
}

// Setter
void BoxPeteW::setHeight(const FractionPeteW &height) {
	h = height;
	computeArea();
	computeVolume();
}

// Helpers
void BoxPeteW::computeArea() {
	(*this).area = 
		((upperRight.getY() - lowerLeft.getY()) * 
			(upperRight.getX() - lowerLeft.getX()) * 2) + 
		((h * (upperRight.getX() - lowerLeft.getX())) * 2) + 
		((h * (upperRight.getY() - lowerLeft.getY())) * 2); 
}

// (*this).area = (upperRight.getY() - lowerLeft.getY()) * (upperRight.getX() - lowerLeft.getX());

void BoxPeteW::computeVolume() {
	(*this).volume = (upperRight.getY() - lowerLeft.getY()) *
		(upperRight.getX() - lowerLeft.getX()) * h;
}

void BoxPeteW::print() {
	cout << "\nBox:"
		"\n  Lower left:	" << lowerLeft <<
		"\n  Upper right:	" << upperRight <<
		"\n  Height:		" << h <<
		"\n  Area:			" << area <<
		"\n  Volume:		" << volume;
}
