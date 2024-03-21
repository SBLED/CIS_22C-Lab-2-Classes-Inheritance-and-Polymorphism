/* CIS-22C
*  Lab 2
*  Spencer Bledsoe
*/

#pragma once
#include <string>

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

	Currency(Currency &t) {
		currency = t.currency;
		coin = t.coin;
	}

	//Overloading equality operator
	friend bool operator == (Currency x, Currency y);

	//Setters & Getters (make virtual)
	virtual int getCurr();
	virtual int getCoin();

	virtual void add(Currency); //changed to Currency from int
	virtual void subtract(Currency);//changed to Currency from int
	virtual void isEqual(Currency, Currency);
	virtual void isGreater(Currency, Currency);
	virtual void print();

};

bool operator == (Currency x, Currency y) {
	return (x.currency == y.currency) && (x.coin == y.coin);
}

