#pragma once
#include "stock.h"
#include <map>
#include <string>

class Stocks
{
	std::map<std::string, Stock*> stocks; //주식이름과 그에 해당하는 주식

public:
	void Increase(std::string name,int number);
	void Decrease(std::string name,int number);
	void Print();
	int GetNumber(std::string name);
};
