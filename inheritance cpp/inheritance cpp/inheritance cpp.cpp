#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_util.h"
using namespace std;

int main()
{
	try {
		Account obj("wndq", -10);
	}
	catch (const IllegalBalanceException& ex)
	{
		std::cout << ex.what() << std::endl;
	}

}
