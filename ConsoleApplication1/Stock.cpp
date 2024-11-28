#include "Stock.h"

string Stock::get_symbol()
{
	return symbol;
}

double Stock::get_price()
{
	return price;
}

unordered_map<string, int> Stock::get_attributes()
{
	return attributes;
}

void Stock::set_symbol(string given_symbol)
{
	symbol = given_symbol;
}

void Stock::set_price(double given_price)
{
	price = given_price;
}

void Stock::set_attributes(unordered_map<string, int> given_attributes)
{
	attributes = given_attributes;
}

void Stock::set_random_price()
{
	price = rand();
}

Stock::Stock()
{
	symbol = "";
	price = NULL;
	attributes = unordered_map<string, int>();
}


Stock::Stock(double given_price)
{
	symbol = "";
	price = given_price;
	attributes = unordered_map<string, int>();
}

Stock::Stock(double given_price, unordered_map<string, int> given_attributes)
{
	symbol = "";
	price = given_price;
	attributes = given_attributes;
}

Stock::Stock(string given_symbol, double given_price, unordered_map<string, int> given_attributes)
{
	symbol = given_symbol;
	price = given_price;
	attributes = given_attributes;
}
