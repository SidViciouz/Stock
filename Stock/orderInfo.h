#pragma once
#include <string>

class OrderInfo
{
	int orderOwner;
	int number;

public:
	OrderInfo() = delete;
	OrderInfo(int orderOwner, int number);
};
