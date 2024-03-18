/* CIS-22C
*  Lab 2 - Classes, Inheritance, and Polymorphism
*  Spencer Bledsoe
*  Program Description: To check a user-inputted array to determine whether or not it consists entirely of prime numbers,
*						using both recursive and iterative methods.
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

//Prototype
bool IsArrayPrimeIter(int[], int);


int main() {

	//Use pointer of type Currency, and reference functions with "->" instead of "."; e.g. Currency *currency[] = { new Dollar; new Pound; };
	Currency* currency[] = { new Dollar(), new Pound };

	system("pause"); //pausing for user input before returning
	return 0;
}

bool IsArrayPrimeIter(int ary[], int aryLen) {
	/*Pre: ary[] - array containing up to 16 user defined elements
	*		aryLen - int for the number of user-defined elements in the array
	* Post:
	* Return: isPrime - boolean describing whether all numbers were detected as prime in the array
			  (true if all are prime, false if at least one is not prime) */

	cout << "Entering IsArrayPrimeIter" << endl;

	bool isPrime = true;

	//Increments through the array elements
	for (int j = 0; j < aryLen; j++) {

		if (ary[j] == 1) {
			isPrime = false;
			break;
		}

		//Increments through all possible divisors without repeating
		for (int k = 2; k < (ary[j] / 2); k++) {

			//Increments k if k is divisible by 2 or 3, but is not equal to 2 or 3
			while (k > 3 && k % 2 == 0 && k % 3 == 0) {
				k++;
			}

			//Checks for non-prime numbers and exits inner loop if one is found.
			if (ary[j] % k == 0 && ary[j] != 0 && ary[j] != 1) {
				isPrime = false;
				break;
			}
		}

		//If a non-prime number was found, exits outer loop.
		if (isPrime == false) {
			break;
		}

	}

	cout << "Leaving IsArrayPrimeIter" << endl;
	return isPrime;
}
