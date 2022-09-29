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