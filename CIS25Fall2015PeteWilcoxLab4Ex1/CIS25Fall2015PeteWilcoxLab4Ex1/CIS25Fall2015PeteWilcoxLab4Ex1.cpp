/**
* Program Name: cis25Fall2015PeteWilcoxLab4Ex1.cpp
* Discussion:   Lab #4 Exercise #1
* Written by:   Pete Wilcox
* Date:         2015/10/08
*/

#include <iostream>

using namespace std;

void displayHeader(void);
void displayMenu(void);
int arrangeMultipleArrayPeteWilcox(int**, int);
void getInput(void);
int* createArray(void);


int main() {

	displayHeader();
	displayMenu();

	return 0;
}

void displayHeader() {
	cout << "\nClass Information --"
		"\n  CIS 25 - C++ Programming"
		"\n  Laney College"
		"\n"
		"\nAssignment Information -- "
		"\n  Assignment Number:  Lab 04 - Exercise #1"
		"\n  Written by:         Pete Wilcox"
		"\n  Submitted Date:     2015/10/08"
		"\n";
	return;
}

void displayMenu() {
	int menuChoice = 0;

	do {
		cout << "\n"
			"\n************************************************"
			"\n*               MENU 04 -- Arrays              *"
			"\n* (1) Calling arrangeMultipleArrayPeteWilcox() *"
			"\n* (2) Quit                                     *"
			"\n************************************************"
			"\nSelect an option (1 or 2): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			getInput();
			break;
		case 2:
			cout << "\nHaving fun..." << endl;
			break;
		default:
			cout << "\nWRONG OPTION!\n";
		}
	} while (menuChoice != 2);

	return;
}

void getInput() {
	/* Takes user input to create specified arrays, then
	 * calls arrangeMultiple() with the required information
	 */

	int** userArray;
	int arraySize;
	int numSwaps;
	int i, j;

	cout << "\nSetting up data before calling"
		" ArrangeMultipleArrayPeteWilcox() --";
	cout << "\n\nHow many arrays of int (treating these as "
		"arrays of int? ";
	cin >> arraySize;

	userArray = new int*[arraySize];

	for (i = 0; i < arraySize; i++) {
		cout << "\nCreating array index # " << i;
		*(userArray + i) = createArray();

		cout << "\nFor array index #" << i << endl;
		for (j = 0; j < (*(*(userArray + i)) + 1); j++) {
			cout << "  Element index #" << j << " : " <<
				*(*(userArray + i) + j) << endl;
		}
	}


	cout << "\nConfirming before working through with "
		"swapping --";
	cout << "\n\nThere is/are " << arraySize <<
		" array(s).";

	for (i = 0; i < arraySize; i++) {
		cout << "\n\nThe current array #" << (i + 1) << " has "
			<< ((*(*(userArray + i))) + 1) <<
			" element(s).\n..";

		for (j = 0; j < ((*(*(userArray + i))) + 1); j++) {
			cout << "Element index #" << j << " : " <<
				*(*(userArray + i) + j) << "\n  ";
		}

	}

	cout << "\nCalling arrangeMultipleArrayPeteWilcox() --\n";
	numSwaps =
		arrangeMultipleArrayPeteWilcox(userArray, arraySize);

	cout << "\n\nDisplaying outside of "
		"arrangeMultipleArrayYourName() -\n";

	for (i = 0; i < arraySize; i++) {
		cout << "\n\nThe updated array #" << (i + 1) << " has "
			<< *(*(userArray + i)) << " element(s).";

		for (j = 0; j <= *(*(userArray + i)); j++) {
			cout << "\n  Element index #" << j << " : " <<
				*(*(userArray + i) + j);
		}
	}

	if (numSwaps > 0) {
		cout << "\n\nThere is/are " << numSwaps << " swap(s).";
	}

	for (i = 0; i < arraySize; i++) {
		delete[] *(userArray + i);
	}

	delete[] userArray;

	return;
}

int* createArray() {
	/* Creates an array of user-specified size and returns the
	 * address.
	 */
	int* newArray;
	int newArraySize;
	int i;

	cout << "\n\n  How many value(s)? ";
	cin >> newArraySize;

	newArray = new int[++newArraySize];
	*(newArray) = (newArraySize - 1);

	for (i = 1; i < newArraySize; i++) {
		cout << "\n    Enter the value for element at index "
			<< i << " : ";
		cin >> *(newArray + i);
	}

	return newArray;
}


