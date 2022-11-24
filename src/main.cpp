//*****************
//Program Name: Program 6
//Author: Daniel Arlegui & Harpreet Basota
//IDE Used: Eclipse
//Program description: Stock Analysis (Partner Coding Project)
//*****************

//Libraries
#include "stock.h"
#include "stockList.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//Function(s)
void getData(stockList &);

int main()
{
    //declarations
    stockList stockList;
    freopen("error.txt", "w", stderr);
    cout << fixed << setprecision(2) << showpoint;

    getData(stockList);        //read external file data into stockList
    stockList.sortStockList(); //sorts stockList
    stockList.printBySymbol(); //prints alphabetically by symbol
    stockList.printByGain();   //prints high-to-low low by gain

	cout << "\n\nThis our original work; apart from standard tutoring or class collaboration, "
			"\nI neither received help nor copied this code from another source."  << endl;

	return 0;
}

//getData(): takes the .txt file and sets up the stock temp then using the insert method from stockList
//Arguments: (stockList &s) | Returns: void
void getData(stockList &s){
	string line, id;
	stock temp;
	double gain;

	ifstream fin("stockData.txt");
	if(!fin){
		cerr << "\n\nError: Input File does not exist!";
		exit(EXIT_FAILURE);
	}
	while(fin >> temp){
		gain = ((temp.getPrices(1) / temp.getPrices(4)) - 1) * 100;
		temp.setGain(gain);
		s.insert(temp);
	}
	fin.close();
}

/* Partner Attestation
 * Daniel Arlegui (Work Done)
 * - setup both header files and their implementation files.
 * - made and got the getData() function to work (without overloading them).
 * - sorted the deque<stock> myStocks by symbol
 * - managed to figure out how to sort the gain by using the sortGain() method in stockList.cpp
 * Harpreet Basota (Work Done)
 * - made both friend functions
 * - managed to figure out and fix the overloaded operators.
 * - made the printResults()
 * Summary
 * Overall we both communicated very well and managed to get work done!
 */
