#include "Stock.h"

// getters

// gets symbol of Stock
string Stock::get_symbol()
{
	return symbol;
}

// gets price of Stock
double Stock::get_price()
{
	return price;
}

// gets attributes of Stock
unordered_map<string, int> Stock::get_attributes()
{
	return attributes;
}

// setters

// sets symbol of Stock
void Stock::set_symbol(string given_symbol)
{
	symbol = given_symbol;
}

// sets price of Stock
void Stock::set_price(double given_price)
{
	price = given_price;
}

// sets attributes of Stock
void Stock::set_attributes(unordered_map<string, int> given_attributes)
{
	attributes = given_attributes;
}

// sets random price of Stock
void Stock::set_random_price()
{
	set_price(rand());
}

// constructors

// constructs an empty Stock with a null price, empty string, and empty attributes vector
Stock::Stock()
{
	symbol = "";
	price = NULL;
	attributes = unordered_map<string, int>();
}

// constructs a mostly empty Stock with the passed in symbol, null price, and empty attributes vector
Stock::Stock(string given_symbol)
{
	symbol = given_symbol;
	price = NULL;
	attributes = unordered_map<string, int>();
}

// constructs a Stock with an empty string, the passed in price, and empty attributes vector
Stock::Stock(double given_price)
{
	symbol = "";
	price = given_price;
	attributes = unordered_map<string, int>();
}

// constructs a Stock with an empty String, the passed in price, and passed in attributes vector
Stock::Stock(double given_price, unordered_map<string, int> given_attributes)
{
	symbol = "";
	price = given_price;
	attributes = given_attributes;
}

// constructs a Stock given a symbol, price, and attributes all passed in
Stock::Stock(string given_symbol, double given_price, unordered_map<string, int> given_attributes)
{
	symbol = given_symbol;
	price = given_price;
	attributes = given_attributes;
}
