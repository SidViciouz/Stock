#include "trading.h"

Trading::Trading(StockOrders& stockOrders): stockOrders{stockOrders}
{

}

void Trading::MakeOrder(OrderData orderData)
{
	stockOrders.Make(orderData);
}

void Trading::DeleteOrder(OrderData orderData)
{

}


