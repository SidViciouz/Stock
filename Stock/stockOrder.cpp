#include "stockOrder.h"
#include "data.h"

void StockOrder::Make(OrderData orderData)
{
	if (orderData.deal == BUY)
	{
		stockToBuy.Increase(orderData.price, orderData.number);
		orderInfosForBuying.Make(orderData.accountNumber, orderData.number);
	}
	else
	{
		stockToSell.Increase(orderData.price, orderData.number);
		orderInfosForSelling.Make(orderData.accountNumber, orderData.number);
	}
}
