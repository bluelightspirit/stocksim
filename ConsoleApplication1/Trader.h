#pragma once
#include <string>
#include <vector>
#include "Stock.h"
using namespace std;
class Trader
{
public:
// getters
	string get_name();
	double get_balance();
	vector<Stock> get_portfolio();
// setters
	void set_name(string given_name);
	void set_balance(double given_balance);
	void set_portfolio(vector<Stock> given_portfolio);
// constructors
	Trader();
	Trader(string given_name);
	Trader(string given_name, double given_balance, vector<Stock> given_portfolio);
// adders
	void add_to_portfolio(Stock given_stock);
	
private:
	// main variables
	string name;
	double balance;
	vector<Stock> portfolio;
};

