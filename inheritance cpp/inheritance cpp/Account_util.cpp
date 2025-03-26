#include <iostream>
#include "Account_util.h"

void display(const std::vector<Account>& accounts) {
	for (const auto& acc : accounts)
		std::cout << acc << std::endl;
}
void deposit(std::vector<Account>& accounts,double amount) {
	for (auto& acc : accounts)
		if (acc.deposit(amount))
			std::cout << "Deposited" << amount << "to" << acc << std::endl;
		else
			std::cout << "Failed deposit of" << amount << "to" << acc << std::endl;
}
void withdraw(std::vector<Account>& accounts, double amount) {
	for (auto& acc : accounts)
		if (acc.withdraw(amount))
			std::cout << "Withdrew" << amount << "from" << acc << std::endl;
		else
			std::cout << "Failed withdrawal of" << amount << "from" << acc << std::endl;
}

void display(const std::vector<Savings_Account>& accounts) {
	for (const auto& acc : accounts)
		std::cout << acc << std::endl;
}
void deposit(std::vector<Savings_Account>& accounts, double amount) {
	for (auto& acc : accounts)
		if (acc.deposit(amount))
			std::cout << "Deposited" << amount << "to" << acc << std::endl;
		else
			std::cout << "Failed deposit of" << amount << "to" << acc << std::endl;
}
void withdraw(std::vector<Savings_Account>& accounts, double amount) {
	for (auto& acc : accounts)
		if (acc.withdraw(amount))
			std::cout << "Withdrew" << amount << "from" << acc << std::endl;
		else
			std::cout << "Failed withdrawal of" << amount << "from" << acc << std::endl;
}
