#pragma once
#include <string>
#include <vector>
#include <map>
class Trader; // forward declaration of Trader class so include isn't needed (include had breaking problems before)
using namespace std;
// the Stock class represents a thing traders can buy and sell worth a certain price that could go up or down
class Stock
{
public:
	// getters
	string get_symbol(); // gets symbol of Stock
	double get_price(); // gets price of Stock
	map<Trader*, int> get_attributes(); // gets attributes of Stock
	int get_max_quantity(); // gets max quantity of Stock
	int get_attributes_simplified(Trader * given_trader); // gets quantity of Stock given a trader
	// setters
	void set_symbol(string given_symbol); // sets symbol of Stock
	void set_price(double given_price); // sets price of Stock
	void set_attributes(map<Trader*, int> given_attributes); // sets attributes of Stock (literal)
	void set_random_price(); // sets random price of Stock
	void set_max_quantity(int given_max_quantity); // sets max quantity of stock
	void set_random_max_quantity(); // sets random max quantity of stock
	bool set_attributes_simplified(Trader* given_trader, int given_quantity); // sets attributes of Stock (simplified)
	// constructors
	Stock(); // constructs an empty Stock with a null price, empty string, and empty attributes vector
	Stock(string given_symbol); // constructs a mostly empty Stock with the passed in symbol, null price, and empty attributes vector
	Stock(double given_price); // constructs a Stock with an empty string, the passed in price, and empty attributes vector
	Stock(double given_price, map<Trader*, int> given_attributes); // constructs a Stock with an empty String, the passed in price, and passed in attributes vector
	Stock(string given_symbol, double given_price, map<Trader*, int> given_attributes, int given_max_quantity, int given_used_quantity); // constructs a Stock given a symbol, attributes, and max quantity all passed in

private:
	string symbol; // symbol of Stock can be interpreted like a name (empty string is set if not set)
	double price; // price of Stock can be interpreted as how much stock is worth (set to null if not set)
	map<Trader*, int> attributes; // attributes of Stock can be interpreted as a quantity-trader map (empty map is set if not set) - non-pointer Trader gives error to access the map
	int max_quantity; // max quantity stock can be bought (set to null if not set)
	int current_used_quantity; // current quantity stock being used (default 0)
};
