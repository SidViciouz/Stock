#pragma once
#include <string>

class OrderInfo
{
	int orderOwner;
	float price;
	int number;

public:
	OrderInfo() = delete;
	OrderInfo(int orderOwner,float price, int number);
	void Print();
	int Decrease(int number);
	int GetOrderOwner();
	float GetPrice();
};
