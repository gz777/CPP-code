/* friend+operator overloading+template
   9/15/2020 gz All rights reserved.
*/

#include <iostream>

template <class T>
class X
{  
    T v;
public:  
    
    X<T>(T y=0):v(y){}  //constructor
    
    template <class U>
    //friend operator overloading
    friend std::ostream& operator<<(std::ostream&, const X<U>&);
	
	
};

template<class U>
//friend function  
std::ostream& operator<<(std::ostream& os, const X<U>& x)
{  
    os << "value: " << x.v <<std::endl;
    return os;  
}  

int main()  
{  
    X<int> x1(2020);
    X<float> x2(9.15);
    std::cout << x1 << " " << x2;

	return 0;
}
