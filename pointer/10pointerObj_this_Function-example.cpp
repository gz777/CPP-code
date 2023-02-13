/*
pointer declaration
pointer initialization
reference
dereference

this object
Rvalue
pass pointer as parameter v.s. pass obj as parameter

gz 2/22/19

*/

#include <iostream>

using namespace std;

class Student{
  int i;
  public:
  Student(int i=0) { 
      //display this address
      cout << "Inside class, &(*this): " <<  &(*this) << endl; 
      cout << "Inside class, this address: " << this << endl; 
      //cout << &this;//you can not do this because this pointer is a Rvalue
      this->i=i;
  }
  int getI() {return i;}
  void setI(int i) {this->i = i;}
};

//function overloading
//Let us do function passing pointer as parameter
void getStudent(Student * s) {
    s->setI(5);
    cout <<"inside getStudent() w pointer: " << s->getI() << endl;
}

//pass obj - pass by value
void getStudent(Student s) {
    s.setI(6);
    cout <<"inside getStudent() w obj: " << s.getI() << endl;
}


int main()
{
    Student s1(2);
    Student * ptr_s2 = nullptr;//initialization
    ptr_s2 = &s1;
    
    //calling member function
    cout << " s1 getI(): " << s1.getI()<<endl;
    cout << " s2 getI: " << ptr_s2->getI() << endl;
     
    //display this obj address
    cout << "&s1: " << &s1 << endl;
    cout << "ptr_s2: " << ptr_s2 << endl;
    cout << "&(*ptr_s2): "<< &(*ptr_s2) <<endl;
   
    //function call to getStudent(), which one is calling which function signature?
    getStudent(s1);
    getStudent(&s1);
    getStudent(*ptr_s2);
    getStudent(ptr_s2);
    
    //would i change its value? If yes, to which number?
    cout << s1.getI() << endl;
    cout << ptr_s2->getI() << endl;
    
    return 0;
}
