/*
* Program name: CISFall2015Driver.cpp
*/

#include <iostream>
#include "fraction.h"

using namespace std;

int main() {/*
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

	cout << "Operator testing, let's add 1/2 and 3/4" << endl;

	Fraction half;
	half.setNum(1);
	half.setDenom(2);

	Fraction twothird;
	twothird.setNum(3);
	twothird.setDenom(4);

	Fraction result = half + twothird;

	cout << "Result: " << result.getNum() << "/" << result.getDenom();*/

	cout << "Operator testing: frac 1 starts as 1/2, frac2 starts as 3/4. frac3 = frac1 + frac2? ";

	Fraction frac1 = Fraction(1, 2);
	Fraction frac2 = Fraction(3, 4);
	Fraction frac3 = frac1 + frac2;

	cout << "Frac1: " << frac1.getNum() << "/" << frac1.getDenom() << endl;
	cout << "Frac2: " << frac2.getNum() << "/" << frac2.getDenom() << endl;
	cout << "Frac3: " << frac3.getNum() << "/" << frac3.getDenom() << endl;
	return 0;
}