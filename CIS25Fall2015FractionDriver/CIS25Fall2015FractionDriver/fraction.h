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
	Fraction(int, int, bool);

	int getNum(void); // Return numerator
	void setNum(int); // Set numerator

	int getDenom(void); // Return denominator
	void setDenom(int);

	void setPositive(bool); // set true for positive
	bool getPositive(void); // return true if positive
	char printPositive(void); // return - if negative

	void reduce(void); // Helper function to reduce fraction

	void print(void); // Display fraction

	private:
	int num;
	int denom;
	bool isPositive;
};

#endif

