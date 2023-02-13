//nynamic 2d array example
//https://gsamaras.wordpress.com/code/dynamic-2d-array-in-c/
//modified by gz 3/3/19

#include <iostream>
 
int main() {
  // dimensions
  int ROW = 3;
  int COL = 3;
 
  // dynamic allocation
  int** ary = new int*[ROW];
  for(int i = 0; i < ROW; ++i)
      ary[i] = new int[COL];
 
  // fill
  for(int i = 0; i < ROW; ++i)
    for(int j = 0; j < COL; ++j)
      ary[i][j] = i+1;
 
  // print
  for(int i = 0; i < ROW; ++i) {
    for(int j = 0; j < COL; ++j)
      std::cout << ary[i][j] << " ";
    std::cout << "\n";
  }
  
  // free
  for(int i = 0; i < ROW; ++i)
    delete [] ary[i];
  delete [] ary;
 
  return 0;
} 