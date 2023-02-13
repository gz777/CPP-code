//
//  OpO.cpp
//  cpp_demo
//
//  Created by gz on 9/8/20.
//  Copyright © 2020 gz. All rights reserved.
//

#include "OpO.h"
//function call -
//infix: thisObj * i
//regular method call: thisObj.operator*(i)
void OpO::operator*(int i) {
    this->i *= i;
}

//infix: thisObj + thatObj
//method: thisObj.operator_(thatObj)
void OpO::operator*(const OpO & that) {
    this->i *= that.i; //why we can directly use . notation here for private variable i?
}
