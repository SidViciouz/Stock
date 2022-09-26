#include "accounts.h"

bool Accounts::Sending(int sourceNumber,int targetNumber,float cash)
{
	float withdrawedCash = accounts[sourceNumber]->Withdraw(cash);
	accounts[targetNumber]->Deposit(withdrawedCash);

	return true;
}
