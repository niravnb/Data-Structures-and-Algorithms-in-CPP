 
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/* Create your class(es) here 
   You may use more than one class */
 struct node{
        int key;
        struct node *left;
        struct node *right;
 }*root;

class BST {
      
    
    public:
        int insert(int);
        int ceil(int);
        int height();
        int insertWithRootProvided(node*,int,int);
        int heightWithRecursion(node*);
        int ceilWithRecursion(node*,int,int);
    
        BST(){
            root = NULL;
        }
     
    
};

int BST::insert(int val){
        
    return insertWithRootProvided(root,val,0);
}


int BST::insertWithRootProvided(node *currentnode,int val,int level){
   // int level;
    
    if(root == NULL){
            root = new node;
            root->key = val;
            root->left = NULL;
            root->right = NULL;
            level = 0;
       
    }else if((currentnode->key) > val){
        if((currentnode->left) == NULL){
            currentnode->left = new node;
            (currentnode->left)->key = val;
            (currentnode->left)->left = NULL;
            (currentnode->left)->right = NULL;
            level++;
            
          
          
        }else{
            level++;
            currentnode = currentnode->left;
            level = insertWithRootProvided(currentnode,val,level);
        }
       
    }else if((currentnode->key) < val){
        if((currentnode->right) == NULL){
            currentnode->right = new node;
            (currentnode->right)->key = val;
            (currentnode->right)->left = NULL;
            (currentnode->right)->right = NULL;
            level++;
            
          
          
        }else{
            level++;
            currentnode = currentnode->right;
            level = insertWithRootProvided(currentnode,val,level);
        }
       
    }
    
      return level;
}

int BST::ceil(int val){
   
           struct node *temp = root;
            while(temp->right != NULL){
                temp = temp->right;
            }
            
            if(temp->key < val){
                return 10000;
            }
    
    return ceilWithRecursion(root,val,root->key);
}

int BST::ceilWithRecursion(node* currentnode,int val,int preVal){
  // int l;
    
    
    if(currentnode->key == val){
        
        return val;
    }
    
             

    
    if(currentnode->key < val){
        if(currentnode->right != NULL){
       // currentnode = currentnode->right;
           if(currentnode->key > val){
                
          
                preVal = currentnode->key;
            }
       return  ceilWithRecursion(currentnode->right,val,preVal);
        } else {
             if(currentnode->key > val){
                 return currentnode->key;
             } else {
                 return preVal;
             }
        }
    } else {
        if(currentnode->left != NULL){
           // currentnode = currentnode->left;
            if(currentnode->key > val){
                
          
                preVal = currentnode->key;
            }
           return ceilWithRecursion(currentnode->left,val,preVal);
        } else {
           if(currentnode->key > val) {
               return currentnode->key;
        } else{
               return preVal;
           }
        
    }
  //  return l;
}
}

int BST::height(){
        
         return heightWithRecursion(root);
    
    
}


int BST::heightWithRecursion(node* currentnode){
    
    if((currentnode->left == NULL) && (currentnode->right == NULL)){
        return 0;
    } else {
        int lefth;
        int righth;
        if((currentnode->left) != NULL){
           lefth = heightWithRecursion(currentnode->left);
        }else{
            lefth = 0;
        } 
        if((currentnode->right) != NULL){
           righth = heightWithRecursion(currentnode->right); 
        } else {
            righth = 0;
        } 
        if(lefth>righth) {
            return (lefth+1);
        }else{
             return (righth+1);   
        }
  
    }
    
    
 
}

// ! DO NOT CHANGE WHEN SUBMITTING !
int main() {
    int N,val;
    string cmd;
    
    BST tree;   // BST is the class you have to create.
      // Contains atleast 3 public methods.
      // insert(val), ceil(val), height()
    
    cin >> N;
    for(int i=0;i<N;++i) {
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
 
