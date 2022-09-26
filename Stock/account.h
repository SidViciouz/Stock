#pragma once
#include "stocks.h"
#include <string>

class Account
{
	float cash; //보유중인 현금
	Stocks& stocks; // 보유중인 주식

public:
	Account() = delete;
	Account(Stocks& stocks,float cash);
	void Show();
	float Withdraw(float cash);
	void Deposit(float cash);
};