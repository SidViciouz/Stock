#include "orderInfo.h"

OrderInfo::OrderInfo(int orderOwner, int number)
{
	this->orderOwner = orderOwner;
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
