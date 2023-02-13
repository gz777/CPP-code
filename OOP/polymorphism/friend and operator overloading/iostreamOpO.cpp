//updated 2/8/22
#include <iostream>
using std::string;
using std::ostream;

// templated class with friend operator overloading function
template <class T> 
class Student {
    private:
       T grade;// A, A+, 3, 4, 3.5
       string name;
    
    public:
       Student(T g=0, string n = ""):grade(g),name(n) {}
    
       friend ostream& operator<<(ostream & c_out, const Student<T> & student1 ) { //const is a must in this case
            c_out << student1.grade << " " << student1.name;
            return c_out;
        }
        
        friend std::istream& operator>>(std::istream & c_in, Student<T>& student1 ) { //& is important
            c_in >> student1.grade >> student1.name;
            return c_in;
        }
    
};


int main()
{
    Student<double> mary;
    std::cin >> mary;
    
    Student<int> matt(100, "john");
    
    std::cout << matt << mary;
    

    return 0;
}