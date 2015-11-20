/** Inheritance notes - in class **/
#include <iostream>
using namespace std;
class B {
	public:
	B() {
		value = 1;
	}
	B(int v) : value(v) {
	}

	~B() {

	}
	int getValue() {
		return value;
	}
	void setValue(int v) {
		value = v;
	}
	//private:
	protected:
	int value;
};
class D : public B {
	public:
	D() : B() {
		data = 1;
	}
	D(int a) : B(value) {
		data = a;
	}
	D(int v, int a) : B(v), data(a) {
	}
	~D() {
	}
	void updateData(int v, int a) {
		value = v;
		data = a;
	}
	int getData() {
		return data;
	}
	void setData(int a) {
		data = a;
		value = a;
	}

	private:
	int data;
};
class D1 : public B {
	public:
	D1() : B(), data(1) {
	}
	D1(int v, int a) : B(v), data(a) {
	}
	~D1() {
	}
	int getData() {
		return data;
	}
	private:
	int data;
};
class B1 {
	public:
	B1() : value(0) {
	}
	B1(int v) {
		value = v;
	}
	private:
	int value;
};
class D2 : public B1 {
	private:
	int data2;
};
int main() {
	B*bPtr1 = new B[5];
	B b1;
	D*dPtr2;
	D d2;
	D1 d1Obj3(4, 9);
	d1Obj3.getValue(); // if protected change to public
	D2 d2Obj4;
	//b1.value = 5; //cant access because value is protected
	//(*bPtr1).getValue(); *no good
	//bPtr1.getValue(); *no good
	bPtr1 = nullptr;
	//bPtr1->getValue(); *no good
	bPtr1 = &b1;
	//bPtr1 = &d2;
	dPtr2 = &d2;
	cout << dPtr2->getValue() << endl;
	cout << sizeof(b1) << "\n" << sizeof(B) << endl;
	cout << sizeof(D) << endl;

	return 0;
}