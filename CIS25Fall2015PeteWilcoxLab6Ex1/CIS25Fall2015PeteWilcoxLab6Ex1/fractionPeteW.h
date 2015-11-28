/**
  * Program Name: fractionPeteW.h
  * Discussion:   Declaration File --
  *                 FractionPeteW class
  * Written by:   Pete Wilcox
  * Date:         2015/12/01
  */

#pragma once

#ifndef FRACTIONPETEW_H
#define FRACTIONPETEW_H

#include <iostream>

using namespace std;

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
	int getNum  (void) const;
	int getDenom(void) const;

	// Setters	
	void setNum  (int);
	void setDenom(int);
	void setBoth (int, int);

	// Print
	void print(void);

	// Member arithmetic functions
	void add     (const FractionPeteW&, const FractionPeteW&);
	void subtract(const FractionPeteW&, const FractionPeteW&);
	void multiply(const FractionPeteW&, const FractionPeteW&);
	void divide  (const FractionPeteW&, const FractionPeteW&);

	void add     (const FractionPeteW&);
	void subtract(const FractionPeteW&);
	void multiply(const FractionPeteW&);
	void divide  (const FractionPeteW&);

	// Operator overloads
	FractionPeteW  operator-(void);
	FractionPeteW& operator=(const FractionPeteW&);
	FractionPeteW  operator+(const FractionPeteW&);
	FractionPeteW  operator-(const FractionPeteW&);
	FractionPeteW  operator*(const FractionPeteW&) const;
	FractionPeteW  operator/(const FractionPeteW&);
	FractionPeteW& operator+=(const FractionPeteW&);
	FractionPeteW& operator+=(const int&);
	FractionPeteW& operator-=(const FractionPeteW&);
	FractionPeteW& operator-=(const int&);
	FractionPeteW& operator*=(const FractionPeteW&);
	FractionPeteW& operator*=(const int&);
	FractionPeteW& operator/=(const FractionPeteW&);
	FractionPeteW& operator/=(const int&);
	bool operator==(const FractionPeteW&);
	bool operator<(const FractionPeteW&);
	bool operator>(const FractionPeteW&);
	bool operator<=(const FractionPeteW&);
	bool operator>=(const FractionPeteW&);

	// Friend overloads
	friend ostream& operator<<(ostream& os,
		const FractionPeteW& f);
	friend FractionPeteW operator+(const int&,
		const FractionPeteW&);
	friend FractionPeteW operator-(const FractionPeteW&,
		const int&);
	friend FractionPeteW operator*(const int&,
		const FractionPeteW&);
	friend FractionPeteW operator*(const FractionPeteW&,
		const int&);
	friend FractionPeteW operator/(const int&,
		const FractionPeteW&);
	friend FractionPeteW operator/(const FractionPeteW&,
		const int&);
	friend bool operator==(const int&, const FractionPeteW&);
	friend bool operator==(const FractionPeteW&, const int&);
	friend bool operator<(const int&, const FractionPeteW&);
	friend bool operator<(const FractionPeteW&, const int&);
	friend bool operator>(const int&, const FractionPeteW&);
	friend bool operator>(const FractionPeteW&, const int&);
	friend bool operator<=(const int&, const FractionPeteW&);
	friend bool operator<=(const FractionPeteW&, const int&);
	friend bool operator>=(const int&, const FractionPeteW&);
	friend bool operator>=(const FractionPeteW&, const int&);


	private:
	int num;
	int denom;

	// Helper function to reduce fractions
	void reduce(void);

};

#endif