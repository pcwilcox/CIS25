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
	cout << "Testing new fraction stuff: ";

	int inputNum;
	int inputDenom;
	char inputSign;
	bool inputPositive;
	
	cout << endl << "Input numerator: ";
	cin >> inputNum;
	cout << "Input denominator: ";
	cin >> inputDenom;
	cout << "Input sign: ";
	cin >> inputSign;

	Fraction frTest;
	
	if (inputSign == '+') {
		inputPositive = true;
	} else {
		inputPositive = false;
	}

	frTest.setNum(inputNum);
	frTest.setDenom(inputDenom);
	frTest.setPositive(inputPositive);

	cout << endl;

	frTest.print();
	
	cout << endl;
	Fraction frAddTest;
	Fraction frAddTest2;

	cout << "Add test. Enter a fraction num: ";
	cin >> inputNum;

	cout << "Denom: ";
	cin >> inputDenom;

	frAddTest.setNum(inputNum);
	frAddTest.setDenom(inputDenom);

	cout << "Enter second fraction num: ";
	cin >> inputNum;

	cout << "Denom: ";
	cin >> inputDenom;
	
	frAddTest2.setNum(inputNum);
	frAddTest2.setDenom(inputDenom);

	frAddTest.add(frAddTest2);

	cout << endl;

	return 0;
}