#include "orderInfo.h"

OrderInfo::OrderInfo(int orderOwner,float price, int number)
{
	this->orderOwner = orderOwner;
	this->price = price;
	this->number = number;
}

void OrderInfo::Print()
{
	printf("owner : %d, number : %d\n", orderOwner, number);
}

int OrderInfo::Decrease(int number)
{
	if (this->number > number)
	{
		this->number -= number;
		return -1;
	}
	else
	{
		number -= this->number;
		this->number = 0;
		return number;
	}
}

int OrderInfo::GetOrderOwner()
{
	return orderOwner;
}

float OrderInfo::GetPrice()
{
	return price;
}