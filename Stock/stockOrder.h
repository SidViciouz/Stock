#pragma once
#include "stock.h"
#include "data.h"
#include "orderInfos.h"

class StockOrder
{
	std::string name;
	Stock* stockToSell;
	Stock* stockToBuy;
	OrderInfos* orderInfosForSelling;
	OrderInfos* orderInfosForBuying;

public:
	void Make(OrderData orderData);
	StockOrder(std::string name);
	~StockOrder();
	void Print();
	void Execute();
};