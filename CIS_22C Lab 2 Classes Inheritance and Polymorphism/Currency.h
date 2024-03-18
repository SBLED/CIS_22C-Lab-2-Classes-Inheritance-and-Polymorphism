/* CIS-22C
*  Lab 2
*  Spencer Bledsoe
*/

#pragma once

class Currency {
private:
	int currency;
	int coin;

public:
	//Constructor Declarations (Default, All Param, Copy), no constructors/destructors needed, abstract class
	Currency() {
		currency = 0;
		coin = 0;
	}

	Currency(double inCurr) {
		currency = inCurr;
		coin = (inCurr - currency) * 100;
	}

	Currency(Currency) {

	}
	//Destructor Declaration; not needed, abstract class

	//Setters & Getters (make virtual)
	virtual void add(int);
	virtual void subtract(int);
	virtual void isEqual(Currency, Currency);
	virtual void isGreater(Currency, Currency);
	virtual void print();

};

