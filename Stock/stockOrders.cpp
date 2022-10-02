#include "stockOrders.h"

StockOrders::StockOrders(Accounts& accounts_):
	accounts_{accounts_}
{

}

void StockOrders::Make(OrderData orderData)
{
	if (stockOrders_.find(orderData.name) == stockOrders_.end())
	{
		stockOrders_.insert({ orderData.name,new StockOrder(orderData.name,accounts_)}); // 언제 삭제?
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