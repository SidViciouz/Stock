#include "stockOrders.h"

void StockOrders::Make(OrderData orderData)
{
	stockOrders[orderData.name]->Make(orderData);
}