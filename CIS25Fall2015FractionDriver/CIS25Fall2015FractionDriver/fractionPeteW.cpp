/**
  * Program Name: fractionPeteW.cpp
  * Discussion:   Declaration File --
  *                 FractionPeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/11/24
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
							 num(input.num), 
							 denom(input.denom) {

	cout << "\nCalling Fraction()";
	reduce();
}

// Detailed constructor
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

// Member arithmetic functions
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

void FractionPeteW::multiply(const FractionPeteW& arg) {
	num *= arg.num;
	denom *= arg.denom;
	reduce();
}

void FractionPeteW::divide(const FractionPeteW& arg) {
	num *= arg.denom;
	denom *= arg.num;
	reduce();
}

void FractionPeteW::add(const FractionPeteW& left,
					    const FractionPeteW& right) {

	num = left.num * right.denom + left.denom * right.num;
	denom = left.denom * right.denom;
	reduce();
}

void FractionPeteW::subtract(const FractionPeteW& left,
							 const FractionPeteW& right) {

	num = left.num * right.denom - left.denom * right.num;
	denom = left.denom * right.denom;
	reduce();
}

void FractionPeteW::multiply(const FractionPeteW& left,
							 const FractionPeteW& right) {

	num = left.num * right.num;
	denom = left.denom * right.denom;
	reduce();
}

void FractionPeteW::divide(const FractionPeteW& left,
						   const FractionPeteW& right) {
	num = left.num * right.denom;
	denom = left.denom * right.num;
	reduce();
}

// Operator overloads - member
FractionPeteW FractionPeteW::operator-() {
	num = -num;
	return *this;
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
		((*this).num * arg.denom) + ((*this).denom * arg.num),
		(*this).denom * arg.denom);
}

FractionPeteW FractionPeteW::operator-(const FractionPeteW&
									   arg) {
	return FractionPeteW(
		((*this).num * arg.denom) - ((*this).denom * arg.num),
		(*this).denom * arg.denom);
}

FractionPeteW FractionPeteW::operator*(const FractionPeteW&
									   arg) {
	return FractionPeteW((*this).num * arg.num,
		(*this).denom * arg.denom);
}

FractionPeteW FractionPeteW::operator/(const FractionPeteW&
									   arg) {
	return FractionPeteW(
		(*this).num * arg.denom, (*this).denom * arg.num);
}

FractionPeteW& FractionPeteW::operator+=(const FractionPeteW 
										 &arg) {
	(*this).num = (*this).num * arg.denom + 
				  (*this).denom * arg.num;
	(*this).denom = (*this).denom * arg.denom;
	reduce();
	return *this;
}

FractionPeteW& FractionPeteW::operator-=(const FractionPeteW 
										 &arg) {
	(*this).num = (*this).num * arg.denom - 
				  (*this).denom * arg.num;
	(*this).denom = (*this).denom * arg.denom;
	reduce();
	return *this;
}

FractionPeteW& FractionPeteW::operator*=(const FractionPeteW 
										 &arg) {
	(*this).num = (*this).num * arg.num;
	(*this).denom = (*this).denom * arg.denom;
	reduce();
	return *this;
}

FractionPeteW& FractionPeteW::operator/=(const FractionPeteW 
										 &arg) {
	(*this).num = (*this).num * arg.denom;
	(*this).denom = (*this).denom * arg.num;
	reduce();
	return *this;
}

FractionPeteW FractionPeteW::operator+(const int& arg) {
	return FractionPeteW(num + arg * denom, denom);
}

FractionPeteW FractionPeteW::operator-(const int& arg) {

	return FractionPeteW(denom * arg - num, denom);
}

FractionPeteW FractionPeteW::operator*(const int& arg) {

	return FractionPeteW(num * arg, denom);
}

FractionPeteW FractionPeteW::operator/(const int& arg) {

	return FractionPeteW(denom * arg, num);
}

FractionPeteW& FractionPeteW::operator+=(const int &arg) {
	(*this).num = (*this).num + (*this).denom * arg;
	reduce();
	return *this;
}

FractionPeteW& FractionPeteW::operator-=(const int &arg) {
	(*this).num = (*this).num - arg * (*this).denom;
	reduce();
	return *this;
}

FractionPeteW& FractionPeteW::operator*=(const int &arg) {
	(*this).num = (*this).num + (*this).denom * arg;
	reduce();
	return *this;
}

FractionPeteW& FractionPeteW::operator/=(const int &arg) {
	(*this).denom = (*this).denom * arg;
	reduce();
	return *this;
}

FractionPeteW& FractionPeteW::operator++() {
	(*this).num += 1;
	return *this;
}

FractionPeteW& FractionPeteW::operator--() {
	(*this).num -= 1;
	return *this;
}

FractionPeteW FractionPeteW::operator++(int arg) {
	int oldNum, oldDenom;
	oldNum = num;
	oldDenom = denom;
	++(*this);
	reduce();
	return FractionPeteW(oldNum, oldDenom);
}

FractionPeteW FractionPeteW::operator--(int arg) {
	int oldNum, oldDenom;
	oldNum = num;
	oldDenom = denom;
	--(*this);
	reduce();
	return FractionPeteW(oldNum, oldDenom);
}

bool FractionPeteW::operator==(const FractionPeteW& arg) {
	if (num == arg.num && denom == arg.denom) {
		return true;
	} else {
		return false;
	}
}

bool FractionPeteW::operator==(const int& arg) {
	if (denom == 1 && num == arg) {
		return true;
	} else {
		return false;
	}
}

bool FractionPeteW::operator<(const FractionPeteW& arg) {
	if (num * arg.denom < denom * arg.num) {
		return true;
	} else {
		return false;
	}
}

bool FractionPeteW::operator<(const int& arg) {
	if (num < arg * denom) {
		return true;
	} else {
		return false;
	}
}

bool FractionPeteW::operator>(const FractionPeteW& arg) {
	if (num * arg.denom > denom * arg.num) {
		return true;
	} else {
		return false;
	}
}

bool FractionPeteW::operator>(const int& arg) {
	if (num > arg * denom) {
		return true;
	} else {
		return false;
	}
}

bool FractionPeteW::operator<=(const FractionPeteW& arg) {
	if (num * arg.denom <= denom * arg.num) {
		return true;
	} else {
		return false;
	}
}

bool FractionPeteW::operator<=(const int& arg) {
	if (num <= arg * denom) {
		return true;
	} else {
		return false;
	}
}

bool FractionPeteW::operator>=(const FractionPeteW& arg) {
	if (num * arg.denom >= denom * arg.num) {
		return true;
	} else {
		return false;
	}
}

bool FractionPeteW::operator>=(const int& arg) {
	if (num >= arg * denom) {
		return true;
	} else {
		return false;
	}
}

// Friend overloads
ostream& operator<<(ostream& os, const FractionPeteW& f) {
	os << f.num << "/" << f.denom;
	return os;
}

FractionPeteW operator+(const int& left,
	const FractionPeteW& right) {

	return FractionPeteW(
		left * right.denom + right.num, right.denom);
}

FractionPeteW operator*(const int& left,
	const FractionPeteW& right) {

	return FractionPeteW(
		left * right.num, right.denom);
}

FractionPeteW operator/(const int& left,
	const FractionPeteW& right) {

	return FractionPeteW(left * right.denom, right.num);
}

bool operator<(const int& left, const FractionPeteW& right) {
	if (left * right.denom < right.num) {
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

bool operator<=(const int& left, const FractionPeteW& right) {
	if (left * right.denom <= right.num) {
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

bool operator==(const int& left, const FractionPeteW& right) {
	if (right.denom == 1 && left == right.num) {
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

