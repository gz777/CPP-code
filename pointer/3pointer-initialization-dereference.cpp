//10/23/18 class demo Knowing pointer data type
//Demo code 2: knowing how a pointer variable works
// pointer variable has a pointer data type
// pointer variable's value is always a member address
// The derefereced value of a pointer variable is the value of the variable the pointer is pointing to.
#include <iostream>
using namespace std;

int main() {
	int n = 10;
	
	int * intPrt = nullptr;//initialization
	intPrt = &n;//assigning a memory address (reference) to a pointer
	
	cout << "Value of intPrt is: " << intPrt << endl;
	cout << "Address of n is: " << &n << endl;
	cout << "Value of n is: " << n << endl;
	cout << "Dereferenced intPrt is: " << *intPrt << endl;
	
	return 0;
}
