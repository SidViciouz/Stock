#pragma once
#include "account.h"
#include <map>

class Accounts
{
	std::map<int, Account*> accounts; // 계좌번호와 그에 해당하는 계좌

public:
	bool Sending(int sourceNumber,int targetNumber,float cash); //계좌간 송금
};