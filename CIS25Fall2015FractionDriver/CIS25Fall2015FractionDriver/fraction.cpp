#include "fraction.h"
#include <iostream>

using namespace std;



Fraction::Fraction() : num(0), denom(1), isPositive(true) {
	cout << "\nCalling Fraction()";
}

Fraction::Fraction(int input) : num(input), denom(1), isPositive(true) {
	cout << "\nCalling Fraction()";
}

Fraction::Fraction(const Fraction& input) : num(input.num), denom(input.denom), isPositive(input.isPositive) {
	cout << "\nCalling Fraction()";
}

Fraction::Fraction(int inputNum, int inputDenom) : num(inputNum), denom(inputDenom), isPositive(true) {
	cout << "\nCalling Fraction()";
}

Fraction::Fraction(int inputNum, int inputDenom, bool inputSign) {
	cout << "\nCalling Fraction()";
	num = inputNum;
	denom = inputDenom;
	isPositive = inputSign;
}

Fraction::~Fraction() {
	cout << "\nCalling ~Fraction()\n";
}

int Fraction::getNum(void) {
	return num;
}

void Fraction::setNum(int input) {
	if (input < 0) {
		num = -input;
		isPositive = -isPositive;
	} else {
		num = input;
	}
	reduce();
}

int Fraction::getDenom(void) {
	return denom;
}

void Fraction::setDenom(int input) {
	if (input < 0) {
		denom = -input;
		isPositive = -isPositive;
	} else if (input > 0) {
		denom = input;
	} else {
		// denominator can't be 0, put an error message here
	}
	reduce();
}

bool Fraction::getPositive() {
	return isPositive;
}

void Fraction::setPositive(bool input) {
	isPositive = input;
}

char Fraction::printPositive() {
	if (isPositive == false) {
		return '-';
	} else {
		return '\0';
	}
}

void Fraction::print() {
	cout << printPositive() << num << "/" << denom;
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

//	cout << "\nFinal num = " << num;
//	cout << "\nFinal denom = " << denom;
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

//	cout << "\nFinal num = " << num;
//	cout << "\nFinal denom = " << denom;
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