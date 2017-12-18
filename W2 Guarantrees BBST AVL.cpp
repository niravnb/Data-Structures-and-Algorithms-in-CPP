#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
   int key,height,noOfLeftChild, noOfRightChild, noOfTotalChildrens;
   struct node *left;
   struct node *right;
    
}*root;


class BBST{

    
    
    public:
    
        int height(node *p){
            return p ? p->height : 0;
        }
    
        int balanceFactor(node *p){
            return height(p->right) - height(p->left);
        }
    
        void fixheight(node* p){
            int hl = height(p->left);
            int hr = height(p->right);
            p->height = (hl>hr ? hl : hr) + 1;

            fixNoOfChilds(p);
        }
        
        void fixNoOfChilds(node* p){
            p->noOfLeftChild = (p->left)?(p->left)->noOfTotalChildrens + 1: 0;
            p->noOfRightChild = (p->right)?(p->right)->noOfTotalChildrens + 1: 0;
            p->noOfTotalChildrens = p->noOfLeftChild + p->noOfRightChild;
            

        }
    
        node* rotateright(node* p){
            node* q = p->left;
            p->left = q->right;
            q->right = p;
            fixheight(p);
            fixheight(q);
            return q;
            
        }
        
        node* rotateleft(node* p){
            node* q = p->right;
            p->right = q->left;
            q->left = p;
            fixheight(p);
            fixheight(q);
            return q;
            
        }
    
        node* balancenodes(node* p){
            
            fixheight(p);
            
            if(balanceFactor(p) == 2){
                if( balanceFactor(p->right) < 0 )
                     p->right = rotateright(p->right);
                return rotateleft(p);    
            }
            
            if(balanceFactor(p) == -2){
                if( balanceFactor(p->left) > 0 )
                     p->left = rotateleft(p->left);
                return rotateright(p);    
            }
            
           
            return p;
            
        }
    
        void insertt(int val){
           root = insert(root,val);
        }
    
        node* insert(node *p,int val){
            
            
            if(p == NULL){
                p = new node;
                p->key = val; 
                p->left = NULL; 
                p->right = NULL;
                p->height = 1; 
                p->noOfLeftChild = 0; 
                p->noOfRightChild = 0; 
                p->noOfTotalChildrens = 0; 
                return p;   
            }
            
            if(val < p->key) {
                p->left = insert(p->left,val);
                
        } else {
                p->right = insert(p->right,val);
            }  
            
            
            return balancenodes(p);
            
           
            
        }
    
        node* findmin(node* p){
            return p->left?findmin(p->left):p;
        }
    
        node* removemin(node* p){
            if(p->left == NULL)
                return p->right;
            
            p->left = removemin(p->left);
            return balancenodes(p);
            
        }
    
        node* del(node *p,int val){
            if(p == NULL) return NULL;
            
            if(val < p->key)
                p->left = del(p->left,val);
            else if(val > p->key)
                p->right = del(p->right,val);
            else{
                
                node* q = p->left;
                node* r = p->right;
                delete p;
                if( !r ) return q;
                node* min = findmin(r);
                min->right = removemin(r);
                min->left = q;
                return balancenodes(min);
            }
            
            
            return balancenodes(p);
            
          //  cout << "deleted " << val; 
        }
    
        int minm(node *p,int val){
            
         //   cout << "leftchilds " << p->noOfLeftChild << endl;
          //  cout << "rightchilds " << p->noOfRightChild << endl;
           // cout << "total " << p->noOfTotalChildrens << endl;


            
             if(p->noOfLeftChild  == val-1){
                return p->key;
            }
            
            if(p->noOfLeftChild >= val){
                return minm(p->left,val);
            } else if(p->noOfRightChild >= val - (p->noOfLeftChild + 1)){
                return minm(p->right,val - (p->noOfLeftChild + 1));
            }
            
           
            
           return p->key;
        }
    
        BBST(){
          root = NULL; 
            
        }
    
        
    
    
};



int main() {

    int N,val;
    char cmd;
    
    BBST tree;
  //  node *root;
    
    cin >> N;
    for(int i=0;i<N;++i) {
   cin >> cmd;
   if(cmd == 'i') {
      cin >> val;
     root = tree.insert(root,val);   
   } else if(cmd == 'd') {
      cin >> val;
      root = tree.del(root,val);
   } else if(cmd == 'm') {
       cin >> val;
      cout << tree.minm(root,val) << "\n";   
   }
   
    }
    return 0;
    
}
