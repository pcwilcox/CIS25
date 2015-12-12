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
	h = 0;
	area = 0;
	volume = 0;
	cout << "\nCalling BoxPeteW() on " << *this;
}

// Convert constructor
BoxPeteW::BoxPeteW(const RectanglePeteW &base) : RectanglePeteW(base) {
	h = 0;
	volume = 0;
	cout << "\nCalling BoxPeteW() on " << *this;
}

// Copy constructor
BoxPeteW::BoxPeteW(const BoxPeteW &other) : RectanglePeteW(other.lowerLeft, other.upperRight), h(other.h) {
	area = other.area;
	volume = other.volume;
	cout << "\nCalling BoxPeteW() on " << *this;
}

// Detailed constructor
BoxPeteW::BoxPeteW(const RectanglePeteW &base, const FractionPeteW &height) : RectanglePeteW(base), h(height) {
	computeArea();
	computeVolume();
	cout << "\nCalling BoxPeteW() on " << *this;
}

// Destructor
BoxPeteW::~BoxPeteW() {
	cout << "\nCalling ~BoxPeteW() on " << *this;
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
	FractionPeteW x = upperRight.getX() - lowerLeft.getX();
	FractionPeteW y = upperRight.getY() - lowerLeft.getY();
	
	(*this).area = ((x * y) + (x * h) + (h * y)) * 2;
}

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

ostream& operator<<(ostream& os, BoxPeteW& box) {
	os << "\nBox:"
		"\n  Lower left:	" << box.lowerLeft <<
		"\n  Upper right:	" << box.upperRight <<
		"\n  Height:		" << box.h <<
		"\n  Area:			" << box.area <<
		"\n  Volume:		" << box.volume;
	return os;
}