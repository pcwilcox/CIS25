#include "fraction.h"
#include <iostream>

using namespace std;



Fraction::Fraction() : num(0), denom(1), isPositive(true) {
}

Fraction::Fraction(int input) : num(input), denom(1), isPositive(true) {
}

Fraction::Fraction(const Fraction& input) : num(input.num), denom(input.denom), isPositive(input.isPositive) {
}

Fraction::Fraction(int inputNum, int inputDenom, bool inputSign) {
	num = inputNum;
	denom = inputDenom;
	isPositive = inputSign;
}

Fraction::~Fraction() {
	// idk do stuff
	cout << "\nCalling ~Fraction()";
}

int Fraction::getNum(void) {
	return num;
}

void Fraction::setNum(int input) {
	if (input < 0) {
		num = -input;
		isPositive = false;
	} else {
		num = input;
		isPositive = true;
	}
	reduce();
}

int Fraction::getDenom(void) {
	return denom;
}

void Fraction::setDenom(int input) {
	if (input < 0) {
		denom = -input;
		isPositive = false;
	} else if (input > 0) {
		denom = input;
		isPositive = true;
	} else {
		// denominator can't be 0, put an error message here
	}
	reduce();
}

void Fraction::print() {
	cout << printPositive() << num << "/" << denom;
}

void Fraction::setPositive(bool input) {
	isPositive = input;
}

bool Fraction::getPositive() {
	return isPositive;
}

char Fraction::printPositive() {
	if (isPositive == false) {
		return '-';
	} else {
		return '\0';
	}
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
}

void Fraction::add(const Fraction& arg) {
	int inputNum = arg.num;
	int inputDenom = arg.denom;
	bool inputSign = arg.isPositive;
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

	cout << "\nFinal num = " << num;
	cout << "\nFinal denom = " << denom;
}

void Fraction::subtract(const Fraction& arg) {
	int inputNum = arg.num;
	int inputDenom = arg.denom;
	bool inputSign = arg.isPositive;
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

	cout << "\nFinal num = " << num;
	cout << "\nFinal denom = " << denom;
}

void Fraction::multiply(const Fraction& arg) {
	num *= arg.num;
	denom *= arg.denom;
	reduce();
}

void Fraction::divide(const Fraction& arg) {
	num *= arg.denom;
	denom *= arg.num;
}

Fraction& Fraction::operator=(const Fraction& arg) {
	num = arg.num;
	denom = arg.denom;
	isPositive = arg.isPositive;

	return *this;
}

Fraction& Fraction::operator+(const Fraction& arg) {
	add(arg);
	return *this;
}

Fraction& Fraction::operator-(const Fraction& arg) {
	subtract(arg);
	return *this;
}

Fraction& Fraction::operator*(const Fraction& arg) {
	multiply(arg);
	return *this;
}

Fraction& Fraction::operator/(const Fraction& arg) {
	divide(arg);
	return *this;
}