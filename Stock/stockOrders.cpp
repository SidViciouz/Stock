#include "stockOrders.h"

void StockOrders::Make(OrderData orderData)
{
	if (stockOrders_.find(orderData.name) == stockOrders_.end())
	{
		stockOrders_.insert({ orderData.name,new StockOrder(orderData.name)}); // 언제 삭제?
	}

	stockOrders_[orderData.name]->Make(orderData);
}

void StockOrders::Print()
{
	for (auto stockOrder_ : stockOrders_)
	{
		stockOrder_.second->Print();
	}
}

void StockOrders::Execute()
{
	for (auto stockOrder_ : stockOrders_)
	{
		stockOrder_.second->Execute();
	}
}