// class templates
//http://www.cplusplus.com/doc/oldtutorial/templates/
#include <iostream>
using namespace std;

template <class T>
class MyPair {
    T a, b;
  public:
    MyPair (T first, T second)
      {a=first; b=second;}
    T getmax ();
};

template <class T>
T MyPair<T>::getmax ()
{
  T retval;
  retval = a>b? a : b;
  return retval;
}

int main () {
  MyPair <char> myobject ('z', '-');
  cout << myobject.getmax();
  return 0;
}