int arrangeMultipleArrayPeteWilcox(int** input, int size) {
	// Arrange arrays

	int numSwaps = 0;
	int temp;
	bool swapped = false;
	int i, k;
	int j = 1;

	// Count the number of swaps to be made
	for (i = 1; i <= **input; i++) {
		if ((*(*input) + i) % 2 == 0) {
			numSwaps++;
		}
	}

	if (numSwaps > 0) {
		cout << "\n  Displaying inside "
			"arrangeMultipleArrayPeteWilcox()-";


		for (i = 1; i <= **input; i++) {
			swapped = false;
			// For each value in Array #1

			if (*((*input) + i) % 2 == 0) {
				// If it's even

				while ((j < size) && (!swapped)) {
					// Iterate through each other array
					k = 1;
					while ((k <= *(*(input + j))) && 
							(!swapped)) {

						if (*(*(input + j) + k) % 2 != 0) {
							// Until an odd value is found

							cout << "\n    Array #1 value " <<
								*((*input) + i) <<
								" is swapped with Array #"
								<< (j + 1) << " value " <<
								*(*(input + j) + k);

							// And swap it
							temp = *((*input) + i);
							*((*input) + i) = 
									*(*(input + j) + k);
							*(*(input + j) + k) = temp;

							swapped = true;
						}
						k++;
					}
					// If we've looked through every value
					if (k > *(*(input + j))) {
						// Move to the next array
						j++;
					}
				}

			}


		}
	}
	return numSwaps;
}


