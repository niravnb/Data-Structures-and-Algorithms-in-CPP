#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;



int main() {
    
    int vertices,edges;
    
    cin >> vertices;
    cin >> edges;
   
    
    int adjMatrix[vertices][vertices];
   
  long  int noOfPaths[vertices][vertices];
    
    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; ++j)
        {           

            if (i == j)
            {
                noOfPaths[i][j] = 1;
                 adjMatrix[i][j] = 0;
            }else{
                noOfPaths[i][j] = 0;
                adjMatrix[i][j] = 10001;
            }
        }
    }
    
    int v1,v2,w;
   
    
    for(int i = 0; i < edges;i++){
        
        cin >> v1 >> v2 >> w;
        
       adjMatrix[v1][v2] = w;
       adjMatrix[v2][v1] = w;
       noOfPaths[v1][v2] = 1;
       noOfPaths[v2][v1] = 1;
        
      
    }


     int oldadjMatrix[vertices][vertices];
      int newadjMatrix[vertices][vertices];
      int oldval, newkthval;
        
  copy(&adjMatrix[0][0],&adjMatrix[0][0]+vertices*vertices,&oldadjMatrix[0][0]);

    for (int k = 0; k < vertices; ++k)
    {
        if(k>0){
            copy(&newadjMatrix[0][0],&newadjMatrix[0][0]+vertices*vertices,&oldadjMatrix[0][0]);
        }
        for (int i = 0; i < vertices; ++i)
        {
            for (int j = 0; j < vertices; ++j)
            {   
                oldval = oldadjMatrix[i][j];
                newkthval = oldadjMatrix[i][k] + oldadjMatrix[k][j];

                if (oldval < newkthval)
                {
                    newadjMatrix[i][j] = oldval;

                }else if (oldval == newkthval)
                {
                    newadjMatrix[i][j] = newkthval;
                    if(i != j && i!=k && j!=k)  noOfPaths[i][j] += noOfPaths[i][k]*noOfPaths[k][j]; 

                }else if (oldval > newkthval)
                {
                    newadjMatrix[i][j] = newkthval;
                     if(i != j && i!=k && j!=k)  noOfPaths[i][j] = noOfPaths[i][k]*noOfPaths[k][j]; 
                }


            //  newadjMatrix[i][j] = oldadjMatrix[i][j] < oldadjMatrix[i][k] + oldadjMatrix[k][j] ? oldadjMatrix[i][j] : oldadjMatrix[i][k] + oldadjMatrix[k][j];

            }

        }

    if(k == 0 || k == (int)((vertices-1)/2)){
            
            double op,tempSum,temp;


     for (int k = 0; k < vertices; ++k)
    {
        tempSum = 0.0;
        
        for (int i = 0; i < vertices; ++i)
        {
            for (int j = i+1; j < vertices; ++j)
            {  
                
                 if(i!=k && j!=k ){


                    if (newadjMatrix[i][j] == newadjMatrix[i][k] + newadjMatrix[k][j])
                    {
                            temp = noOfPaths[i][k]*noOfPaths[k][j];                 
                           tempSum += temp/noOfPaths[i][j];
                        }

                 }



            }
        }
         printf("%0.15f\n",tempSum);
         
        }
        
         cout << endl;   
            
        }
        
        
        
        
        
    }
    
        
     
            double op,tempSum,temp;


     for (int k = 0; k < vertices; ++k)
    {
        tempSum = 0.0;
        
        for (int i = 0; i < vertices; ++i)
        {
            for (int j = i+1; j < vertices; ++j)
            {  
                
                 if(i!=k && j!=k ){


                    if (newadjMatrix[i][j] == newadjMatrix[i][k] + newadjMatrix[k][j])
                    {
                            temp = noOfPaths[i][k]*noOfPaths[k][j];                 
                           tempSum += temp/noOfPaths[i][j];
                        }

                 }



            }
        }
         printf("%0.15f\n",tempSum);
     }
    //cout <<  setprecision(9)  << tempSum << endl;
     return 0;
    }
    
   