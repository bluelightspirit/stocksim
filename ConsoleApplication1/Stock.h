#pragma once
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Stock
{
public:
	// getters
	string get_symbol(); // gets symbol of Stock
	double get_price(); // gets price of Stock
	unordered_map<string, int> get_attributes(); // gets attributes of Stock
	// setters
	void set_symbol(string given_symbol); // sets symbol of Stock
	void set_price(double given_price); // sets price of Stock
	void set_attributes(unordered_map<string, int> given_attributes); // sets attributes of Stock
	void set_random_price(); // sets random price of Stock
	// constructors
	Stock(); // constructs an empty Stock with a null price, empty string, and empty attributes vector
	Stock(string given_symbol); // constructs a mostly empty Stock with the passed in symbol, null price, and empty attributes vector
	Stock(double given_price); // constructs a Stock with an empty string, the passed in price, and empty attributes vector
	Stock(double given_price, unordered_map<string, int> given_attributes); // constructs a Stock with an empty String, the passed in price, and passed in attributes vector
	Stock(string given_symbol, double given_price, unordered_map<string, int> given_attributes); // constructs a Stock given a symbol, price, and attributes all passed in

private:
	string symbol; // symbol of Stock can be interpreted like a name
	double price; // price of Stock can be interpreted as how much stock is worth
	unordered_map<string, int> attributes; // attributes of Stock can be interpreted as some more specifics about the stock
};

