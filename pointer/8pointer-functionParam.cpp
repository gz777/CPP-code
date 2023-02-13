/*************************************************************
10/30/18 gz
Pointers as Function Parameters
**************************************************************/

#include <iostream>
#include <string>

using namespace std;

void swap(float&,float&);
void swap(float*, float*);

int main()
{

    float num1 = 20.5f;
    float num2 = 10.5f;

    float * ptr1 = &num1;
    float * ptr2 = &num2;
    swap(ptr1,ptr2);//function call of pointer param
    swap(&num1,&num2);//function call of pointer param

    cout << "num1 is now: " << num1 << endl;
    cout << "num2 is now: " << num2 << endl;

    swap(num1,num2);//function call of pass-by-reference

    cout << "num1 is now: " << num1 << endl;
    cout << "num2 is now: " << num2 << endl;


    return 0;
}

void swap(float& n1, float& n2) {
    float temp = n1;
    n1 = n2;
    n2 = temp;
}

void swap(float* n1, float* n2) {
    float temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
