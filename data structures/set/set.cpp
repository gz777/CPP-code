//data structure: set
//resource: https://www.geeksforgeeks.org/set-in-cpp-stl/
// cpp.sh/93sux
#include <iostream> 
#include <set> 
#include <iterator> 
  
using std::cout;
using std::endl;
using std::set;
using std::greater;
using std::less;
using std::iterator;
  
int main() 
{ 
    // empty set container 
    set <int, less <int> > quiz; //try great, the order will be descending        
  
    // insert elements in random order 
    quiz.insert(40); 
    quiz.insert(20); 
    quiz.insert(50); 
    quiz.insert(50); // only one 50 will be added to the set 
    quiz.insert(10); 
  
    // printing set quiz 
    set <int, less <int> > :: iterator itr; 
    cout << "\nThe set quiz is : "; 
    for (itr = quiz.begin(); itr != quiz.end(); ++itr) 
        cout << '\t' << *itr; 
 
    cout << endl; 
  
    // remove all elements up to 30 in quiz 
    cout << "\nquiz after removal of elements less than 20 : "; 
    quiz.erase(quiz.begin(), quiz.find(20));
    
    for (itr = quiz.begin(); itr != quiz.end(); ++itr) 
        cout << '\t' << *itr; 

    cout << endl; 
  
    return 0; 
  
} 

/*
Some methods of set
begin() 每 Returns an iterator to the first element in the set.
end() 每 Returns an iterator to the theoretical element that follows last element in the set.
size() 每 Returns the number of elements in the set.
max_size() 每 Returns the maximum number of elements that the set can hold.
empty() 每 Returns whether the set is empty.

Time complexity
std::set, std::multiset, std::map, and std::multimap are all sorted using std::less as the default comparison operation. The underlying data-structure used is typically a balanced binary search tree such as a red-black tree. So if you add an element to these data-structures and then iterate over the contained elements, the output will be in sorted order. 
The complexity of adding N elements to the data-structure will be O(N log N), or the same as sorting a vector of N elements using any common O(log N) complexity sort.
(source: https://stackoverflow.com/questions/15582504/is-there-a-sorted-container-in-the-stl)

Insertion: O(log n)
Lookup: O(log n)
Deletion: O(log n)

*/