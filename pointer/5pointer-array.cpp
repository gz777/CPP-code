//10/23/18 class demo Knowing pointer data type
//Demo code 4: array reference, dereferencing
#include <iostream>
using namespace std;

void test(int t[]){//a pointer that points to the array
    cout << "function: " << sizeof(t) << endl;
}

int main()
{
    short numbers[] = {10, 20, 30, 40, 50};
    
    cout << "Knowing how the address of array works: \n"
    	 << "First element address: \n"
    	 << numbers << endl
    	 << &numbers[0] << endl << endl
    	 
    	 << "Second element address: \n"
    	 << &numbers[1] << endl
    	 << numbers+1 << endl << endl;
    	 //question: can we do ++numbers?
  
	cout << "The first element of the array is \n"
		 << numbers[0] << endl
		 << *numbers << endl
		 << *(&numbers[0]) << endl << endl;
   
	cout << "The second element of the array is \n"
		 << numbers[1] << endl
   		 << *(&numbers[1]) << endl
   	     << *(numbers + 1)  << endl << endl;
   	    
    //now how can I display the fourth element of the array?
    
    cout << "In main(): " << sizeof(numbers) << '\n'; // will print sizeof(int) * array length
    
    test(numbers);
		
	
   return 0;
}
