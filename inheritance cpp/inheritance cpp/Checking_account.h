#pragma once
#include "Account.h"
class Checking_account:public Account{
	friend std::ostream& operator<<(std::ostream& os,const Checking_account& account);
protected:
	static constexpr double fee=1.50;
public:
	Checking_account(std::string name, double balance, double fee = 0.0);
	bool withdraw(double amount);
	bool deposit(double amount);
};
