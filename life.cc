/* This programs plays Conway's Game of Life.
 * It is written by Azem Somer.
 * The program allows the user to manipulate living and dead cells.
 * This is enabled by using a class world with relevant member variables and functions.
 * A 2D array is used as starting point, with each point [i][j] represents a cell,
 * a set of functions is used to change the values of each cell, following Conway's rules.
 * This program is compiled with g++ under Ubuntu 11.04 and is written using gedit.
*/
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;

const int maxLength = 1000;//maximal length of array
const int maxWidth = 1000;//maximal width of array

class world{//declaration of the class world
    public: //member variables
        int view[maxLength][maxWidth];//2D-Array
        int height, width;//dimensions of the view
        int xlibo, ylibo;//left upper coordinates
        int numberG;//#generations
        int delayTime;//degree of delay
        int percent;//percentage living cells
		int shiftPara;//shift parameter
        char charL, charD;//characters for living resp. dead cells
        
        //default constructor
        world(){
        height = 100; width = 100;
        xlibo = 0; ylibo = 0;
        numberG = 10; delayTime = 10;
        percent = 25;
        charL = 'x'; charD = ' ';
		shiftPara = 5;
        }//default constructor

        //member functions
        void heightAndWidth();//set height & width
        void coordinaten();//set xlibo & ylibo
        void generations();//set numberG
        void setShift();//set shiftPara
        void percentage();//set percentage
        void characters();//set charL & charD
        void changeView();//changes the view
        void dispArray();//print the view
        void clear();//kills all cells
        void one();//gives one generation
        void go();//gives a series of generations
        void delay();//creates a delay between generations
		void shift(); //shifts the view
    private:
        int count(int i, int j);//help function for dispArray
};

void readOption(char& reChar){//reads a char
    cin.get(reChar);
    while (reChar == '\n')
      cin.get(reChar);
    cin.ignore('\n',10);
}//readOption

void readNumber(int& number){//reads number
    number = 0;
    char kar;
    do{
        cin.get(kar);
        if(isdigit(kar))
            getal = number*10 + (kar-'0');
    }while(kar != '\n');
    if (number > 10000)
       number = 9999;
}//readNumber

//functions belonging to the parameter submenu
void world::coordinates(){
    cout <<"Give xlibo: " <<endl;
    readNumber(xlibo);
    cout <<"Give ylibo: " <<endl;
    readNumber(ylibo);
}//coordinates

void world::heightAndWidth(){
    cout <<"Give the heighth of the view: " <<endl;
    readNumber(height);
    cout <<"Give the width of the view: " <<endl;
    readNumber(width);
}//heightAndWidth

void world::percentage(){
    cout <<"Give the percentage of living cells: " <<endl;
    readNumber(percent);
}//percentage

void world::setShift(){
    cout <<"Give the shift step size: " <<endl;
    readNumber(shiftPara);
}//setShift

void world::characters(){
    cout <<"Choose the character for living cells:" <<endl;
    readOption(charL);
    cout <<"Choose the character for dead cells:" <<endl;
    readOption(charD);
}//characters

//functions belonging to main dmenu
void world::clear(){//reset all cells to 0
    int i,j;
    for(i = 0; i < maxLength; i++){
        for(j = 0; j < maxWidth; j++){
            view[i][j] = 0;
        }//for
    }//for
}//clear

int randInt(){//random number generator
    static int number = 820;//start variable
    number = (711 * number + 1) % 1000;//Knuth's algoritm
    return number;//"random" variabele
}//randInt

void randView(world& abc){//fills a view with random living & dead cells
    int numbCells, numbCL, i, j,k; //hulp variables
    numbCells = abc.height*abc.width;//calculates total #cells
    numbCL = (abc.percent*numbCells)/100;//calculates #living cells
    abc.clear();//give a 2D-Array with dead cells
    for(k = 0; k < numbCL; k++){//makes N cells alive
        i = randInt() % abc.height;
        j = randInt() % abc.width;
        abc.view[i][j] = 1;
    }//for
}//random

void world::dispArray(){//prints view to screen
    int i, j;
    for(i = ylibo; i < height; i++){
        for(j = xlibo; j < width; j++){
            if(view[i][j] == 1)
               cout << charL;
            else cout << charD;
        }//for
        cout << endl;
    }//for
}//dipArray

void world::delay(){//zorgt voor vertraging tussen generaties
  int deLay = delayTime;
  int i, j, k, l;
  double numberA = 2011, numberB = 2312, numberC;

    for(i = 0; i < deLay; i++){
        for(j = 0; j < deLay; j++){
           for(k = 0; k < deLay; k++){
              for(l = 0; l < deLay; l++)
                 numberC = numberA*numberB;
              }//for
        }//for
    }//for
}//delay

//help funtion for changeView
//counts #living neieghbours amd test for view's edge
int world::count(int i, int j){
    int countHelp = 0;
    if ((i-1 > ylibo)&&(j-1 > xlibo)){
        if (view[i-1][j-1] == 1)
            countHelp ++;
    }//if
    if (i-1 > ylibo){
        if (view[i-1][j] == 1)
            countHelp ++;
    }//if
    if ((i-1 > xlibo)&&(j+1 < width)){
        if (view[i-1][j+1] == 1)
            countHelp ++;
    }//if
    if (j-1 > xlibo){
        if (view[i][j-1] == 1)
            countHelp ++;
    }//if
    if (j+1 < width){
        if (view[i][j+1] == 1)
            countHelp ++;
    }//if
    if ((i+1 < height)&&(j-1 > xlibo)){
        if (view[i+1][j-1] == 1)
            countHelp ++;
    }//if
    if (i+1 < height){
        if (view[i+1][j] == 1)
            countHelp ++;
    }//if
    if ((i+1 <height)&&(j+1)){
        if (view[i+1][j+1] == 1)
            countHelp ++;
    }//if
    return countHelp;
}//count


