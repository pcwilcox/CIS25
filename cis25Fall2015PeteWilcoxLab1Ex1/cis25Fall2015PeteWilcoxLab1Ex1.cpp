/**
 * Program Name: cis25Fall2015PeteWilcoxLab1Ex1.cpp
 * Discussion:   Lab #1 Exercise #1
 * Written by:   Pete Wilcox
 * Date:         2015/09/10
 */

#include <iostream>

using namespace std;

// Function prototypes.
void header(void);
void menu(void);
int getMostOccurredDigit(int);

int main() {
	
	header(); // Displays program header info
	menu();   // Displays the user interface

	return 0;
}


void header() {
	cout << "\nCIS 25 - C++ Programming";
	cout << "\nLaney College";
	cout << "\nPete Wilcox";
	cout << "\n";
	cout << "\nAssignment Information -- ";
	cout << "\n  Assignment Number:  Lab 01,";
	cout << "\n                      Coding Assignment -- Exercise #1";
	cout << "\n  Written by:         Pete Wilcox";
	cout << "\n  Submitted Date:     2015/09/10";
	cout << "\n";
	return;
}

void menu() {
	// Declare variables for the menu and for the integer input.
	int menuChoice = 0;
	int userInput = 0;

	// Create a loop for the main menu function.
	do {
		cout << "\n";
		cout << "\n***************************************";
		cout << "\n*                  MENU               *";
		cout << "\n*  (1) Calling getMostOccurredDigit() *";
		cout << "\n*  (2) Quit                           *";
		cout << "\n***************************************";
		cout << "\nEnter your option (1 or 2): ";
		cin >> menuChoice;

		// Get input from user if option (1) is chosen, then call 
		// getMostOccurredDigit function and display result.
		if (menuChoice == 1) { 
			cout << "\nEnter an integer: ";
			cin >> userInput;
			cout << "\nCalling getMostOccurredDigit() --";
			cout << "\nThe digit occurred most in " << userInput;
			cout << " is " << getMostOccurredDigit(userInput) << ".\n";
		} else if (menuChoice == 2) {
			// Quit message.
			cout << "\nWorking good!" << endl;
		} else {
			cout << "\nInvalid menu choice. Please choose 1 or 2.";
		}
	} while (menuChoice != 2);


	return;
}

// Function to determine digit that occurs most in user input integer.
int getMostOccurredDigit(int userInput) {

	// Declare variables - I use an array to process the input integer.
	int maxCount = 0;
	int maxDigit = 0;
	int intSize = 0;
	int currentCount = 0;
	int userInteger[15] = { 0 };
	int i, j;

	// Check to see if the integer is 0.
	if (userInput != 0) {

		// If user input is negative, convert it to positive.
		if (userInput < 0) {
			userInput = -userInput;
		}

		// Iterate through the userInput and place each digit in the
		// userInteger array.
		while (userInput > 0) {
			userInteger[intSize] = userInput % 10;
			userInput /= 10;
			intSize++;
		}
	} else {

		// If the user input 0, skip the rest.
		return 0;
	}

	// For each digit in the array, count the matching digits
	for (i = 0; i < intSize; i++) {
		currentCount = 0;
		userInteger[i];

		for (j = i; j < intSize; j++) {
			if (userInteger[j] == userInteger[i]) {
				currentCount++;
			}
		}

		// If the current count is the highest we've seen, overwrite
		// the previous maximum.
		if (currentCount > maxCount) {
			maxCount = currentCount;
			maxDigit = userInteger[i];
		}
	}

	// Return the maximum digit found.
	return maxDigit;
}
/* Program Output:

CIS 25 - C++ Programming
Laney College
Pete Wilcox

Assignment Information --
  Assignment Number:  Lab 01,
                      Coding Assignment -- Exercise #1
  Written by:         Pete Wilcox
  Submitted Date:     2015/09/10


***************************************
*                  MENU               *
*  (1) Calling getMostOccurredDigit() *
*  (2) Quit                           *
***************************************
Enter your option (1 or 2): 1

Enter an integer: 123444034

Calling getMostOccurredDigit() --
The digit occurred most in 123444034 is 4.


***************************************
*                  MENU               *
*  (1) Calling getMostOccurredDigit() *
*  (2) Quit                           *
***************************************
Enter your option (1 or 2): 1

Enter an integer: -390345505

Calling getMostOccurredDigit() --
The digit occurred most in -390345505 is 5.


***************************************
*                  MENU               *
*  (1) Calling getMostOccurredDigit() *
*  (2) Quit                           *
***************************************
Enter your option (1 or 2): 1

Enter an integer: 39034550

Calling getMostOccurredDigit() --
The digit occurred most in 39034550 is 0.


***************************************
*                  MENU               *
*  (1) Calling getMostOccurredDigit() *
*  (2) Quit                           *
***************************************
Enter your option (1 or 2): 1

Enter an integer: 12312245

Calling getMostOccurredDigit() --
The digit occurred most in 12312245 is 2.


***************************************
*                  MENU               *
*  (1) Calling getMostOccurredDigit() *
*  (2) Quit                           *
***************************************
Enter your option (1 or 2): 3

Invalid menu choice. Please choose 1 or 2.

***************************************
*                  MENU               *
*  (1) Calling getMostOccurredDigit() *
*  (2) Quit                           *
***************************************
Enter your option (1 or 2): 2

Working good!
Press any key to continue . . .
*/

/* User comments:

Second submission 2015/09/10: No additional
comments.

First submission 2015/09/03:
There are some limitations to this program. The 
immediately obvious one is that you must hard-
code the overall size of the integer, though 
ultimately this isn't a huge problem given the
maximum size of an integer.

The second problem is that depending on the user
input, the getMostOccurredDigit() function may
not return complete data. For instance, if the
user input 11223344, the function will return
the value 4 as the most occurred digit. This is
because when the integer is converted to an
array, the ones digit is put in the first space
and this space is processed first.

Ultimately, I don't believe the first problem
is worth worrying about - simply make the array
large enough and leave it at that. The second
issue, however, could be solved by creating an
array of integers to store the return values,
then returning a pointer to the array and
iterating through that. This would allow you to
display multiple digits that each occur multiple
times.

*/
