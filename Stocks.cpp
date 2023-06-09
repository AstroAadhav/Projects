#include <iostream>
#include <vector>
using namespace std;

class Stock {
public:
    string name;
    double boughtPrice;
    double currentPrice;

    void printDetails() {
        cout << "Stock name: " << name << endl;
        cout << "Stock bought at: " << boughtPrice << endl;
        cout << "Stock's current price: " << currentPrice << endl;
        cout << "Stock's percent change is " << percentChange() << " % " << endl;
        cout << "Stock advisory says: " << buyOrSell() << endl;
    }
    double percentChange() {
        return ((currentPrice - boughtPrice)/boughtPrice) * 100;
    }
    string buyOrSell() {
        if (boughtPrice < currentPrice) {
            return "Current is higher than Bought price, so SELL!";
        }
        else if (boughtPrice > currentPrice) {
            return "Current is lower than Bought price, so DON'T SELL (Maybe BUY!)";
        }
        else {
            return "Current price is equal to bought price! Up to you!";
        }
    }
};

int main() {
    vector<Stock> Stocks;
    
    string userInput;
    while (userInput != "done") {
        cout << "Input your stock name (You CANNOT have duplicates): " << endl;
        cout << "Please type 'done' if no more stocks need to be added" << endl;
        cin >> userInput;
        if (userInput == "done") {
            break;
        }
        Stock newStockClass;
        newStockClass.name = userInput;

        Stocks.push_back(newStockClass);

        cout << "Enter stock price when you bought it: " << endl;
        double boughtPriceInput;
        cin >> boughtPriceInput;
        newStockClass.boughtPrice = boughtPriceInput;

        cout << "Enter current stock price: " << endl;
        double currentPriceInput;
        cin >> currentPriceInput;
        newStockClass.currentPrice = currentPriceInput;

        // cout << newStockClass.name << "'s percent change is " << newStockClass.percentChange() << " % " << endl;
        // cout << newStockClass.name << "'s Buy/Sell advisory says " << newStockClass.buyOrSell() << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << endl;
    }
    cout << "-----------------------------------------------------------------" << endl;
    cout << "You have initialized all your stocks and their respective values, now you can view allyour stock details!" << endl;
    cout << "Your initialized stocks are: " << endl;

    for(int i=0; i < Stocks.size(); i++) {
        Stocks.at(i).printDetails();
        cout << endl;   
    }

    return 0;
}