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
	std::map<float, int>::iterator Decrease(float price, int number);
	void Print();
	std::map<float,int>::iterator GetPriceToNumberBegin();
	std::map<float, int>::iterator GetPriceToNumberEnd();
};
