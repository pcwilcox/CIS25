/**
  * Program Name: fractionPeteW.cpp
  * Discussion:   Lab #5
  * Written by:   Pete Wilcox
  * Date:         2015/11/06
  */

#include "fractionPeteW.h"
#include <iostream>

using namespace std;



FractionPeteW::FractionPeteW() : num(0), denom(1) {
	cout << "\nCalling Fraction()";
}

FractionPeteW::FractionPeteW(int input) : num(input), denom(1) {
	cout << "\nCalling Fraction()";
}

FractionPeteW::FractionPeteW(const FractionPeteW& input) : num(input.num), denom(input.denom) {
	cout << "\nCalling Fraction()";
}

FractionPeteW::FractionPeteW(int inputNum, int inputDenom) : num(inputNum), denom(inputDenom) {
	cout << "\nCalling Fraction()";
}

FractionPeteW::~FractionPeteW() {
	cout << "\nCalling ~Fraction()\n";
}

int FractionPeteW::getNum() const {
	return num;
}

void FractionPeteW::setNum(int input) {
	num = input;
	reduce();
}

int FractionPeteW::getDenom() const {
	return denom;
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

void FractionPeteW::print() {
	cout << num << "/" << denom;
}

void FractionPeteW::reduce() {
	bool finished = false;
	int n = 2;
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

void FractionPeteW::add(FractionPeteW& left, FractionPeteW& right) {
	(*this) = left + right;
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

void FractionPeteW::subtract(FractionPeteW& left, FractionPeteW& right) {
	(*this) = left - right;
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

void FractionPeteW::multiply(FractionPeteW& left, FractionPeteW& right) {
	(*this) = left * right;
	reduce();
}

void FractionPeteW::multiply(const FractionPeteW& arg) {
	num *= arg.num;
	denom *= arg.denom;
	reduce();
}

void FractionPeteW::divide(FractionPeteW& left, FractionPeteW& right) {
	(*this) = left / right;
	reduce();
}

void FractionPeteW::divide(const FractionPeteW& arg) {
	num *= arg.denom;
	denom *= arg.num;
	reduce();
}

FractionPeteW& FractionPeteW::operator=(const FractionPeteW& arg) {
	num = arg.num;
	denom = arg.denom;
	return *this;
}

FractionPeteW FractionPeteW::operator+(FractionPeteW& arg) {
	return FractionPeteW((*this).num * arg.denom + ((*this).denom * arg.num), (*this).denom * arg.denom);
}

FractionPeteW FractionPeteW::operator-(FractionPeteW& arg) {
	return FractionPeteW((*this).num * arg.denom - ((*this).denom * arg.num), (*this).denom * arg.denom);
}

FractionPeteW FractionPeteW::operator*(FractionPeteW& arg) {
	return FractionPeteW((*this).num * arg.num, (*this).denom * arg.denom);
}

FractionPeteW FractionPeteW::operator/(FractionPeteW& arg) {
	return FractionPeteW((*this).num * arg.denom, (*this).denom * arg.num);
}

