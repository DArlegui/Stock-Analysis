//stock.h
/*
---------------
	stock
---------------
- stockSymbol : string
- prices[SIZE] : double
- gain : double
- volume : double
---------------
+ stock()
+ ~stock()
+ setstockSymbol(string s) : void
+ setPrices(double n1, double n2, double n3, double n4, double n5) : void
+ setGain(double g) : void
+ setVolume(double v) : void
+ getstockSymbol() : string
+ getPrices(int index) : double
+ getGain() : double
+ getVolume() : double
+ ostream& operator<<(ostream& osObject , const stock& s ) : friend
+ ifstream& operator>>(ifstream& isObject ,  stock& s); : friend
+ operator<(const stock &right) const : bool
+ setStockInfo(string s, double n1, double n2, double n3, double n4, double n5, float g, double v) : void
 */

#ifndef STOCK_H_
#define STOCK_H_

//Libraries
#include <iostream>
#include <iomanip>
#include <deque>
#include <algorithm>
#include <fstream>
using namespace std;

int const SIZE = 5, W1 = 9; //Array Size, W1 for outputting

class stock{
private:
	string stockSymbol;
	double prices[SIZE];
	double gain;
	double volume;
public:
	//Constructor(s)
	stock();
	~stock();

	//Setters & getters
	void setstockSymbol(string s)		{stockSymbol = s;}
	void setPrices(double n1, double n2, double n3, double n4, double n5);
	void setGain(double g)				{gain = g;}
	void setVolume(double v)			{volume = v;}
	string getstockSymbol()				{return stockSymbol;}
	double getPrices(int index)			{return prices[index];}
	double getGain()					{return gain;}
	double getVolume()					{return volume;}

	//Methods
	friend ostream& operator<<(ostream& osObject , const stock& s );
	friend ifstream& operator>>(ifstream& isObject ,  stock& s);
	bool operator<(const stock &right) const;
	void setStockInfo(string s, double n1, double n2, double n3, double n4, double n5, float g, double v);
};

#endif /* STOCK_H_ */
