//https://onlinegdb.com/B18PSWG14
//static local variable

#include <iostream> 
#include <string> 
using namespace std; 
  
void beer() 
{  
    // static variable 
    static int count = 0; 
    
    // value is updated and 
    // will be carried to next 
    // function calls 
    count++;
    cout << "you drink " << count << " beer.\n"; 
      
 
} 
  
int main() 
{ 
    for (int i=0; i<5; i++)     
        beer(); 
    return 0; 
} 
