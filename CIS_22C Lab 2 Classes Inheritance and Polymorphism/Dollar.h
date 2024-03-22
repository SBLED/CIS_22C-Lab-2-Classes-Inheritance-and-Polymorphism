/* CIS-22C
*  Lab 2
*  Spencer Bledsoe
*/

#pragma once
#include "Currency.h"
#include <string>
#include <iomanip>

class Dollar : public Currency {
private:

	int dollars;
	int cents;
	std::string currType = "Dollar";

public:
	//Constructor Declarations (Default, All Param, Copy)
	
	Currency::Currency;

	//Destructor Declaration, using for debugging purposes
	~Dollar() {
		std::cout << "Dollar destructor executed" << std::endl;
	}

	//Setters & Getters (make "override")
	int getCurr() override { return dollars; }
	int getCoin() override { return cents; }
	string getType() override { return currType; }

	void add(Currency newCurr) override { 
		dollars = dollars + newCurr.getCurr(); cents = cents + newCurr.getCoin();
		return;
	}
	void subtract(Currency newCurr) override { 
		dollars = dollars - newCurr.getCurr(); cents = cents - newCurr.getCoin();
		return;
	}

	//Check these two and make sure they only compare objects of same currency: "Dollar", add a check for the string currType for all functions
	//isEqual(Currency y) override { return *this == y; }
	//void isGreater(Currency y) override { return this > y; }
	void print() override { cout << dollars << "." << setprecision(2) << cents << " " << currType << endl; return; }

};
