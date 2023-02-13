//pointer data type -- what type of data is a memory address? How many bytes is it?
//gz 2/20/19

#include <iostream>
using namespace std;


int main()
{
    int number = 5;
    int * int_ptr = &number;

    //how many bytes is a pointer datatype?
    cout << sizeof(int_ptr) << endl;//size of an int pointer
    cout << sizeof(double*) << endl;//size of a double pointer
    cout << sizeof(void*) << endl;//size of a void pointer
    
    int array[] = {1,2,3};
    int *ptr = array;
    cout << sizeof(ptr) << '\n';


    return 0;
}
