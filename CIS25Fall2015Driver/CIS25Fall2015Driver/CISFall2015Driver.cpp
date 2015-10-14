/*
 * Program name: CISFall2015Driver.cpp
 */

#include <iostream>
#include "fraction.h"

using namespace std;

int main() {
	Fraction fr1; //fr1 is built by default constructor

	Fraction fr2(5); //fr1 is built by convert constructor

	Fraction fr3(fr2); //Fr3 is built by copy constructor

	cout << "Fraction 1: ";
	fr1.print();
	cout << endl << "Fraction 2: ";
	fr2.print();
	cout << endl << "Fraction 3: ";
	fr3.print();
	cout << endl;



	return 0;
}