//class demo 3-27-2019
//modified from https://www.codesdope.com/blog/article/c-linked-lists-in-c-singly-linked-list/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

class linked_list
{
private:
    Node *head,*current;
public:
     //constructor
    linked_list()
    {
        head = NULL;//the head pointer
        current = NULL;//acts as the tail of the list
    }

    //destructor - IMPORTANT
    ~linked_list() {
	current = head;
	while( current != NULL ) {//the loop stops when both current and head are NULL
    		head  = head->link;
    		delete current;
    		current = head;
	}

    }

    void add_node(int n)// to add a node at the end of the list
    {
        Node *tmp = new Node;
        tmp->data = n;
        tmp->link = NULL;

        if(head == NULL)
        {
            head = tmp;
            current = tmp;
        }
        else
        {
            current->link = tmp;
            current = current->link;
        }
    }

    void display() // to display all nodes in the list
    {
        Node *tmp;
        tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << endl;
            tmp = tmp->link;
        }
    }
};

int main()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);

	a.display();


    return 0;
}
