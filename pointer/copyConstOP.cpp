// modified from https://www.tutorialspoint.com/cplusplus/cpp_copy_constructor.htm
// copy constructor and operator overloading =
// if member variables have pointers or arrays
// 11/3 gz
// https://onlinegdb.com/BJ3Rex65H

#include <iostream>
using std::cout;
using std::endl;

class Line {
   public:
      Line(int len = 0) {// simple constructor
          cout << "Call normal constructor allocating ptr" << endl;
          // allocate memory for the pointer;
          len_ptr = new int;
          *len_ptr = len;
      }
      
      Line( const Line &obj) {  // copy constructor
         cout << "Calling Copy Constructor allocating ptr." << endl;
         len_ptr = new int;
         *len_ptr = *(obj.len_ptr); // copy the value
      }
      
      void operator=(const Line &obj) { // void because I don't think return *this make sense here
         cout << "Calling operator overloading method allocating ptr." << endl;
         len_ptr = new int;
         *len_ptr = *(obj.len_ptr); // copy the value
      }
      
      ~Line() {                  // destructor
         cout << "Freeing memory!" << endl;
         delete len_ptr;
      }
      
      int getLength() const { //const is necessary if you will have a user-defined function with pass-by-reference obj param
          return *len_ptr;
      }
   private:
      int *len_ptr;
};

// user-defined function
void display(const Line& obj) { // if you do pass-by- value, the copy constructor will be called again
   cout << "Length of line : " << obj.getLength() << "\n";
}

// Main function for the program
int main() {

   Line line1(10);
   Line line2 = line1; // copy constructor
   Line line3(line1); // copy constructor
   
   Line line4;
   line4 = line1; // operator overloading =

   display(line1);
   display(line2);
   display(line3);
   display(line4);

   return 0;
}