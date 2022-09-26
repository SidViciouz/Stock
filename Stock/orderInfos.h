#pragma once
#include "orderInfo.h"
#include <vector>

class OrderInfos
{
	std::vector<OrderInfo*> orderInfos;
	
public:
	void Make(int orderOwner, int number);
};