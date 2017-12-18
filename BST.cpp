#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/* Create your class(es) here 
   You may use more than one class */


/* The following piece of code is for APL-2017-L2.
   Although the code passes all the 6 test cases 
   successfully it has several issues. 
   The issues are highlighted below.
*/


/* I1: uncommented code, difficult to read */

class Node {
 	
	/* I2: all members are public */
	public:
	int value;
	int Nodeheight;
	Node *left;
	Node *right;
	
	/* I3: does not expose any functions to access data */
	
};	
class BST {
	Node *root;
	
	int BSTheight;	// I1.1: Mention if these two are maintained or computed.
	int maxVal;	

	public:
	BST() {
		root = NULL;
		BSTheight = 0;
		maxVal = 0;
	}

	int insert(int data) {
		/* I4: insert function too long, repeats parts of code that
		       create and populate a node
                */
		if (NULL == root) {
			/* I4.1: should create a helper function init().
			*/
			root = new Node;
			root->value = data;
			root->left = NULL;
			root->right = NULL;
			root->Nodeheight = 0;
			maxVal = data;
			return BSTheight;
		} else {
			/* I4.2: should create a helper function search().
			*/
			Node *curr, *parent;
			curr = root;
			parent = NULL;
			while (curr) {
				parent = curr;
				if (curr->value > data) 
					curr = curr->left;
				else
					curr = curr->right;
			}
			if (NULL == parent) {
				/* I5: Error message should reveal more information of the current state.
				*/
				cout << "Something is wrong\n";
				/* I6: Error condition needs to be documented in the header comment above the function.
				*/
				return -1;
			} else {
				
				curr = new Node;
				curr->value = data;
				if (curr->value > maxVal) {
					maxVal = curr->value;
				}
				curr->left = NULL;
				curr->right = NULL;
				curr->Nodeheight = parent->Nodeheight+1;
				/* I7: A high-level macro / function such as MaxHeight() would be more readable.
				*/
				if (curr->Nodeheight > BSTheight) 
					BSTheight = curr->Nodeheight;
				if (parent->value > data) {
					parent->left = curr;
				} else 
					parent->right = curr;
			
				return curr->Nodeheight;
			}
		}
	}
	/* I8: Mention what ceil does.
	*/
	int ceil(int data) {
		if (NULL == root || data > maxVal)  {
			/* I9: Values can be symbolized with const definitions.
			*/
			return 10000;
		} else {
			Node *curr, *parent; 
			curr = root;
			parent = NULL;
			int succ = 10000;
			/* I10: This code should bring out the logic without needing a comment.
			*/
			while (curr) {
				parent = curr;
				if (parent->value > data && parent->value < succ)
					succ = parent->value;
				if (curr->value == data) 
					return data;
		
				if (curr->value > data) 
					curr = curr->left;
				else 
					curr = curr->right;
			}
			/* I11: Mention the invariant on succ.
			*/
			return succ;
		}
	}
	int height() {
		return BSTheight;
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
 

