/* C++ program to demonstrate the working of friend function.
   https://www.programiz.com/cpp-programming/friend-function-class
   updated: 9/15/2020 gz All rights reserved.
*/

#include <iostream>
class Distance {
    private:
        int meter;
    public:
        Distance(): meter(0) { }
    
        //friend function
        friend int addFive(Distance &);
};

// friend function definition
int addFive(Distance & d)
{
    //accessing private data from non-member function
    d.meter += 5;
    return d.meter;
}

int main()
{
    Distance d;
    addFive(d);
    printf("Distance: %d\n",addFive(d));
   
    return 0;
}
