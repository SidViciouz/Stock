#include "message.h"
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <iostream>

OrderData Message::GetOrderData(char* message)
{
	using namespace std;

	string input(message);
	vector<string> result;
	OrderData orderData_;

	boost::split(result, input, boost::is_any_of(" "));

	if (result.size() != 5)
	{
		if (result.size() == 1)
		{
			if (result[0] == "SHOW")
				orderData_.deal = SHOW;
		}

		return orderData_;
	}

	if (result[0] == "BUY")
		orderData_.deal = BUY;
	else
		orderData_.deal = SELL;
	
	sscanf_s(result[1].c_str(), "%f", &orderData_.price);
	sscanf_s(result[2].c_str(), "%d", &orderData_.number);
	sscanf_s(result[3].c_str(), "%d", &orderData_.accountNumber);
	
	orderData_.name = result[4];

	return orderData_;
}

/*
struct OrderData
{
	DEAL deal;
	float price;
	int number;
	int accountNumber;
	std::string name;
};
*/