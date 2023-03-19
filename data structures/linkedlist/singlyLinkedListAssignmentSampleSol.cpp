/* linked list assignment sample solution
gz 10/19/21
all rights reserved
https://onlinegdb.com/ehtNL5U85
*/

/*
Assignment description:
1.	Please use the attached script (https://onlinegdb.com/-z_csdJSs) for your reference to create the node structure and the linked list class. The sample class has implemented the following member methods:
o	constructor
o	destructor
o	print()
o       update()
o	push()

2.	Implement the following member methods:
o	addFirst (T data) // Adds a node with data at the beginning of the list
o	pop() // Removes the first node from the list. Note: Don't forget to delete/re-allocate the removed dynamic memory
o	contains(T data) // Returns true or false if a node contains the data exists in the list
o	size() // Returns the number of nodes in the list
o	remove( T data) //Removes the node that contains the data. Note, you will need to check if the node exists.  Again, don't forget to delete/re-allocate the dynamic memory

(Extra Credit 2 points) Implement the following additional member methods
o	insertAfter(int n, T data) //Adds a node after the n-th node. Note, you will need to check if the nth node exists, if not, do push().
o	merge(const LinkedList &linkedlist) //Merges this object with linkedlist object. In other words, add all nodes in linkedlist to this object. 

*/

#include <iostream>
using std::cout;
using std::endl;


template <typename T>
struct Node {
    T data;
    Node *link;

	Node(T data=0, Node *p=nullptr) { //Note, this constructor combines both default and parameterized constructors. You may modify the contructor to your needs
        this->data = data;
		link = p;
    }
};

template <typename T>
class linked_list
{
    Node<T> *head,*current;//better rename current to tail and make sure it's always in tail position
  public:
    //default constructor
    linked_list() {
        head = nullptr;
        current = nullptr;
    }

    //destructor
    ~linked_list() {
		current = head;
		while( current != nullptr ) {//the loop stops when both current and head are NULL
    		head  = head->link;
    		delete current;
    		current = head;
		}
    }
    

    linked_list& addLast(T data) {// to add a node at the end of the list
        if(head == nullptr){
            head = new Node<T>(data);
            current = head;
        } else {
			while( current->link != nullptr)
				current = current->link;
            current->link = new Node<T>(data);
            current = current->link;
        }
        return *this;
    }

    void addFirst(T data){// to add a node at the beginning of the list
       Node<T> *ptr = new Node<T>(data, head);
       head=ptr;
    }

    void pop(){//removes the first node of the list
        if(head != nullptr) {
            Node<T> *temp = head;
            if(head == current)
                current = current->link;
            head = head->link;
            delete temp;
        }
    }

    bool contains(T data){//searches for the data in the list
         Node<T> *temp = head;
         while(temp != nullptr){
            if(temp->data == data)
                return true;
            temp = temp->link;
        }
        return false;
    }

    void update(T oldData, T newData){// updates old data of a node with new data
        Node<T> *temp = head;
        while(temp != nullptr){
            if(temp->data == oldData) {
              temp->data = newData;//should break/return right here. gz
              break;//or "return". added by gz
            }
            temp = temp -> link;
        }
    }

    int size(){//returns the number of nodes in the list
                //could be more efficent to create a member var "size". then all related methods need to update size. gz
        int num = 0;
        Node<T> *temp = head;
        while(temp != nullptr){
            temp = temp->link;
            num++;
        }
        return num;
    }

    void remove(T data){//removes the node that contains the data
        if(head != nullptr) {
            Node<T> *temp = head;
            Node<T> *previous = head;
            while(temp != nullptr){
                if(temp->data == data) {
                    if(head->data == data)//if the first node is to be removed
                        pop();
                    else {
                        previous->link = temp->link;
                        delete temp;
                    }
                } else {//continue looping
                  previous = temp;
                  temp = temp->link;
                }
            }//end of while
        }
     }

     void insertAfter(int n, T data){//adds a node after the n-th node
         if (n <= size()) {
            Node<T> *temp = head;
            Node<T> *newnode = nullptr;
            int i = 1;
            while(temp != nullptr){
              if(i == n){
                  newnode = new Node<T>(data, temp->link);
                  temp->link = newnode;
                  return;
              }
              temp = temp->link;
              i++;
            }
         }
         else
             addLast(data);
    }


    void print() { // to display all nodes in the list
        Node<T> *tmp = head;
        while (tmp != nullptr) {
            cout << tmp->data << "\n";
            tmp = tmp->link;
        }
    }
    
    //gz
    void merge(const linked_list<T>& ls) { 
        if(ls.head != nullptr) {
            Node<T>* tmp = ls.head;
            while(tmp !=nullptr) {
                addLast(tmp->data);
                tmp = tmp->link;
            }
        } 
    }
    
    void merge_s(linked_list & ls) { //remove const specifier if you want to link the tail to the head,
        if(ls.head != nullptr) {
            if(head != nullptr) {
                while (current->link != nullptr)  //if we have a dedicated member variable Node<T> *tail, we don't need the while loop
                    current = current->link;
                current->link = ls.head;

                
            } else
                head = std::move(ls.head);
            ls.head = nullptr;// otherwise "free(): double free detected in tcache 2" 
            //calling delete on the same piece of memory twice will crash your program
            // If we have two pointers pointing at the same piece of memory, and both destruct and try to delete their own pointers
        } 
    }

};

int main() {
    linked_list<int> a,b;
    a.addLast(1).addLast(2).addLast(3);
	a.print();
    printf("contains: %d\n",a.contains(2));
  
    /*
    a.pop();
    a.print();
    cout << endl;
  
    a.addFirst(3);
    a.print();
    cout << endl;
      
    a.update(3,4);
    a.print();
    cout << endl;
    
    a.remove(4);
    a.print();
    cout << endl;
    */
    a.insertAfter(1,5);
    a.print();
    cout << endl;
   
    b.addLast(7).addLast(8).addLast(9);
    b.print();
    cout << endl;
   
    a.merge_s(b);
    printf("List size is: %d\n",a.size());
    a.print();

}

