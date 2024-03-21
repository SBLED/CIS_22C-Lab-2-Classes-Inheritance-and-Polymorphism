/* CIS-22C
*  Lab 2
*  Spencer Bledsoe
*/

#pragma once
#include "Currency.h"
#include <string>

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

	void add(Currency newCurr) override { dollars = dollars + newCurr.getCurr(); cents = cents + newCurr.getCoin(); }
	void subtract(Currency newCurr) override { dollars = dollars - newCurr.getCurr(); cents = cents - newCurr.getCoin(); }

	//Check these two and make sure they only compare objects of same currency: "Dollar", add a check for the string currType for all functions
	void isEqual(Currency, Currency) override {}
	void isGreater(Currency, Currency) override {}
	void print() override {}

};

