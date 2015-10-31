/**
  * Program Name: fractionPeteW.h
  * Discussion:   Declaration File --
  *                 FractionPeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/11/06
  */

#pragma once

#ifndef FRACTIONPETEW_H
#define FRACTIONPETEW_H

#include <iostream>

class FractionPeteW {

	public:
	FractionPeteW(); // default constructor
	FractionPeteW(int); // convert constructor
	FractionPeteW(const FractionPeteW&); // copy constructor
	FractionPeteW(int, int);

	~FractionPeteW();

	int getNum(void) const; // Return numerator
	void setNum(int); // Set numerator

	int getDenom(void) const; // Return denominator
	void setDenom(int);

	void print(void); // Display fraction

	void add(FractionPeteW&, FractionPeteW&);
	void add(const FractionPeteW&);
	void subtract(FractionPeteW&, FractionPeteW&);
	void subtract(const FractionPeteW&); // subtract ^^
	void multiply(FractionPeteW&, FractionPeteW&);
	void multiply(const FractionPeteW&);
	void divide(FractionPeteW&, FractionPeteW&);
	void divide(const FractionPeteW&);

	FractionPeteW& operator=(const FractionPeteW&);
	FractionPeteW operator+(FractionPeteW&);
	FractionPeteW operator-(FractionPeteW&);
	FractionPeteW operator*(FractionPeteW&);
	FractionPeteW operator/(FractionPeteW&);

	friend std::ostream& operator<<(std::ostream& os, const FractionPeteW& f) {
		os << f.getNum() << "/" << f.getDenom();
		return os;
	}
	friend FractionPeteW operator+(const int& left, const FractionPeteW& right) {
		return FractionPeteW(left * right.denom + right.num, right.denom);
	}

	private:
	int num;
	int denom;
	void reduce(void); // Helper function to reduce fraction

};




#endif

