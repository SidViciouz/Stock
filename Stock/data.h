#pragma once

#include <string>

enum DEAL
{
	BUY,
	SELL,
	SHOW
};

struct OrderData
{
	DEAL deal;
	float price;
	int number;
	int accountNumber;
	std::string name;

	void Print()
	{
		if (deal == BUY)
			printf("BUY ");
		else
			printf("SELL ");
		printf("%f %d %d %s\n", price, number, accountNumber, name.c_str());
	}
};