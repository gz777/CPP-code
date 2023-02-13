// C++ program to insert element in binary tree 
// source: https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/ (modified)
#include <iostream> 
#include <queue> 
using namespace std; 

  
/* A binary tree node has key, pointer to left child 
and a pointer to right child */
struct Node { 
    int key; 
    struct Node* left, *right; 
    
    Node(int key) {
        this->key = key;
        left = right = nullptr;
    }
}; 

//user-defined function prototype
void showq(queue <Node*>);
void insert(Node*, int);
void display(Node*);

// Driver code 
int main() 
{ 
    Node* root = new Node(10); 
    root->left = new Node(11); 
    root->left->left = new Node(7); 
    root->right = new Node(9); 
    root->right->left = new Node(15); 
    root->right->right = new Node(8);
  
    int key = 12; 
    insert(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after insertion:"; 
    display(root); 
  
    return 0; 
} 

/*function to insert element in binary tree */
void insert(Node* root, int key) 
{ 
    queue<Node*> q; 
    q.push(root); 
  
    // Do level order traversal until we find 
    // an empty place.  
    int counter = 0;
    while (!q.empty()) { 
        cout << "Round " << ++counter <<endl;
        showq(q);
        
        Node* temp = q.front(); 
        q.pop(); 
  
        if (!temp->left) { 
            temp->left = new Node(key); 
            break; 
        } else
            q.push(temp->left); 
  
        if (!temp->right) { 
            temp->right = new Node(key); 
            break; 
        } else
            q.push(temp->right); 
    } 
} 

//travere a queue
void showq(queue <Node*> gq) 
{ 
    queue <Node*> g = gq; 
    while (!g.empty()) 
    { 
        cout << '\t' << g.front()->key; 
        g.pop(); 
    } 
    cout << '\n'; 
}

/* Inorder traversal of a binary tree*/
void display(Node* temp) 
{ 
    if (!temp) 
        return; 
  
    display(temp->left); 
    cout << temp->key << " "; 
    display(temp->right); 
}
