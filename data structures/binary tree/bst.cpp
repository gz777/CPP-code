//class demo - binary tree with bst insert method
// first class data structure: linked list
//4/22/19 init version
//9/23/19 added preorderDisplay, getHeight and getLeafCount
//https://onlinegdb.com/HJsVtDv3H

#include <iostream>
#include <iomanip>
using std::cout;
using std::setw;

//Definition of the node
template <class T>
struct BTNode //binary tree node
{
    T data;
    BTNode<T> *left, *right;

    BTNode(T data) {
      this->data = data;
      left = right = NULL;
    }
};

template <class T>
class BST {
	BTNode<T>* root;
  public:
	BST() { root = NULL;}
	~BST();//important! Re-allocate all dynamic memories
	void destroy(BTNode<T>*);

	BTNode<T>* insert(BTNode<T>*, T);

	void inorder(BTNode<T> *p) const {
		if (p != NULL){
			inorder(p->left);
			cout << p->data << " ";
			inorder(p->right);
		}
	}

	void preorder(BTNode<T> *p) const
	{
		if (p != NULL)
		{
			cout<<p->data<<" ";
			preorder(p->left);
			preorder(p->right);
		}
	}

	void postorder(BTNode<T> *p) const
	{
		if (p != NULL){
			postorder(p->left);
			postorder(p->right);
			cout << p->data << " ";
		}		
	}
	
	int getHeight(BTNode<T> *p) const {
	/*
	 maxDepth()
    1. If tree is empty then return 0
    2. Else
     (a) Get the max depth of left subtree recursively  i.e., 
          call maxDepth( tree->left-subtree)
     (a) Get the max depth of right subtree recursively  i.e., 
          call maxDepth( tree->right-subtree)
     (c) Get the max of max depths of left and right 
          subtrees and add 1 to it for the current node.
         max_depth = max(max dept of left subtree,  
                             max depth of right subtree) 
                             + 1
     (d) Return max_depth
	*/
	
	if (p  == nullptr)
	    return 0;
	else {
	    int hl  = getHeight(p->left);
	    int hr = getHeight(p->right);
	    if (hl > hr)
            return(hl + 1);
        return(hl + 1);
	    }
	}
	int getLeafCount(BTNode<T> *p) const {
	    /*
	    Algorithm
	    getLeafCount(node)
        1) If node is NULL then return 0.
        2) Else If left and right child nodes are NULL return 1.
        3) Else recursively calculate leaf count of the tree using below formula.
            Leaf count of a tree = Leaf count of left subtree + Leaf count of right subtree
	    */
	    if (p == nullptr) //nil
	        return 0;
	    else if ( p->left == nullptr && p->right == nullptr) // a leaf
	        return 1;
	    else {
	        return getLeafCount(p->left) + getLeafCount(p->right);
	    }
	    
	}
	
	void preorderDisplay(BTNode<T> *p, int count) const {  //init count to height
	    if (p != NULL && count !=0) {
            cout << setw(count*4) << ' ';
            count--;
		    cout<<p->data<<"\n ";
		    preorderDisplay(p->left, count);
		    preorderDisplay(p->right, count);
	    }
    }
};

template <class T>
BST<T>:: ~BST(){ destroy(root);}

template <class T>
void BST<T>::destroy(BTNode<T>* p){
    if(p != NULL) {
      destroy(p->left);
      destroy(p->right);
      cout << "\nInside destory.";
      delete p;
    }
  }
  
template<class T>
BTNode<T>* BST<T>::insert(BTNode<T>* p, T data){//BST logic
  if(p == NULL) {
    p = new BTNode<T>(data);
    if(this->root == NULL)
      this->root = p;
  } else {
    if(data < p->data)
     p->left = insert(p->left, data);
    else
     p->right = insert(p->right,data);
  }
  return p;
}

int main() {
  BST<int> bst; //create a binary tree
  
  BTNode<int>* root = NULL;
  
  //int numbers[5] = {5,1,8,7,3};
  int numbers[5] = {8,7,3,5,1};
  for(int x: numbers)
    root = bst.insert(root,x);
  
  cout << "inorder\n";
  bst.inorder(root);
  cout << "\npreorder\n";
  bst.preorder(root);
  cout << "\npostorder\n";
  bst.postorder(root);
  cout << "\n";
  int h = bst.getHeight(root);
  bst.preorderDisplay(root,h);
  cout << "\ntree height is: " << h ;
  cout << "\nleaves count is: " << bst.getLeafCount(root);
 
  return 0;

}