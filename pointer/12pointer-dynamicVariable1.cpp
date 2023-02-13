/*
10/30/19
Dynamic variable, array...
Dynamic memory allocation in C/C++ refers to performing memory allocation manually by programmer.
4/3/2020
Added dangling pointer prevention code
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
  int * size_ptr = nullptr, *array_ptr;//"Dangling pointer"
                                       //A dangling pointer points to memory that has already been freed.
                                       //So, it's always a good habit to initialize a pointer with nullptr
  size_ptr = new int; //new (keyword) returns address of a memory location (in heap) //annonymous variable

  cout << "how many students? ";
  cin >> *size_ptr;//de-reference -- value of the annonymous variable

  array_ptr = new int[*size_ptr];//new returns the address of the first byte memory location in the annonymous array with size - dsize, datatype int, in heap

  for (int i=0; i<*size_ptr; i++)
  {
    cout << "Enter id for student " << i+1 << ": ";
    cin >> array_ptr[i];
  }

  for(int i=0; i<*size_ptr; i++) {
      cout << *array_ptr << " ";
      array_ptr++; //pointer arithmatic
                   //cout << *(array_ptr + i) << endl; //shorter way
  }

  /*IMPORTANT, prevent memory leaking
    A memory leak occurs if no-longer-needed dynamic memory is not freed.
    General rule: whenever there is a "new" operator, there should be a corresponding "delete" operator following up when the dynamic variable is no longer in need.
  */

  delete size_ptr; //delete keyword releases Dynamic Memory (deallocate memory)
  delete [] array_ptr;
  //Question: what if you reassign array_ptr to another array address before the dynamic array gets deleted?
  //Memory leak

  /*
  A pointer pointing to non-existing memory location is called dangling pointer.

  Dangling pointers arise when an object is deleted or de-allocated, 
  without modifying the value of the pointer, so that the pointer 
  still points to the memory location of the de-allocated memory.
  */
  size_ptr = nullptr; //prevent dangling pointer.
  array_ptr = nullptr;


  return 0;
}
