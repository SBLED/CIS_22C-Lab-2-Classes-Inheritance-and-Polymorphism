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

	virtual std::string getType();
	bool operator == (Currency y);
	bool operator > (Currency y);
	bool operator < (Currency y);

	//Setters & Getters (make virtual)
	virtual int getCurr();
	virtual int getCoin();

	virtual void add(Currency); //changed to Currency from int
	virtual void subtract(Currency);//changed to Currency from int
	bool isEqual(Currency y) { return *this == y; }
	virtual void isGreater(Currency);
	virtual void print();

};

bool Currency::operator == (Currency y) {
	try {
		if (this->getType() == y.getType()) {
			return (this->getCurr() == y.getCurr()) && (this->getCoin() == y.getCoin());
		}
		else {
			throw ('==');
		}
	}
	catch (char z) {
		cout << "Invalid comparison: Currency Type Mismatch for operator " << z << endl;
	}
}

bool Currency::operator > (Currency y) {
	try {
		if (this->getType() == y.getType()) {
			return (this->getCurr() > y.getCurr()) && (this->getCoin() > y.getCoin());
		}
		else {
			throw ('>');
		}
	}
	catch (char z) {
		cout << "Invalid comparison: Currency Type Mismatch for operator " << z << endl;
	}
}

bool Currency::operator < (Currency y) {
	try {
		if (this->getType() == y.getType()) {
			return (this->getCurr() < y.getCurr()) && (this->getCoin() < y.getCoin());
		}
		else {
			throw ('<');
		}
	}
	catch (char z) {
		cout << "Invalid comparison: Currency Type Mismatch for operator " << z << endl;
	}
}