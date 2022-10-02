#include "stock.h"

int Stock::Increase(float price, int number)
{
	priceToNumber[price] += number;

	return number;
}

std::map<float,int>::iterator Stock::Decrease(float price, int number)
{
	int left = priceToNumber[price];
	auto it = priceToNumber.find(price);

	if (left > number)
	{
		priceToNumber[price] -= number;
		it++;

		return it;
	}
	else
	{
		priceToNumber.erase(it++);
		//priceToNumber[price] = 0;
		return it;
	}

	//거래가 체결되면 이 함수가 실행되므로 주식이 0이 되면 
	//priceToNumber에서 해당 price를 지워주는 것도 여기서 해야함.
}

Stock::Stock(std::string name)
{
	this->name = name;
}


void Stock::Print()
{
	if (priceToNumber.size() != 0)
	{
		printf("%s : ", name.c_str());
		for (auto e : priceToNumber)
		{
			printf("[%f,%d], ", e.first, e.second);
		}
		printf("\n");
	}
}

std::map<float, int>::iterator Stock::GetPriceToNumberBegin()
{
	return priceToNumber.begin();
}

std::map<float, int>::iterator Stock::GetPriceToNumberEnd()
{
	return priceToNumber.end();
}
