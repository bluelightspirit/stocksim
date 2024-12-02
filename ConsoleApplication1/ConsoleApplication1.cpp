// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include "Stock.h"
#include "Trader.h"
using namespace std;

// flat functions that don't require special global variables for less repetition

// display stocks a trader has in reverse order, return true if there are any, or false if there are none
bool display_stocks(Trader trader) {
	// create vector of Stock objects and set it to the trader portfolio
	vector<Stock> new_portfolio = trader.get_portfolio();
	// set i maximum based on size of portfolio
	int i = new_portfolio.size() - 1;
	// if i is < 0, tell user they have no stocks and return false
	if (i < 0) {
		cout << "You have no stocks!" << endl;
		return false;
	}
	// if i is >= 0, print out the stocks to the user until there are no more
	while (i >= 0) {
		Stock latest = new_portfolio[i];
		cout << "--- Stock #" << i+1 << " ---\n" << "Symbol: " << latest.get_symbol() << "\nPrice: " << latest.get_price() << "\n---------------" << endl;
		i--;
	}
	// return true if user has stocks
	return true;
}

// main method to run command prompt for now. maybe not allowed for HCI so is temporary for now, but good start?
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
			// create new stock
			Stock newStock;
			// store users command
			string new_command;
			// loop asking for commands on what to do with stocks
			while (true) {
				// set a random stock price
				newStock.set_random_price();
				// print cost of stock
				cout << newStock.get_price() << " is the cost of some random stock.\nCommands:\nBuy (B)\nSkip (S)\nExit command loops(E)" << endl;
				// take in command from user
				cin >> new_command;
				// if B, buy the stock and add it to portfolio
				if (new_command == "B") {
					cout << "Bought" << endl;
					trader.add_to_portfolio(newStock);
					vector<Stock> new_portfolio = trader.get_portfolio();
					Stock latest = new_portfolio[new_portfolio.size() - 1];
					cout << "--- New Stock Received ---\n" << "Symbol: " << latest.get_symbol() << "\nPrice: " << latest.get_price() << endl;
					break;
				}
				// else if S, skip the stock
				else if (new_command == "S") {
					cout << "Skipping" << endl;
				}
				// else if E, exit the while loop
				else if (new_command == "E") {
					command = "E";
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
					cout << "To sell a stock, type in the stock number you wish to sell, or type 0 to exit\nNumber: " << endl;
					// input command statement for stock number
					cin >> number;
					// if number is not 0, subtract the number since the vector starts from 0 then sell that from portfolio.
					if (number != 0) {
						number--;
						trader.sell_from_portfolio(number);
					}
					// else if number is 0, tell user the program is exiting sell stocks command and exit while loop
					else {
						if (number == 0) {
							cout << "Exiting selling stocks command..." << endl;
							break;
						}
					}
				}
				// else if there are no stocks, tell user they have no stocks to sell and exit while loop
				else {
					cout << "You have no stocks to sell!" << endl;
					break;
				}
			}
		}
		// else if command is Dl, display available stocks
		else if (command == "Dl") {
			// tell user their command to display a list of available stocks is received
			cout << "Display a list of available stocks received" << endl;
			// create a new trader
			Trader the_stock_market;
			// create new stock
			Stock newStock1("DoStock391");
			// give it a random price
			newStock1.set_random_price();
			// create new stock
			Stock newStock2("ReStock123");
			// give it a random price
			newStock2.set_random_price();
			// add the stocks to the portfolio
			the_stock_market.add_to_portfolio(newStock1);
			the_stock_market.add_to_portfolio(newStock2);
			// display the stocks the stock market trader has
			display_stocks(the_stock_market);
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
			cout << trader.get_balance() << endl;
		}
		// else if command is Md, 
		else if (command == "Md") {
			cout << "Make a deposit received" << endl;

		}
		// else if command is Mw,
		else if (command == "Mw") {
			cout << "Make a withdrawal received" << endl;
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
