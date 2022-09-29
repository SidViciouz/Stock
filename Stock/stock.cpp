#include "stock.h"

int Stock::Increase(float price, int number)
{
	priceToNumber[price] += number;

	return number;
}

int Stock::Decrease(float price, int number)
{
	int left = priceToNumber[price];

	if (left > number)
	{
		priceToNumber[price] -= number;
		return number;
	}
	else
	{
		priceToNumber[price] = 0;
		return left;
	}
}

Stock::Stock(std::string name)
{
	this->name = name;
}


void Stock::Print()
{
	if (priceToNumber.size() != 0)
	{
		printf("%s : ", name.c_str());
		for (auto e : priceToNumber)
		{
			printf("[%f,%d], ", e.first, e.second);
		}
		printf("\n");
	}
}

std::map<float, int>::iterator Stock::GetPriceToNumberBegin()
{
	return priceToNumber.begin();
}

std::map<float, int>::iterator Stock::GetPriceToNumberEnd()
{
	return priceToNumber.end();
}
