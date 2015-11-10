/**
  * Program Name: CIS25Fall2015PeteWilcoxLab5Ex2.cpp
  * Discussion:   Lab #5 Exercise #2
  * Written by:   Pete Wilcox
  * Date:         2015/11/06
  */

#include <iostream>
#include "fractionPeteW.h"

using namespace std;

void displayHeader(void);
void displayMenu(void);

int arrangeMultiArraysPeteWilcox(FractionPeteW**, int);

int main() {
	int menuChoice;
	int numArrays = 0;
	int numSwaps;
	int num;
	int newArraySize;
	int i, j;

	FractionPeteW** fracArray = nullptr;

	displayHeader();

	do {
		displayMenu();

		cin >> menuChoice;

		switch (menuChoice) {
		case 1:

			cout << "\nSetting up data before calling "
				"ArrangeMultiArraysPeteWilcox() --\n\nHow many "
				"arrays of fractions? ";
			cin >> numArrays;

			fracArray = new FractionPeteW*[numArrays];

			for (i = 0; i < numArrays; i++) {
				cout << "\n\nCreating array index # " << i;

				cout << "\n\n  How many value(s)? ";
				cin >> newArraySize;

				*(fracArray + i) = new 
					FractionPeteW[newArraySize + 1];
				(*(fracArray + i))->setNum(newArraySize);

				for (j = 1; j < newArraySize + 1; j++) {
					cout << "\n    Enter the numerator for "
						"element at index " << j << " : ";
					cin >> num;

					((*(fracArray + i)) + j)->setNum(num);
				}

				cout << "\n\nFor array index #" << i;

				for (j = 0; j < newArraySize + 1; j++) {
					cout << "\n  Element index #" << j << ": " 
						<< *((*(fracArray + i)) + j);
				}

			}
			cout << "\n\nConfirming before working through with"
				" swapping --\n\nThere is/are " << numArrays <<
				" array(s).";

			for (i = 0; i < numArrays; i++) {
				cout << "\n\nThe current array #" << (i + 1) <<
					" has " << (*(fracArray + i))->getNum() <<
					" element(s).\n..";

				for (j = 0; 
					j < (*(fracArray + i))->getNum() + 1; j++) {

					cout << "Element index #" << j << " : " <<
						*((*(fracArray + i)) + j) << "\n  ";
				}

			}

			cout << "\nCalling "
				"arrangeMultiArraysPeteWilcox() --\n";
			numSwaps =
				arrangeMultiArraysPeteWilcox(
					fracArray, numArrays);

			cout << "\n\nDisplaying outside of "
				"arrangeMultiArraysPeteWilcox() -\n";

			for (i = 0; i < numArrays; i++) {
				cout << "\n\nThe updated array #" << (i + 1) << 
					" has " << (*(fracArray + i))->getNum() <<
					" element(s).";

				for (j = 0; 
					j < (*(fracArray + i))->getNum() + 1; j++) {

					cout << "\n  Element index #" << j << " : "
						<< *((*(fracArray + i)) + j);
				}
			}

			if (numSwaps > 0) {
				cout << "\n\nThere is/are " << numSwaps <<
					" swap(s).";
			}

			for (i = 0; i < numArrays; i++) {
				delete[] (*(fracArray + i));
			}

			delete[] fracArray;

			break;
		case 2:
			cout << "\nHaving fun..." << endl;
			break;

		default:
			cout << "\nWRONG OPTION!\n";
		}


	} while (menuChoice != 2);



	return 0;
}

void displayHeader() {
	cout << "CIS 25 - C++ Programming\nLaney College"
		"\nPete Wilcox \n\nAssignment Information --"
		"\n  Assignment Number: Lab 5,"
		"\n                     Exercise #2"
		"\n  Written by: Pete Wilcox"
		"\n  Due Date: 2015/11/06\n\n";
}

void displayMenu() {
	cout << "\n\n**********************************************"
		"\n*                Fraction Arrays             *"
		"\n* (1) Calling arrangeMultiArraysPeteWilcox() *"
		"\n* (2) Quit                                   *"
		"\n**********************************************"
		"\nSelect an option (1 or 2): ";
}

int arrangeMultiArraysPeteWilcox(FractionPeteW** fracArray, 
	int size) {

	int numSwaps = 0;
	FractionPeteW temp;
	bool swapped = false;
	int i, k, j;

	cout << "\n  Displaying inside "
		"arrangeMultiArraysPeteWilcox()-";

	for (i = 1; i < (*(fracArray + 0) + 0)->getNum() + 1; i++) {
		// For each value in array #1

		if ((*(fracArray + 0) + i)->getNum() % 2 == 0) {
			// If it's even
			j = 1;
			while ((j < size) && (!swapped)) {
				// Iterate through each other array

				k = 1;
				while 
					((k < (*(fracArray + j) + 0)->getNum() + 1)
					&& (!swapped)) {


					if ((*(fracArray + j) + k)->getNum() 
						% 2 != 0) {
						
						// When an odd value is found
						cout << "\n    Array #1 value "
							<< *(*(fracArray + 0) + i) 
							<< " is swapped with Array #" 
							<< (j + 1) << " value " 
							<< (*(*(fracArray + j) + k));

						// Swap it
						temp = *(*(fracArray + 0) + i);
						*(*(fracArray + 0) + i) = 
								*(*(fracArray + j) + k);
						*(*(fracArray + j) + k) = temp;

						numSwaps++;
						swapped = true;
					}
					k++;
				}
				// If we've looked through every value
				if (k == (*(fracArray + j) + 0)->getNum() + 1) {
					// Move to the next array
					j++;
				}
			}
			swapped = false;
		}
	}

	return numSwaps;
}

