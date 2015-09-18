#include <iostream>

using namespace std;

// Function prototypes
void header(void);
void menu(void);
void arrangeArrayPeteWilcox(int*, int, int*, int);
void createArrays(void);

int main() {

	header(); // Display program header information.
	menu();   // Display user interface.

	return 0;
}

void header() {
	cout << "\nClass Information --";
	cout << "\n  CIS 25 - C++ Programming";
	cout << "\n  Laney College";
	cout << "\n";
	cout << "\nAssignment Information -- ";
	cout << "\n  Assignment Number:  Lab 03 - Exercise #1";
	cout << "\n  Written by:         Pete Wilcox";
	cout << "\n  Submitted Date:     2015/09/29";
	cout << "\n";
	return;
}

void menu() {
	// Declare variables for the menu and for the integer input.
	int menuChoice = 0;

	// Create a loop for the main menu function.
	do {
		cout << "\n";
		cout << "\n*****************************************";
		cout << "\n*            MENU 03 -- Arrays          *";
		cout << "\n*  (1) Calling arrangeArrayPeteWilcox() *";
		cout << "\n*  (2) Quit                             *";
		cout << "\n*****************************************";
		cout << "\nSelect an option (1 or 2): ";
		cin >> menuChoice;

		switch (menuChoice) {
		case 1:
			createArrays();
			break;
		case 2:
			// Quit message.
			cout << "\nHaving fun..." << endl;
			break;
		default:
			cout << "\nWRONG OPTION!\n";
		}
	} while (menuChoice != 2);

	return;
}

void createArrays() {
	// Create arrays and pass their information to arrangeArray()
	int* firstArray = nullptr;
	int* secondArray = nullptr;
	int firstArraySize;
	int secondArraySize;
	int i;

	// Get user data and assign to arrays
	cout << "\nCreating the first array -";
	cout << "\nEnter the array size: ";
	cin >> firstArraySize;

	firstArray = new int[firstArraySize];

	cout << "\nEnter value for";
	for (i = 0; i < firstArraySize; i++) {
		cout << "  Index " << i << " : ";
		cin >> *(firstArray + i);
	}

	cout << "\nCreating the second array -";
	cout << "\nEnter the array size: ";
	cin >> secondArraySize;

	secondArray = new int[secondArraySize];

	cout << "\nEnter value for";
	for (i = 0; i < secondArraySize; i++) {
		cout << "  Index " << i << " : ";
		cin >> *(secondArray + i);
	}

	// Call arrangeArray() with user data
	cout << "\nCalling arrangeArraysPeteWilcox() --";
	arrangeArrayPeteWilcox(firstArray, firstArraySize, secondArray, secondArraySize);

	// Cleanup
	delete firstArray;
	delete secondArray;
	return;
}

void arrangeArrayPeteWilcox(int* firstArray, int firstArraySize,
	int* secondArray, int secondArraySize) {
	// Arrange arrays

	int* swapFromFirst = new int[firstArraySize];
	int* swapFromSecond = new int[secondArraySize];
	int numSwaps = 0;
	int i, j, temp;
	bool swapped;

	// Display original arrays
	cout << "\n\n  Original Arrays";
	cout << "\n    Array #1:";

	for (i = 0; i < firstArraySize; i++) {
		cout << "  " << *(firstArray + i);
	}

	cout << "\n    Array #2:";

	for (i = 0; i < secondArraySize; i++) {
		cout << "  " << *(secondArray + i);
	}


	// Iterate through array #1
	for (i = 0; i < firstArraySize; i++) {
		swapped = false;

		// If value is even
		if (*(firstArray + i) % 2 == 0) {
			j = 0;
			do {
				
				// Iterate through array #2
				if (*(secondArray + j) % 2 != 0) {

					// Track which values were swapped
					*(swapFromFirst + numSwaps) = *(firstArray + i);
					*(swapFromSecond + numSwaps) = *(secondArray + j);
					numSwaps++;

					// Swap values
					temp = *(firstArray + i);
					*(firstArray + i) = *(secondArray + j);
					*(secondArray + j) = temp;

					// Move to next element of array #1
					swapped = true;
				}
				j++;
			} while ((swapped == false) && (j < secondArraySize));
		}
	}

	// Display updated arrays
	cout << "\n\n  Updated Arrays";
	cout << "\n    Array #1:";

	for (i = 0; i < firstArraySize; i++) {
		cout << "  " << *(firstArray + i);
	}

	cout << "\n    Array #2:";

	for (i = 0; i < secondArraySize; i++) {
		cout << "  " << *(secondArray + i);
	}

	// Display swap info
	if (numSwaps > 0) {
		cout << "\n\n  Swapping info -";
		for (i = 0; i < numSwaps; i++) {
			cout << "\n    Array #1 value " << *(swapFromFirst + i) 
				<< " swapped with Array #2 value " << *(swapFromSecond + i);
		}
	}

	cout << "\n\nThere is/are " << numSwaps << " swap(s)." << endl;

	// Cleanup
	delete swapFromFirst;
	delete swapFromSecond;
	
	return;
}


