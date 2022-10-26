#include "stockOrder.h"
#include "data.h"
#include <cmath>

void StockOrder::Make(OrderData orderData)
{
	if (orderData.deal == BUY)
	{
		stockToBuy->Increase(orderData.price, orderData.number);
		orderInfosForBuying->Make(orderData.accountNumber,orderData.price, orderData.number);
	}
	else
	{
		stockToSell->Increase(orderData.price, orderData.number);
		orderInfosForSelling->Make(orderData.accountNumber,orderData.price, orderData.number);
	}
}

StockOrder::StockOrder(std::string name, Accounts& accounts_):
	accounts_{accounts_}
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
	printf("[buy order]\n");
	stockToBuy->Print();
	printf("\n");
	printf("[sell order]\n");
	stockToSell->Print();
	printf("\n");
	printf("[buyer information]\n");
	orderInfosForBuying->Print();
	printf("\n");
	printf("[seller information]\n");
	orderInfosForSelling->Print();
	printf("\n");
	printf("--------------------------------------------");
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
			if (fabs(it->first-jt->first) < 0.001)
			{
				printf("Transaction Executed!!!\n");
				int smaller = it->second < jt->second ? it->second : jt->second;

				//거래될 수 있는지 다시 check. (수정1)

				//더 작은 것 만큼 decrease.
				it = stockToBuy->Decrease(it->first, smaller);
				jt = stockToSell->Decrease(jt->first, smaller);

				//orderInfosForBuying and selling에서도 개수 맞게 차감.
				//orderInfos에서 거래 당사자들의 계좌를 얻은 후에 (decrease에서 배열 또는 벡터로 반환하게 해야함) (수정2)
				std::vector<OrderData> buyerDatas = orderInfosForBuying->Decrease(smaller);
				std::vector<OrderData> sellerDatas = orderInfosForSelling->Decrease(smaller);

				//accounts에서 minus, add 해줌. (수정3)
				for (auto buyerData : buyerDatas)
				{
					accounts_.Minus(buyerData.accountNumber, buyerData.price * buyerData.number);
					accounts_.Add(buyerData.accountNumber,name,buyerData.number);
				}

				for (auto sellerData : sellerDatas)
				{
					accounts_.Add(sellerData.accountNumber,sellerData.price * sellerData.number);
					accounts_.Minus(sellerData.accountNumber,name,sellerData.number);
				}

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