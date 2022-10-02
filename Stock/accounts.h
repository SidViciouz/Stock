#pragma once
#include "account.h"
#include <map>

class Accounts
{
	std::map<int, Account*> accounts; // 계좌번호와 그에 해당하는 계좌

public:
	void Add(int accountNumber, float cash);
	void Add(int accountNumber, std::string name, int number);
	void Minus(int accountNumber, float cash);
	void Minus(int accountNumber, std::string name, int number);
	bool Sending(int sourceNumber,int targetNumber,float cash); //계좌간 송금
	void Print();
	bool CanAfford(OrderData orderData);
};