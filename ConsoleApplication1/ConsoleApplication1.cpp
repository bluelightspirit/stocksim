// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <unordered_map>
#include "Stock.h"
#include "Trader.h"
using namespace std;

// needs and nice to haves brainstorming

// DONE: need global variables for stocks to buy, and access to them (displaying list of available stocks and buying stocks should link up together instead of being different)
// only the trader has to be global. the stocks within this trader can be local just part of the_stock_market's portfolio
Trader the_stock_market(-1);
// create stocks available on stock market

// !!!! deciding on using symbol as not possible to duplicate and to be used for search. searching objects isn't simplistic much vs Java
// DONE: need quantity options for stocks
// need total value for stocks
// need stock price simulation to fluctuate prices of stocks over time - attributes string int could be good for this such as doubling randomness or halving randomness
// PARTIALLY DONE: need selling stock to add to balance
// need unordered_map of Stock to consider allowing traders as one part and number of stocks they have as another part. so no more <string, int> instead <Trader, int>
// need get method for getting trader name and number of stocks they have
// need get method for getting all traders and stocks they have
// need change method for changing number of stock units a trader has
// need set method for adding a trader to a stock with number of stock units they have
// need search method for stocks, searching for a certain trader and the # of stocks they have
// need error messages for insufficient funds, invalid stock symbols, or negative quantities -- if i add max stocks option then error for that too
// need sell and buy methods to change account balance depending on quantity they choose

// nice to have: ability to remove trader from a stock (need to at least make it just be 0 - the efficiency of keeping them at 0 vs. just removing them would take too long to measure) - leaned to nice to have because removing makes listing traders and their stock units easier
// nice to have: the first entry of the map has some sort of stock maximum with a trader Admin.
// nice to have: stocks have quantity maximum to buy
// nice to have: switch trader accounts
// nice to have: save data in .txt files on exit and load them (may have done similar in Java 240 but would take a while)

// flat functions that don't require special global variables for less repetition

// fluctuate stock prices - set randomize price multiplier
void set_randomize_price_multiplier_stock(Stock stock) {
	// randomize prices from 0.00 to 1.99
	stock.set_attributes_simplistic("Randomize Price Multiplier", rand() % 200 / 100.0);
}

// fluctuate the stock
Stock fluctuate_stock(Stock stock) {
	// if stock attributes string is randomize price multiplier
	//if (stock.get_attributes().find("Randomize Price Multiplier") != stock.get_attributes().end()) {
	// randomize price multiplier set
	set_randomize_price_multiplier_stock(stock);
	// set price to the randomized multiplier
	stock.set_price(stock.get_price()*stock.get_attributes()[0]);
	//}
	//else {
	//}
	return stock;
}

// fluctuate all stocks
bool fluctuate_all_stocks(Trader trader) {
	// vector of stocks based on trader portfolio
	vector<Stock> new_portfolio = trader.get_portfolio();
	// set i maximum based on size of portfolio
	int i = new_portfolio.size() - 1;
	// if i is < 0, return false as there are no stocks to fluctuate
	if (i < 0) {
		return false;
	}
	// if i is >= 0, loop through all stocks in portfolio and set new prices
	while (i >= 0) {
		Stock latest = new_portfolio[i];
		latest = fluctuate_stock(latest);
		i--;
	}
	// set the new portfolio based on fluctuated prices
	trader.set_portfolio(new_portfolio);
	return true;
}

