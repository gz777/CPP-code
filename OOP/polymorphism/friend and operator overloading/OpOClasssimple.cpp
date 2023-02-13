 /* BCS370 Demo code
 user-defined function: operator overloading
 Date: 9/15/2020
 gz All rights reserved.*/
 #include <iostream>
 using std::cout;

  class X {
    int i;
   public:
    X(int i=0) { this->i = i;} //constructor
    void show(string);
    
    //operator overloading
	void operator*(int);// member binary operator

};

void X::show(string objName) {cout << objName <<"'s i is: " << i << endl;}
void X::operator*(int a) { i = i*a;}


int main() {
  X x(10);
  
  cout << "[Multiplication]\n";
  x * 10;
  x.show("x");
  
  return 0;
}
