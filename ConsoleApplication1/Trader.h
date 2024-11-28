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
	
private:
	string name;
	double balance;
	vector<string> portfolio;
};

