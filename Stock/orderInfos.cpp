#include "orderInfos.h"

void OrderInfos::Make(int orderOwner, int number)
{
	orderInfos.push_back(new OrderInfo(orderOwner, number));
}