/* CIS-22C
*  Lab 2
*  Spencer Bledsoe
*/

#pragma once
#include "Currency.h"
#include <string>

class Pound : public Currency {
private:
	std::string currType = "Pound";

public:
	//Constructor Declarations (Default, All Param, Copy)
	using Currency::Currency;

	//Setters & Getters (make "override")
	int getCurr() const override { return currency; }
	int getCoin() const override { return coin; }
	std::string getType() const override { return currType; }

};

