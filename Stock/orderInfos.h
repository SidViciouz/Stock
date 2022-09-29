#pragma once
#include "orderInfo.h"
#include <vector>

class OrderInfos
{
	std::vector<OrderInfo*> orderInfos_;
	
public:
	void Make(int orderOwner, int number);
	void Print();
	void Decrease(int number);
};