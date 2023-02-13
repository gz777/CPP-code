//10/23/18 class demo Knowing pointer data type
//Demo code 5: pointer arithmatic
//Updated: 2/17/19
//This demo code aims to give a complete picture of array element address and value expressions. You may pick the one that makes the most sense to you.

#include <iostream>
using namespace std;

int main()
{
  short numbers[] = {10, 20, 30}; //short: 2 bytes
  short * shortPtr = numbers;

  //first element address
  cout << "The memory address of the first element of the array is:\n";
	cout<< numbers << endl
		<< shortPtr << endl
		<< &numbers[0] << endl;
 
	//first element value	
   cout << "\nThe value of the first element of the array is: \n";
	cout<< numbers[0] << endl
	 	  << *shortPtr<< endl
		  << *(&numbers[0]) << endl
		  << *numbers << endl;

  //second element address
  cout << "\nThe memory address of the second element of the array is: \n";
  cout << numbers + 1 << endl
       << &numbers[1] << endl
       << shortPtr + 1 << endl;

  //second element value     
	cout << "\nThe value of the second element of the array is:\n";
	cout << numbers[1] << endl
   		 << *(&numbers[1]) << endl
   	   << *(numbers + 1) << endl
   	   << *(shortPtr + 1) << endl;
   	    
	cout<< *(++shortPtr) << endl << endl; // Note: ++shortPtr will change the value of shortPtr

  //now how can I display the address and value of the third element of the array?

	shortPtr = numbers;//We reset this because we did ++shortPtr earlier.

  cout << "Loop through the array" << endl;
	for (int index = 0; index < sizeof(numbers)/sizeof(numbers[0]); index++) //sizeof(numbers)/sizeof(numbers[0]) only applicable to primitive datatypes
	{
    //method 1
      // cout << *shortPtr << " ";
      // shortPtr++; //same as ++shortPtr

    //method 2
      //cout << *(shortPtr + index) << endl;

    //method 3
      cout << *(numbers + index) << endl;
                    
	}

  
	cout << endl;



   return 0;
}