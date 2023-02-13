//data structure: unordered_map, hash table
//resource: https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/
//cpp.sh/63fx6
//An c++ implemenation of hash table: https://www.tutorialspoint.com/cplusplus-program-to-implement-hash-tables
//cpp.sh/9flcm

#include <iostream> 
#include <unordered_map> 

using std::cout;
using std::endl;
using std::unordered_map;
using std::string; 
  
int main() 
{ 
    // Declaring umap to be of <string, int> type 
    // key will be of string type and mapped value will 
    // be of double type 
    unordered_map<string, int> umap; 
  
    // inserting values by using [] operator 
    umap["GeeksforGeeks"] = 10; 
    umap["Practice"] = 20; 
    umap["Contribute"] = 30; 
  
    // Traversing an unordered map 
    for (auto x : umap) 
      cout << x.first << " " << x.second << endl; 
  
} 

/*
unordered_map is an associated container that stores elements formed by combination of key value and a mapped value. The key value is used to uniquely identify the element and mapped value is the content associated with the key. Both key and value can be of any type predefined or user-defined.
Internally unordered_map is implemented using Hash Table, the key provided to map are hashed into indices of hash table

Time complexity:
average the cost of search, insert and delete from hash table is O(1)
*/