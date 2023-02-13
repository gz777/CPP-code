/************************************************
 10/30/18
const dereferenced value, const pointer value
*************************************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{

    int num = 10, age=20;

    int * const prt = &num; //A constant pointer is a pointer whose data (the address in the pointer) cannot change
                            //must be initialized at the time of declaration
    //prt = &age; //you can't do this because pointer value is a constant

    const int * prt1 = &num; //Pointer to Constant

    //*prt = 20;//you can not do this


    cout << *prt << endl;


    return 0;
}
