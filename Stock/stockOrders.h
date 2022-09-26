#pragma once

#include "stockOrder.h"
#include "data.h"

class StockOrders
{
	std::map<std::string, StockOrder*> stockOrders;

public:
	void Make(OrderData orderData);
};
