/* CIS-22C
*  Lab 2
*  Spencer Bledsoe
*/

#pragma once
#include "Currency.h"
#include <string>

class Dollar : public Currency {
private:
	std::string currType = "Dollar";

public:
	//Constructor Declarations (Default, Double, Copy)
	using Currency::Currency;

	//Getters (make "override")
	/*Pre: this.currType == Dollar
	Post: Returns corresponding member variable
	*/
	int getCurr() const override { return currency; }
	int getCoin() const override { return coin; }
	std::string getType() const override { return currType; }

};
