#include "stockOrder.h"
#include "data.h"

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
}