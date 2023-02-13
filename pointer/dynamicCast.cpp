// How to cast from base to derived objects or vise versa
// 1/30/20 gz

#include <iostream>

class Base{
    public: 
        void print() { std::cout<<"Base"<<std::endl;}
};

class Derive : public Base{
    public:
        void print() { std::cout<<"Derived"<<std::endl;}
};

int main()
{
  Derive d;
  d.print();  
 
  //using references
  
  //Base &b = d;//this will work. Or the following
  Base &b = dynamic_cast<Base&>(d);
  
  b.print();
  
  //OR, using pointers
  //Base *b1 = &d;//this will work. Or the following
  Base *b1 = dynamic_cast<Base*>(&d);
  
  b1->print();
  
  return 0;
}
