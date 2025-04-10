#pragma once
#include "Account.h"
class Checking_account:public Account{
	friend std::ostream& operator<<(std::ostream& os,const Checking_account& account);
	static constexpr double fee = 1.50;
public:
	Checking_account(std::string name, double balance);
	bool withdraw(double amount);
	bool deposit(double amount);
};
