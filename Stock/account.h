#pragma once
#include "stocks.h"
#include "data.h"
#include <string>

class Account
{
	float cash; //보유중인 현금
	Stocks stocks; // 보유중인 주식
	int accountNumber;

public:
	Account() = delete;
	Account(int accountNumber,float cash);
	void Show();
	float Withdraw(float cash);
	void Deposit(float cash);
	void Print();
	bool CanAfford(OrderData orderData);
	void DepositStock(std::string name, int number);
	void WithdrawStock(std::string name, int number);
};