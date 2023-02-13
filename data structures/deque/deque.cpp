// data structure: deque
//resource: https://appdividend.com/2019/10/09/deque-in-cpp-example-cpp-deque-program/
//cpp.sh/7rcih

#include <iostream>
#include <deque>

using std::cout;
using std::deque;

void showdata(deque<int> deque1)
{
  deque<int>::iterator iterator_1;
  for (iterator_1 = deque1.begin(); iterator_1 != deque1.end(); ++iterator_1)
    cout << "\t" << *iterator_1;
  cout << "\n";
}

int main()
{
  deque<int> myqueue;
  myqueue.push_front(230); // getting data from front
  myqueue.push_front(240); // getting data from front
  myqueue.push_back(250);  // getting data from back
  myqueue.push_back(260);  // getting data from back
  cout << "Deque elements are: ";
  showdata(myqueue);

  return (0);
}

/*
Methods associated with deque
2.1 insert()
2.2 rbegin()
2.3 rend()
2.4 cbegin()
2.5 assign()
2.6 max_size()
2.7 resize()
2.8 push_front()
2.9 push_back()
2.10 pop_front()
2.11 pop_back()
2.12 clear()
2.13 erase()
2.14 front()
2.15 back()
2.16 at()
2.17 swap()
2.18 begin()
2.19 end()
2.20 emplace_front()
2.21 emplace_back()

Time complexity
Random access: constant O(1)
Insertion or removal of items at the end or beginning ¨C constant O(1)
Insertion or removal of items ¨C linear O(n)

*/