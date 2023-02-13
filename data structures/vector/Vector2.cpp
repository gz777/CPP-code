/*Vector methods*/
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    std::vector<double> a;
    cout<<"array capacity: " << a.capacity()<<endl;
	cout<<"array size: " << a.size()<<endl;
    a.push_back(1.0);
    a.push_back(2.0);
    a.push_back(3.0);
    
    cout<<"array capacity: " << a.capacity()<<endl;
	cout<<"array size: " << a.size()<<endl;
    
    for(auto i=a.begin(); i!=a.end(); ++i)
        std::cout<<(*i)<<std::endl;
    
    
    a.pop_back();
    cout << "after pop_back()\n";
    for(auto i=a.begin(); i!=a.end(); ++i)
        std::cout<<(*i)<<std::endl;
    
    return 0;
}
