// C++ code to demonstrate the macros for data types
// source: https://www.geeksforgeeks.org/data-type-ranges-and-their-macros-in-c/
// modified by gz 10/2/18
#include <iostream>
#include <limits.h> // for int,char macros
#include <float.h> // for float,double macros
using namespace std;
int main()
{

char c = 'c';
bool b = true;
short s = 23;
int i = 12345;
float f = 11.5;
double d = 11.5;

// Displaying the size of variables
cout << "The number of bytes of char c is: " << sizeof(c) << endl
     << "The number of bytes of bool b is: " << sizeof(b) << endl
     << "The number of bytes of short s is: " << sizeof(s) << endl
     << "The number of bytes of int i is: " << sizeof(i) << endl
     << "The number of bytes of float f is: " << sizeof(f) << endl
     << "The number of bytes of double s is: " << sizeof(d) << endl;

// Displaying the size of literals
cout << "The number of bytes of a char value|constant|literal ('a') is: " << sizeof('a') << endl
    << "The number of bytes of a string value (\"a\") is: " << sizeof("a") << endl
    << "The number of bytes of a boolean value (false) is: " << sizeof(false) << endl
    << "The number of bytes of a float value (11.4f) is: " << sizeof(11.4f) << endl
    << "The number of bytes of a double value (11.4) is: " << sizeof(11.4) << endl << endl;


// Displaying ranges with the help of macros
cout << "char ranges from : " << CHAR_MIN << " to " << CHAR_MAX;
cout << "\n\nshort char ranges from : " << SCHAR_MIN << " to " << SCHAR_MAX;
cout << "\n\nunsigned char ranges from : " << 0 << " to " << UCHAR_MAX;

cout << "\n\n\nshort int ranges from : " << SHRT_MIN << " to " << SHRT_MAX;
cout << "\n\nunsigned short int ranges from : " << 0 << " to " << USHRT_MAX;
cout << "\n\nint ranges from : " << INT_MIN << " to " << INT_MAX;
cout << "\n\nunsigned int ranges from : " << 0 << " to " << UINT_MAX;
cout << "\n\nlong int ranges from : " << LONG_MIN << " to " << LONG_MAX;

cout << "\n\nunsigned long int ranges from : " << 0 << " to " << ULONG_MAX;
cout << "\n\nlong long int ranges from : " << LLONG_MIN << " to " << LLONG_MAX;
cout << "\n\nunsigned long long int ranges from : " << 0 << " to " << ULLONG_MAX;

cout << "\n\n\nfloat ranges from : " << FLT_MIN << " to " << FLT_MAX;
cout << "\n\nnegative float ranges from : " << -FLT_MIN << " to " << -FLT_MAX;
cout << "\n\ndouble ranges from : " << DBL_MIN << " to " << DBL_MAX;
cout << "\n\nnegative double ranges from : " << -DBL_MIN << " to " << +DBL_MAX;

return 0;

}
