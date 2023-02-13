#include <iostream>
#include <stdio.h>
//4/25/21 gz 

// Anonymous union type
// S has three variant members (c, i, d).
struct S
{
    union
    {
        char c;
        int i;
        double d;
    };
    
   
};

//Named union. Can be treated as a special type of struct
union U {
        char uc;
        int ui;
        double ud;
};

//user-defined function, so that we can print out the address of each variance to see they are pointing to the same memory location.
void print_s(const S& s)
{
  std::cout << &(s.c)<< "; s.c: " << s.c << std::endl;
  std::cout << &(s.i)<< "; s.i: " <<s.i << std::endl;
  std::cout << &(s.d)<< "; s.d: " << s.d << std::endl;
}
 
int main()
{
    //test anonymous union
    S s = {'a'};
    print_s(s);
    s.i = 123;
    print_s(s);
    s.d = 77.7;
    print_s(s);
    
    //test named union
    U u = {111};
    std::cout << u.ui << "\n";
    
}