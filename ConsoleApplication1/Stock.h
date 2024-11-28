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
	void set_random_price();
	// constructors
	Stock();
	Stock(string given_symbol);
	Stock(double given_price);
	Stock(double given_price, unordered_map<string, int> given_attributes);
	Stock(string given_symbol, double given_price, unordered_map<string, int> given_attributes);

private:
	string symbol;
	double price;
	unordered_map<string, int> attributes;
};

