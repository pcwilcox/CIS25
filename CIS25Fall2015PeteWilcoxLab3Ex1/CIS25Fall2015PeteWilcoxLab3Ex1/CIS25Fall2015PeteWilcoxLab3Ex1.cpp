#include <iostream>

using namespace std;

// Function prototypes
void header(void);
void menu(void);

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
		cout << "\n***************************************************";
		cout << "\n*               MENU 02 -- Arrays & Digits        *";
		cout << "\n*  (1) Calling displayDigitInfoUpdatePeteWilcox() *";
		cout << "\n*  (2) Quit                                       *";
		cout << "\n***************************************************";
		cout << "\nSelect an option (1 or 2): ";
		cin >> menuChoice;

		// Get input from user if option (1) is chosen, then call 
		// getMostOccurredDigit function and display result.
		switch (menuChoice) {
		case 1:
			cout << "\nCalling displayDigitInfoUpdatePeteWilcox() --";

			displayDigitInfoUpdatePeteWilcox();
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

/* PROGRAM OUTPUT:

*/

/* COMMENTS:


*/