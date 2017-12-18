#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int vertex,weight;
    node *next;
    
};


struct graph{
    int noofVertices;
    struct node** adjList;
};

node* createnode(int v, int w){
    node *temp = (struct node*)malloc(sizeof(struct node));
    temp->vertex = v;
    temp->weight = w;
    temp->next = NULL;
    
    return temp;
}


graph* creategraph(int n){
    
    graph* temp = (struct graph*)malloc(sizeof(struct graph));
    temp->noofVertices = n;
    
    temp->adjList = (struct node**)malloc(n * sizeof(struct node*));
    
    for (int i = 0; i<n; i++) {
        temp->adjList[i] = NULL;
    }
    
    return temp;
                         
    
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int vertices,edges;
    
    cin >> vertices;
    cin >> edges;
    
    graph *mygraph = creategraph(vertices);

    
    int verticesseen[vertices];
    int v1,v2,w;
    
    for(int i = 0;i<vertices;i++){
        verticesseen[i] = 0;

        
    }
    
    
    int maxweight = 0;
    
    for(int i = 0; i < edges;i++){
        
        cin >> v1 >> v2 >> w;
        
            node *temp = createnode(v2, w);
            temp->next = mygraph->adjList[v1];
            mygraph->adjList[v1] = temp;
      //  mygraph->adjList[v1]->weight = w;
        
        node *temp1 = createnode(v1, w);
        temp1->next = mygraph->adjList[v2];
        mygraph->adjList[v2] = temp1;
    //    mygraph->adjList[v2]->weight = w;

        
        if(w > maxweight) maxweight = w;
        
    }
    
    
//    for(int i = 0;i<vertices;i++){
//    
//        struct node* temp = mygraph->adjList[i];
//        
//        while (temp) {
//            cout <<  temp->vertex << "  " << temp->weight << endl;
//            temp = temp->next;
//        }
//        
//    
//    
//    }
    
    
    
        int v0,vminedge,minver;
        double minTreeWeight, vminweight;
        vminedge = 0;
        vminweight = 0;
        minTreeWeight = 0;
        cin >> v0;
        verticesseen[v0] = 1;
        int ifseen = 0;
        // int firsttime = 0;
    
        for(int i = 0;i<vertices-1;i++){
    
            ifseen = 0;
            vminweight = maxweight;
            
            
            if (i == 0) {
                
           
            
            struct node* temp = mygraph->adjList[v0];
            
                    while (temp) {
                        if (temp->weight <= vminweight && verticesseen[temp->vertex] == 0) {
                            vminweight = temp->weight;
                            vminedge = temp->vertex;
                            ifseen = 1;
                        }
                        temp = temp->next;
                    }

            }else{
                
                for (int j = 0; j<vertices; j++) {
                    
                    if (verticesseen[j] == 1) {
                        
                        struct node* temp = mygraph->adjList[j];
                        
                        while (temp) {
                            if (temp->weight <= vminweight && verticesseen[temp->vertex] == 0) {
                                vminweight = temp->weight;
                                vminedge = temp->vertex;
                                ifseen = 1;
                            }
                            temp = temp->next;
                        }
                        
                        
                    }
                    
                }
                
                
            }
    
        
           //   cout << "Min Vertex " << vminedge << " with weight " << vminweight << endl;
    
            if(ifseen == 1){
                minTreeWeight = minTreeWeight + vminweight;
                verticesseen[vminedge] = 1;
                //   weights[minver][vminedge] = 0;
                //   weights[vminedge][minver] = 0;
            }
            
            v0 = vminedge;
            
        }
    
        cout << minTreeWeight << endl;
    
    //
    //    /*
    //
    //     0 1 2 3 4 5
    //     0 0 2 1 0 0 0
    //     1 0 0 0 4 0 0
    //     2 0 0 0 3 1 1
    //     3 0 0 0 0 0 0
    //     4 0 0 0 1 0 1
    //     5 0 0 0 2 0 0
    //     */
    //
    //
    return 0;
}
