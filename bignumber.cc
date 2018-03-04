//This file contains the definitions of the bignumber class member functions
//The function regarding to the collatz problem are put away as comment
//this has yet to be worked out
#include<iostream>
#include "bignumber.h"
using namespace std;

const int k = 3;

bignumber::bigNumber(){//default constructor
  start = NULL;
  end = NULL;
  numberFields = 0;
}

void bignumber::print(){//dprints big number
    vakje* hulp = start;
    while (hulp != NULL) {
      if (hulp->info <= 10)
          cout << "00" << hulp->info;
      else if (hulp->info <= 100)
          cout <<"0"<< hulp->info;
      else cout << hulp->info;
      hulp = hulp->previous;
    }//while
    cout<<endl;
}//print

void bignumber::addBehind(int value){//add new field behind existing big number
    field* nieuw = new field;        //nieuw is Dutch for 'new'
    nieuw->previous = NULL; nieuw->info = value; nieuw->previous = end;
    if (end != NULL)
      end->next = nieuw;
    else
      start = nieuw;
    end = nieuw;
}//addBehind

void bignumber::addBefore(int value){//add new field before existing big number
    field* nieuw = new field; 
    nieuw->previous = NULL; nieuw->info = value; nieuw->next = start;
    if (start != NULL)
      end->previous = nieuw;
    else
      end = nieuw;
    start = nieuw;
}//addBefore

void bignumber::read(){//reads big number
    int number = 0; //help variables
    int i = 0;
    char kar;
    int count = 0;
    cout<<"Enter a big number: ";
    do{
        cin.get(kar);
        if(isdigit(kar)) {
            number = number*10 + (kar-'0');
	    count++;
          //  if(count == k){//what's k?
            //  addBehind(number);
	      number = 0;
	      count = 0;
	      i++;
            }//if
	}//if
    }while(kar != '\n');
    numberFields = i;
}//read

//This function adds up two big numbers
void bignumber::addUp(bignumber gg1, bignumber gg2){
    field* hulp1 = gg1.end;//Kijk hierna!! (personal note)
    field* hulp2 = gg2.end;//idem
    int hulp3; int rest = 0;
    while ( hulp1 != NULL && hulp2 != NULL ) {
      hulp3 = hulp1->info + hulp2->info + rest;
      rest = hulp3 /1000;
      hulp3 = hulp3 %1000;
      addBefore(hulp3);//voegvoor!!!! (personal note)
      hulp1 = hulp1->previous;
      hulp2 = hulp2->previous;
    }//while
    addBefore(rest);
}//addUp

void bignumber::makeZeroes(int m){//create m fields with value 0
    int i;
    for(i=0; i<m; i++){
       addBehind(0);
    }//for
    numberFields = m;
}//makeZeroes

void bignumber::destroy() {//delete all used fields
    field* hulp = start->next;
    field* p;//help variable
    while (hulp != NULL && hulp->next != NULL){
      p = hulp->next;
      if (p->next != NULL)
        p->next->previous = hulp;
      hulp->next = p->next; delete p;
    }//while
}//destroy

/*void grootgetal::kopieer(grootgetal & gg2){
    vakje* hulp = begin;
    while (hulp != NULL) {
      gg2.voegVoor(hulp->info);
      hulp = hulp->volgende;
    }//while
}//kopieer
*/
bool bignumber::testOne(){//test if big number equals 1
    bool checkOne;
    int i;
    int count = numberFields - 1;
    field* hulp = start;
    for(i = 0; i < count; i++){//checks all vakjes fields except the first one
        if(hulp->info != 0)    //are equal to zero
            return checkOne = false;
        else hulp = hulp->previous;//will eventual point to final field
    }//for
    if(hulp->info == 1)
      checkOne = true;
    else checkOne = false;
    return checkOne;
}//testOne

bool bignumber::testEven(){//cheks if big number is even
    bool checkEven = false;
    field* hulp = end;
    int last = hulp->info;
    if(last % 2 == 0)
      checkEven = true;
    return checkEven;
}//testEven

void bignumber::divideBy2(){//Divide big number by two
    int hulp;
    int carry = 0;
    field* hulp1 = start;//help pointer
    while (hulp1 != NULL){//runs through all fields
        hulp = (hulp1->info + carry)/2;
        if(hulp1->info % 2 == 1)
          carry = 1000;
        else carry = 0;
        hulp1->info = hulp;
        hulp1 = hulp1->previous;
    }//while
}//divideBy2

void bignumber::multiplyByThreePlusOne(){//multiply big number by 3
    int carry = 1;                 // and increment it with 1
    int hulp;
    field* hulp1 = end;
    while (hulp1 != NULL) {//runs through all fields
      hulp = 3*hulp1->info + carry;
      hulp1->info = hulp % 1000;
      carry = hulp/1000;
      hulp1 = hulp1->previous;
    }//while
    addBehind(carry);//adds all remaining fields
}//multiplyByThreePlusOne

void bignumber::threeNPlus1(){//Executes Collatz-conjecture
    int i=0;//counts number of itterations
    while(testEen()!= true){//test for Collatz-conjecture
        print();
        if(testEven())
           divideBy2();
        else multiplyByThreePlusOne();
        i++;
    }//while
    print();
    cout<<"Number of itterations: "<<i<<endl;
}//threeNPlus1

