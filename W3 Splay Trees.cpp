#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node{
    
public:
    
    int key;
    Node *left, *right;
    int noOfLC, noOfRC;

    
    
    Node(int key){
        this->key = key;
        this->left = NULL;
        this->right = NULL;
        this->noOfLC = 0;
        this->noOfRC = 0;
    }
};

class BST {
    
private:
    Node *root1;
    Node *root2;
    int threshold;
    bool oneTree;
    
public:
   
    
    BST() {
        root1 = NULL;
        root2 = NULL;
        threshold = 0;
        oneTree = true;
    }
    
    

    
    void insert(int key){
        
        if (this->oneTree == true) {
            this->root1 = insert(this->root1, key);
            this->root1 = splay(this->root1,key);
        }else{
        
        if (key < this->threshold){
               this->root1 = insert(this->root1, key);
               this->root1 = splay(this->root1,key);

           }else {
               this->root2 = insert(this->root2, key);
               this->root2 = splay(this->root2,key);

           }
        }
}
        

 
    
    
    
    Node* insert(Node *root, int key){
        if(root == NULL){
            root = new Node(key);
        }
        else{

            if(root-> key < key){
                root->noOfRC++;
                root->right = insert(root->right, key);
            }
            else if(root-> key > key){
                root->noOfLC++;
                root->left = insert(root-> left, key);
            }
        }
        return root;
    }

    

    
    void preorder(){
        preorder(this->root1);
    }
    
    void preorder(Node *root){
        if(root != NULL){
            cout << "(" << ((root)->key) << " " << ((root)->noOfLC) << " " << ((root)->noOfRC) << ") ";
            preorder(root->left);
            preorder(root->right);
        }
        
    }
    

    
    Node* rightrotate(Node *root){
        
        
        if (root->left != NULL) {
            
            
        Node* temp = root->left;
        
        int t = temp->noOfRC;
        temp->noOfRC = temp->noOfRC + root->noOfRC + 1;
        root->noOfLC =  t;
        
        root->left = temp->right;
        temp->right = root;

         return temp;
        }
        else return root;
    }
    

    Node* leftrotate(Node *root){
        
      
        
        if (root->right != NULL) {
            
        
        
        Node* temp = root->right;
        
        int t = temp->noOfLC;
        temp->noOfLC = temp->noOfLC + root->noOfLC + 1;
        root->noOfRC =  t;
        
        root->right = temp->left;
        temp->left = root;
        
        return temp;
        }
        else return root;
    }

    
    
    
    
    void search(int key){
        bool foundnode;
        
            if (key <= this->threshold || this->threshold == 0){
                foundnode = findnode(this->root1,key);
                if (foundnode == true) {
                   this->root1 = splay(this->root1,key);
                    printf("YES %d",this->root1->noOfRC);
                }
                else printf("NO");

            }else {
                foundnode = findnode(this->root2,key);
                if (foundnode == true) {
                    this->root2 = splay(this->root2,key);
                    printf("YES %d",this->root2->noOfRC);
                }
                    else printf("NO");

            }
        }
        
    
    bool findnode(Node *root,int key){
        bool found = false;
        if(root->key == key){
            found = true;
        }
        else {
            if(root->key > key){
                if (root->left != NULL) {
                  found  = findnode(root->left,key);
                }
                
            } else {
                if (root->right != NULL) {
                  found =  findnode(root->right,key);
                }
                
            }
            
        }
        return found;
    }
    
    
    void split(int key){
        
        this->root1 = splay(this->root1, key);
        if (this->root1->right != NULL) {
            this->root2 = this->root1->right;
            this->root1->right = NULL;
            this->root1->noOfRC = 0;
        }else{
            this->root2 = NULL;
//            this->root1->right = NULL;
//            this->root1->noOfRC = 0;

        }
        
        this->threshold = key;
        this->oneTree = false;
        
    }
    
    void join(){
        
       this->root1 = splay(this->root1, this->threshold);
        
        if (this->root2 != NULL) {
             this->root1->right = this->root2;
            this->root1->noOfRC = this->root2->noOfRC + this->root2->noOfLC + 1;
          }
        this->root2 = NULL;
        this->threshold = 0;
        
        this->oneTree = true;
        
    }
    
    Node* splay(Node* root,int key){
        
        if (root == NULL || root->key == key) {
            return root;
        }
        
        //Going in left subtree
        if (root->key > key) {
            
            if (root->left == NULL) {
                return root;
            }
            
            //Left Left
            if (root->left->key > key) {
                
                if (root->left->left != NULL)
                    root->left->left = splay(root->left->left, key);
                
                //1st right rotate grandparent
                root = rightrotate(root);
                
        }
            // Left Right
            else if (root->left->key < key){
                
                if (root->left->right != NULL)
                    root->left->right = splay(root->left->right, key);
                
                //1st left rotate parent
                if (root->left->right != NULL)
                    root->left = leftrotate(root->left);
                
                
            }
            //2nd right rotate
            return (root->left == NULL)? root: rightrotate(root);

            
            
        }
        //Going in right subtree
        else {
            
            if (root->right == NULL) {
                return root;
            }
            
            //Right Left
            if (root->right->key > key) {
                
                if (root->right->left != NULL)
                    root->right->left = splay(root->right->left, key);
                
                //1st right rotate parent
                if (root->right->left != NULL)
                    root->right = rightrotate(root->right);
                
            }
            // Right Right
            else if (root->right->key < key){
                
                if (root->right->right != NULL)
                    root->right->right = splay(root->right->right, key);
                
                //1st left rotate grandparent
                root = leftrotate(root);
                
            }
            
            
            //2nd left rotate
            return (root->right == NULL)? root: leftrotate(root);

            
            
            
        }
     
       // return root;
        
    }
    
};

int main() {
    int T, N;
    string s;
    cin >> T;
    BST bst;
    for(int t=0; t<T; t++){
        cin >> s;
        if(s == "INSERT"){
            cin >> N;
            bst.insert(N);
        }
        if(s == "SPLIT"){
            cin >> N;
            bst.split(N);
        }
        if (s == "PRE-ORDER")
        {
            bst.preorder();
            cout<< endl;
        }
        if(s == "SEARCH"){
            cin >> N;
            bst.search(N);
            cout<< endl;
        }
        if(s == "JOIN"){
            bst.join();
        }
        
    }
    return 0;
}


