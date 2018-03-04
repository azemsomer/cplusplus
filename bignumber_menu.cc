/*This program allows users to manipulate numbers of an arbitrary length,
 * through the application of a pointer list.
 * The program does not yet work entirely as it is supposed to, whenever time permits
 * I will complete this program
 */
#include<iostream>
#include "azemsomergg4.h" //file which define the "bignumber" object class
using namespace std;

void readOption(char& reChar){//reads a char
    cin.get(reChar);
    while (reChar == '\n')
      cin.get(reChar);
    cin.ignore('\n',10);
}//leesOptie

void addingUp(bignumber gg1[]){
    gg1[2].addUp(gg1[0], gg1[1]);
}

void readIn(bignumber gg1[]){
    cout <<"Enter big number A: ";
    gg1[0].leesIn();
    cout <<"Enter big number B: ";
    gg1[1].read();
}

void display(bignumber gg1[]){
    gg1[0].print();
    gg1[1].print();
    gg1[2].print();
}

void collatz(bignumber gg1[]){
    char option4;
    cout<<"Choose A, B of C to check for Collatz: ";
    leesOptie(option4);
    switch (option4){
      case 'A':
      gg1[0].threeNPlus1();
      break;
      case 'B':
      gg1[1].threeNPlus1();
      break;
      case 'C':
      gg1[2].threeNPlus1();
      break;
    }//switch
}//collatz

void nullify(bignumber gg1[]){
    char option3;
    int m = 5;
    cout<<"Choose A, B of C to nullify: ";
    leesOptie(option3);
    switch (option3){
      case 'A':
      gg1[0].makeZeroes(m);
      break;
      case 'B':
      gg1[1].makeZeroes(m);
      break;
      case 'C':
      gg1[2].makeZeroes(m);
      break;
    }//switch
}//nullify

void menu(bignumber gg1[]){//shows menu
    char option;//help variable
    while (option != 'S'){
        cout <<"Select: (A)upp, (C)ollatz-problem, (N)ullify "
             <<"(R)ead number, (D)isplay or (S)top: ";
        leesOptie(option);
        switch (option){ //processes user selection
          case 'A':
          addingUp(gg1);
          break;
          case 'C'://this function does not work yet
          collatz(gg1);
          break;
          case 'N':
          nullify(gg1);
          break;
          case 'R':
          readIn(gg1);
          break;
          case 'D':
          display(gg1);
          break;
          case 'S':
          break;
        }//switch
    }//while
}//menu


void infoblock(){//Dislays infoblock
    cout <<"-----------------------------------------" <<endl;
    cout <<"| This programma is written by :        |" <<endl;
    cout <<"| Azem Somer, 2009                      |" <<endl;
    cout <<"-----------------------------------------" <<endl;
}//

int main(){
    infoblock();
    bignumber beauty[3];
    menu(beauty);
    return 0;
}//main
