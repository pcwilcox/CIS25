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
}

// Convert constructor
CylinderPeteW::CylinderPeteW(const CirclePeteW &) {
}

// Copy constructor
CylinderPeteW::CylinderPeteW(const CylinderPeteW &) {
}

// Detailed constructor
CylinderPeteW::CylinderPeteW(const CirclePeteW &, const FractionPeteW &) {
}

// Destructor
CylinderPeteW::~CylinderPeteW() {
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

ostream& operator<<(ostream& os, CylinderPeteW &cyl) {
	os << "\nCylinder: "
		"\n  Center:	" << cyl.center <<
		"\n  Radius:	" << cyl.radius <<
		"\n  Height:	" << cyl.h <<
		"\n  Area:		" << cyl.area <<
		"\n  Volume:	" << cyl.volume << endl;
	return os;
}
