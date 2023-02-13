/*************************************************************
10/30/18
Pointer demo program 6
this, object pointer, dot notation v.s. ->(arrow operator), function chaining

**************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Student {
     string name;
     int age;
   public:
     Student(){name="";age=0;}
     Student(string name, int age) {this->name = name; this->age = age;}
     string getName() {return name;}
     int getAge(){return age;}
     void printObjMemAddress() { cout << this << endl;}//print the memory address of the current object
    
     /*
       Function chaining.
       <syntax>
          return datatype: className &
          return: *this
      */
     Student& setName(string name) {
         this->name = name;
         return *this;
     }
     Student& setAge(int age) {
         this->age = age;
         return *this;
     }
};

int main()
{

    Student st1("Mark",21);

    st1.printObjMemAddress();//=&st1
    cout << &st1 << endl;
    
    cout << st1.getName() << " " << st1.getAge() << endl;//object, dot notation
    
    Student st2;
    st2.setName("Mary").setAge(19);//function chaining

    Student * st3 = &st1;
    cout << (*st3).getName() << " " << (*st3).getAge() << endl;//object, dot notation
    cout << st3->getName() << " " << st3->getAge() << endl; //pointer, arrow operator
    


    return 0;
}
