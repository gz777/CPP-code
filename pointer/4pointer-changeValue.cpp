//10/23/18 class demo Knowing pointer data type
//Demo code 3: changing values

#include <iostream>
using namespace std;

int main() {
	int n = 10;
	
	int * intPrt = nullptr;
	intPrt = &n;
	
	cout << "Value of intPrt is: " << intPrt << endl;
	cout << "Address of n is: " << &n << endl;
	cout << "Value of n is: " << n << endl;
	cout << "Dereferenced intPrt is: " << *intPrt << endl;
	cout << "Address of intPrt is: " << &intPrt << endl;
	
	n = 20;
	cout << "Dereferenced intPrt is: " << *intPrt << endl;
	
	*intPrt = 5;
	cout << "Dereferenced intPrt is: " << *intPrt << endl;
	
	//assign pointer to another address
	int m = 30;
	intPrt = &m;
	cout << "Dereferenced intPrt is: " << *intPrt << endl;
	
	return 0;
}
