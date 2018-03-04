/*bignumber class header file
*/
struct field{//struct declaration field
    field* next;//points to next field
    field* previous;//points to previous field
    int info; //contains field data
};//vakje

class bignumber{//declaration of class bignumber
    private://membervariabelen
        field* start;//start pointer to bignumber
        field* end;//end pointer to bignumber
        int numberFields;//number of figure fields
    public://member functions
        bigNumber();
        void print();
        void read();
        void addUp(bignumber gg1, bignumber gg2);
        void threeAndPlus1();
        void makeZeroes(int m);
        void destroy();
        void copy(bignumber & gg2);
        void addBehind(int value);
        void addBefore(int value);
        bool testOne();
        bool testEven();
        void divideBy2();
        void multiplyByThreePlusOne();
        void threeNPlus1();
};//bignumber

