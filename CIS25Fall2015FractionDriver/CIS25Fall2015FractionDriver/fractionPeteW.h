/**
  * Program Name: fractionPeteW.h
  * Discussion:   Lab #5
  * Written by:   Pete Wilcox
  * Date:         2015/11/06
  */

#pragma once

#ifndef FRACTIONPETEW_H
#define FRACTIONPETEW_H

#include <iostream>

class Fraction {

	public:
	Fraction(); // default constructor
	Fraction(int); // convert constructor
	Fraction(const Fraction&); // copy constructor
	Fraction(int, int);

	~Fraction();

	int getNum(void) const; // Return numerator
	void setNum(int); // Set numerator

	int getDenom(void) const; // Return denominator
	void setDenom(int);

	void print(void); // Display fraction

	void add(Fraction&, Fraction&);
	void add(const Fraction&);
	void subtract(Fraction&, Fraction&);
	void subtract(const Fraction&); // subtract ^^
	void multiply(Fraction&, Fraction&);
	void multiply(const Fraction&);
	void divide(Fraction&, Fraction&);
	void divide(const Fraction&);

	Fraction& operator=(const Fraction&);
	Fraction operator+(Fraction&);
	Fraction operator-(Fraction&);
	Fraction operator*(Fraction&);
	Fraction operator/(Fraction&);

	friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
		os << f.getNum() << "/" << f.getDenom();
		return os;
	}
	friend Fraction operator+(const int& left, const Fraction& right) {
		return Fraction(left * right.denom + right.num, right.denom);
	}

	private:
	int num;
	int denom;
	void reduce(void); // Helper function to reduce fraction

};




#endif

