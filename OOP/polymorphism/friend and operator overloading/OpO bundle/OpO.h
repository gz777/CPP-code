//
//  OpO.h
//  cpp_demo
//
//  Created by gz on 9/8/20.
//  Copyright © 2020 gz. All rights reserved.
//
#ifndef OPO_H
#define OPO_H

#include <iostream>

class OpO {
    int i;
   public:
    OpO(int i=0) { this->i = i;} //constructor
    void show() {std::cout << "i is: " << i << std::endl;} //util method
    
    /*
     operator overloading
     binary operator *, takes a primitive datatype argument
     */
    void operator*(int); // member binary operator
    
    /*
     operator overloading
     binary operator *, takes an object  parameter
     */
    void operator*(const OpO &);
};
#endif /* OPO_H */
