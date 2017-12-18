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

struct heapnode{
    int name,key;
    
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




class myHeap{
    
public:
    
    heapnode *heapArray;
    int noOfElements;
    
    void createHeap(int n,int s){
        this->noOfElements = 0;
        this->heapArray = (struct heapnode*)malloc(n * sizeof(struct heapnode));
        
        for (int i = 0; i < n; i++) {
            insertKey(i,INT32_MAX);
        }
        decreaseKey(s, 0);

    }
    
    void insertKey(int n, int k){
        noOfElements++;
        heapArray[noOfElements-1].name = n;
        heapArray[noOfElements-1].key = k;
        heapifyUp(noOfElements-1);
        
    }
    
    
    void heapifyUp(int i){
        
        if(i>0 && heapArray[i].key < heapArray[(int)((i-1)/2)].key){
            int j = (int)((i-1)/2);
            swapHeap(i, j);
             heapifyUp(j);
            
        }
    }
    
    void swapHeap(int i, int j){
            int temp = heapArray[i].key;
            heapArray[i].key = heapArray[j].key;
            heapArray[j].key = temp;
            
            int temp1 = heapArray[i].name;
            heapArray[i].name = heapArray[j].name;
            heapArray[j].name = temp1;
            
        }
        
    
    void decreaseKey(int i, int k){
        
        heapArray[i].key = k;
        heapifyUp(i);
    }
    
    
    
    void heapifyDown(int i){
        int l,r;
        l = 2*i + 1;
        r = 2*i + 2;
        
        int smallest = i;
        if (l < noOfElements && heapArray[l].key < heapArray[i].key)
            smallest = l;
        if (r < noOfElements && heapArray[r].key < heapArray[smallest].key)
            smallest = r;
        if (smallest != i)
        {
            swapHeap(i, smallest);
            heapifyDown(smallest);
            
        }
        
    }
    
    heapnode extractMin(){
        
        heapnode m = heapArray[0];
        
        if (noOfElements == 1)
        {
            noOfElements--;
            
        }
        else {
            
            heapArray[0].key = heapArray[noOfElements-1].key;
            heapArray[0].name = heapArray[noOfElements-1].name;
            noOfElements--;
            heapifyDown(0);
        }
        
        return m;
        
        
    }
    
    void levelOrder(){
        
        for (int i = 0; i < noOfElements; ++i)
        {
            cout << heapArray[i].name << " " << heapArray[i].key << endl;
        }
        
    }
    
    
};


int main() {
    
    int vertices,edges,source;
    
    cin >> vertices;
    cin >> edges;
    cin >> source;
    
    graph *mygraph = creategraph(vertices);
    
    
//    int verticesseen[vertices];
//    for(int i = 0;i<vertices;i++){
//        verticesseen[i] = 0;
//    }
    
    int v1,v2,w;
    int maxweight = 0;
    
    for(int i = 0; i < edges;i++){
        
        cin >> v1 >> v2 >> w;
        
        node *temp = createnode(v2, w);
        temp->next = mygraph->adjList[v1];
        mygraph->adjList[v1] = temp;
       
        node *temp1 = createnode(v1, w);
        temp1->next = mygraph->adjList[v2];
        mygraph->adjList[v2] = temp1;
        
        if(w > maxweight) maxweight = w;
    }
    
    
    
    myHeap h;
    h.createHeap(vertices,source);
   // h.levelOrder();
    

//                    for(int i = 0;i<vertices;i++){
//    
//                        struct node* temp = mygraph->adjList[i];
//                        cout  << "Adj list for vertex: " << i << " is ";
//                        while (temp) {
//                            cout <<  temp->vertex << "  " << temp->weight << " ";
//                            temp = temp->next;
//                        }
//                        cout << endl;
//                    }
//    
    
    graph *myMinGraph = creategraph(vertices);
    int shortespath[vertices];
    shortespath[source] = 0;
  //  shortespath[1] = 100;
    
    int noOfPaths[vertices];
    
    for(int i = 0;i<vertices;i++){
        noOfPaths[i] = 0;
    //    shortespath[i] = 0;
        
    }
    
     noOfPaths[source] = 1;
    
    
    
    while (h.noOfElements != 0) {
        heapnode currentMin = h.extractMin();
        
        // add to S
        v1 = source;
        v2 = currentMin.name;
        w = currentMin.key;
        
//        cout << "level order :" << endl;
//        h.levelOrder();
//        cout << "Current extract min is : " << v2 << " with weitht " << w << endl;
////
        shortespath[v2] = w;
       

        
        if (v1 != v2) {
        node *temp = createnode(v2, w);
        temp->next = myMinGraph->adjList[v1];
        myMinGraph->adjList[v1] = temp;
        
        node *temp1 = createnode(v1, w);
        temp1->next = myMinGraph->adjList[v2];
        myMinGraph->adjList[v2] = temp1;
        }
        
        struct node* temp2 = mygraph->adjList[v2];
            while (temp2) {
                int wu,wv;
                
                int index;
                for (int j = 0; j < h.noOfElements; j++) {
                    if (h.heapArray[j].name == temp2->vertex) {
                        index = j;
                        wu = h.heapArray[index].key;
                        wv = w + temp2->weight;
                        if (wu > wv) {
                            h.decreaseKey(index, wv);
                            noOfPaths[temp2->vertex] = noOfPaths[v2];
                        }else if (wu == wv) {
                            //h.decreaseKey(index, wv);
                            noOfPaths[temp2->vertex] += noOfPaths[v2];
                        }
                        break;
                    }
                }
                
               
                temp2 = temp2->next;
            }
        
    }
    
//    cout << "Shortest path array :" << endl;
//    for(int i = 0;i<vertices;i++){
//        cout << shortespath[i] << " " ;
//    }
//    cout << endl;
    

    
//    for(int i = 0;i<vertices;i++){
//        if(shortespath[i] == INT32_MAX){
//            noOfPaths[i] = 0;
//        }
//    }
    
        for(int i = 0;i<vertices;i++){
            cout << noOfPaths[i] << " " ;
        }
        cout << endl;

    
    
    
    
    return 0;
}



