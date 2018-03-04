/* This program ask the user for a products current price and that of last year,
 * subsequently it calculates the rate of inflation and then this is used to calculate
 * next year's price
 */
#include <iostream>
using namespace std;

double calcInflation(double price1, double price2){
    double rate, help;
    
    //calculate inflation rate
    help = price1 - price2;
    rate = (help / price2) * 100;
    
    return rate;
}//double

void futPrice(double price, double infRate){
    double price1, price2;
    
    //calculate future prices
    price1 = price * (1 + infRate / 100);
    price2 = price1 * (1 + infRate / 100);
    
    //output future prices
    cout << "Price in one year will be: " << price1 << endl;
    cout << "Price in two years will be: " << price2 << endl;
}//void

int main(){
    double price1, price2, rate;
    
    //query user for data
    cout << "Please, give current price: ";
    cin >> price1;
    cout << "Please, give last year's price: ";
    cin >> price2;
    
    //call calcInflation() & display result
    rate = calcInflation(price1, price2);
    cout << "Rate of inflation is: " << rate << endl;
    
    //call futPrice()
    futPrice(price1, rate);
    
    return 0;
}//main
