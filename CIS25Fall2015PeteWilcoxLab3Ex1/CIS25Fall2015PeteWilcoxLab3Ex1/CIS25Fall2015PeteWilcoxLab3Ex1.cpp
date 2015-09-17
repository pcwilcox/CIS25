#include <iostream>

using namespace std;

// Function prototypes
void header(void);
void menu(void);
void arrangeArrayPeteWilcox(void);

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

			arrangeArrayPeteWilcox();
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

void arrangeArrayPeteWilcox(void) {
	int* firstArray = nullptr;
	int* secondArray = nullptr;
	int arraySize;
	int i, j;

	// Create arrays
	cout << "\nCreating the first array -";
	cout << "\nEnter the array size: ";
	cin >> arraySize;
	
	firstArray = new int[arraySize];
	
	cout << "\nEnter value for";
	for (i = 0; i < arraySize; i++) {
		cout << "\n  Index " << i << " : ";
		cin >> firstArray[i];
	}

	cout << "\nCreating the second array -";
	cout << "\nEnter the array size: ";
	cin >> arraySize;

	secondArray = new int[arraySize];

	cout << "\nEnter value for";
	for (i = 0; i < arraySize; i++) {
		cout << "\n  Index " << i << " : ";
		cin >> secondArray[i];
	}


	delete firstArray;
	delete secondArray;

	return;
}


/* PROGRAM OUTPUT:

*/

/* COMMENTS:


*/