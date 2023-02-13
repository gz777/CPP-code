//parallel array

#include <iostream> 
#include <string> 
using namespace std; 
  
 
  
int main() 
{ 
    string exams[4] = {"bcs120", "bcs121", "bcs122"};
    string dates[4] = {"12/5/18", "12/15/18", "12/22/18"};
    
    for (int i=0; i<3; i++)     
        cout << "Take exam " << exams[i] << " on " << dates[i] <<".\n";
    return 0; 
} 