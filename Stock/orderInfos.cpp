#include "orderInfos.h"

void OrderInfos::Make(int orderOwner, int number)
{
	orderInfos_.push_back(new OrderInfo(orderOwner, number));
}

void OrderInfos::Print()
{
	for (auto Info : orderInfos_)
	{
		Info->Print();
	}
}