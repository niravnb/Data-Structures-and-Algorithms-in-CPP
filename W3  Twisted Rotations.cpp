#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


struct node{
    int key;
    node *left, *right;
    int noOfLC, noOfRC;
};

class BST {
private:
    node* root;
public:
    node* new_node(int key);
    void insert(int key);
    void insert(node **root, int key);
    void preorder();
    void preorder(node **root);
    void rr(int key);
    void rr(node **root,int key);
    void lr(int key);
    void lr(node **root,int key);
    node* find(node **root,int key);
    BST() {
        root = NULL;
    }
};

node* BST::new_node(int key){
    node* temp = new node;
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    temp->noOfLC = 0;
    temp->noOfRC = 0;
    return temp;
}

void BST::insert(int key){
    insert(&root, key);
}

void BST::insert(node **root, int key){
    if(*root == NULL){
        *root = new_node(key);
    }
    else{
        if((*root) -> key < key){
            (*root)->noOfRC++;
            insert(&((*root) -> right), key);
        }
        else if((*root) -> key > key){
            (*root)->noOfLC++;
            insert(&((*root) -> left), key);
        }
    }
}


void BST::preorder(){
    preorder(&root);
}

void BST::preorder(node **root){
    if(*root != NULL){
        cout << "(" << ((*root)->key) << " " << ((*root)->noOfLC) << " " << ((*root)->noOfRC) << ") ";
        preorder(&((*root)->left));
        preorder(&((*root)->right));
    }
    
}

void BST::rr(int key){
    //node* temp = find(&root,key);
    // cout << "found " << (temp)->key;
    rr(&root,key);
}

void BST::rr(node **root,int key){
    
    bool isfound = false;
    node** temp = root;
    node** keyPtr = NULL;
    node** parent = NULL;
     bool pl = false;
    bool pr = false;
    
    while(!isfound && temp){
        
        if(((*temp)->key) == key){
            keyPtr = temp;
            isfound = true;
        }
        else {
            if(((*temp)->key) > key){
                parent = temp;
                pl = true;
                pr = false;
                temp = &((*temp)->left);
            } else if(((*temp)->key) < key){
                parent = temp;
                pr = true;
                pl = false;
                temp = &((*temp)->right);
            }
        }
    }
    //cout << "found " << (*keyPtr)->key;
    if (((*keyPtr)->left) != NULL && (*keyPtr != NULL)) {
        
        
        
        bool keyIsRoot = false;
        if (keyPtr == root) {
            keyIsRoot = true;
        }
        
        node* temp1 = ((*keyPtr)->left);
        
        int t = (temp1)->noOfRC;
        (temp1)->noOfRC = (temp1)->noOfRC + (*keyPtr)->noOfRC + 1;
        (*keyPtr)->noOfLC =  t;
        
        
        (*keyPtr)->left = (temp1)->right;
        (temp1)->right = (*keyPtr);
        
        
        if (keyIsRoot) {
            *root = temp1;
        }else if(pr){
            (*parent)->right = temp1;
        }else{
            (*parent)->left = temp1;
        }
    }
    
    // return &temp;
}

void BST::lr(int key){
    lr(&root,key);
}

void BST::lr(node **root,int key){
    
    bool isfound = false;
    node** temp = root;
    node** keyPtr = NULL;
    node** parent = NULL;
    bool pl = false;
    bool pr = false;
   
    while(!isfound && temp){
        
        
        if((*temp)->key == key){
            keyPtr = temp;
            isfound = true;
        }
        else {
            if(((*temp)->key) > key){
                parent = temp;
                pl = true;
                pr = false;
                temp = &((*temp)->left);
            } else if(((*temp)->key) < key){
                parent = temp;
                pr = true;
                pl = false;
                temp = &((*temp)->right);
            }
        }
    }
    //cout << "found " << (*keyPtr)->key;
    if (((*keyPtr)->right) != NULL  && (*keyPtr != NULL)) {
        
        
        
        
        bool keyIsRoot = false;
        if (keyPtr == root) {
            keyIsRoot = true;
        }
        
        node* temp1 = ((*keyPtr)->right);
        
        int t = (temp1)->noOfLC;
        (temp1)->noOfLC = (temp1)->noOfLC + (*keyPtr)->noOfLC + 1;
        (*keyPtr)->noOfRC =  t;
        
        
        (*keyPtr)->right = (temp1)->left;
        (temp1)->left = (*keyPtr);
        
        
        if (keyIsRoot) {
            *root = temp1;
        }else if(pr){
            (*parent)->right = temp1;
        }else{
            (*parent)->left = temp1;
        }
    }
}

//node* BST::find(node **root,int key){
//    if((*root)->key == key){
//        return *root;
//    }
//    else {
//        if(((*root)->key) > key){
//            find(&((*root)->left),key);
//        } else if(((*root)->key) < key){
//            find(&((*root)->right),key);
//        }
//    }
//    return *root;
//}

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
        if (s == "PRE-ORDER")
        {
            bst.preorder();
            cout << endl;
        }
        if(s == "RR"){
            cin >> N;
            bst.rr(N);
        }
        if(s == "LR"){
            cin >> N;
            bst.lr(N);
        }
        
    }
    return 0;
}
