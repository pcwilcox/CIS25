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
	// Default constructor
	FractionPeteW(); 

	// Convert constructor
	FractionPeteW(int); 

	// Copy constructor
	FractionPeteW(const FractionPeteW&); 

	// Explicit constructor
	FractionPeteW(int, int);

	~FractionPeteW();

	// Getters
	int getNum(void) const;
	int getDenom(void) const;

	// Setters	
	void setNum(int); 
	void setDenom(int);
	void setBoth(int, int);

	// Print
	void print(void); 

	// Member arithmetic functions
	void add(FractionPeteW&, FractionPeteW&);
	void add(const FractionPeteW&);

	void subtract(FractionPeteW&, FractionPeteW&);
	void subtract(const FractionPeteW&); 

	void multiply(FractionPeteW&, FractionPeteW&);
	void multiply(const FractionPeteW&);

	void divide(FractionPeteW&, FractionPeteW&);
	void divide(const FractionPeteW&);

	// Operator overloads
	FractionPeteW& operator=(const FractionPeteW&);
	FractionPeteW operator+(FractionPeteW&);
	FractionPeteW operator-(FractionPeteW&);
	FractionPeteW operator*(FractionPeteW&);
	FractionPeteW operator/(FractionPeteW&);

	// Friend overloads
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

	// Helper function to reduce fraction
	void reduce(void); 

};

#endif

