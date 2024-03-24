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
#include <sstream>
using namespace std;

void print(Currency*[]); //Check if pointer is correct

int main() {
	string userInput;
	string opType, inType, actType;
	double inVal = 0.00;

	Currency* currArray[2] = { new Pound(), new Dollar() };

	//sample input: a d 1.11 Dollar
	// "a" defines operation, "d" defines input object type, "1.11" defines input object value, "Dollar" defines object type to be acted upon (in the array)
	//sample input to exit program: q

	while (userInput != "q") {
		userInput = "";
		print(currArray);
		getline(cin, userInput);
		if (userInput != "q") {
			stringstream ss(userInput);
			ss >> opType >> inType >> inVal >> actType;

			try {
				if (inType == "p") {
					Pound* inputPound = new Pound(inVal);
					if (opType == "a") {
						if (actType == "pound") {
							currArray[0]->add(*inputPound);
						}
						else {
							throw string("Invalid addition");
						}
					}
					else if (opType == "s") {
						if (actType == "pound") {
							currArray[0]->subtract(*inputPound);
						}
						else {
							throw string("Invalid subtraction");
						}
					}
					delete inputPound;
				}

				else if (inType == "d") {
					Dollar* inputDollar = new Dollar(inVal);
					if (opType == "a") {
						if (actType == "dollar") {
							currArray[1]->add(*inputDollar);
						}
						else {
							throw string("Invalid addition");
						}
					}
					else if (opType == "s") {
						if (actType == "dollar" && (currArray[1]->getCurr() >= inputDollar->getCurr()) && (currArray[1]->getCoin() >= inputDollar->getCoin())) {
							currArray[1]->subtract(*inputDollar);
						}
						else {
							throw string("Invalid subtraction");
						}
					}
					delete inputDollar;
				}
			}

			catch (string err) {

				cout << err << endl;
			}
		}

	}


	for (int i = 0; i < 2; i++) {
		delete currArray[i];
	}

	system("pause");
	return 0;
}

void print(Currency** currArray) {
	currArray[0]->print();
	cout << " ";
	currArray[1]->print();
	cout << endl;
}