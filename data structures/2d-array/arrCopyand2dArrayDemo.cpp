#include <iostream>
using std::cout;
using std::endl;

//gz 2018 All rights reserved.

int main()
{
   //declare two one-dimensional arrays. The first one is initialized. The second one is an empty array.
   int nums1[3] = {1,2,3};//you can access to each element via nums1[0] , nums1[1], num1[2]
   int nums2[3];

   //cout << nums1 << endl;//this will display the memory address of the first byte of the array nums1
   //cout << nums2 << endl;//this will display the memory address of the first byte of the array nums2
   // Therefore you can not copy one array from another using "=". For example, you can not do nums2 = nums1;

   // array copy using loop to copy the value of each element over to the new array
   for(int i=0;i<3;i++) {
       nums2[i] = nums1[i];
   }

   // traverse an array and display each element
   for(int i=0;i<3;i++) {
      cout << nums2[i] << endl;
   }


   //2-dimensional array
   const int numOfRows = 3;
   const int numOfCols = 5;
   int table[numOfRows][numOfCols];
   int count = 0;

   //outer loop: rows
   for(int i=0;i<3;i++){
       //inner loop: columns
       for(int j=0;j<5;j++){
           table[i][j] = ++count; // we will assign sequential integer numbers starting from 1 to the 2-d array elements
           cout << table[i][j] << " ";
       }
       cout << endl; //this newline separates each rows
   }

   //The following is the new way -- Ranged-based for loop -- to do the 2-d array traverse.
   for(auto &row: table) { // Here  the & is a MUST and you will need to use 'auto' datatype because the element of each row is an array.
       for(int column: row){ // If you want to update each element, you will need to put & infront of column
           cout << column << " ";
       }
       cout << endl;
   }



    return 0;
}
