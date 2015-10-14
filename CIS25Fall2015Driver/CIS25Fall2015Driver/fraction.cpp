#include "fraction.h"
#include <iostream>

using namespace std;



Fraction::Fraction() {
	num = 0;
	denom = 1;
	isNegative = false;
}

Fraction::Fraction(int input) {
	if (input < 0) {
		input = -input;
		isNegative = true;
	} else {
		isNegative = false;
	}
	num = input;
	denom = 1;
}

Fraction::Fraction(const Fraction& input) {
	if (input.getSign == true) {
		num = -input.getNum;
	} else {
		num = input.getNum;
	}

	denom = input.getDenom;
}

int Fraction::getNum(void) {
	return num;
}

void Fraction::setNum(int input) {
	if (input < 0) {
		num = -input;
	} else {
		num = input;
	}
}

int Fraction::getDenom(void) {
	return denom;
}

void Fraction::setDenom(int input) {
	if (input != 0) {
		denom = input;
	} else if (input < 0) {
		denom = -input;
		isNegative = true;
	} else {
		denom = input;
	}
}

// Returns true if negative
bool Fraction::getSign(void) {
	return isNegative;
}

void Fraction::setSign(bool input) {
	isNegative = input;
}

char Fraction::printSign() {
	if (isNegative == true) {
		return '-';
	} else {
		return '\0';
	}
}

void Fraction::print() {
	cout << printSign() << num << "/" << denom;
}