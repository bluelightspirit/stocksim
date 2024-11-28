// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include "Stock.h"
#include "Trader.h"
using namespace std;

// flat functions that don't require special global variables for less repetition
bool display_stocks(Trader trader) {
	vector<Stock> new_portfolio = trader.get_portfolio();
	int i = new_portfolio.size() - 1;
	if (i < 0) {
		cout << "You have no stocks!" << endl;
		return false;
	}
	while (i >= 0) {
		Stock latest = new_portfolio[i];
		cout << "--- Stock #" << i+1 << " ---\n" << "Symbol: " << latest.get_symbol() << "\nPrice: " << latest.get_price() << "\n---------------" << endl;
		i--;
	}
	return true;
}

int main()
{
	string trader_name;
	cout << "Hello trader!\n";
	cout << "Enter your name here: ";
	cin >> trader_name;
	Trader trader(trader_name);
	cout << "Your trader name is: " << trader.get_name() << endl;
	string commands = "Commands (Case sensitive):\nBuy a stock (B)\nSell a stock (S)\nDisplay a list of available stocks (Dl)\nDisplay your portfolio (Dp)\nView Account Balance (V)\nMake a Deposit (Md)\nMake a Withdrawal (Mw)\nHelp (H)\nExit (E)";
	cout << commands << endl;
	string command;
	while (true) {
		if (command == "E") {
			exit(0);
		}
		cout << "Enter a command here: ";
		cin >> command;
		if (command == "B") {
			cout << "Buy a stock received" << endl;
			Stock newStock;
			string new_command;
			while (true) {
				newStock.set_random_price();
				cout << newStock.get_price() << " is the cost of some random stock.\nCommands:\nBuy (B)\nSkip (S)\nExit command loops(E)" << endl;
				cin >> new_command;
				if (new_command == "B") {
					cout << "Bought" << endl;
					trader.add_to_portfolio(newStock);
					vector<Stock> new_portfolio = trader.get_portfolio();
					Stock latest = new_portfolio[new_portfolio.size() - 1];
					cout << "--- New Stock Received ---\n" << "Symbol: " << latest.get_symbol() << "\nPrice: " << latest.get_price() << endl;
					break;
				}
				else if (new_command == "S") {
					cout << "Skipping" << endl;
				}
				else if (new_command == "E") {
					command = "E";
					break;
				}
			}
		}
		else if (command == "S") {
			int number;
			while (true) {
				if (display_stocks(trader) == true) {
					cout << "To sell a stock, type in the stock number you wish to sell, or type 0 to exit" << endl;
					cin >> number;
					if (number != 0) {
						number--;
						trader.sell_from_portfolio(number);
						break;
					}
					else {
						if (number == 0) {
							break;
						}
					}
				}
				else {
					break;
				}
			}
		}
		else if (command == "Dl") {
			cout << "Display a list of available stocks received" << endl;
			Trader the_stock_market;
			Stock newStock1("DoStock391");
			newStock1.set_random_price();
			Stock newStock2("ReStock123");
			newStock2.set_random_price();
			the_stock_market.add_to_portfolio(newStock1);
			the_stock_market.add_to_portfolio(newStock2);
			display_stocks(the_stock_market);
		}
		else if (command == "Dp") {
			cout << "Display your portfolio received" << endl;
			display_stocks(trader);
		}
		else if (command == "V") {
			cout << "Here is your balance:" << endl;
			cout << trader.get_balance() << endl;
		}
		else if (command == "Md") {
			cout << "Make a deposit received" << endl;
		}
		else if (command == "Mw") {
			cout << "Make a withdrawal received" << endl;
		}
		else if (command == "H") {
			cout << commands << endl;
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