/* PROGRAM OUTPUT:
CIS 25 - C++ Programming
Laney College
Pete Wilcox

Assignment Information --
  Assignment Number: Lab 5,
                     Exercise #2
  Written by: Pete Wilcox
  Due Date: 2015/11/06



**********************************************
*                Fraction Arrays             *
* (1) Calling arrangeMultiArraysPeteWilcox() *
* (2) Quit                                   *
**********************************************
Select an option (1 or 2): 4

WRONG OPTION!


**********************************************
*                Fraction Arrays             *
* (1) Calling arrangeMultiArraysPeteWilcox() *
* (2) Quit                                   *
**********************************************
Select an option (1 or 2): 1

Setting up data before calling ArrangeMultiArraysPeteWilcox() --

How many arrays of fractions? 3


Creating array index # 0

  How many value(s)? 6

Calling Fraction()
Calling Fraction()
Calling Fraction()
Calling Fraction()
Calling Fraction()
Calling Fraction()
Calling Fraction()
    Enter the numerator for element at index 1 : 1

    Enter the numerator for element at index 2 : -23

    Enter the numerator for element at index 3 : 18

    Enter the numerator for element at index 4 : 27

    Enter the numerator for element at index 5 : -36

    Enter the numerator for element at index 6 : 45


For array index #0
  Element index #0: 6/1
  Element index #1: 1/1
  Element index #2: -23/1
  Element index #3: 18/1
  Element index #4: 27/1
  Element index #5: -36/1
  Element index #6: 45/1

Creating array index # 1

  How many value(s)? 3

Calling Fraction()
Calling Fraction()
Calling Fraction()
Calling Fraction()
    Enter the numerator for element at index 1 : 4

    Enter the numerator for element at index 2 : -17

    Enter the numerator for element at index 3 : 8


For array index #1
  Element index #0: 3/1
  Element index #1: 4/1
  Element index #2: -17/1
  Element index #3: 8/1

Creating array index # 2

  How many value(s)? 2

Calling Fraction()
Calling Fraction()
Calling Fraction()
    Enter the numerator for element at index 1 : -1

    Enter the numerator for element at index 2 : -3


For array index #2
  Element index #0: 2/1
  Element index #1: -1/1
  Element index #2: -3/1

Confirming before working through with swapping --

There is/are 3 array(s).

The current array #1 has 6 element(s).
..Element index #0 : 6/1
  Element index #1 : 1/1
  Element index #2 : -23/1
  Element index #3 : 18/1
  Element index #4 : 27/1
  Element index #5 : -36/1
  Element index #6 : 45/1


The current array #2 has 3 element(s).
..Element index #0 : 3/1
  Element index #1 : 4/1
  Element index #2 : -17/1
  Element index #3 : 8/1


The current array #3 has 2 element(s).
..Element index #0 : 2/1
  Element index #1 : -1/1
  Element index #2 : -3/1

Calling arrangeMultiArraysPeteWilcox() --

Calling Fraction()
  Displaying inside arrangeMultiArraysPeteWilcox()-
    Array #1 value 18/1 is swapped with Array #2 value -17/1
    Array #1 value -36/1 is swapped with Array #3 value -1/1
Calling ~Fraction() on -36/1

Displaying outside of arrangeMultiArraysPeteWilcox() -


The updated array #1 has 6 element(s).
  Element index #0 : 6/1
  Element index #1 : 1/1
  Element index #2 : -23/1
  Element index #3 : -17/1
  Element index #4 : 27/1
  Element index #5 : -1/1
  Element index #6 : 45/1

The updated array #2 has 3 element(s).
  Element index #0 : 3/1
  Element index #1 : 4/1
  Element index #2 : 18/1
  Element index #3 : 8/1

The updated array #3 has 2 element(s).
  Element index #0 : 2/1
  Element index #1 : -36/1
  Element index #2 : -3/1

There is/are 2 swap(s).
Calling ~Fraction() on 45/1
Calling ~Fraction() on -1/1
Calling ~Fraction() on 27/1
Calling ~Fraction() on -17/1
Calling ~Fraction() on -23/1
Calling ~Fraction() on 1/1
Calling ~Fraction() on 6/1
Calling ~Fraction() on 8/1
Calling ~Fraction() on 18/1
Calling ~Fraction() on 4/1
Calling ~Fraction() on 3/1
Calling ~Fraction() on -3/1
Calling ~Fraction() on -36/1
Calling ~Fraction() on 2/1

**********************************************
*                Fraction Arrays             *
* (1) Calling arrangeMultiArraysPeteWilcox() *
* (2) Quit                                   *
**********************************************
Select an option (1 or 2): 2

Having fun...
*/

/* COMMENTS:
2015/11/10:
This was a very frustrating project to write. The output was not
specified. There was no additional advancement in the logic
needed to complete the assignment, we just copied the logic we
used for Lab #4 and adjusted it to use pointers to objects. In
the end this resulted in a truly obscene amount of debugging
time spent for an extremely small amount of educational value.
*/