// display stocks a trader has in reverse order, return true if there are any, or false if there are none
bool display_stocks(Trader trader) {
	// fluctuate the stocks (in interest of time, this will not be implemented)
	//if (fluctuate_all_stocks(trader) == false) {
	//	cout << "no" << endl;
	//}

	// calculate total balance of stocks
	// used quantity
	double total_balance_used_quantity = 0;
	// max quantity
	double total_balance_max_quantity = 0;
	// unavailable counter for counting stocks not available to buy
	int unavailable_counter = 0;
	// create vector of Stock objects and set it to the trader portfolio
	vector<Stock> new_portfolio = trader.get_portfolio();
	// set i maximum based on size of portfolio
	int i = new_portfolio.size() - 1;
	// if i is < 0, tell user or stock market they have no stocks and return false
	if (i < 0) {
		// if the trader is the stock market determined by balance -1, say the stock market has no stocks
		if (trader.get_balance() == -1) {
			cout << "The stock market has no stocks!" << endl;
		}
		// else if the trader is a user, say they have no stocks
		else {
			cout << "You have no stocks!" << endl;
		}
		return false;
	}
	// if i is >= 0, print out the stocks to the user until there are no more
	while (i >= 0) {
		Stock latest = new_portfolio[i];
		// if get used quantity is = to max quantity and trader get balance of -1 indicates it is stock market, stock is unavailable so add to the unavailable counter
		if (latest.get_used_quantity() == latest.get_max_quantity() && trader.get_balance() == -1) {
			unavailable_counter++;
		}
		// else if used max quantity is not = to max quantity, print the stock
		else {
			// add to total balance for used quantity and max quantity for AVAILABLE stocks
			total_balance_used_quantity += latest.get_used_quantity_price();
			total_balance_max_quantity += latest.get_max_quantity_price();
			cout << "--- Stock #" << i + 1 << " ---\n" << "Symbol: " << latest.get_symbol() << "\nPrice: $" << latest.get_price() << "\nQuantity Used Overall: " << latest.get_used_quantity() << "\nMax Quantity: " << latest.get_max_quantity() << "\nTotal Price For Max Quantity: $" << latest.get_max_quantity_price() << "\nTotal Price For Current Used Quantity: $" << latest.get_used_quantity_price() << "\n---------------" << endl;
		}
		i--;
	}
	// if portfolio size is equal to unavailable counter, there are no more stocks available in the market so return false
	if (trader.get_portfolio().size() == unavailable_counter) {
		return false;
	}
	// cout the sum of stocks used and maximum prices
	cout << "Sum of Stock Used Quantity Prices: $" << total_balance_used_quantity << endl;
	cout << "Sum of Stock Maximum Quantity Prices: $" << total_balance_max_quantity << endl;

	// return true if user has stocks
	return true;
}

void add_random_stocks_to_stock_market() {
	// initialize random_number_1 to 9
	int random_number_1 = -1;
	int random_number_2 = -1;
	int random_number_3 = -1;
	int random_number_4 = -1;
	int random_number_5 = -1;
	int random_number_6 = -1;
	int random_number_7 = -1;
	int random_number_8 = -1;
	int random_number_9 = -1;
	int random_number_10 = -1;
	bool added = false;
	// loop until added is true
	while (added == false) {
		// generate random number
		random_number_1 = rand() % 10 + 1;
		// generate random number
		random_number_2 = rand() % 10 + 1;
		// generate random number
		random_number_3 = rand() % 10 + 1;
		// generate random number
		random_number_4 = rand() % 10 + 1;
		// generate random number
		random_number_5 = rand() % 10 + 1;
		// generate random number
		random_number_6 = rand() % 10 + 1;
		// generate random number
		random_number_7 = rand() % 10 + 1;
		// generate random number
		random_number_8 = rand() % 10 + 1;
		// generate random number
		random_number_9 = rand() % 10 + 1;
		// generate random number
		random_number_10 = rand() % 10 + 1;
		// combine numbers in a string
		string random_numbers = to_string(random_number_1) + to_string(random_number_2) + to_string(random_number_3) + to_string(random_number_4) + to_string(random_number_5) + to_string(random_number_6) + to_string(random_number_7) + to_string(random_number_8) + to_string(random_number_9) + to_string(random_number_10);
		// create new stock if possible
		if (the_stock_market.find_position_from_portfolio_stock("DoStock" + random_numbers) == -1) {
			Stock newStock1("DoStock" + random_numbers);
			// give it a random price
			newStock1.set_random_price();
			// set random quantity available
			newStock1.set_random_max_quantity();
			// add it to stock market portfolio
			the_stock_market.add_to_portfolio(newStock1);
			// set added to true to escape while loop
			added = true;
		}
	}
	// set added back to false for next while loop
	added = false;
	// loop until added is true
	while (added == false) {
		// generate random number
		random_number_1 = rand() % 10 + 1;
		// generate random number
		random_number_2 = rand() % 10 + 1;
		// generate random number
		random_number_3 = rand() % 10 + 1;
		// generate random number
		random_number_4 = rand() % 10 + 1;
		// generate random number
		random_number_5 = rand() % 10 + 1;
		// generate random number
		random_number_6 = rand() % 10 + 1;
		// generate random number
		random_number_7 = rand() % 10 + 1;
		// generate random number
		random_number_8 = rand() % 10 + 1;
		// generate random number
		random_number_9 = rand() % 10 + 1;
		// generate random number
		random_number_10 = rand() % 10 + 1;
		// combine numbres in a string
		string random_numbers = to_string(random_number_1) + to_string(random_number_2) + to_string(random_number_3) + to_string(random_number_4) + to_string(random_number_5) + to_string(random_number_6) + to_string(random_number_7) + to_string(random_number_8) + to_string(random_number_9) + to_string(random_number_10);
		// create new stock if possible
		if (the_stock_market.find_position_from_portfolio_stock("ReStock" + random_numbers) == -1) {
			Stock newStock2("ReStock" + random_numbers);
			// give it a random price
			newStock2.set_random_price();
			// set random quantity available
			newStock2.set_random_max_quantity();
			// add the stock to the stock market portfolio
			the_stock_market.add_to_portfolio(newStock2);
			// set added to true to escape while loop
			added = true;
		}
	}
}

