//class demo
// 3/6/19 gz

#include <iostream>
using namespace std;

int main() {
  
	int num = 10;
	int * ptr = &num;
	int **pptr = &ptr; //pointer to pointer

	//dereference
	cout << *ptr << endl //10
        << **pptr << endl; //10

	//whose memory is it? - &num
	cout << *pptr << endl
        << ptr << endl
        << &num << endl << endl; 

	//whose memory is it? - &ptr
	cout << pptr << endl
        << &ptr << endl;

	return 0;
}