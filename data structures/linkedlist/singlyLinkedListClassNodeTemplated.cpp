//class Node, templated
//singly linked list
//10-27-19 gz

//class demo singly linked list
//4/1/19
#include <iostream>
using std::cout;
using std::endl;

template<class T>
class Node {
    T data;//data field
    Node * next;//link field
  public:
    Node(T data) {//constructor
      this->data = data;
      next = nullptr;
    }
    T getData() const {return data;}
    void setData(T data) { this->date = data;}
    Node* getNext() const {return next;}
    void setNext(Node* node) {next = node;}
};

template<class T>
class linked_list{
  private:
      Node<T> *head,*current;
  public:
      linked_list(){//constructor, empty linked list
        head = nullptr;
        current = nullptr;
      }

      ~linked_list(){//destructor, de-allocate all dynamic memories
        current = head;
        while(current != nullptr) {
          head = current->getNext();
          delete current;
          current = head;
        }
      }

      linked_list& add_node(T n) {//add a node at the end of the list
          if(head == nullptr) {//empty list
            head = new Node<T>(n);
            current = head;
          } else {//non-empty list
            current->setNext(new Node<T>(n));
            current = current->getNext();
          }
          return *this;//function chaining
      }

      void display(){
        current = head;
        while(current != nullptr) {
          cout << current->getData() << endl;
          current = current->getNext();
        }
      }
      
      linked_list& reverse() {
          Node<T> * pre = nullptr; //pre, left node
          next = head->next; //next,right node
          while(true) {
              if (head->next == nullptr) {
                  head->next = pre;
                  break;
              }
              head->next = pre;
              pre = head;
              head=head->next;
          }
          return *this;
      }
};


int main() {
  linked_list<char> a;
  a.add_node('a').add_node('c').add_node('b');
  a.display();
  a.reverse().display()

  return 0;
}
