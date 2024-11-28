#pragma once
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Stock
{
public:
	// getters
	string get_symbol();
	double get_price();
	unordered_map<string, int> get_attributes();
	// setters
	void set_symbol(string given_symbol);
	void set_price(double given_price);
	void set_attributes(unordered_map<string, int> given_attributes);
	// constructors


private:
	string symbol;
	double price;
	unordered_map<string, int> attributes;
};

