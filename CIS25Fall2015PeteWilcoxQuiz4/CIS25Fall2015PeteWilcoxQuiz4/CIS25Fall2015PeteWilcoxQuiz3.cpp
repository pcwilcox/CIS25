/**
  * Program Name: CIS25Fall2015PeteWilcoxQuiz3.cpp
  * Author:       Pete Wilcox
  * Date:         2015/11/12
  */

#include <iostream>
using namespace std;

class B {
	public:

	B() {
		value = 0;
	}

	B(int arg) {
		value = arg;
	}

	int getValue() {
		return value;
	}
	

	void setValue(int arg) {
		value = arg;
	}

	~B() {
	}

	private:
	int value;
};

class D : public B {
	public:
	D() {
		data = 0;
	}

	D(int arg) : data(arg) {

	}

	D(int v, int a) : B(v) {
		data = a;

		setValue(data * data);
	}

	~D() {
	}


	private:
	int data;
};

int main() {
	B b1;

	D d2;

	D d3(5);

	D d4(6, 9);

	cout << "d4::B::value ..> " << d4.getValue() << endl;

	return 0;
}

/* PROGRAM OUTPUT:

d4::B::value ..> 81

*/
