 /* BCS230 Demo code
 member function: operator overloading 
 Date: 11/13/18
 gz*/
 #include <iostream>
 using namespace std;

  class X {
    int i;
   public:
    X(int i=0) { this->i = i;} //constructor
    void show(string);
    
    //operator overloading
	void operator*(int);// member binary operator
	void operator+(X x);
    void operator-(int);//binary
    void operator-(); //unary
    X& operator++(); //prefix
    X operator++(int); //postfix. //The int parameter is a dummy parameter used to differentiate between prefix and postfix versions of the operators. When the user-defined postfix operator is called, the value passed in that parameter is always zero
    X& operator=(int);
    

};

void X::operator*(int a) { i = i*a;}
void X::operator+(X x) { this->i += x.i; } //notice x.i

void X::operator-(int a) { i = i-a;}
void X::operator-() { i = -i;}

X& X::operator++() {//prefix
	++i;
	return *this;
}

X X::operator++(int) { //postfix
	i++;
	return X(i-1);
}

X& X::operator=(int a) {
	i = a;
	return *this;
}
void X::show(string objName) {cout << objName <<"'s i is: " << i << endl;}



int main() {
  X x(10);
  
  cout << "[Multiplication]\n";
  x * 10;
  x.show("x");
  
  cout << "\n[Deduction]\n";
  x-10;
  x.show("x");
  
  cout << "\n[Negation]\n";
  -x;
  x.show("x");
  
  cout << "\n[Negation]\n";
  -x;
  x.show("x");
  
  cout << "\n[Prefix]\n";
  X x1 = ++x;
  x1.show("x1");
  
  cout << "\n[Postfix]\n";
  X x2 = x++;
  x2.show("x2");
  x.show("x");
  
  cout << "\n[Assignment] \n";
  x = 3;
  x.show("x");
  
  cout << "\n[Addition between objects] \n";
  x1 + x2;
  x1.show("x1");
  
  
  
  return 0;
}
