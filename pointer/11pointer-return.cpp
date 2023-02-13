/*
Pointer demo code 10
Returning a pointer from a function
C++ allows a function to return a pointer to local variable, static variable and dynamically allocated memory as well.
1) it is not good idea to return the address of a local variable to outside of the function, so you would have to define the local variable as static variable.
2) The function must not return a pointer to a local variable in the function
3)The function should only return a pointer
   - to data that was passed to the function as an argument
   - to dynamically allocated memory
*/
#include <iostream>
#include <ctime>

using namespace std;

// function to generate and retrun random numbers.
int * getRandom( ) {//Not a good idea. static variable is not secure in this way.
   static int  r[10];

   // set the seed
   srand( (unsigned)time( NULL ) );

   for (int i = 0; i < 10; ++i) {
      r[i] = rand();
      cout << r[i] << endl;
   }

   return r;
}

// main function to call above defined function.
int main () {
   // a pointer to an int.
   int *p;

   p = getRandom();
   for ( int i = 0; i < 10; i++ ) {
      cout << "*(p + " << i << ") : ";
      cout << *(p + i) << endl;
   }

   return 0;
}
//BASICALLY, DO NOT RETURN A POINTER! EXCEPTION: this POINTER in a class declaration.
