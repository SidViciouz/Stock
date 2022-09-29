#pragma once

#include "stockOrder.h"
#include "data.h"

class StockOrders
{
	std::map<std::string, StockOrder*> stockOrders_;

public:
	void Make(OrderData orderData);
	void Print();
	void Execute();
};
