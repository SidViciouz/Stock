#include "accounts.h"

void Accounts::Add(int accountNumber, float cash)
{
	if(accounts.find(accountNumber) == accounts.end())
	{
		accounts.insert({ accountNumber,new Account(accountNumber,cash) });
	}
	else
	{
		accounts[accountNumber]->Deposit(cash);
	}
}

void Accounts::Add(int accountNumber, std::string name, int number)
{
	if (accounts.find(accountNumber) == accounts.end())
	{
		accounts.insert({ accountNumber,new Account(accountNumber,0) });
	}
	
	accounts[accountNumber]->DepositStock(name, number);
	
}

void Accounts::Minus(int accountNumber, float cash)
{
	if (accounts.find(accountNumber) == accounts.end())
	{
		return;
	}

	accounts[accountNumber]->Withdraw(cash);
	
}

void Accounts::Minus(int accountNumber, std::string name, int number)
{
	if (accounts.find(accountNumber) == accounts.end())
	{
		return;
	}

	accounts[accountNumber]->WithdrawStock(name, number);

}

bool Accounts::Sending(int sourceNumber,int targetNumber,float cash)
{
	float withdrawedCash = accounts[sourceNumber]->Withdraw(cash);
	accounts[targetNumber]->Deposit(withdrawedCash);

	return true;
}

void Accounts::Print()
{
	for (auto account : accounts)
	{
		account.second->Print();
	}
}

bool Accounts::CanAfford(OrderData orderData)
{
	return accounts[orderData.accountNumber]->CanAfford(orderData);
}