/* BCS 230 Vector */

#include <vector>
#include <iostream>
using namespace std;

int main() {

	vector<int> array; 		  // create an empty vector
	array.reserve(3);         // make room for 3 elements
	cout<<"array capacity: " << array.capacity()<<endl;
	cout<<"array size: " << array.size()<<endl;
                        	  // at this point, capacity() is 3
                       		  // and size() is 0
	for(auto i:array)
	    cout << i << " ";
	cout << endl;
	array.push_back(999);     // append an element
	array.resize(5);          // resize the vector
                          	  // at this point, the vector contains
                        	  // 999, 0, 0, 0, 0
	array.push_back(333);     // append another element into the vector
                	          // at this point, the vector contains
                    	      // 999, 0, 0, 0, 0, 333
	array.reserve(1);         // will do nothing, as capacity() > 1
	array.resize(3);          // at this point, the vector contains
    	                      // 999, 0, 0
        	                  // capacity() remains 6
            	              // size() is 3
	array.resize(6, 1);       // resize again, fill up with ones
               	              // at this point the vector contains
                    	      // 999, 0, 0, 1, 1, 1
    cout<<"array capacity: " << array.capacity()<<endl;
	cout<<"array size: " << array.size()<<endl;
	
	//traverse array
	//range-based for loop
	for(int i:array)
	    cout << i << " ";//add & if you want to modify i
	cout << endl;
	
	//traditional for loop
	for(int i=0;i<array.size();i++)
		//cout << array[i] << " ";//equivalent to the following line
		cout << array.at(i) << " ";

	cout << endl;
	
	//iterator
	for(auto i=array.begin(); i!=array.end(); ++i) //std::vector<int>::const_iterator i;
        cout<<(*i)<<" ";//pointer arithmetic
    cout << endl;
    
    //pointer arithmetic
    const int *p;
    for(p=&array[0]; p!=&array[0]+array.size(); ++p)
        cout<<(*p)<<" ";
    cout << endl;
	
	return 0;
}

