#include "trading.h"

Trading::Trading(Accounts& accounts_):
	accounts_{accounts_}
{
	stockOrders_ = new StockOrders();
}
Trading::~Trading()
{
	delete stockOrders_;
}

void Trading::MakeOrder(OrderData orderData)
{
	if (accounts_.CanAfford(orderData))
	{
		stockOrders_->Make(orderData);
	}
}

void Trading::DeleteOrder(OrderData orderData)
{

}

void Trading::Print()
{
	stockOrders_->Print();
}

void Trading::OrderExecute()
{
	stockOrders_->Execute();
}


