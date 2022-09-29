#pragma once

#include <iostream>
#include <map>

class Stock
{
	std::string name;
	std::map<float, int> priceToNumber;

public:
	Stock(std::string name);
	int Increase(float price, int number);
	int Decrease(float price, int number);
	void Print();
};
