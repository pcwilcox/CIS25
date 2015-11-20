/**
  * Program name: cis25Fall2015PeteWilcoxInheritanceQuiz31.cpp
  * Author:       Pete Wilcox
  * Date:         2015/11/19
  */

#include <iostream>
using namespace std;

class BPeteWilcox {
	public:
	BPeteWilcox() {
		baseValue = 1;
	}

	BPeteWilcox(int v) : baseValue(v) {
	}

	int getBaseValue() {
		return baseValue;
	}

	protected:
	int baseValue;
};

class DPeteWilcox : public BPeteWilcox {
	public:
	DPeteWilcox() {
		derivedValue = 1;
	}

	DPeteWilcox(int d, int v) : BPeteWilcox(v), derivedValue(d) {

	}

	int getDerivedValue() {
		return derivedValue;
	}

	private:
	int derivedValue;
};

int* extractCommonDigit(DPeteWilcox*, int);

int main() {
	DPeteWilcox* dPtr1 = new DPeteWilcox[2] {DPeteWilcox(12, 25), DPeteWilcox(3, 4)};

	DPeteWilcox* dPtr2 = new DPeteWilcox[4] {DPeteWilcox(12, 25), DPeteWilcox(3, 4),
											 DPeteWilcox(123, 234), DPeteWilcox()};

	int* dPtr3 = nullptr;
	
	int size;
	int i;

	size = 2;
	dPtr3 = extractCommonDigit(dPtr1, size);

	cout << "\nThe common digit array:\n  ";
	for (i = 0; i < size + 1; i++) {
		cout << (*(dPtr3 + i)) << " ";
	}

	size = 4;
	dPtr3 = extractCommonDigit(dPtr2, size);


	cout << "\n\nThe common digit array:\n  ";
	for (i = 0; i < size + 1; i++) {
		cout << (*(dPtr3 + i)) << " ";
	}

	delete[] dPtr1;
	delete[] dPtr2;
	delete[] dPtr3;

	return 0;
}

int* extractCommonDigit(DPeteWilcox* dAry, int size) {
	int* dTmp = new int[size + 1];
	bool commonDigit[10] = {false};
	int commons = 0;
	int base;
	int derived;
	int search;
	int i, j;

	(*dTmp) = size + 1;

	for (i = 0; i < size; i++) {
		base = (dAry + i)->getBaseValue();
		do {
			search = base % 10;
			if (commonDigit[search] == false) {
				derived = (dAry + i)->getDerivedValue();
				do {

					if (search == derived % 10) {
						commonDigit[search] = true;
						commons++;
					}
					derived /= 10;
				} while (commonDigit[search] == false, derived > 0);
			}
			base /= 10;
		} while (base > 0);
		(*(dTmp + i + 1)) = commons;
		commons = 0;

		for (j = 0; j < 10; j++) {
			commonDigit[j] = false;
		}
	}

	return dTmp;
}

/* SAMPLE OUTPUT

The common digit array:
  3 1 0

The common digit array:
  5 1 0 2 1

*/

/* PROGRAM OUTPUT:

The common digit array:
  3 1 0

The common digit array:
  5 1 0 2 1

*/

