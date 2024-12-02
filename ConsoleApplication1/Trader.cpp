#include "Trader.h"
#include "Stock.h"

// getters

// gets Trader's name
string Trader::get_name()
{
	return name;
}

// gets Trader's balance
double Trader::get_balance()
{
	return balance;
}

// gets Trader's portfolio
vector<Stock> Trader::get_portfolio()
{
	return portfolio;
}

// setters

// sets Trader's name
void Trader::set_name(string given_name)
{
	name = given_name;
}

// sets balance of Trader
void Trader::set_balance(double given_balance)
{
	balance = given_balance;
}

// sets portfolio of Trader
void Trader::set_portfolio(vector<Stock> given_portfolio)
{
	portfolio = given_portfolio;
}

// constructors

// constructs Trader with no parameters, default setting name to an empty string, balance to null, and portfolio to an empty vector
Trader::Trader()
{
	name = "";
	balance = NULL;
	portfolio = vector<Stock>();
}

// constructs Trader with a passed in name, null balance, and empty vector portfolio
Trader::Trader(string given_name)
{
	name = given_name;
	balance = NULL;
	portfolio = vector<Stock>();
}

// constructs Trader with everything passed in: a name, a balance, and a portfolio vector
Trader::Trader(string given_name, double given_balance, vector<Stock> given_portfolio)
{
	name = given_name;
	balance = given_balance;
	portfolio = given_portfolio;
}

// adders and removers

// add Stock to portfolio vector
void Trader::add_to_portfolio(Stock given_stock)
{
	portfolio.push_back(given_stock);
}

// remove Stock from portfolio vector
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

// withdraw certain amount of money removing from balance, return true if possible and successful, return false if not possible
bool Trader::withdraw(double amount)
{
	// store expected balance that subtracts amount from trader balance
	double expectedBalance = balance - amount;
	// if expected balance is >= 0, store the new balance and return true
	if (expectedBalance >= 0) {
		set_balance(expectedBalance);
		return true;
	}
	// else if expected balance is < 0, return false
	return false;
}

// deposit certain amount of money adding to balance
void Trader::deposit(double amount)
{
	set_balance(balance + amount);
}
