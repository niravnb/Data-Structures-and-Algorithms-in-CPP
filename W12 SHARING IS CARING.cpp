#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
 int N,M;
vector<vector<int> > adjMatrix;
vector<int> distances;


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


int bellmonford(struct graph* g){

  int distance[N];
  int distancenew[N];
  int value = 1;

  for (int i = 0; i < N; ++i)
  {
    distance[i] = INT16_MAX;
        distancenew[i] = INT16_MAX;

  }
  distance[0] = 0;
    distancenew[0] = 0;


  for (int i = 0; i < N-1; ++i)
  {
      
      
        
    for (int j = 0; j < M; ++j)
    {
      int u = g->edgeList[j].source;
      int v = g->edgeList[j].dest;
      int w = g->edgeList[j].weight;

      if (distance[u] != INT16_MAX && distance[v] > distance[u] + w)
      {
        distance[v] = distance[u] + w;
      }
      
    }
        
  }

  // for (int i = 0; i < N; ++i)
  // {
  //   cout << distance[i]  << " ";

  // }

  for (int j = 0; j < M; ++j)
    {
      int u = g->edgeList[j].source;
      int v = g->edgeList[j].dest;
      int w = g->edgeList[j].weight;

      if (distance[u] != INT16_MAX && distance[v] > distance[u] + w)
      {
        return 0;
        break;
      }
      
    }


  return 1;



}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
     // int st,tt,temp;
    cin >> N;
    cin >> M;



     



     adjMatrix = vector<vector<int>>(M, vector<int>(4));
     distances = vector<int>(N);
    int v1,v2,b,t,equalcount;
    equalcount = 0;
    for (int i = 0; i < M; ++i)
    {
      cin >> v1 >> v2 >> b >> t;
      // mygraph->edgeList[i].source = v1-1;
      // mygraph->edgeList[i].dest = v2-1;
      // mygraph->edgeList[i].weight = wt;
      //adjMatrix[v1][v2] = wt;
      if (t==2)
      {
      adjMatrix[i][0] = v1;
      adjMatrix[i][1] = v2;
      adjMatrix[i][2] = -b;
      adjMatrix[i][3] = t;
      }else{
      adjMatrix[i][0] = v2;
      adjMatrix[i][1] = v1;
      adjMatrix[i][2] = b;
      adjMatrix[i][3] = t;
    }
      if (t==0)
      {
        equalcount++;
      }

    }

    M = M+N+equalcount;
    N++;

     graph *mygraph = creategraph(N,M);
     int i = 0;
    int j = 0;

     for (;i < M-N+1; ++i,j++)
    {
      

      mygraph->edgeList[i].source = adjMatrix[j][0];
      mygraph->edgeList[i].dest = adjMatrix[j][1];
      mygraph->edgeList[i].weight = adjMatrix[j][2];


      if (adjMatrix[j][3] == 0)
      {
        i++;
        mygraph->edgeList[i].source = adjMatrix[j][1];
      mygraph->edgeList[i].dest = adjMatrix[j][0];
      mygraph->edgeList[i].weight = -1*adjMatrix[j][2];
      }
    }
    


    int tempsource = 1;

       for (; i < M; ++i)
    {
      

      mygraph->edgeList[i].source = 0;
      mygraph->edgeList[i].dest = tempsource++;
      mygraph->edgeList[i].weight = 0;
     


}

    
    int val =  bellmonford(mygraph);

    if (val == 0)
    {
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
    }


  

    
    
    return 0;
}
