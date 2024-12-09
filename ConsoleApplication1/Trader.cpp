#include "Trader.h"
#include "Stock.h"
#include <iostream>

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

// get a Stock from portfolio vector
Stock Trader::get_from_portfolio(int position)
{
	return portfolio[position];
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

// constructs Trader with just balance passed in
Trader::Trader(double given_balance)
{
	name = "";
	balance = given_balance;
	portfolio = vector<Stock>();
}

// constructs Trader with everything passed in: a name, a balance, and a portfolio vector
Trader::Trader(string given_name, double given_balance, vector<Stock> given_portfolio)
{
	name = given_name;
	balance = given_balance;
	portfolio = given_portfolio;
}

// position valdiator for portfolio
bool Trader::validate_position(int position)
{
	if (portfolio.size() <= 0 || position < 0 || position > portfolio.size() - 1) {
		return false;
	}
	else {
		return true;
	}
}

// find position of a stock in a portfolio
int Trader::find_position_from_portfolio_stock(string given_symbol)
{
	// if portfolio is empty return -1 instantly
	if (portfolio.size() <= 0) {
		return -1;
	}
	// search portfolio
	int i = 0;
	while (i < portfolio.size()) {
		// return i position if portfolio has given stock already
		if (portfolio[i].get_symbol() == given_symbol) {
			return i;
		}
		i++;
	}
	// return -1 if portfolio does not have given stock already
	return -1;
}


// adders and removers

// add Stock to portfolio vector if portfolio does not have given stock already
bool Trader::add_to_portfolio(Stock given_stock)
{
	// search portfolio
	int i = 0;
	while (i < portfolio.size() - 1) {
		// return false if portfolio has given stock already
		if (&portfolio[i] == &given_stock) {
			return false;
		}
		i++;
	}
	portfolio.push_back(given_stock);
	// return true if portfolio does not have given stock already
	return true;
}

// remove Stock from portfolio vector
void Trader::remove_from_portfolio(int position)
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

// change quantity of a portfolio stock
void Trader::change_quantity_from_portfolio_stock(int position, int given_quantity)
{
	portfolio[position].set_used_quantity(given_quantity);
}

// sell Stock from portfolio vector given quantity and position
bool Trader::sell_from_portfolio(int position, int given_quantity)
{
	// use stock messing with from position
	Stock stock_messing_with = get_from_portfolio(position);
	// if given quantity is less than 0 or greater than current used quantity
	if (given_quantity <= 0 || given_quantity > stock_messing_with.get_used_quantity()) {
		// return false as this is not possible
		return false;
	}
	// set stock cost based on that price and quantity
	int stock_cost = stock_messing_with.get_price() * given_quantity;
	// subtract from used quantity in stock by given quantity
	portfolio[position].set_used_quantity(stock_messing_with.get_used_quantity() - given_quantity);
	// remove stock from portfolio if necessary
	if (portfolio[0].get_used_quantity() == 0) {
		remove_from_portfolio(position);
	}
	// add stock cost to user balance
	balance += stock_cost;
	// return true as this is possible
	return true;
}

// sell Stock from stock market portfolio vector given quantity and position (does not alter balance or remove stocks)
bool Trader::sell_from_stock_market(int position, int given_quantity)
{
	// use stock messing with from position
	Stock stock_messing_with = get_from_portfolio(position);
	// if given quantity is less than 0 or greater than current used quantity
	if (given_quantity <= 0 || given_quantity > stock_messing_with.get_used_quantity()) {
		// return false as this is not possible
		return false;
	}
	// set stock cost based on that price and quantity
	int stock_cost = stock_messing_with.get_price() * given_quantity;
	// subtract from used quantity in stock by given quantity
	portfolio[position].set_used_quantity(stock_messing_with.get_used_quantity() - given_quantity);
	// return true as this is possible
	return true;
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