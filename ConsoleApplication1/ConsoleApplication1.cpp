// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Stock.h"
#include "Trader.h"
using namespace std;

int main()
{
	string trader_name;
    cout << "Hello trader!\n";
	cout << "Enter your name here: ";
	cin >> trader_name;
	Trader trader(trader_name);
	cout << "Your trader name is: " << trader.get_name() << endl;
	cout << "Commands:\nBuy a stock (B)\nSell a stock (S)\nDisplay a list of available stocks (Dl)\nDisplay your portfolio (Dp)\nView Account Balance (V)\nMake a Deposit (Md)\nMake a Withdrawal (Mw)\nHelp (H)" << endl;

	
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
