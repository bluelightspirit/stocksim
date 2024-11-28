#pragma once
#include <string>
#include <vector>
using namespace std;
class Trader
{
public:
// getters
	string get_name();
	double get_balance();
	vector<string> get_portfolio();
// setters
	void set_name(string given_name);
	void set_balance(double given_balance);
	void set_portfolio(vector<string> given_portfolio);
// constructors
	Trader(string given_name);
	Trader(string given_name, double given_balance, vector<string> given_portfolio);
	
private:
	// main variables
	string name;
	double balance;
	vector<string> portfolio;
};

