/******************************************************************************
 Sator Square 
 Description: The program varifies if the 2d array (n * n, n>=2) is a sator square or not
 Requirements:
     Programming paradigm: OOP
     Data Structure: Dynamic array
     Programming Language: C++.
 gz 2/20/23 All rights reserved.
 Code can be directly run via: https://onlinegdb.com/K4ikSE1QHG
 See more on Sator Square: https://en.wikipedia.org/wiki/Sator_Square
 *******************************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


class SS{
    private:
    int size;
    char ** ss;
    
    public:
    SS(int s, char ** arr) {
        size = s;
        ss = new char*[size];
        
        for(int i = 0; i < size; ++i)
            ss[i] = new char[size];
            
        for (int i=0;i<size;i++) {
             for (int j=0;j<size;j++) 
               ss[i][j] = arr[i][j];
        }
    }
    

    ~SS() { //destructor, !important
        for (int i=0;i<size;i++) {
            delete [] ss[i]; //deallocate rows
        }
        delete [] ss; //deallocate cols
        ss = nullptr;
    }
    
    bool testSS() {
        for (int i = 0; i<size/2; i++) {//size/2: we only need to do symmetric comparisons 
            for (int j = i; j<size; j++) { //j=i: no duplicate comparisons
                if (ss[i][j] != ss[size-i-1][size-j-1]) {//upper right to lower left diagonal line symmetry.
                    cout << "Mismatch found - i:" << i << " j:" << j << " " << ss[i][j] << " vs " << ss[size-i-1][size-j-1] << endl;//for logging
                    return false;
                    }
            }
        } 
        return true;
    }
    
};

int main()
{
    //test code. Since it's dynamic array, we should not try to hard code the data
    int SIZE;
    cout << "Enter SIZE for n*n square array: "; cin >> SIZE; // n * n square array. n=SIZE
    char ** square;
    
    square = new char*[SIZE]();//declare and initialize elements in a row
    for(int i = 0; i < SIZE; ++i) //declare and initialize number of rows
            square[i] = new char[SIZE]();
            
    cout<<"Enter characters one row at a time\n";
    for(int row=0;row<SIZE;row++) {
           cin >>square[row];
    }
 
    SS ss(SIZE, square);
    cout << ss.testSS();
   
    /*
    [test dataset 1]
    size: 2
    data:
           ab
           ba
           
    [test dataset 2]
    size: 3
    data:
           abc
           bdb
           cba
   
   [test dataset 3]
   size: 4
   data: 
           abcd
           befc
           cfeb
           dcca
   ...
        
    */
    
    return 0;
}

