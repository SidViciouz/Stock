#include "stocks.h"

void Stocks::Increase(std::string name, int number)
{
	if (stocks.find(name) == stocks.end())
	{
		stocks.insert({ name,new Stock(name) });
	}
	stocks[name]->Increase(0,number);
}
void Stocks::Decrease(std::string name, int number)
{
	if (stocks.find(name) == stocks.end())
	{
		return;
	}

	stocks[name]->Decrease(0,number);
}

void Stocks::Print()
{
	for (auto stock : stocks)
	{
		stock.second->Print();
	}
}

int Stocks::GetNumber(std::string name)
{
	if (stocks.find(name) == stocks.end())
	{
		return 0;
	}

	return stocks[name]->GetPriceToNumber(0);
}