//BCS370 demo code
//memory leak and pointer dangling
//2/12/20
//Note: I used pointer arithmetic in different ways to loop through the dynamic array
#include <iostream>


int main()
{
  double * ptr = new double[3];
  for (double* p=ptr;p<ptr+3;p++)//initialize values to each element. pointer arithmetic
    *p = 2.3;//assign 2.3 to all elements
  
  for(int i=0;i<3;i++)//traverse the dynamic array
    std::cout << ptr[i] << std::endl;
    
  double * ptr1 = new double[3];
  /*
  ptr1 = ptr; //shallow copy + memory leak (memory location that ptr1 originally pointed to
  delete [] ptr1; //dangling pointer - ptr
  */
  
  //deep copy
  for(int i=0;i<3;i++)//traver the dynamic array
    *(ptr1+i) = *(ptr+i);//pointer arithmetic

  for(int i=0;i<3;i++)//traverse the dynamic array
    std::cout << *(&ptr1[i]) << std::endl;//pointer arithmetic
  
  delete [] ptr;
  delete [] ptr1;
  
}