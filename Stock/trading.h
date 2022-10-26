#pragma once
#include "stockOrders.h"
#include "data.h"
#include "accounts.h"

class Trading
{
	StockOrders* stockOrders_;
	Accounts& accounts_;

public:
	Trading() = delete;
	Trading(Accounts& accounts_);
	~Trading();
	void MakeOrder(OrderData orderData);
	void DeleteOrder(OrderData orderData);
	void Print();
	void OrderExecute();
	void PrintAccount();
};