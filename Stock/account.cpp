#include "account.h"

Account::Account(int accountNumber,float cash) {
	this->accountNumber = accountNumber;
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

void Account::Print()
{
	printf("Account Number : %d\n", accountNumber);
	printf("Cash : %d\n", cash);
	stocks.Print();
	printf("\n");
}

bool Account::CanAfford(OrderData orderData)
{
	if (orderData.deal == BUY)
	{
		if (cash >= orderData.price * orderData.number)
			return true;
		else
			return false;
	}
	else
	{
		if (stocks.GetNumber(orderData.name) < orderData.number)
			return false;
		else
			return true;
	}
}

void Account::DepositStock(std::string name, int number)
{
	stocks.Increase(name, number);
}
void Account::WithdrawStock(std::string name, int number)
{
	stocks.Decrease(name, number);
}