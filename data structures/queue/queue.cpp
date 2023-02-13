//data structure: queue
//resource: https://www.thegeekstuff.com/2017/01/cpp-stl-queue/
//http://www.cplusplus.com/reference/queue/queue/
//https://www.thegeekstuff.com/2017/01/cpp-stl-queue/

//cpp.sh/8bdg
#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;

int main()
{

 queue < int > ourQueue;

 cout<<"The occupied place in the memory is = "
       <<ourQueue.size()
       <<endl;

 ourQueue.emplace( 3 );
 ourQueue.emplace( 6 );
 ourQueue.emplace( 7 );


 cout<<"The occupied place in the memory is = "
       <<ourQueue.size()
       <<endl
       <<"And with the bits it is ="
       <<ourQueue.size() * sizeof( int )
       <<endl;


 while( ! ourQueue.empty() )
 {
     int iTemp = ourQueue.front();
     cout<<iTemp<<endl;
     ourQueue.pop();
 }

 return 0;
}

/*
Some methods of queue:
empty() 每 Check if the queue is empty. If queue is empty the answer will be true, otherwise the answer is false.
size() 每 Figure out the number of elements in your queue. Just like size, you also have sizeof() operation as well.
front() and back(); 每 You can access the first element in the queue, or the last element in the queue using front and back function respectively.
push() 每 When you are creating the queue, you can use push to add new elements to the queue.
pop() 每 If you would like to remove the element from the queue, use the pop function.

Time complexity in big O notation
Algorithm		Average	Worst case
Space		O(n)	O(n)
Search		O(n)	O(n)
Insert		O(1)	O(1)
Delete		O(1)	O(1)
*/