//BCS370 class demo - operator overloading
//2/9/21 gz

#include <iostream> 

class Student{
  private:
     int ID;
     std::string name;
  public:
   Student() { ID = 0; name = "";}
   void operator+(int rightOperand) { //this object
     ID += rightOperand;
   }

   void setID(const int id) {
     ID = id;
   }

    int getID() const {
     return ID;
   }

};
/*
//user-defined function
void operator+(Student & leftOperand,int rightOperand) {
    leftOperand.ID += rightOperand;
}
*/


int main() {
  
  Student john;
  john.setID( 1001 );
  john.operator+(1);

  john + 10;//infix

  std::cout << john.getID(); 
}