#include "Trader.h"

string Trader::get_name()
{
	return name;
}

double Trader::get_balance()
{
	return balance;
}

vector<string> Trader::get_portfolio()
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

void Trader::set_portfolio(vector<string> given_portfolio)
{
	portfolio = given_portfolio;
}

Trader::Trader(string name)
{
	name = name;
	balance = NULL;
	portfolio = vector<string>();
}

Trader::Trader(string given_name, double given_balance, vector<string> given_portfolio)
{
	name = name;
	balance = balance;
	portfolio = portfolio;
}