void world::changeView(){//adjust view according to the rules of life
     int count1, i,j, n, m;//help variables
     int Bcd[maxLength][maxWidth];//help array
     
     //cells are converted according to Conway's rules
     //only cells within the by user select view
     //will be considered
    for(i = ylibo; i < height; i++){
         for(j = xlibo; j < width; j++){
             count1 = count(i,j);
             if((view[i][j] == 1) && (count1 < 2))
                Bcd[i][j] = 0;
             else if((view[i][j] == 1) && (count1 > 2))
                Bcd[i][j] = 0;
             else if((view[i][j] == 0) && (count1 == 3))
                Bcd[i][j] = 1;
             else Bcd[i][j] = view[i][j];
         }//for
     }//for

     for(n = ylibo; n < height; n++){//copies Bcd to view
         for(m = xlibo; m < width; m++){
             view[n][m] = Bcd[n][m];
         }//for
     }//for
}//changeView

void world::one(){
	//the rule below prints the coordinates of the upper left point
	cout << '(' << xlibo << ',' << ylibo << ')' <<endl;
    dispArray();//prints orginal view
    delay();
    changeView();
	cout << '(' << xlibo << ',' << ylibo << ')' <<endl;
    dispArray();//prints new view 
}//one

void wereld::go(){
    int i;
	//the rule below prints the coordinates of the upper left point
	cout << '(' << xlibo << ',' << ylibo << ')' <<endl;
    dispArray();//prints orginal view
    for(i = 0; i <numberG; i++){
        delay();
        changeView();
		cout << '(' << xlibo << ',' << ylibo << ')' <<endl;
        dispArray();//prints new view
    }//for
}//go

void world::shift(){//enables the user to shift the view 
	char option2;
	cout <<"Shift view (u)p, (d)own,"
	     <<"(r)ight or (l)left: ";
	leesOptie(option2);
        switch (option2){//processes user's choice
          case 'u'://shift to outside world will be ignored
            if(ylibo - shiftPara >= 0){//prevents segmentation errors
		      ylibo = ylibo - shiftPara;
              height = height - shiftPara;}//if
            break;
          case 'd':
            if(ylibo + shiftPara < maxLength){
		      ylibo = ylibo + shiftPara;
              height = height - shiftPara;}//if
            break;
          case 'r':
            if(xlibo + shiftPara < maxWidth){
		      xlibo = xlibo + shiftPara;
              width = width + shiftPara;}//if
            break;
          case 'l':
            if(xlibo - shiftPara >= 0){
		      xlibo = xlibo - shiftPara;
              width = width + shiftPara;}//if
            break;
		}//switch
}//shift

int checkChar(char token){//help function for readFile
    int value;
    if(token == ' ')
       return value = 0;
    else return value = 1;
}//checkKar

void readFile(wereld & abc){ //reads a file
    string fileName;
    ifstream inPut;
    char kar;
    int i = 0, j = 0, cell;

    abc.clear();//gives a 2D-Array with dead cells

    cout << "Enter file name: "<<endl; //asks user for a file
    cin >> fileName;

    inPut.open(fileName.c_str()); //checks if file exists
    if (inPut.fail()){
        cout << "Non existent file" <<endl;
        exit (1);
    }//if

    kar = inPut.get();
    while(!inPut.eof()){
        if (kar == '\n'){//checks for end of line
            j = 0; i++;//shifts a row down and starts with column 1
        }//if
        else if (kar != '\r'){//convert kar to 1 or 0 and writes to view
            cel = checkKar(kar);
            abc.view[i][j] = cell; j++;
        }//else
        kar = inPut.get();
    }//while
}//leesFile

void parameters(world & abc){//displays parameter menu 
                              //and starts associated functionss
    char option1 = 'x';
    while(option1 != 'B'){
        cout <<"Select: (B)ack to main menu, (H)eigt and width, "
             <<" (S)hift, (P)ercentage, (C)haracters: "<<endl;
        leesOptie(option1);
        switch (option1){//verwerkt submenu
          case 'B':
            break;
          case 'H':
            abc.heightAndWidth();
            break;
          case 'S':
            abc.setShift();
            break;
          case 'P':
            abc.percentage();
            break;
          case 'C':
            abc.characters();
            break;
        }//switch
    }//while
}//parameters

void menu(world & abc){ //initializes the main menu
                         //and starts the requested functions
    char option;//hulpvar
    while (option != 'Q'){
        cout <<"Select: (C)lear, (R)andom, (O)ne, (P)arameters,"
             <<"(F)ile, (G)o, (S)hift, (Q)uit: ";
        leesOptie(option);
        switch (option){ //verwerkt menukeuze
          case 'C':
            abc.clear();
            break;
          case 'R':
            randView(abc);
            break;
          case 'E':
            abc.one();
            break;
          case 'P':
            parameters(abc);
            break;
          case 'G':
            abc.go();
            break;
          case 'F':
            readFile(abc);
            break;
          case 'S':
            abc.shift();
            break;
          case 'Q':
            break;
        }//switch
    }//while 
}//menu

void infoblock(){//Shows info block
    cout <<"-----------------------------------" <<endl;
    cout <<"| Conway's Game of Life           |"
    cout <<"| This program is made by:        |" <<endl;
    cout <<"| Azem Somer, MSc, LIPC-1         |" <<endl;
    cout <<"-----------------------------------" <<endl;
}//

int main(){
    world southKimmLand;//intializes a world
    //Default settings
    randView(southKimmLand);
    infoblok();
    menu(southKimmLand);//starts the menu
    return 0;
}//main
