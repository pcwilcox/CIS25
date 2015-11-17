#include "RectanglePeteW.h"

RectanglePeteW::RectanglePeteW() {
	upperRight = PointPeteW(FractionPeteW(0), FractionPeteW(0));
	lowerLeft = PointPeteW(FractionPeteW(0), FractionPeteW(0));
	cout << "\nCalling RectanglePeteW() on " << (*this);
}

RectanglePeteW::RectanglePeteW(const RectanglePeteW &arg) : upperRight(arg.upperRight), lowerLeft(arg.lowerLeft) {
	if (upperRight.getX() < lowerLeft.getX()) {
		// right is left of left
	} else if (upperRight.getY() < lowerLeft.getY()) {
		// upper is lower than lower
	}
	cout << "\nCalling RectanglePeteW() on " << (*this);
}

RectanglePeteW::RectanglePeteW(const PointPeteW &arg) : upperRight(arg), lowerLeft(PointPeteW(0)) {
	cout << "\nCalling RectanglePeteW() on " << (*this);
}

RectanglePeteW::RectanglePeteW(const PointPeteW &argPoint, const int &argInt) : lowerLeft(argPoint), upperRight(FractionPeteW(argPoint.getX + argInt, argPoint.getY + argInt)) {
	cout << "\nCalling RectanglePeteW() on " << (*this);
}

RectanglePeteW::RectanglePeteW(const PointPeteW &left, const PointPeteW &right) : lowerLeft(left), upperRight(right) {
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
