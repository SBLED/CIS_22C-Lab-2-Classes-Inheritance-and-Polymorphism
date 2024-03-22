/* CIS-22C
*  Lab 2 - Classes, Inheritance, and Polymorphism
*  Spencer Bledsoe
*  Program Description: To manipulate currency objects of types Dollar and Pound, adding and subtracting amounts based on user input.
*
*  Pseudocode:
*	Take user input for the array elements.
*	Open iterative function to loop through and check for non-prime numbers.
*		Return true if all are prime, false if not.
*	Output results to user.
*	Open recursive function to check for non-prime numbers through the use of a helper function.
*		Recursively call itself to check each possible divisor for each element in the array.
*		Exit all function calls and return true if all are prime, false if not.
*	Output results to user.
*	Pause for user input.
*	Return 0 and exit program.
* */

#include "Currency.h"
#include "Dollar.h"
#include "Pound.h"
#include <iostream>
using namespace std;

int main() {

	//Use pointer of type Currency, and reference functions with "->" instead of "."; e.g. Currency *currency[] = { new Dollar; new Pound; };
	Currency* currency[] = { new Dollar(), new Pound };

	system("pause"); //pausing for user input before returning
	return 0;
}