#pragma once
#include "stock.h"
#include <map>
#include <string>

class Stocks
{
	std::map<std::string, Stock> stocks; //주식이름과 그에 해당하는 주식

public:
	int Increase();
	int Decrease();
};
