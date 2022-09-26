#pragma once
#include "stockOrders.h"
#include "data.h"

class Trading
{
	StockOrders& stockOrders;

public:
	Trading(StockOrders& stockOrders);
	void MakeOrder(OrderData orderData);
	void DeleteOrder(OrderData orderData);
};