#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
 int N,M;
vector<vector<int> > adjMatrix;


struct edge{
    int source,dest,weight;   
};


struct graph{
    int V,E;
    struct edge* edgeList;
};



graph* creategraph(int n, int m){
    
    graph* temp = new graph;  //(struct graph*)malloc(sizeof(struct graph));
    temp->V = n;
    temp->E = m;
    
    temp->edgeList = new edge[m]; //(struct edge*)malloc(m * sizeof(struct edge*));
    
    // for (int i = 0; i<m; i++) {
    //     temp->edgeList[i] = NULL;
    // }
    
    return temp;
                         
    
}


int bellmonford(struct graph* g,int s, int t,int k){

  int distance[N];
  int distancenew[N];

  for (int i = 0; i < N; ++i)
  {
    distance[i] = INT16_MAX;
        distancenew[i] = INT16_MAX;

  }
  distance[s] = 0;
    distancenew[s] = 0;


  for (int i = 0; i < k; ++i)
  {
      
        if(i>=1){
             for (int l = 0; l < N; ++l)
                distance[l] = distancenew[l];
        }
        
          
        
    for (int j = 0; j < M; ++j)
    {
      int u = g->edgeList[j].source;
      int v = g->edgeList[j].dest;
      int w = g->edgeList[j].weight;

      if (distance[u] != INT16_MAX && distancenew[v] > distance[u] + w)
      {
        distancenew[v] = distance[u] + w;
      }
      
    }
        
  }


  return distancenew[t];



}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
     int st,tt,temp;
    cin >> N;
    cin >> M;

    cin >> st;
    cin >> tt;

     graph *mygraph = creategraph(N,M);

    // adjMatrix = vector<vector<int>>(N, vector<int>(N));

    int v1,v2,wt;
    for (int i = 0; i < M; ++i)
    {
      cin >> v1 >> v2 >> wt;
      mygraph->edgeList[i].source = v1-1;
      mygraph->edgeList[i].dest = v2-1;
      mygraph->edgeList[i].weight = wt;
      //adjMatrix[v1][v2] = wt;
    }

    int testcases,s,t,k;
    cin >> testcases;

    while(testcases--){
      cin >> s >> t >> k;
      cout << bellmonford(mygraph,s-1,t-1,k) << endl;

    }



    
    //  for (int j = 0; j < M; ++j)
    // {
    //  cout << mygraph->edgeList[j].source << " " << mygraph->edgeList[j].dest << " " << mygraph->edgeList[j].weight << endl;
    // }
    
    
    
    return 0;
}
