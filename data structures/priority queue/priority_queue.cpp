//data structure: priority queue
//resource: https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/
//https://en.cppreference.com/w/cpp/container/priority_queue
//default C++ creates a max-heap for priority queue 
//cpp.sh/8t37r

#include <iostream> 
#include <queue> 
  
using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;
using std::greater;
  
void showpq(priority_queue <int> gq) //max-heap
{ 
    priority_queue <int> g = gq; 
    while (!g.empty()) 
    { 
        cout << '\t' << g.top(); 
        g.pop(); 
    } 
    cout << '\n'; 
} 

void showpq(priority_queue <int, vector<int>, greater<int>> gq) //min-heap
{ 
    priority_queue <int, vector<int>, greater<int>> g = gq; 
    while (!g.empty()) 
    { 
        cout << '\t' << g.top(); 
        g.pop(); 
    } 
    cout << '\n'; 
} 
  
int main () 
{ 
    priority_queue <int> gquiz1; 
	priority_queue <int, vector<int>, greater<int>> gquiz2;
	
	//You may change the following code with gquiz2 to see the result
    gquiz1.push(10); 
    gquiz1.push(30); 
    gquiz1.push(20); 
    gquiz1.push(5); 
    gquiz1.push(1); 
  
    cout << "The priority queue gquiz is : "; 
    showpq(gquiz1); 
  
    cout << "\ngquiz1.size() : " << gquiz1.size(); 
    cout << "\ngquiz1.top() : " << gquiz1.top(); 
    cout << "\ngquiz1.pop() : "; 
    gquiz1.pop(); 
    showpq(gquiz1); 
  
    return 0; 
} 
/*
Output:

The priority queue gquiz is :     30    20    10    5    1

gquiz.size() : 5
gquiz.top() : 30
gquiz.pop() :     20    10    5    1
*/

/*
Methods of priority queue are:
priority_queue::empty() in C++ STL每 empty() function returns whether the queue is empty.
priority_queue::size() in C++ STL每 size() function returns the size of the queue.
priority_queue::top() in C++ STL每 Returns a reference to the top most element of the queue
priority_queue::push() in C++ STL每 push(g) function adds the element ＆g＊ at the end of the queue.
priority_queue::pop() in C++ STL每 pop() function deletes the first element of the queue.
priority_queue::swap() in C++ STL每 This function is used to swap the contents of one priority queue with another priority queue of same type and size.
priority_queue::emplace() in C++ STL 每 This function is used to insert a new element into the priority queue container, the new element is added to the top of the priority queue.
priority_queue value_type in C++ STL每 Represents the type of object stored as an element in a priority_queue. It acts as a synonym for the template parameter.
*/