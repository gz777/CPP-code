//
//  main.cpp
//  cpp_demo
//
//  Created by gz on 9/8/20.
//  Copyright © 2020 gz. All rights reserved.
//

#include "OpO.h"
#include "Account.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    //abstract class test code
    SavingsAccount sa(1000, 0.1);
    sa.printBalance();
    
    CheckingAccount * caPtr = new CheckingAccount(2000);
    
    Account * accPtr = dynamic_cast<Account*>(caPtr);
    accPtr->printBalance();
    delete caPtr;
    
    return 0;
}
