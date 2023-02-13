#include <iostream>
using namespace std;

int main()
{
    //typedef of primitive datatype
    typedef unsigned short MYSHORT;
    MYSHORT num = 1;
    cout << num << endl;

    //typeof of struct
    typedef struct Dimensions
    { int length,
      width,
      height;
    }S_DIMENTION;

    S_DIMENTION box = {12,6,3};
    cout << box.length << endl;

    //typedef of array
    struct PersonInfo
    {  string name,
           address,
           city;
    };

    PersonInfo person = {"John Smith", "123 Main Street", "New York"};
    cout << person.name << endl;
    typedef PersonInfo S_PERSONS[3];
    S_PERSONS p = {{"a1","b1","c1"},{"a2","b2","c2"},{"a3","b3","c3"}};//declaration and initialization at the same time

    cout << p[0].name << endl;
    cout << p[2].address  << endl;

    return 0;
}
