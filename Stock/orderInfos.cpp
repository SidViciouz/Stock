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

void OrderInfos::Decrease(int number)
{

	for (auto it = orderInfos_.begin(); it != orderInfos_.end(); )
	{
		number = (*it)->Decrease(number);
		if (number == -1)
			break;
		else if(number == 0)
		{
			delete (*it);
			orderInfos_.erase(it);
			break;
		}
		else
		{
			delete (*it);
			it = orderInfos_.erase(it);
		}
	}
}