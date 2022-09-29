#pragma once
#include "stockOrders.h"
#include "data.h"

class Trading
{
	StockOrders* stockOrders_;

public:
	Trading();
	~Trading();
	void MakeOrder(OrderData orderData);
	void DeleteOrder(OrderData orderData);
	void Print();
	void OrderExecute();
};