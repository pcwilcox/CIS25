/**
  * Program Name: fractionPeteW.cpp
  * Discussion:   Definition File --
  *                 FractionPeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/12/15
  */

#include "fractionPeteW.h"
#include <iostream>

using namespace std;


// Default constructor
FractionPeteW::FractionPeteW() : num(0), denom(1) {
	cout << "\nCalling Fraction() on " << *this;
}

// Convert constructor
FractionPeteW::FractionPeteW(int input) : num(input), denom(1) {
	cout << "\nCalling Fraction() on " << *this;
}

// Copy constructor
FractionPeteW::FractionPeteW(const FractionPeteW& input) :
		num(input.num), denom(input.denom) {

	cout << "\nCalling Fraction() on " << *this;
	reduce();
}

// Explicit constructor
FractionPeteW::FractionPeteW(int inputNum, int inputDenom) :
		num(inputNum), denom(inputDenom) {
	reduce();
	cout << "\nCalling Fraction() on " << *this;
	
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
	if (right.num == 0) {
		cout << "\nDivide by zero!";
	} else {
		num = left.num * right.denom;
		denom = left.denom * right.num;
		reduce();
	}
}

void FractionPeteW::divide(const FractionPeteW& arg) {
	if (arg.num == 0) {
		cout << "\nDivide by zero!";
	} else {
		num *= arg.denom;
		denom *= arg.num;
		reduce();
	}
}

// Member overloads
FractionPeteW FractionPeteW::operator-() const {
	return FractionPeteW(-num, denom);
}

FractionPeteW& FractionPeteW::operator=(const FractionPeteW&
	arg) {

	num = arg.num;
	denom = arg.denom;
	return *this;
}

FractionPeteW FractionPeteW::operator+(const FractionPeteW&
	arg) const {

	return FractionPeteW(
		(*this).num * arg.denom + ((*this).denom * arg.num),
		(*this).denom * arg.denom);
}

FractionPeteW FractionPeteW::operator-(const FractionPeteW&
	arg) const {
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
	arg) const {
	return FractionPeteW(
		(*this).num * arg.denom, (*this).denom * arg.num);
}

FractionPeteW& FractionPeteW::operator+=(const FractionPeteW& arg) {
	num = num * arg.denom + denom * arg.num;
	denom = num * denom;
	reduce();
	return *this;
}

FractionPeteW& FractionPeteW::operator-=(const FractionPeteW& arg) {
	num = num * arg.denom - denom * arg.num;
	denom = num * denom;
	reduce();
	return *this;
}

FractionPeteW& FractionPeteW::operator*=(const FractionPeteW& arg) {
	num *= arg.num;
	denom *= arg.denom;
	reduce();
	return *this;
}

FractionPeteW& FractionPeteW::operator/=(const FractionPeteW& arg) {
	if (arg.denom == 0) {
		cout << "\nDivide by zero!";
	} else {
		num *= arg.denom;
		denom *= arg.num;
		reduce();
	}
	return *this;
}

bool FractionPeteW::operator==(const FractionPeteW &arg) const {
	if ((*this).num == arg.num && (*this).denom == arg.denom) {
		return true;
	}
	return false;
}

bool FractionPeteW::operator<(const FractionPeteW &arg) const {
	if (((*this).num * arg.denom) < ((*this).denom * arg.num)) {
		return true;
	}
	return false;
}

bool FractionPeteW::operator>(const FractionPeteW &arg) const {
	if (((*this).num * arg.denom) > ((*this).denom * arg.num)) {
		return true;
	}
	return false;
}

bool FractionPeteW::operator<=(const FractionPeteW &arg) const {
	if (((*this).num * arg.denom) <= ((*this).denom * arg.num)) {
		return true;
	}
	return false;
}

bool FractionPeteW::operator>=(const FractionPeteW &arg) const {
	if (((*this).num * arg.denom) >= ((*this).denom * arg.num)) {
		return true;
	}
	return false;
}

// Reduce() is called whenever other operations are performed
void FractionPeteW::reduce() {
	bool finished = false;
	bool negative = false;
	int n = 2;
	
	if (denom < 0) {
		num = -num;
		denom = -denom;
	}

	if (num < 0) {
		negative = true;
		num = -num;
	}

		
	while (finished == false) {
		if ((num < n) || (denom < n)) {
			finished = true;
		} else if ((num % n == 0) && (denom % n == 0)) {
			num /= n;
			denom /= n;
		} else {
			n++;
		}
	}

	if (negative) {
		num = -num;
	}
}

// Friend overload
ostream& operator<<(ostream& os, const FractionPeteW& f) {
	os << f.num << "/" << f.denom;
	return os;
}