// display stocks stock market has, and also add new stocks if necessary
void display_stock_market_stocks() {
	// if display stocks for stock market is false,
	if (display_stocks(the_stock_market) == false) {
		// ad more stocks to stock market
		cout << "Adding more stocks to the stock market..." << endl;
		add_random_stocks_to_stock_market();
		cout << "Stocks added!" << endl;
		// then redisplay stocks for stock market
		display_stocks(the_stock_market);
	}
}

// main method to run command prompt for now. 
int main()
{
	// store traders name
	string trader_name;
	// tell user hello
	cout << "Hello trader!\n";
	// tell user to enter their name
	cout << "Enter your name here: ";
	// take in input for trader to enter their name
	cin >> trader_name;
	// create trader object for the user
	Trader trader(trader_name);
	// output trader name to user
	cout << "Your trader name is: " << trader.get_name() << endl;
	// store commands for user to enter
	string commands = "Commands (Case sensitive):\nBuy a stock (B)\nSell a stock (S)\nDisplay a list of available stocks (Dl)\nDisplay your portfolio (Dp)\nView Account Balance (V)\nMake a Deposit (Md)\nMake a Withdrawal (Mw)\nChange name (C)\nView name (Vn)\nHelp (H)\nExit (E)";
	// output commands for user to enter to user
	cout << commands << endl;
	// store main command for user to enter (user enters this before entering other commands required by some features such as buying a stock)
	string command;
	// infinite while loop asking user for commands
	while (true) {
		// exit if command is E
		if (command == "E") {
			exit(0);
		}
		// ask for command input from user and take it in
		cout << "Enter a command here: ";
		// take in input from user and store it to command
		cin >> command;
		// if command is B, give optinos to buy or skip stocks, or exit
		if (command == "B") {
			cout << "Buy a stock received" << endl;
			// store users command
			int number;
			// loop asking for commands on what to do with stocks
			while (true) {
				// display stock market stocks
				display_stock_market_stocks();
				// print commands for buying stock
				cout << "\nCommands:\nBuy Stock - Enter In Number (#)\nExit buying (0)" << endl;
				cout << "Your command: ";
				// take in command from user
				cin >> number;
				cout << endl;
				// if a number not 0, buy the stock and add it to portfolio if possible
				if (number != 0) {
					// subtract number by 1 as vectors start from 0
					number--;
					if (the_stock_market.validate_position(number) == false) {
						cout << "Your number does not match the number of any of the stocks above. Try again!" << endl;
					}
					else {
						// get new stock from stock market portfolio
						// tell trader their balance is too low if their balance is less than the stock price and break out of the buying while loop
						if (trader.get_balance() < the_stock_market.get_from_portfolio(number).get_price()) {
							cout << "Your balance is too low to buy this stock! Exiting buying..." << endl;
							break;
						}
						// ask for quantity user wants, asking for > 0 and < quantity you want + max quantity stock supports
						cout << "What quantity do you want (greater than 0 and less than your quantity you want plus the max quantity the stock supports)?\nQuantity: ";
						int quantity;
						cin >> quantity;
						cout << endl;
						// break out of the buying while loop for asking quantity if it's <= 0
						if (quantity <= 0) {
							cout << "Your quantity is less than or equal to 0, which is invalid. Exiting buying..." << endl;
							break;
						}
						// checks stock max quantity, breaking while loop if quantity exceeds maximum
						if (quantity + the_stock_market.get_from_portfolio(number).get_used_quantity() > the_stock_market.get_from_portfolio(number).get_max_quantity()) {
							cout << "Your quantity requested would exceed the max quantity the stock supports! Exiting buying..." << endl;
							break;
						}
						// if stock price mulitplied by desired quantity is less than or equal to trader balance (checked by withdraw boolean), tell user the stock is bought and subtract from their balance
						// checks trader balance
						if (trader.withdraw(the_stock_market.get_from_portfolio(number).get_price() * quantity) == true) {
							// get symbol from stock before finding position
							string symbol_from_stock = the_stock_market.get_from_portfolio(number).get_symbol();
							// get old position of trader stock
							int old_position_trader = trader.find_position_from_portfolio_stock(symbol_from_stock);
							// if old position is -1 meaning not found,
							if (old_position_trader == -1) {
								// change quantity from stock market stock
								the_stock_market.change_quantity_from_portfolio_stock(number, the_stock_market.get_from_portfolio(number).get_used_quantity() + quantity);
								// add new stock to trader portfolio
								trader.add_to_portfolio(the_stock_market.get_from_portfolio(number));
							}
							// if old position is found,
							else {
								// change the quantity for trader
								trader.change_quantity_from_portfolio_stock(old_position_trader, the_stock_market.get_from_portfolio(number).get_used_quantity() + quantity);
								// change quantity from stock market stock
								the_stock_market.change_quantity_from_portfolio_stock(number, the_stock_market.get_from_portfolio(number).get_used_quantity() + quantity);
							}

							// show new stock added
							cout << "--- New Stock Added ---\n" << "Symbol: " << the_stock_market.get_from_portfolio(number).get_symbol() << "\nPrice: $" << the_stock_market.get_from_portfolio(number).get_price() << "\nQuantity Used Overall: " << the_stock_market.get_from_portfolio(number).get_used_quantity() << "\nMax Quantity: " << the_stock_market.get_from_portfolio(number).get_max_quantity() << "\nTotal Price For Max Quantity: $" << the_stock_market.get_from_portfolio(number).get_max_quantity_price() << "\nTotal Price For Current Used Quantity: $" << the_stock_market.get_from_portfolio(number).get_used_quantity_price() << "\n---------------" << endl;
						}
					}
					//	break;
				}
				// else if 0, exit the while loop
				else {
					cout << "Exiting buying..." << endl;
					break;
				}
			}
		}
		// if command is S, prompt user to sell a stock by entering the stock number, or type 0 to exit
		else if (command == "S") {
			// store number of user input
			int number;
			// loop asking for user input to sell a stock number or 0 to exit
			while (true) {
				// if trader has stocks, ask them to sell a stock
				if (display_stocks(trader) == true) {
					// print statement giving instructions to user on how to sell stock or to exit
					cout << "To sell a stock, type in the stock number you wish to sell, or type 0 to exit\nNumber: ";
					// input command statement for stock number
					cin >> number;
					// if number is greater than 0, subtract the number since the vector starts from 0 then sell that from portfolio.
					if (number > 0) {
						number--;
						// ask for quantity user wants, asking for > 0 and <= overall used quantity
						cout << "What quantity do you want (greater than 0 and less than or equal to overall used quantity)?\nQuantity: ";
						int quantity;
						cin >> quantity;
						cout << endl;
						// break out of the selling while loop for asking quantity if it's <= 0
						if (quantity <= 0) {
							cout << "Your quantity is less than or equal to 0, which is invalid. Exiting selling stocks..." << endl;
							break;
						}
						// if selling from portfolio is not possible,
						if (trader.sell_from_portfolio(number, quantity) == false) {
							// tell user failed to sell quantity from portfolio and exit selling loop
							cout << "Failed to sell quantity from portfolio, number is higher than the overall used quantity. Exiting selling stocks..." << endl;
							break;
						}
						// else if possible to sell from portfolio,
						else {
							// sell from stock market also
							the_stock_market.sell_from_stock_market(number, quantity);
						}
					}
					// else if number is 0 or less, tell user the program is exiting sell stocks command and exit while loop
					else {
						if (number == 0) {
							cout << "Exiting selling stocks..." << endl;
							break;
						}
						// tell user number is too small
						if (number < 0) {
							cout << "Your number is too small... Exiting selling stocks..." << endl;
							break;
						}
					}
				}
				// else if there are no stocks, tell user they have no stocks and exit while loop
				else {
					// telling user they have no stocks is done by default
					break;
				}
			}
		}
		// else if command is Dl, display available stocks
		else if (command == "Dl") {
			// tell user their command to display a list of available stocks is received
			cout << "Display a list of available stocks received" << endl;
			// display the stocks the stock market has
			display_stock_market_stocks();
		}
		// else if command is Dp, show stocks the user has
		else if (command == "Dp") {
			// tell user the command to display their portfolio is received
			cout << "Display your portfolio received" << endl;
			// show stocks user has
			display_stocks(trader);
		}
		// else if command is V, show the user's balance
		else if (command == "V") {
			// tell user here is your balance
			cout << "Here is your balance:" << endl;
			// tell user's actual balance to the user
			cout << "$" << trader.get_balance() << endl;
		}
		// else if command is Md, prompt user to make a deposit by entering in the amount of money they wish to deposit
		else if (command == "Md") {
			// tell user the make a deposit command is received
			cout << "Make a deposit received" << endl;
			// prompt user to enter in the amount they wish to deposit
			cout << "Enter in the amount you wish to deposit (decimal numbers are allowed)" << endl;
			cout << "Amount: $";
			// store deposit amount
			double depositAmount;
			// take in deposit amount from user
			cin >> depositAmount;
			// deposit the deposit amount to the user
			trader.deposit(depositAmount);
			// tell user their new balance
			cout << "This is your new balance after depositing: $" << trader.get_balance() << endl;
		}
		// else if command is Mw,
		else if (command == "Mw") {
			// tell user the make a withdrawal command is received
			cout << "Make a withdrawal received" << endl;
			// prompt user to enter in the amount they wish to withdraw
			cout << "Enter in the amount you wish to deposit (decimal numbers are allowed)" << endl;
			cout << "Amount: $";
			// store withdraw amount
			double withdrawAmount;
			// take in withdrawal amount from user
			cin >> withdrawAmount;
			// withdraw amount from the user
			// if withdraw is not possible, tell user they cannot withdraw that amount
			if (trader.withdraw(withdrawAmount) == false) {
				cout << "You cannot withdraw that amount! Here is your balance: $" << trader.get_balance() << endl;
			}
			// if withdraw is possible, tell user their new balance after withdrawing
			else {
				// tell user their new balance
				cout << "This is your new balance after withdrawing: $" << trader.get_balance() << endl;
			}
		}
		// else if command is H, show help commands available to the user
		else if (command == "H") {
			// prints out help commands to the user
			cout << commands << endl;
		}
		// else if command is C, ask user what they want to change their name to and change it
		else if (command == "C") {
			// ask user what they want to change their name to
			cout << "What do you want to change your name to?" << endl;
			string new_name; // store the new name
			// fancy prompt for telling user what name to enter by outputting Name: first
			cout << "Name: ";
			// take in input to change the name from the user
			cin >> new_name;
			// change the name to the name the user gave
			trader.set_name(new_name);
			// output the name is changed to the user and the new name they choes
			cout << "Name changed to: " << trader.get_name() << endl;
		}
		// else if command is Vn, view their name
		else if (command == "Vn") {
			// tell the user their name
			cout << "Your name is: " << trader.get_name() << endl;
		}
	}


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file