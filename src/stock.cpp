//stock.cpp
#include "stock.h"
#include <iostream>
using namespace std;

stock::stock(){
	stockSymbol = "";
	for(int i = 0; i < SIZE; i++)
		prices[i] = 0.0;
	gain = 0.0;
	volume = 0.0;
}

stock::~stock() {
	// TODO Auto-generated destructor stub
}

//setPrices(): a setter for Prices Array
//Arguments: (double n1, double n2, double n3, double n4, double n5) | Returns: void
void stock::setPrices(double n1, double n2, double n3, double n4, double n5){
	prices[0] = n1; prices[1] = n2; prices[2] = n3; prices[3] = n4; prices[4] = n5;
}

//operator<<: couts out the stock info
//Arguments: (ostream& osObject , const stock& s) | Returns: ostream
ostream& operator<<(ostream& osObject , const stock& s){
	osObject << setw(W1)<< s.stockSymbol << setw(W1);
	for(int i=0 ;i <SIZE; i++){
		cout << s.prices[i] << setw(W1);
	}
	osObject << setw(8) <<  s.gain << "%";
	osObject << setw(11) << s.volume << endl;
	return osObject;
}

//operator>>: uses this in the getData() function to retrieve each stock data
//Arguments: (istream& isObject , const stock& s ) | Returns: istream
ifstream& operator>>(ifstream& isObject ,   stock& s){
	isObject >> s.stockSymbol >> s.prices[0] >>s.prices[1] >> s.prices[2] >> s.prices[3] >> s.prices[4] >> s.volume;
	return isObject;
}

//operator<(): sorts the symbols by using sort method
//Arguments: (const stock &right) const | Returns: bool
bool stock::operator<(const stock &right) const{ //For symbol sorting
	bool status = false;
	if(stockSymbol < right.stockSymbol){
		status = true;
	}
	return status;
}

//setStockInfo(): sets up all the private viables for stock
//Arguments: (string s, double n1, double n2, double n3, double n4, double n5, float g, double v)
//Returns: void
void stock::setStockInfo(string s, double n1, double n2, double n3, double n4, double n5, float g, double v){
	stockSymbol = s;
	prices[0] = n1;
	prices[1] = n2;
	prices[2] = n3;
	prices[3] = n4;
    prices[4] = n5;
    gain = g;
    volume = v;
}
