/**
* Program name: fraction.h
*/

#pragma once

#ifndef FRACTION_H
#define FRACTION_H


class Fraction {
	public:
	Fraction(); // default constructor
	Fraction(int); // convert constructor
	Fraction(const Fraction&); // copy constructor

	int getNum(void); // Return numerator
	void setNum(int); // Set numerator

	int getDenom(void); // Return denominator
	void setDenom(int);

	void print(void); // Display fraction

	private:
	int num;
	int denom;
};

#endif

