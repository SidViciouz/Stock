#include "trading.h"

Trading::Trading()
{
	stockOrders_ = new StockOrders();
}
Trading::~Trading()
{
	delete stockOrders_;
}

void Trading::MakeOrder(OrderData orderData)
{
	stockOrders_->Make(orderData);
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

}


