#pragma once

#include "stockOrder.h"
#include "data.h"
#include "accounts.h"

class StockOrders
{
	std::map<std::string, StockOrder*> stockOrders_;
	Accounts& accounts_;

public:
	StockOrders(Accounts& accounts_);
	void Make(OrderData orderData);
	void Print();
	void Execute();
};
