/**
  * Program Name: fractionPeteW.h
  * Discussion:   Lab #5
  * Written by:   Pete Wilcox
  * Date:         2015/11/06
  */

#pragma once

#ifndef FRACTIONPETEW_H
#define FRACTIONPETEW_H


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

	void add(const Fraction&); // Add arg fraction to this fraction
	void subtract(const Fraction&); // subtract ^^
	void multiply(const Fraction&);
	void divide(const Fraction&);

	Fraction& operator=(const Fraction&);
	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&);
	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction&);

	//what the actual fuck

	private:
	int num;
	int denom;
	void reduce(void); // Helper function to reduce fraction
	friend ostream& operator<<(ostream&, const Fraction&);

};

ostream& operator<<(ostream& os, const Fraction& f) {
	os << f.getNum() << "/" << f.getDenom();
	return os;
}

#endif

