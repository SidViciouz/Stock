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