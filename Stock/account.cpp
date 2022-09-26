#include "account.h"

Account::Account(Stocks& stocks,float cash) : stocks{ stocks } {
	this->cash = cash;
}

void Account::Show()
{

}

float Account::Withdraw(float cash)
{
	if (this->cash >= cash)
	{
		this->cash -= cash;
		return cash;
	}
	else
	{
		float cashBefore = this->cash;
		this->cash = 0;

		return cashBefore;
	}
}

void Account::Deposit(float cash)
{
	this->cash += cash;
}