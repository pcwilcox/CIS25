/**
  * Program Name: fractionPeteW.cpp
  * Discussion:   Definition File --
  *                 FractionPeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/12/01
  */

#include "fractionPeteW.h"
#include <iostream>

using namespace std;


// Default constructor
FractionPeteW::FractionPeteW() : num(0), denom(1) {
	cout << "\nCalling Fraction()";
}

// Convert constructor
FractionPeteW::FractionPeteW(int input) : num(input), denom(1) {
	cout << "\nCalling Fraction()";
}

// Copy constructor
FractionPeteW::FractionPeteW(const FractionPeteW& input) :
	num(input.num), denom(input.denom) {

	cout << "\nCalling Fraction()";
	reduce();
}

// Explicit constructor
FractionPeteW::FractionPeteW(int inputNum, int inputDenom) :
	num(inputNum), denom(inputDenom) {

	cout << "\nCalling Fraction()";
	reduce();
}

// Destructor
FractionPeteW::~FractionPeteW() {
	cout << "\nCalling ~Fraction() on " << (*this);
}

// Getters
int FractionPeteW::getNum() const {
	return num;
}

int FractionPeteW::getDenom() const {
	return denom;
}

// Setters
void FractionPeteW::setNum(int input) {
	num = input;
	reduce();
}

void FractionPeteW::setDenom(int input) {
	if (input < 0) {
		denom = -input;
		num = -num;
	} else if (input > 0) {
		denom = input;
	} else {
		cout << "\nDenominator cannot be 0!";
	}

	reduce();
}

void FractionPeteW::setBoth(int inputNum, int inputDenom) {
	if (inputDenom < 0) {
		denom = -inputDenom;
		num = -inputNum;
	} else {
		num = inputNum;
		denom = inputDenom;
	}
	reduce();
}

// Print
void FractionPeteW::print() {
	cout << num << "/" << denom;
}

// Member math functions
void FractionPeteW::add(const FractionPeteW& left,
	const FractionPeteW& right) {

	num = left.num * right.denom + left.denom * right.num;
	denom = left.denom * right.denom;
	reduce();
}

void FractionPeteW::add(const FractionPeteW& arg) {
	int inputNum = arg.num;
	int inputDenom = arg.denom;
	int workingNum = num;
	int workingDenom = denom;

	if (inputDenom == workingDenom) {
		num += inputNum;
	} else {

		inputNum *= workingDenom;
		inputDenom *= workingDenom;
		workingNum *= arg.denom;
		workingDenom *= arg.denom;

		num = workingNum + inputNum;
		denom = workingDenom;
	}

	reduce();
}

void FractionPeteW::subtract(const FractionPeteW& left,
	const FractionPeteW& right) {

	num = left.num * right.denom - left.denom * right.num;
	denom = left.denom * right.denom;
	reduce();
}

void FractionPeteW::subtract(const FractionPeteW& arg) {
	int inputNum = arg.num;
	int inputDenom = arg.denom;
	int workingNum = num;
	int workingDenom = denom;

	if (inputDenom == workingDenom) {
		num += inputNum;
	} else {

		inputNum *= workingDenom;
		inputDenom *= workingDenom;
		workingNum *= arg.denom;
		workingDenom *= arg.denom;

		num = workingNum - inputNum;
		denom = workingDenom;
	}

	reduce();
}

void FractionPeteW::multiply(const FractionPeteW& left,
	const FractionPeteW& right) {

	num = left.num * right.num;
	denom = left.denom * right.denom;
	reduce();
}

void FractionPeteW::multiply(const FractionPeteW& arg) {
	num *= arg.num;
	denom *= arg.denom;
	reduce();
}

void FractionPeteW::divide(const FractionPeteW& left,
	const FractionPeteW& right) {
	num = left.num * right.denom;
	denom = left.denom * right.num;
	reduce();
}

void FractionPeteW::divide(const FractionPeteW& arg) {
	num *= arg.denom;
	denom *= arg.num;
	reduce();
}

// Member overloads
FractionPeteW FractionPeteW::operator-() {
	return FractionPeteW(-num, denom);
}

FractionPeteW& FractionPeteW::operator=(const FractionPeteW&
	arg) {

	num = arg.num;
	denom = arg.denom;
	return *this;
}

FractionPeteW FractionPeteW::operator+(const FractionPeteW&
	arg) {

	return FractionPeteW(
		(*this).num * arg.denom + ((*this).denom * arg.num),
		(*this).denom * arg.denom);
}

FractionPeteW FractionPeteW::operator-(const FractionPeteW&
	arg) {
	return FractionPeteW(
		(*this).num * arg.denom - ((*this).denom * arg.num),
		(*this).denom * arg.denom);
}

FractionPeteW FractionPeteW::operator*(const FractionPeteW&
	arg) const {
	return FractionPeteW((*this).num * arg.num,
		(*this).denom * arg.denom);
}

FractionPeteW FractionPeteW::operator/(const FractionPeteW&
	arg) {
	return FractionPeteW(
		(*this).num * arg.denom, (*this).denom * arg.num);
}

FractionPeteW& FractionPeteW::operator+=(const FractionPeteW& arg) {
	num = num * arg.denom + denom * arg.num;
	denom = num * denom;
	reduce();
	return *this;
}

FractionPeteW& FractionPeteW::operator+=(const int& arg) {
	num += arg * denom;
	reduce();
	return *this;
}

