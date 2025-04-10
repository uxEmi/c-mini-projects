#include "Account.h"
#include <exception>
class IllegalBalanceException : public std::exception{
public:
	IllegalBalanceException() = default;
	~IllegalBalanceException() = default;
	virtual const char* what() const noexcept {
		return "nu se poate introduce un cont pe negativ";
	}
};
Account::Account(std::string name, double balance) : name(name), balance(balance) {
		if(balance<0)
			 throw IllegalBalanceException();
}
bool Account::deposit(double amount) 
{
	if (amount < 0)
		return false;
	else {
		balance += amount;
		return true;
	}
}
bool Account::withdraw(double amount)
{
	if (balance - amount >= 0)
	{
		balance -= amount;
		return true;
	}
	else
		return false;
}
double Account::get_balance()const
{
	return balance;
}
std::ostream& operator<<(std::ostream& os,const Account& account)
{
	os << "[Account: " << account.name << "]" <<std::endl;
	return os;
}