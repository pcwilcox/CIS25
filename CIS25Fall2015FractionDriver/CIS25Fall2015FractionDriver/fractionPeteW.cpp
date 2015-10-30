/**
  * Program Name: fractionPeteW.cpp
  * Discussion:   Lab #5
  * Written by:   Pete Wilcox
  * Date:         2015/11/06
  */

#include "fractionPeteW.h"
#include <iostream>

using namespace std;



Fraction::Fraction() : num(0), denom(1) {
	cout << "\nCalling Fraction()";
}

Fraction::Fraction(int input) : num(input), denom(1) {
	cout << "\nCalling Fraction()";
}

Fraction::Fraction(const Fraction& input) : num(input.num), denom(input.denom) {
	cout << "\nCalling Fraction()";
}

Fraction::Fraction(int inputNum, int inputDenom) : num(inputNum), denom(inputDenom) {
	cout << "\nCalling Fraction()";
}

Fraction::~Fraction() {
	cout << "\nCalling ~Fraction()\n";
}

int Fraction::getNum() const {
	return num;
}

void Fraction::setNum(int input) {
	num = input;
	reduce();
}

int Fraction::getDenom() const {
	return denom;
}

void Fraction::setDenom(int input) {
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

void Fraction::print() {
	cout << num << "/" << denom;
}

void Fraction::reduce() {
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

void Fraction::add(Fraction& left, Fraction& right) {
	(*this) = left + right;
	reduce();
}

void Fraction::add(const Fraction& arg) {
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

void Fraction::subtract(Fraction& left, Fraction& right) {
	(*this) = left - right;
	reduce();
}

void Fraction::subtract(const Fraction& arg) {
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

void Fraction::multiply(Fraction& left, Fraction& right) {
	(*this) = left * right;
	reduce();
}

void Fraction::multiply(const Fraction& arg) {
	num *= arg.num;
	denom *= arg.denom;
	reduce();
}

void Fraction::divide(Fraction& left, Fraction& right) {
	(*this) = left / right;
	reduce();
}

void Fraction::divide(const Fraction& arg) {
	num *= arg.denom;
	denom *= arg.num;
	reduce();
}

Fraction& Fraction::operator=(const Fraction& arg) {
	num = arg.num;
	denom = arg.denom;
	return *this;
}

Fraction Fraction::operator+(Fraction& arg) {
	return Fraction((*this).num * arg.denom + ((*this).denom * arg.num), (*this).denom * arg.denom);
}

Fraction Fraction::operator-(Fraction& arg) {
	return Fraction((*this).num * arg.denom - ((*this).denom * arg.num), (*this).denom * arg.denom);
}

Fraction Fraction::operator*(Fraction& arg) {
	return Fraction((*this).num * arg.num, (*this).denom * arg.denom);
}

Fraction Fraction::operator/(Fraction& arg) {
	return Fraction((*this).num * arg.denom, (*this).denom * arg.num);
}

