#pragma once
#include "stock.h"
#include "data.h"
#include "orderInfos.h"
#include "accounts.h"

class StockOrder
{
	std::string name;
	Stock* stockToSell;
	Stock* stockToBuy;
	OrderInfos* orderInfosForSelling;
	OrderInfos* orderInfosForBuying;
	Accounts& accounts_;

public:
	void Make(OrderData orderData);
	StockOrder(std::string name,Accounts& accounts_);
	~StockOrder();
	void Print();
	void Execute();
};