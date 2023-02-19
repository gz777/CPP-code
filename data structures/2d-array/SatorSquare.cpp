/******************************************************************************
Sator Square 
Description: The program varifies if the 2d array is a sator square or not
Requirements: Using OOP programming paradigm. Language: C++. SS size >=2
gz 2/15/23 All rights reserved.
Code can be directly run via: https://onlinegdb.com/ognei5uQ9
See more on Sator Square: https://en.wikipedia.org/wiki/Sator_Square
Updated algorithm 2/19/23
*******************************************************************************/

#include <iostream>
using std::cout;
using std::endl;

#define MAXSIZE 10

class SS{
    private:
    int size;
    char ss[][MAXSIZE];
    
    public:
    SS(int s, char arr[][MAXSIZE]) {
        size = s;
        for (int i=0;i<size;i++) {
             for (int j=0;j<size;j++) 
               ss[i][j] = arr[i][j];
        }
    }
    
    bool testSS() {
        for (int i = 0; i<size/2; i++) {//size/2: we only need to do symmetric comparisons 
            for (int j = i; j<size; j++) { //j=i: no duplicate comparisons
                if (ss[i][j] != ss[size-i-1][size-j-1]) //upper right to lower left diagonal line symmetry.
                    return false;
            }
        } 
        return true;
    }
    
};

int main()
{
    //test code
    char t1[3][MAXSIZE]  = { {'a','b','c'},
                       {'b','d','b'},
                       {'c','b','a'}};
       
    char t2[4][MAXSIZE]  = { {'a','b','c','d'},
                       {'b','e','f','c'},
                       {'c','f','e','b'},
                       {'d','c','b','a'}};

    char t3[2][MAXSIZE] = { {'a','b'}, {'b','a'}};
    
        
    SS test1(3,t1); //Do NOT declare two or more objects on the same line, comma separated, due to C++ quirkness/potential bugs on 2d array assignments.
    cout << "test1: " << test1.testSS() << endl;
 
    SS test2(4, t2);
    cout<< "test2: " << test2.testSS() << endl;
    
    SS test3(2, t3);
    cout << "test3: " << test3.testSS() << endl;
      
    return 0;
}

