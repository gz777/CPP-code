// function template
#include <iostream>
using namespace std;

template <class T>
T getSum (T a, T b) {
  T result;
  result = a+b;
  return (result);
}

int main () {
  int i=5, j=6, intTotal;
  float l=10.5f, m=5.4f, floatTotal;
  intTotal=getSum<int>(i,j);
  floatTotal=getSum<float>(l,m);
  cout << intTotal << endl
       << floatTotal << endl;
  return 0;
}
