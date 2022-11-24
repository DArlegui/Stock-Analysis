#include "stockList.h"
#include <iostream>
using namespace std;

stockList::~stockList() {
	// TODO Auto-generated destructor stub
}

//sortGain(): sorts the gain from highest to lowest for myStocks
//Arguments: N/A | Returns: void
void stockList::sortGain(){
	deque<stock>::iterator iter = myStocks.begin();
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			if(iter->getGain() < myStocks[i].getGain()){
				iter_swap(iter, myStocks.begin() + i);
				iter++; //Goes to the next Index of myStocks
			}
		}
	}
}

//printBySymbol(): prints out the stock results by symbol (which has already been sorted)
//Arguments: N/A | Returns: void
void stockList::printBySymbol(){
	cout << "\n\t\t********* First Investor's Heaven ********** " << endl;
	cout << "\t\t********* Financial Report ********** " << endl;
	cout << "\t\t********* Sorted by Symbol ********** " << endl;
	cout << endl;
	printResults();
}

//printByGain(): prints out the stock results by gain from highest to lowest
//Arguments: N/A | Returns: void
void stockList::printByGain(){
	double temarr[SIZE];
	deque<stock>::iterator iter = myStocks.begin();
	for(int i = 0; i < SIZE; i++){
		temarr[i] = iter->getGain(); iter++;
	}

	sort(temarr, temarr + SIZE);
	sortGain();

	cout << "\n\t\t********* First Investor's Heaven ********** " << endl;
	cout << "\t\t********* Financial Report ********** " << endl;
	cout << "\t\t********* Sorted by Percent Gain ********** " << endl;
	cout << "\nHighest to lowest : ";
	for(int i = SIZE - 1; i >= 0;i--){
		cout << temarr[i] << " ";
	} cout << endl << endl;
	printResults();
}

//printResults()): couts out the stocks results
//Arguments: N/A | Returns: void
void stockList::printResults(){
	cout << setw(W1) << "Stock"  << setw(18) << "Today" << setw(23) << " Previous" << setw(16) << "Percent" << endl;
	cout << setw(W1) << "Symbol" << setw(W1) << "Open"  << setw(W1) << "Close" <<  setw(W1) << "High"
		 <<  setw(W1) << "Low" << setw(W1) << "Close" << setw(W1) << "Gain" << setw(W1) << "Volume" << endl;
	cout << setw(W1) << "------" << setw(W1) << "------" << setw(W1) << "------" << setw(W1) << "-----" << setw(W1)
			<< "-----" << setw(W1) << "-----"<<  setw(W1)<<  "-----" << setw(W1) << "------" << endl;
	for(auto it : myStocks){
		cout << setw(W1)<< it << setw(W1); //Uses the friend << function
	}
	cout << "\nClosing asset: ";
	double temp = 0;
	for(int i=0; i<SIZE;i++ )
		temp += myStocks[i]. getVolume() * myStocks[i].getPrices(1) ;
	cout << "$ " << temp << endl;
}
