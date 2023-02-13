//Example of template class, friend operator overloading
//2/13/19 gz All rights reserved.
#include <iostream>
using std::cout;

template <class T>
class MyPair {
    T a, b;
  public:
    MyPair (T first, T second):a(first),b(second){}

    void display(){
        cout << a << " " << b ;
    }
    
    //note, friend function using template T
    template <class U>
    friend void operator+(MyPair<U> &, U);
};

template <class T>
void operator+(MyPair<T> & mp, T t) {
  mp.a += t;
  mp.b+=t;
}

int main () {
  MyPair<int> pair (1, 2); //supply <int> in replace of template T datatype
  
  pair + 1; //function call of operator+()
  pair.display();
    
  return 0;
}
