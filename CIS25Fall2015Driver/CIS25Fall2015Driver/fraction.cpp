#include "fraction.h"
#include <iostream>

using namespace std;



Fraction::Fraction() : num(0), denom(1) {
}

Fraction::Fraction(int input) : num(input), denom(1) {
}

Fraction::Fraction(const Fraction& input) : num(input.num), denom(input.denom) {
}

int Fraction::getNum(void) {
	return num;
}

void Fraction::setNum(int input) {
	num = input;
}

int Fraction::getDenom(void) {
	return denom;
}

void Fraction::setDenom(int input) {
	denom = input;
}

void Fraction::print() {
	cout << num << "/" << denom;
}