/* PROGRAM OUTPUT:

Class Information --
  CIS 25 - C++ Programming
  Laney College

Assignment Information --
  Assignment Number:  Lab 03 - Exercise #1
  Written by:         Pete Wilcox
  Submitted Date:     2015/09/29


*****************************************
*            MENU 03 -- Arrays          *
*  (1) Calling arrangeArrayPeteWilcox() *
*  (2) Quit                             *
*****************************************
Select an option (1 or 2): 4

WRONG OPTION!


*****************************************
*            MENU 03 -- Arrays          *
*  (1) Calling arrangeArrayPeteWilcox() *
*  (2) Quit                             *
*****************************************
Select an option (1 or 2): 1

Creating the first array -
Enter the array size: 4

Enter value for  Index 0 : 21
  Index 1 : 41
  Index 2 : -21
  Index 3 : 81

Creating the second array -
Enter the array size: 2

Enter value for  Index 0 : 1
  Index 1 : 4

Calling arrangeArraysPeteWilcox() --

  Original Arrays
    Array #1:  21  41  -21  81
    Array #2:  1  4

  Updated Arrays
    Array #1:  21  41  -21  81
    Array #2:  1  4

There is/are 0 swap(s).


*****************************************
*            MENU 03 -- Arrays          *
*  (1) Calling arrangeArrayPeteWilcox() *
*  (2) Quit                             *
*****************************************
Select an option (1 or 2): 1

Creating the first array -
Enter the array size: 5

Enter value for  Index 0 : 2
  Index 1 : 4
  Index 2 : -2
  Index 3 : 81
  Index 4 : 8

Creating the second array -
Enter the array size: 3

Enter value for  Index 0 : 1
  Index 1 : 4
  Index 2 : -21

Calling arrangeArraysPeteWilcox() --

  Original Arrays
    Array #1:  2  4  -2  81  8
    Array #2:  1  4  -21

  Updated Arrays
    Array #1:  1  -21  -2  81  8
    Array #2:  2  4  4

  Swapping info -
    Array #1 value 2 swapped with Array #2 value 1
    Array #1 value 4 swapped with Array #2 value -21

There is/are 2 swap(s).


*****************************************
*            MENU 03 -- Arrays          *
*  (1) Calling arrangeArrayPeteWilcox() *
*  (2) Quit                             *
*****************************************
Select an option (1 or 2): 1

Creating the first array -
Enter the array size: 3

Enter value for  Index 0 : 1
  Index 1 : -1
  Index 2 : -2

Creating the second array -
Enter the array size: 5

Enter value for  Index 0 : 2
  Index 1 : 3
  Index 2 : -2
  Index 3 : 81
  Index 4 : 8

Calling arrangeArraysPeteWilcox() --

  Original Arrays
    Array #1:  1  -1  -2
    Array #2:  2  3  -2  81  8

  Updated Arrays
    Array #1:  1  -1  3
    Array #2:  2  -2  -2  81  8

  Swapping info -
    Array #1 value -2 swapped with Array #2 value 3

There is/are 1 swap(s).


*****************************************
*            MENU 03 -- Arrays          *
*  (1) Calling arrangeArrayPeteWilcox() *
*  (2) Quit                             *
*****************************************
Select an option (1 or 2): 1

Creating the first array -
Enter the array size: 5

Enter value for  Index 0 : 21
  Index 1 : 41
  Index 2 : -2
  Index 3 : 81
  Index 4 : 8

Creating the second array -
Enter the array size: 4

Enter value for  Index 0 : 10
  Index 1 : 41
  Index 2 : 181
  Index 3 : 401

Calling arrangeArraysPeteWilcox() --

  Original Arrays
    Array #1:  21  41  -2  81  8
    Array #2:  10  41  181  401

  Updated Arrays
    Array #1:  21  41  41  81  181
    Array #2:  10  -2  8  401

  Swapping info -
    Array #1 value -2 swapped with Array #2 value 41
    Array #1 value 8 swapped with Array #2 value 181

There is/are 2 swap(s).


*****************************************
*            MENU 03 -- Arrays          *
*  (1) Calling arrangeArrayPeteWilcox() *
*  (2) Quit                             *
*****************************************
Select an option (1 or 2): 2

Having fun...

*/

/* COMMENTS:
2015/09/27:
This implementation seems limited - why not allow the user
to determine the number of arrays?

Working with pointer syntax instead of array syntax seems 
unnecessarily complicated. I'm not sure I see the difference
between firstArray[i] and *(firstArray + i) except that one
has a more complicated notation.

*/