/* CIS-22C
*  Lab 2
*  Spencer Bledsoe
*/

#pragma once
#include <string>
#include <iomanip>
#include <iostream>

class Currency {
protected:
	int currency;
	int coin;

public:
	//Constructor Declarations (Default, All Param, Copy), no constructors/destructors needed, abstract class
	Currency() {
		currency = 0;
		coin = 0;
	}

	Currency(double inCurr) {
		currency = static_cast<int>(inCurr);
		coin = static_cast<int>((inCurr * 100) - (currency * 100));
	}

	Currency(Currency &t) {
		currency = t.currency;
		coin = t.coin;
	}

	bool operator == (const Currency& y) const;
	bool operator > (const Currency& y) const;
	bool operator < (const Currency& y) const;

	//Setters & Getters (make virtual)
	virtual int getCurr() const = 0;
	virtual int getCoin() const = 0;
	virtual std::string getType() const = 0;

	void add(Currency& newCurr) {
		try {
			if (this->getType() == newCurr.getType()) {
				currency = currency + newCurr.getCurr(); coin = coin + newCurr.getCoin();
				if (coin > 99) {
					coin = coin - 100;
					currency++;
				}
			}
			else {
				throw ("addition");
			}
		}
		catch (std::string a) {
			std::cout << "Invalid " << a << std::endl;
		}

		return;
	}
	void subtract(Currency& newCurr) {
		try {
			if (this->isGreater(&newCurr) || this->isEqual(&newCurr)) {
				currency = currency - newCurr.getCurr(); coin = coin - newCurr.getCoin();
			}
			else {
				throw std::string("subtraction");
			}
		}
		catch (std::string s) {
			std::cout << "Invalid " << s << std::endl;
		}

		return;
	}
	bool isEqual(Currency* y) const { return (this == y); }
	bool isGreater(Currency* y) const { return (this > y); } //returns true if this > input obj
	void print() {
		std::cout << getCurr() << "." << std::setw(2) << std::setfill('0') << std::right << getCoin() << " " << getType();
		return;
	}

};

bool Currency::operator==(const Currency& y) const {
	try {
		//std::cout << "this->getType(): " << this->getType() << ", y->getType(): " << y->getType() << std::endl;
		if (getType() == y.getType()) {
			if ((this->getCurr() == y.getCurr()) && (this->getCoin() == y.getCoin())) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			throw char('=');
		}
	}
	catch (char z) {
		std::cout << "Invalid comparison: Currency Type Mismatch for operator " << z << z << std::endl;
		return false;
	}

}

bool Currency::operator > (const Currency& y) const {
	try {
		if (this->getType() == y.getType()) {
			return (this->getCurr() > y.getCurr()) && (this->getCoin() > y.getCoin());
		}
		else {
			throw char('>');
		}
	}
	catch (char z) {
		std::cout << "Invalid comparison: Currency Type Mismatch for operator " << z << std::endl;
		return false;
	}
}

bool Currency::operator < (const Currency& y) const {
	try {
		if (this->getType() == y.getType()) {
			return (this->getCurr() < y.getCurr()) && (this->getCoin() < y.getCoin());
		}
		else {
			throw char('<');
		}
	}
	catch (char z) {
		std::cout << "Invalid comparison: Currency Type Mismatch for operator " << z << std::endl;
		return false;
	}
}