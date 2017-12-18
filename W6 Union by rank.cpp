#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node{
public:
    int rank,label;
    node* parent;

    node(int r){
        this->rank = 0;
        this->label = r;
        this->parent = this;
    }
};

class unionOfSets{
public:

    node** sets;
    int noOfSets;

    unionOfSets(){
        this->sets = NULL;
        this->noOfSets = 0;
    }

    void makesets(int n){
        this->sets = new node*[n+1];
        this->noOfSets = n;

        for (int i = 1; i <= n; ++i)
        {
            this->sets[i] = new node(i);
            // this->sets[i]->rank = 0;
            // this->sets[i]->label = i;
            // this->sets[i]->parent = NULL;

        }
    }

    void unionsets(int a, int b){

        int p,q;
        p = find(a);
        q = find(b);

        if (p != q)
        {
            int r,r1;
            r = this->sets[p]->rank;
            r1 = this->sets[q]->rank;

            if (r == r1)
            {
                this->sets[p]->parent = this->sets[q];
                this->sets[q]->rank++;
            }
            if(r < r1){
                this->sets[p]->parent = this->sets[q];
                
            }
            if(r > r1){
                this->sets[q]->parent = this->sets[p];
                
            }

            this->noOfSets--;
        }

        
    }

    int find(int a){
        node* temp = this->sets[a];
        while(temp != temp->parent){
            temp = temp->parent;
        }

        return temp->label;
    }

    int findparent(int a){
        node* temp = this->sets[a];
        //while(temp != temp->parent){
            temp = temp->parent;
        //}

        return temp->label;
    }

    int cc(){

        return this->noOfSets;
    }



};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,Q;
    cin >> N;
    cin >> Q;
    string cmd;
    int p,q;

    unionOfSets u;
    u.makesets(N);



    int temp;
    for (int i = 0; i < Q; ++i)
    {
        cin >> cmd;
        if (cmd == "UNION")
        {
            cin >> p;
            cin >> q;
            u.unionsets(p,q);
            
        }
        if (cmd == "FIND")
        {
            cin >> p;
            temp = u.find(p);
            cout << temp << endl;
            
        }
        if (cmd == "CC")
        {
            temp = u.cc();
            cout << temp << endl;   
            
        }

    }


    return 0;
}
