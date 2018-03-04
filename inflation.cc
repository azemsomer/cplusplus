/*Program to test some basic programming skills,
 * See Absolute C++, fourth edition, Savitch
 * chapter 2, exercise 1*/

#include <iostream>
using namespace std;

int main(){
    double price, inflation1, inflation2;
    int time, i;
    
    //query user for data
    cout << "Give timespan in years: ";
    cin >> time;
    cout << "Give the anual rate of in flation as percentage: ";
    cin >> inflation1;
    cout << "Give current price: ";
    cin >> price;
    
    
    //convert percentage into decimal fraction
    inflation2 = inflation1 / 100;
    //cout << inflation2 <<endl;
    
    //calculate new price in time years
    for(i = 1; i <= time; i++){
        price = price * (inflation2 + 1);
        //cout <<price <<endl;
    }//for
    
    //output new price
    cout << "Price after "<<time<<" years, is: "<<price<<endl;
    
    return 0;
}//main
