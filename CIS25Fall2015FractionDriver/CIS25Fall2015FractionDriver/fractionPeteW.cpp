/* Program Name: fractionPeteW.h
 * Written By:   Pete Wilcox
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

Fraction::Fraction(int inputNum, int inputDenom) {
	cout << "\nCalling Fraction()";
	num = inputNum;
	denom = inputDenom;
}

Fraction::~Fraction() {
	cout << "\nCalling ~Fraction()\n";
}

int Fraction::getNum(void) {
	return num;
}

void Fraction::setNum(int input) {
	num = input;
	reduce();
}

int Fraction::getDenom(void) {
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

void Fraction::multiply(const Fraction& arg) {
	num *= arg.num;
	denom *= arg.denom;
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

Fraction Fraction::operator+(const Fraction& arg) {
	Fraction foo = *this;
	foo.add(arg);
	return foo;
}

Fraction Fraction::operator-(const Fraction& arg) {
	Fraction foo = *this;
	foo.subtract(arg);
	return foo;
}

Fraction Fraction::operator*(const Fraction& arg) {
	Fraction foo = *this;
	foo.multiply(arg);
	return foo;
}

Fraction Fraction::operator/(const Fraction& arg) {
	Fraction foo = *this;
	foo.divide(arg);
	return foo;
}