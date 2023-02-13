//class demo singly linked list
//4/1/19
#include <iostream>
using namespace std;

template<class T>
class Node {
    T data;//data field
    Node * next;//link field
  public:
    Node(T data) {//constructor
      this->data = data;
      next = nullptr;
    }
};

template<class T>
class linked_list{
  private:
      Node<T> *head,*current;
  public:
      linked_list(){//constructor, empty linked list
        head = NULL;
        current = NULL;
      }

      ~linked_list(){//destructor, de-allocate all dynamic memories
        current = head;
        while(current != NULL) {
          head = current->next;
          delete current;
          current = head;
        }

      }

      linked_list& add_node(T n) {//add a node at the end of the list
          if(head == NULL) {//empty list
            head = new Node<T>(n);
            current = head;
          } else {//non-empty list
            current->next = new Node<T>(n);
            current = current->next;
          }
          return *this;
      }

      void display(){
        current = head;
        while(current != NULL) {
          cout << current->data << endl;
          current = current->next;
        }
      }
};


int main() {
  linked_list<char> a;
  a.add_node('a').add_node('c').add_node('b');
  a.display();

  return 0;
}
