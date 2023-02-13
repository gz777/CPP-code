/* 
The program was created for illustration on move semantics and its related deep copy approach, solely for the use of FSC BCS370 course.
Author: grace zhao
Date: 10/7/2021
All rights reserved.
Reference: https://stackoverflow.com/questions/67772282/problems-with-move-constructor-and-move-overloaded-assignment-operator 
*/
#include<iostream>
#include<cstring>
class A {
    int p;
    char * s; //pointer. we will need deep copy.
  public:
    /*constructors*/
    A();                            //  0 arg ctor
    A(int,const char*);             //  2 arg ctor
    A(const A&);                    //  copy ctor
    A(A&&) noexcept;                //  Move ctor
    
    /*overloading assignment operator*/
     A& operator=(A);               // `OCSAO` copy-and-swap
    //A& operator=(const A&) ;        // `OAO` overloaded as assignment operator
    //A& operator=(A&&) noexcept;     // `OMAO` // noexcept: to prevent source object to unknown state
    
    /*destructor*/    
    ~A();                           // dctor destructor
    
    
    void display();
    void swap(A&);
};

//default constructors
A::A():p(0),s(nullptr)                      // O arg ctor
{
    printf("0 arg constructor\n");
        
}

A::A(int k1,const char *str)                 // 2 arg ctor
{
    printf("2 arg constructor with %d and %s\n", k1,str);
    
    p=k1;
    s=new char[strlen(str)+1];
    strcpy(s,str);
}

//copy constructors
A::A(const A &a)                             // copy ctor
{
    printf("Copy constructor\n");
    
    p=a.p;
    s=new char[strlen(a.s)+1];
    strcpy(s,a.s);
    
}

A::A(A&& a) noexcept: p(a.p), s(a.s)                // Move ctor
{
    printf("Move copy constructor\n");
    //p = std::move(a.p);
    //s = std::move(a.s);
    a.s = nullptr;
    a.p = 0;
    
}

//overloaded assignment operator
A& A::operator=(A a) {
    swap(a);
    printf ("Copy and Swap OAO \n"); //OCSAO = OAO+OMAO it does both jobs
    return *this;
}

/*
A& A::operator=(const A &a)                 // Overloaded assignement opeator `OAO`
{
    printf("overloade= operator\n");
    
    if (this != &a)// Don't assign to self
    {
        p = a.p;
        delete[] s;
        s = new char[strlen(a.s) + 1];
        strcpy(s, a.s);
    }
    return *this;
    
}

A& A::operator=(A&& a) noexcept         // `OMAO`
{
    printf("Move overload operator=\n");

    if (this != &a) {
        p = a.p;
        delete [] s;
        s = a.s;
        a.s = nullptr;
    }
    return *this;
}
*/

//destructor
A::~A()                                       // Dctor
{
    delete []s;
    printf("Destructor\n");
    
}

void A::display()
{
    printf ("%d %s\n", p, s);
    
}

void A::swap(A& o) {
    std::swap(p,o.p);
    std::swap(s,o.s);
}

//standalone function - factory function
A make_A(int i, std::string str) //replace A make_A(int,char*) for convenience
{
    A a(i,str.c_str());
    printf("Inside make_A\n");
    return a; //temporary unnamed object - Rvalue
}


void printReference(A& value)
{
        printf ("Lvalue reference \n");
}
 
void printReference(A&& value)
{
        printf ("Rvalue reference \n");
}


int main()
{
    printReference(make_A(8, "hi"));
    
    A a1(make_A(7, "hello")); //if NRVO (Move or Named Return Value Optimization) apply, then a is construct "in-place" so no extra destruction/move happens;
                              //copy elision: https://en.cppreference.com/w/cpp/language/copy_elision
                              //In the initialization of an object, when the initializer expression is a prvalue of the same class type (ignoring cv-qualification) as the variable type:
                              // e.g. T x = T(T(f())); // only one call to default constructor of T, to initialize x
    //A b1(std::move(a1));
    
    //b1.display();
    a1.display();
   
    /*A a2 = std::move(b1);//=(A&&)b1
    printReference(a2);
    a2.display();
    b1.display();*/
    
    return 0;
}


