#pragma once
#include "orderInfo.h"
#include "data.h"
#include <vector>

class OrderInfos
{
	std::vector<OrderInfo*> orderInfos_;
	
public:
	void Make(int orderOwner,float price, int number);
	void Print();
	std::vector<OrderData> Decrease(int number);
};