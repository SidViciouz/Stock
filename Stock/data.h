#pragma once

#include <string>

enum DEAL
{
	BUY,
	SELL
};

struct OrderData
{
	DEAL deal;
	float price;
	int number;
	int accountNumber;
	std::string name;
};