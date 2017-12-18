#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#define DEFRETVAL 10000
/* Create your class(es) here 
   You may use more than one class */


/*********** class Node *********************/
class Node {
 	
	private:
	int value;
	int height;
	Node *left;
	Node *right;
	
	public:
	Node(int value, int height) {
		this->value = value;
		this->height = height;
		this->left = NULL;
		this->right = NULL;
	}

	/* Functions to set values */
	void setHeight(int height) {
		this->height = height;
	}
	void setValue(int value) {
		this->value = value;
	}
	void setLeftChild(Node *leftChild) {
		this->left = leftChild;
	}
	void setRightChild(Node *rightChild) {
		this->right = rightChild;
	}

	/* Functions to get values */
	int getHeight() {
		return this->height;
	}
	int getValue() {
		return this->value;
	}
	Node* getLeftChild() {
		return this->left;
	}
	Node* getRightChild() {
		return this->right;
	}

};	

/****************end of Node class **************/

/***************** class BST ********************/
class BST {
	private:
	Node *root;
	
	int treeHeight;	// this will maintain the current height of the BST.
	int maxVal;	// this will maintain the maximum value present in BST.
	


	public:
	BST() {
		root = NULL;
		treeHeight = 0;
		maxVal = 0;
	}
	void updateHeight(int val) {
		if (val > treeHeight) {
			this->treeHeight = val;
		}
	}
	void updateMaxVal(int val) {
		if (val > maxVal) {
			this->maxVal = val;
		}
	}
	int height() {
		return this->treeHeight;
	}
	int insert (int data) {
		if (NULL == root) {
			root = new Node(data, 0);
			updateMaxVal(data);
			updateHeight(0);
			return 0; // equivalent to root->getHeight();
		} else {
			/* Find the right place to insert the data value */
			Node *curr, *parent;
			curr = root;
			parent = NULL;
			while (curr) {
				parent = curr;
				if (curr->getValue() > data) 
					curr = curr->getLeftChild();
				else
					curr = curr->getRightChild();
			}
			/* The data value should be either a left child or right child of parent */
			int parentHeight = parent->getHeight();
			curr = new Node(data, parentHeight+1);
			updateMaxVal(data);
			updateHeight(parentHeight+1);
			/* place curr node at the appropriate place */
			if (parent->getValue() > data) 
				parent->setLeftChild(curr);
			else 
				parent->setRightChild(curr);
			
			return curr->getHeight();
		}

		
	}
	int ceil(int data) {
	    	// returns the smallest value in tree which is larger than data.
	    	// if data > largest value in tree, then returns 10000.
		if (NULL == root || data > maxVal) {	
			return DEFRETVAL;
		}
		// Ceil(data) is the smallest value larger than data encountered 
		// from root to leaf while searching data in the BST.
		Node *curr, *parent;
		curr = root;
		parent = NULL;
		int succ = DEFRETVAL;
		while (curr) {
			parent = curr;
			if (curr->getValue() == data) 
				return data;
			if (parent->getValue() > data && parent->getValue() < succ)
				succ = parent->getValue();

			// succ stores the ceil(data) in the path from root to curr.
		
			if (curr->getValue() > data) 
				curr = curr->getLeftChild();
			else 
				curr = curr->getRightChild();
			
		}
		return succ;
	}

};
// ! DO NOT CHANGE WHEN SUBMITTING !
int main() {
    int N, val;
    string cmd;
    
    BST tree;   // BST is the class you have to create.
      // Contains atleast 3 public methods.
      // insert(val), ceil(val), height()
    
    cin >> N;
    for(int i=0; i<N; ++i) {
    	cin >> cmd;
    	if(cmd == "insert") {
      		cin >> val;
      		cout << tree.insert(val) << "\n";   
    	} else if(cmd == "ceil") {
      		cin >> val;
      		cout << tree.ceil(val) << "\n";
    	} else if(cmd == "height") {
      		cout << tree.height() << "\n";   
    	}
   
    }
    return 0;
}
// ! DO NOT CHANGE UNTIL THIS LINE  
 

