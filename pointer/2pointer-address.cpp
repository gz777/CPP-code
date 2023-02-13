//10/23/18 class demo Knowing pointer data type -- pointer value: memory address
//Demo code 1: knowing memory address - address operator
// This program uses the & operator to determine a
// variable's address.
// Why pointer needs a datatype? The Data type is needed when dereferencing the pointer so it knows how much data it should read. For example dereferencing a char pointer should read the next byte from the adress it is pointing to while an int pointer should read 2 bytes.

#include <iostream>
using namespace std;

 
int main()
{  
    char letter='c';
	short number =0;
	float amount = 0.0f;
	double profit = 0.0;
	bool flag = true;
	int numbers[3] = {1,2,3};

    // Print address of each variable
    // The cast to long long makes addresses print in decimal
    // rather than in hexadecimal
    
    cout << "Address of number is:  " << &number <<" " << (long long)&number<< endl;//By default, memory address is displayed as hexadecimal. Casting long long, will display the address in decimal.
         
    cout << "Address of amount is:  " 
         << &amount << endl;
    cout << "Address of profit is:  "
         << &profit << endl;
	cout << "Address of flag is:  "
         << (long long)&flag << endl;
    cout << "Address of letter is:  "
         << (void *)&letter << endl;
    cout << "Address of array numbers is: "
		 << (long long)numbers << endl;
	cout << "Addres of numbers[1] is: "
		 <<(long long) &(numbers[1])<< endl;

    return 0;
 }
