#include "stockOrder.h"
#include "data.h"
#include <cmath>

void StockOrder::Make(OrderData orderData)
{
	if (orderData.deal == BUY)
	{
		stockToBuy->Increase(orderData.price, orderData.number);
		orderInfosForBuying->Make(orderData.accountNumber, orderData.number);
	}
	else
	{
		stockToSell->Increase(orderData.price, orderData.number);
		orderInfosForSelling->Make(orderData.accountNumber, orderData.number);
	}
}

StockOrder::StockOrder(std::string name)
{
	this->name = name;
	stockToBuy = new Stock(name);
	stockToSell = new Stock(name);
	orderInfosForBuying = new OrderInfos();
	orderInfosForSelling = new OrderInfos();
}

StockOrder::~StockOrder()
{
	delete stockToBuy;
	delete stockToSell;
	delete orderInfosForBuying;
	delete orderInfosForSelling;
}

void StockOrder::Print()
{
	stockToBuy->Print();
	stockToSell->Print();
	orderInfosForBuying->Print();
	orderInfosForSelling->Print();
	printf("\n");
}

void StockOrder::Execute()
{
	bool Executed = false;

	for (auto it = stockToBuy->GetPriceToNumberBegin();
		it != stockToBuy->GetPriceToNumberEnd();)
	{
		Executed = false;
		for (auto jt = stockToSell->GetPriceToNumberBegin();
			jt != stockToSell->GetPriceToNumberEnd();)
		{
			if (fabs(it->first-jt->first) < 0.00001)
			{
				printf("Transaction Executed!!!\n");
				int smaller = it->second < jt->second ? it->second : jt->second;

				//더 작은 것 만큼 decrease.
				it = stockToBuy->Decrease(it->first, smaller);
				jt = stockToSell->Decrease(jt->first, smaller);

				//orderInfosForBuying and selling에서도 개수 맞게 차감.
				orderInfosForBuying->Decrease(smaller);
				orderInfosForSelling->Decrease(smaller);

				Executed = true;

				break;
			}
			else
				jt++;
			
		}
		if (!Executed)
			it++;
	}
}