#include "Stock.h"
#include "Trader.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

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
map<string, double> Stock::get_attributes()
{
	return attributes;
}

// gets max quantity of Stock
int Stock::get_max_quantity()
{
	return max_quantity;
}

// gets used quantity of Stock
int Stock::get_used_quantity()
{
	return current_used_quantity;
}

// gets price based on current used quantity
double Stock::get_used_quantity_price()
{
	return current_used_quantity*price;
}

// gets price based on max quantity
double Stock::get_max_quantity_price()
{
	return max_quantity*price;
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

// sets attributes of Stock (literal)
void Stock::set_attributes(map<string, double> given_attributes)
{
	attributes = given_attributes;
}

// sets random price of Stock
void Stock::set_random_price()
{
	set_price(rand());
}

// sets max quantity of Stock
void Stock::set_max_quantity(int given_max_quantity)
{
	max_quantity = given_max_quantity;
}

// sets random max quantity of Stock
void Stock::set_random_max_quantity()
{
	set_max_quantity(rand() % 100 + 1);
}

// sets used quantity of Stock
void Stock::set_used_quantity(int given_current_used_quantity)
{
	current_used_quantity = given_current_used_quantity;
}

// sets attributes of Stock (simplistic) - inserts into attributes given an action and strength
void Stock::set_attributes_simplistic(string given_action, double given_strength) {
	attributes.insert({ given_action, given_strength });
}

// constructors

// constructs an empty Stock with a null price, empty string, and empty attributes vector
Stock::Stock()
{
	symbol = "";
	price = NULL;
	attributes = map<string, double>();
	max_quantity = NULL;
	current_used_quantity = 0;
}

// constructs a mostly empty Stock with the passed in symbol, null price, and empty attributes vector
Stock::Stock(string given_symbol)
{
	symbol = given_symbol;
	price = NULL;
	attributes = map<string, double>();
	max_quantity = NULL;
	current_used_quantity = 0;
}

// constructs a Stock with an empty string, the passed in price, and empty attributes map
Stock::Stock(double given_price)
{
	symbol = "";
	price = given_price;
	attributes = map<string, double>();
	max_quantity = NULL;
	current_used_quantity = 0;
}

// constructs a Stock with an empty String, the passed in price, and passed in attributes map
Stock::Stock(double given_price, map<string, double> given_attributes)
{
	symbol = "";
	price = given_price;
	attributes = given_attributes;
	max_quantity = NULL;
	current_used_quantity = 0;
}

Stock::Stock(string given_symbol, double given_price, map<string, double> given_attributes, int given_max_quantity, int given_used_quantity)
{
	symbol = given_symbol;
	price = given_price;
	attributes = given_attributes;
	max_quantity = given_max_quantity;
	current_used_quantity = given_used_quantity;
}