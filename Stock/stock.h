#pragma once

#include <iostream>
#include <map>

class Stock
{
	std::string name;
	std::map<float, int> priceToNumber;

public:
	int Increase(float price, int number);
	int Decrease(float price, int number);
};
