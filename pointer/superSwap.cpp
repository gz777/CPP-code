//In-class lab: To create a user-defined function to swap two pointers' values (memory addresses)
// 3/6/19 BCS 370

#include <iostream>
using namespace std;

//reminiscence of pass-by-reference
void superSwap(int& a, int& b){
	int  temp = a;
	a = b;
	b = temp;
}

/*void superSwap(int *a, int *b) {//another of my version
   int c = *a;
   *a = *b;
   *b = c;
}*/

//Purvil's solution
void superSwap(int* &a, int* &b){//Notice: "int*" is the data type, &a is the pass-by-reference
	int * temp = a;
	a = b;
	b = temp;
}

//point-to-pointer solution
void superSwap(int** a, int** b){
	int * temp = *a;
	*a = *b;
	*b = temp;
} 

int main() {

   int a = 10, b=20;
   superSwap(a,b);//pass by reference
   cout << a << " " << b << endl; //should display 20, 10
   
   
   int * ptr1 = &a, *ptr2 = &b;
   superSwap(ptr1,ptr2); //pass by reference of pointer
   cout << *ptr1 << " " << *ptr2 << endl; //should display 10, 20
   
  
   superSwap(&ptr1, &ptr2); //pass to pointer
   cout << *ptr1 << " " << *ptr2 << endl; //should display 20, 10

 

  return 0;

}
