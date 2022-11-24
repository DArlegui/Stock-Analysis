//stockList.h
/*
---------------
	stockList : stock
---------------
- myStocks : deque<stock>
---------------
+ stockList() : stock(){}
+ ~stockList()
+ insert(const stock& s) : void
+ sortStockList() : void
+ sortGain() : void
+ printBySymbol() : void
+ printByGain();
+ printResults() : void
 */

#ifndef STOCKLIST_H_
#define STOCKLIST_H_

//Libraries
#include "stock.h"
#include <iostream>
using namespace std;

class stockList: public stock
{
private:
	deque<stock> myStocks;
public:
	//Constructor(s)
	stockList() : stock(){}
	~stockList();
	//Method(s)
	void insert(const stock& s)	{myStocks.push_back(s);}
	void sortStockList()		{sort(myStocks.begin(), myStocks.end());}
	void sortGain();
	void printBySymbol();
	void printByGain();
	void printResults();
};

#endif /* STOCKLIST_H_ */