/* PROGRAM OUTPUT:

Class Information --
  CIS 25 - C++ Programming
  Laney College

Assignment Information --
  Assignment Number:  Lab 04 - Exercise #1
  Written by:         Pete Wilcox
  Submitted Date:     2015/10/08


*************************************************
*                MENU 04 -- Arrays              *
*  (1) Calling arrangeMultipleArrayPeteWilcox() *
*  (2) Quit                                     *
*************************************************
Select an option (1 or 2): 4

WRONG OPTION!


*************************************************
*                MENU 04 -- Arrays              *
*  (1) Calling arrangeMultipleArrayPeteWilcox() *
*  (2) Quit                                     *
*************************************************
Select an option (1 or 2): 1

Setting up data before calling ArrangeMultipleArrayPeteWilcox() --

How many arrays of int (treating these as arrays of int? 3

Creating array index # 0

  How many value(s)? 6

	Enter the value for element at index 1 : 1

	Enter the value for element at index 2 : -23

	Enter the value for element at index 3 : 18

	Enter the value for element at index 4 : 27

	Enter the value for element at index 5 : -36

	Enter the value for element at index 6 : 45

For array index #0
  Element index #0 : 6
  Element index #1 : 1
  Element index #2 : -23
  Element index #3 : 18
  Element index #4 : 27
  Element index #5 : -36
  Element index #6 : 45

Creating array index # 1

  How many value(s)? 3

	Enter the value for element at index 1 : 4

	Enter the value for element at index 2 : -17

	Enter the value for element at index 3 : 8

For array index #1
  Element index #0 : 3
  Element index #1 : 4
  Element index #2 : -17
  Element index #3 : 8

Creating array index # 2

  How many value(s)? 2

	Enter the value for element at index 1 : -1

	Enter the value for element at index 2 : -3

For array index #2
  Element index #0 : 2
  Element index #1 : -1
  Element index #2 : -3

Confirming before working through with swapping --

There is/are 3 array(s).

The current array #1 has 7 element(s).
..Element index #0 : 6
  Element index #1 : 1
  Element index #2 : -23
  Element index #3 : 18
  Element index #4 : 27
  Element index #5 : -36
  Element index #6 : 45


The current array #2 has 4 element(s).
..Element index #0 : 3
  Element index #1 : 4
  Element index #2 : -17
  Element index #3 : 8


The current array #3 has 3 element(s).
..Element index #0 : 2
  Element index #1 : -1
  Element index #2 : -3

Calling arrangeMultipleArrayPeteWilcox() --

  Displaying inside arrangeMultipleArrayPeteWilcox()-
	Array #1 value 18 is swapped with Array #2 value -17
	Array #1 value -36 is swapped with Array #3 value -1

Displaying outside of arrangeMultipleArrayYourName() -


The updated array #1 has 6 element(s).
  Element index #0 : 6
  Element index #1 : 1
  Element index #2 : -23
  Element index #3 : -17
  Element index #4 : 27
  Element index #5 : -1
  Element index #6 : 45

The updated array #2 has 3 element(s).
  Element index #0 : 3
  Element index #1 : 4
  Element index #2 : 18
  Element index #3 : 8

The updated array #3 has 2 element(s).
  Element index #0 : 2
  Element index #1 : -36
  Element index #2 : -3

There is/are 3 swap(s).

*************************************************
*                MENU 04 -- Arrays              *
*  (1) Calling arrangeMultipleArrayPeteWilcox() *
*  (2) Quit                                     *
*************************************************
Select an option (1 or 2): 1

Setting up data before calling ArrangeMultipleArrayPeteWilcox() --

How many arrays of int (treating these as arrays of int? 4

Creating array index # 0

  How many value(s)? 12

	Enter the value for element at index 1 : 4894848

	Enter the value for element at index 2 : 848425886

	Enter the value for element at index 3 : 6518486

	Enter the value for element at index 4 : 23153483

	Enter the value for element at index 5 : 1984869

	Enter the value for element at index 6 : 35435484

	Enter the value for element at index 7 : 53484

	Enter the value for element at index 8 : 354388

	Enter the value for element at index 9 : -6158

	Enter the value for element at index 10 : -44

	Enter the value for element at index 11 : -6843848

	Enter the value for element at index 12 : 35138

For array index #0
  Element index #0 : 12
  Element index #1 : 4894848
  Element index #2 : 848425886
  Element index #3 : 6518486
  Element index #4 : 23153483
  Element index #5 : 1984869
  Element index #6 : 35435484
  Element index #7 : 53484
  Element index #8 : 354388
  Element index #9 : -6158
  Element index #10 : -44
  Element index #11 : -6843848
  Element index #12 : 35138

Creating array index # 1

  How many value(s)? 4

	Enter the value for element at index 1 : 13235

	Enter the value for element at index 2 : 4864865

	Enter the value for element at index 3 : 32154

	Enter the value for element at index 4 : 35889

For array index #1
  Element index #0 : 4
  Element index #1 : 13235
  Element index #2 : 4864865
  Element index #3 : 32154
  Element index #4 : 35889

Creating array index # 2

  How many value(s)? 3

	Enter the value for element at index 1 : 35486

	Enter the value for element at index 2 : 354834845

	Enter the value for element at index 3 : 35153185

For array index #2
  Element index #0 : 3
  Element index #1 : 35486
  Element index #2 : 354834845
  Element index #3 : 35153185

Creating array index # 3

  How many value(s)? 5

	Enter the value for element at index 1 : 35486

	Enter the value for element at index 2 : 3518655

	Enter the value for element at index 3 : 3515229

	Enter the value for element at index 4 : 321848

	Enter the value for element at index 5 : 315377

For array index #3
  Element index #0 : 5
  Element index #1 : 35486
  Element index #2 : 3518655
  Element index #3 : 3515229
  Element index #4 : 321848
  Element index #5 : 315377

Confirming before working through with swapping --

There is/are 4 array(s).

The current array #1 has 13 element(s).
..Element index #0 : 12
  Element index #1 : 4894848
  Element index #2 : 848425886
  Element index #3 : 6518486
  Element index #4 : 23153483
  Element index #5 : 1984869
  Element index #6 : 35435484
  Element index #7 : 53484
  Element index #8 : 354388
  Element index #9 : -6158
  Element index #10 : -44
  Element index #11 : -6843848
  Element index #12 : 35138


The current array #2 has 5 element(s).
..Element index #0 : 4
  Element index #1 : 13235
  Element index #2 : 4864865
  Element index #3 : 32154
  Element index #4 : 35889


The current array #3 has 4 element(s).
..Element index #0 : 3
  Element index #1 : 35486
  Element index #2 : 354834845
  Element index #3 : 35153185


The current array #4 has 6 element(s).
..Element index #0 : 5
  Element index #1 : 35486
  Element index #2 : 3518655
  Element index #3 : 3515229
  Element index #4 : 321848
  Element index #5 : 315377

Calling arrangeMultipleArrayPeteWilcox() --

  Displaying inside arrangeMultipleArrayPeteWilcox()-
	Array #1 value 4894848 is swapped with Array #2 value 13235
	Array #1 value 848425886 is swapped with Array #2 value 4864865
	Array #1 value 6518486 is swapped with Array #2 value 35889
	Array #1 value 35435484 is swapped with Array #3 value 354834845
	Array #1 value 53484 is swapped with Array #3 value 35153185
	Array #1 value 354388 is swapped with Array #4 value 3518655
	Array #1 value -6158 is swapped with Array #4 value 3515229
	Array #1 value -44 is swapped with Array #4 value 315377

Displaying outside of arrangeMultipleArrayYourName() -


The updated array #1 has 12 element(s).
  Element index #0 : 12
  Element index #1 : 13235
  Element index #2 : 4864865
  Element index #3 : 35889
  Element index #4 : 23153483
  Element index #5 : 1984869
  Element index #6 : 354834845
  Element index #7 : 35153185
  Element index #8 : 3518655
  Element index #9 : 3515229
  Element index #10 : 315377
  Element index #11 : -6843848
  Element index #12 : 35138

The updated array #2 has 4 element(s).
  Element index #0 : 4
  Element index #1 : 4894848
  Element index #2 : 848425886
  Element index #3 : 32154
  Element index #4 : 6518486

The updated array #3 has 3 element(s).
  Element index #0 : 3
  Element index #1 : 35486
  Element index #2 : 35435484
  Element index #3 : 53484

The updated array #4 has 5 element(s).
  Element index #0 : 5
  Element index #1 : 35486
  Element index #2 : 354388
  Element index #3 : -6158
  Element index #4 : 321848
  Element index #5 : -44

There is/are 6 swap(s).

*************************************************
*                MENU 04 -- Arrays              *
*  (1) Calling arrangeMultipleArrayPeteWilcox() *
*  (2) Quit                                     *
*************************************************
Select an option (1 or 2): 2

Having fun...
Press any key to continue . . .


*/

/* COMMENTS:
2015/10/08:
The scope seems limited - why not move all the odd values to
one side with all the even values moved to the other side?
*/