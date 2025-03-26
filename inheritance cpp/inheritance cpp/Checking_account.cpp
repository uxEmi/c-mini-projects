#include "Checking_account.h"

Checking_account::Checking_account(std::string name, double balance, double fee = 0.0) :Account(name, balance), fee(fee) {}
bool  Checking_account::deposit(double amount)
{
	return Account::deposit(amount);
}
bool Checking_account::withdraw(double amount) {
	if (balance - amount - fee >= 0)
	{
		balance -= amount + fee;
		return true;
	}
	return false;
}
std::ostream& operator<<(std::ostream & os, const Checking_account& account)
{
	os << account.balance << std::endl;
	return os;
}