//
//  main.cpp
//  cpp_demo
//
//  Created by gz on 9/8/20.
//  Copyright © 2020 gz. All rights reserved.
//

#include "OpO.h"
#include "Account.h"

// templated user defined function
template<typename T>
T add2(T a, T b) {
    return a + b;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    //overloading test code
    OpO opo1(10), opo2(20);
    opo1 * 2; //opo1.operator*(2)
    opo1 * opo2; //infix notation
    opo1.show();
    
    //template test code
    add2<int>(2,3);
    add2<char>('+','-');//what is the result?
    
    //abstract class test code
    SavingsAccount sa(1000, 0.1);
    sa.printBalance();
    
    CheckingAccount * caPtr = new CheckingAccount(2000);
    Account * accPtr = dynamic_cast<Account*>(caPtr);
    accPtr->printBalance();
    delete caPtr;
    
    return 0;
}
