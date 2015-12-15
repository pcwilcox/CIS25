/**
  * Program Name: CylinderPeteW.cpp
  * Discussion:   Definition File --
  *                 CylinderPeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/12/15
  */

#include "CylinderPeteW.h"

// Default constructor
CylinderPeteW::CylinderPeteW() {
	h = 0;
	area = 0;
	volume = 0;
	cout << "\nCalling CylinderPeteW() on " << *this;
}

// Convert constructor
CylinderPeteW::CylinderPeteW(const CirclePeteW &base) : 
		CirclePeteW(base), h(0) {
	volume = 0;
	cout << "\nCalling CylinderPeteW() on " << *this;
}

// Copy constructor
CylinderPeteW::CylinderPeteW(const CylinderPeteW &other) : 
		CirclePeteW(other.center, other.radius), h(other.h) {
	area = other.area;
	volume = other.volume;
	cout << "\nCalling CylinderPeteW() on " << *this;
}

// Detailed constructor
CylinderPeteW::CylinderPeteW(const CirclePeteW &base, 
								const FractionPeteW &height) : 
								CirclePeteW(base), h(height) {
	computeArea();
	computeVolume();
	cout << "\nCalling CylinderPeteW() on " << *this;
}

// Destructor
CylinderPeteW::~CylinderPeteW() {
	cout << "\nCalling ~CylinderPeteW() on " << *this;
}

// Getters
FractionPeteW CylinderPeteW::getHeight() const {
	return h;
}

FractionPeteW CylinderPeteW::getArea() const {
	return area;
}

FractionPeteW CylinderPeteW::getVolume() const {
	return volume;
}

// Setter
void CylinderPeteW::setHeight(const FractionPeteW &height) {
	h = (height > 0) ? height : -height;
	computeArea();
	computeVolume();
}

// Helpers
void CylinderPeteW::computeArea() {
	FractionPeteW PI(157, 50);
	area = (PI * radius * 2) * (h + radius);
}

void CylinderPeteW::computeVolume() {
	FractionPeteW PI(157, 50);
	volume = PI * radius * radius * h * 2;
}

void CylinderPeteW::print() {
	cout << "\nCylinder: "
		"\n  Center:	" << center <<
		"\n  Radius:	" << radius <<
		"\n  Height:	" << h <<
		"\n  Area:		" << area <<
		"\n  Volume:	" << volume << endl;
}

FractionPeteW CylinderPeteW::getBaseArea() const {
	return CirclePeteW::getArea();
}

ostream& operator<<(ostream& os, CylinderPeteW &cyl) {
	os << "\nCylinder: "
		"\n  Center:	" << cyl.center <<
		"\n  Radius:	" << cyl.radius <<
		"\n  Height:	" << cyl.h <<
		"\n  Area:		" << cyl.area <<
		"\n  Volume:	" << cyl.volume << endl;
	return os;
}

CylinderPeteW CylinderPeteW::operator+(const CylinderPeteW& arg) {
	return CylinderPeteW(
		CirclePeteW((*this).center.midpoint(arg.center),
			FractionPeteW(((*this).radius > arg.radius) ? 
						   (*this).radius : arg.radius)), 
		FractionPeteW(((*this).h > arg.h) ? (*this).h : arg.h));
}

bool CylinderPeteW::operator==(const CylinderPeteW& arg) const {
	if ((*this).volume == arg.volume) {
		return true;
	}
	return false;
}

bool CylinderPeteW::operator<(const CylinderPeteW& arg) const {
	if ((*this).volume < arg.volume) {
		return true;
	}
	return false;
}

bool CylinderPeteW::operator>(const CylinderPeteW& arg) const {
	if ((*this).volume > arg.volume) {
		return true;
	}
	return false;
}

bool CylinderPeteW::operator<=(const CylinderPeteW& arg) const {
	if ((*this).volume <= arg.volume) {
		return true;
	}
	return false;
}

bool CylinderPeteW::operator>=(const CylinderPeteW& arg) const {
	if ((*this).volume >= arg.volume) {
		return true;
	}
	return false;
}