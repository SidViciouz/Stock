#include "orderInfos.h"

void OrderInfos::Make(int orderOwner,float price, int number)
{
	orderInfos_.push_back(new OrderInfo(orderOwner,price, number));
}

void OrderInfos::Print()
{
	for (auto Info : orderInfos_)
	{
		Info->Print();
	}
}

std::vector<OrderData> OrderInfos::Decrease(int number)
{
	std::vector<OrderData> returnOrderDatas;

	for (auto it = orderInfos_.begin(); it != orderInfos_.end(); )
	{
		int previousNumber = number;
		number = (*it)->Decrease(number);


		if (number == -1)
		{
			returnOrderDatas.push_back({ BUY,(*it)->GetPrice(),previousNumber,(*it)->GetOrderOwner(),"" });
			break;
		}
		else if(number == 0)
		{
			returnOrderDatas.push_back({ BUY,(*it)->GetPrice(),previousNumber,(*it)->GetOrderOwner(),"" });
			delete (*it);
			orderInfos_.erase(it);
			break;
		}
		else
		{
			returnOrderDatas.push_back({ BUY,(*it)->GetPrice(),previousNumber-number,(*it)->GetOrderOwner(),"" });
			delete (*it);
			it = orderInfos_.erase(it);
		}
	}

	return returnOrderDatas;
}