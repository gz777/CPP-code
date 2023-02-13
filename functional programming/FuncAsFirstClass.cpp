#include <iostream>
//gz 2018
void my_int_func(int x) {
    std::cout<< x <<std::endl;
}
 
 
int main() {
    void (*foo)(int);
    foo = &my_int_func;//& is optional
 
    /* call my_int_func (note that you do not need to write (*foo)(2) ) */
    foo( 2 );
    /* but if you want to, you may */
    (*foo)( 2 );
}
