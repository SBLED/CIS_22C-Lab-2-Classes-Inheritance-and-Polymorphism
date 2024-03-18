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

	//Dollar() {
	//	dollars = 0;
	//	cents = 0;
	//}

	//Dollar(double currency) {
	//	dollars = currency;
	//	cents = (currency - dollars) * 100;
	//}

	//Destructor Declaration, using for debugging purposes
	~Dollar() {
		std::cout << "Dollar destructor executed" << std::endl;
	}

	//Setters & Getters (make "override")

	void add(Dollar curry) override { dollars = dollars + currency; }
	void subtract(int) override { dollars = dollars - currency; }

	//Check these two and make sure they only compare objects of same currency: "Dollar"
	void isEqual(Currency, Currency) override {}
	void isGreater(Currency, Currency) override {}
	void print() override {}

};

