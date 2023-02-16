/******************************************************************************
Sator Square 
Description: The program varifies if the 2d array is a sator square or not
Requirements: Using OOP programming paradigm. Language: C++. SS size >=2
gz 2/15/23 All rights reserved.
See more on Sator Square: https://en.wikipedia.org/wiki/Sator_Square
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
        for (int i = 0; i<size-1; i++) { // size-1 because we don't need to compare the last element: ss[size-1][size-1]
            if( i < size/2 && ss[i][i] != ss[size-i-1][size-i-1]) //diagonal line symmetry.
                return false;
            for (int j = i+1; j<size; j++) { //no duplicate comparisons
                if (ss[i][j] != ss[j][i] )
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
    
        
    SS test1(3,t1); //Do NOT declare two or more objects on the same line due to C++ quirkness on 2d array.
    cout << "test1: " << test1.testSS() << endl;
 
    SS test2(4, t2);
    cout<< "test2: " << test2.testSS() << endl;
    
    SS test3(2, t3);
    cout << "test3: " << test3.testSS() << endl;
      
    return 0;
}