FractionPeteW& FractionPeteW::operator-=(const FractionPeteW& arg) {
	num = num * arg.denom - denom * arg.num;
	denom = num * denom;
	reduce();
	return *this;
}
FractionPeteW& FractionPeteW::operator-=(const int& arg) {
	num -= arg * denom;
	reduce();
	return *this;
}

FractionPeteW& FractionPeteW::operator*=(const FractionPeteW& arg) {
	num *= arg.num;
	denom *= arg.denom;
	reduce();
	return *this;
}

FractionPeteW& FractionPeteW::operator*=(const int& arg) {
	num *= arg;
	reduce();
	return *this;
}

FractionPeteW& FractionPeteW::operator/=(const FractionPeteW& arg) {
	num *= arg.denom;
	denom *= arg.num;
	reduce();
	return *this;
}

FractionPeteW& FractionPeteW::operator/=(const int& arg) {
	num /= arg;
	reduce();
	return *this;
}


bool FractionPeteW::operator==(const FractionPeteW &arg) {
	if ((*this).num == arg.num && (*this).denom == arg.denom) {
		return true;
	} else {
		return false;
	}
}

bool FractionPeteW::operator<(const FractionPeteW &arg) {
	int leftNum, rightNum;

	leftNum = (*this).num * arg.denom;
	rightNum = (*this).denom * arg.num;

	if (leftNum < rightNum) {
		return true;
	} else {
		return false;
	}

}

bool FractionPeteW::operator>(const FractionPeteW &arg) {
	int leftNum, rightNum;

	leftNum = (*this).num * arg.denom;
	rightNum = (*this).denom * arg.num;

	if (leftNum > rightNum) {
		return true;
	} else {
		return false;
	}
}

bool FractionPeteW::operator<=(const FractionPeteW &arg) {
	int leftNum, rightNum;

	leftNum = (*this).num * arg.denom;
	rightNum = (*this).denom * arg.num;

	if (leftNum <= rightNum) {
		return true;
	} else {
		return false;
	}
}

bool FractionPeteW::operator>=(const FractionPeteW &arg) {
	int leftNum, rightNum;

	leftNum = (*this).num * arg.denom;
	rightNum = (*this).denom * arg.num;

	if (leftNum >= rightNum) {
		return true;
	} else {
		return false;
	}
}

// Reduce() is called whenever other operations are performed
void FractionPeteW::reduce() {
	bool finished = false;
	int n = 2;
	int workingNum;

	if (num < 0) {
		workingNum = -num;
	} else {
		workingNum = num;
	}

	while (finished == false) {
		if ((num % n == 0) && (denom % n == 0)) {
			num /= n;
			denom /= n;
		} else if ((num <= n) || (denom <= n)) {
			finished = true;
		} else {
			n++;
		}
	}

	if (denom < 0) {
		num = -num;
		denom = -denom;
	}
}

// Friend overloads
ostream& operator<<(ostream& os, const FractionPeteW& f) {
	os << f.num << "/" << f.denom;
	return os;
}

// Two each of these so that binary operations can be performed
// with a Fraction on either side of the operator
FractionPeteW operator+(const int& left,
	const FractionPeteW& right) {

	return FractionPeteW(
		left * right.denom + right.num, right.denom);
}


FractionPeteW operator-(const FractionPeteW& left,
	const int& right) {

	return FractionPeteW(
		left.denom * right + left.num, left.denom);
}

FractionPeteW operator*(const int& left,
	const FractionPeteW& right) {

	return FractionPeteW(
		left * right.num, right.denom);
}

FractionPeteW operator*(const FractionPeteW& left,
	const int& right) {

	return FractionPeteW(left.num * right, left.denom);
}

FractionPeteW operator/(const int& left,
	const FractionPeteW& right) {

	return FractionPeteW(left * right.denom, right.num);
}

FractionPeteW operator/(const FractionPeteW& left,
	const int& right) {

	return FractionPeteW(left.denom * right, left.num);
}

bool operator==(const int& left, const FractionPeteW& right) {
	if (left * right.denom == right.num) {
		return true;
	} else {
		return false;
	}
}

bool operator==(const FractionPeteW& left, const int& right) {
	if (right * left.denom == left.num) {
		return true;
	} else {
		return false;
	}
}
bool operator<(const int& left, const FractionPeteW& right) {
	if (left * right.denom < right.num) {
		return true;
	} else {
		return false;
	}
}

bool operator<(const FractionPeteW& left, const int& right) {
	if (left.num < left.denom * right) {
		return true;
	} else {
		return false;
	}
}

bool operator>(const int& left, const FractionPeteW& right) {
	if (left * right.denom > right.num) {
		return true;
	} else {
		return false;
	}
}

bool operator>(const FractionPeteW& left, const int& right) {
	if (left.num > left.denom * right) {
		return true;
	} else {
		return false;
	}
}

bool operator<=(const int& left, const FractionPeteW& right) {
	if (left * right.denom <= right.num) {
		return true;
	} else {
		return false;
	}
}

bool operator<=(const FractionPeteW& left, const int& right) {
	if (left.num < right * left.denom) {
		return true;
	} else {
		return false;
	}
}

bool operator>=(const int& left, const FractionPeteW& right) {
	if (left * right.denom >= right.num) {
		return true;
	} else {
		return false;
	}
}

bool operator>=(const FractionPeteW& left, const int& right) {
	if (left.num >= left.denom * right) {
		return true;
	} else {
		return false;
	}
}