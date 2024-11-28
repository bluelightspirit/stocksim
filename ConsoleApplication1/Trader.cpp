#include "Trader.h"
#include "Stock.h"

string Trader::get_name()
{
	return name;
}

double Trader::get_balance()
{
	return balance;
}

vector<Stock> Trader::get_portfolio()
{
	return portfolio;
}

void Trader::set_name(string given_name)
{
	name = given_name;
}

void Trader::set_balance(double given_balance)
{
	balance = given_balance;
}

void Trader::set_portfolio(vector<Stock> given_portfolio)
{
	portfolio = given_portfolio;
}

Trader::Trader()
{
	name = "";
	balance = NULL;
	portfolio = vector<Stock>();
}

Trader::Trader(string given_name)
{
	name = given_name;
	balance = NULL;
	portfolio = vector<Stock>();
}

Trader::Trader(string given_name, double given_balance, vector<Stock> given_portfolio)
{
	name = given_name;
	balance = given_balance;
	portfolio = given_portfolio;
}

void Trader::add_to_portfolio(Stock given_stock)
{
	portfolio.push_back(given_stock);
}

void Trader::sell_from_portfolio(int position)
{
	if (portfolio.size() - 1 < 0) {
		portfolio.pop_back();
		return;
	}
	if (portfolio.size() - 1 == position) {
		portfolio.pop_back();
		return;
	}
	Stock end = portfolio[portfolio.size() - 1];
	Stock pos = portfolio[position];
	portfolio[position] = end;
	portfolio.pop_back();
}