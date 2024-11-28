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
