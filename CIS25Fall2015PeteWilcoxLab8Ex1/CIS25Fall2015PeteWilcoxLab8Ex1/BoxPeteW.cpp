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
	checkPoints();
	h = 0;
	volume = 0;
	cout << "\nCalling BoxPeteW() on " << *this;
}

// Copy constructor
BoxPeteW::BoxPeteW(const BoxPeteW &other) : RectanglePeteW(other.lowerLeft, other.upperRight), h(other.h) {
	checkPoints();
	area = other.area;
	volume = other.volume;
	cout << "\nCalling BoxPeteW() on " << *this;
}

// Detailed constructor
BoxPeteW::BoxPeteW(const RectanglePeteW &base, const FractionPeteW &height) : RectanglePeteW(base), h(height) {
	checkPoints();
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
	FractionPeteW length = upperRight.getX() - lowerLeft.getX();
	FractionPeteW width = upperRight.getY() - lowerLeft.getY();
	
	(*this).area = length * width * 2 + length * h * 2 + width * h * 2;
}

void BoxPeteW::computeVolume() {
	(*this).volume = (upperRight.getY() - lowerLeft.getY()) *
		(upperRight.getX() - lowerLeft.getX()) * h;
}

void BoxPeteW::checkPoints() {
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