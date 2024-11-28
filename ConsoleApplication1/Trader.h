#pragma once
#include <string>
#include <vector>
#include "Stock.h"
using namespace std;
class Trader
{
public:
// getters
	string get_name(); // gets Trader's name
	double get_balance(); // gets Trader's balance
	vector<Stock> get_portfolio(); // gets Trader's portfolio
// setters
	void set_name(string given_name); // sets Trader's name
	void set_balance(double given_balance); // sets balance of Trader
	void set_portfolio(vector<Stock> given_portfolio); // sets portfolio of Trader
// constructors
	Trader(); // constructs Trader with no parameters, default setting name to an empty string, balance to null, and portfolio to an empty vector
	Trader(string given_name); // constructs Trader with a passed in name, null balance, and empty vector portfolio
	Trader(string given_name, double given_balance, vector<Stock> given_portfolio); // constructs Trader with everything passed in: a name, a balance, and a portfolio vector
// adders and removers
	void add_to_portfolio(Stock given_stock); // add Stock to portfolio vector
	void sell_from_portfolio(int position); // remove Stock from portfolio vector
	
private:
	// main variables
	string name; // Trader's name
	double balance; // how much money Trader has
	vector<Stock> portfolio; // how many Stocks Trader has in portfolio
};

