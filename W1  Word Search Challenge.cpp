#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    
    int noOfTestCases,n1,o1,lens1;
    string first;
    
    
    cin>>noOfTestCases;
    
    
    for(int a = 0;a<noOfTestCases;a++){
        
        o1 = 0;
        cin>>n1;
        
        char firstMatrix[n1][n1];
        
        for(int i = 0;i<n1;i++){
            for(int k = 0;k<n1;k++){
                char temp;
                cin>>temp;
                firstMatrix[i][k] = temp;
            }
        }
        
        cin>>first;
        
        
        lens1 = (int)first.size();

   //    if(lens1 != 0) {
            
          
        
        for(int row = 0;row<n1;row++){
            
            for(int cols = 0;cols<n1;cols++){
                
                int col = cols;
                int sPtr = 0;
                
                while(1){
                    
                if(firstMatrix[row][col] == first[sPtr]){
                    sPtr++;
                    col = (col + 1)%n1;
                } else {
                   break;
                }
                
                if(sPtr == lens1){
                    o1++;
                    sPtr = 0;
                    break;
                    
                } 
              }  
                
                
            }
                        
        }
        
  //  if(lens1 != 1) {
           
           
                      
       
        for(int col = 0;col<n1;col++){
           
            for(int rows = 0;rows<n1;rows++){
                
                int row = rows;
                int sPtr = 0;
                
                while(1){
                    
                if(firstMatrix[row][col] == first[sPtr]){
                    sPtr++;
                    row = (row + 1)%n1;
                } else {
                   break;
                }
                
                if(sPtr == lens1){
                    o1++;
                    sPtr = 0;
                    break;
                    
                } 
              }  
                
                
            }
           
           
           
        }
       
      if(lens1 <= n1) {
       
        for(int rows = 0;rows<n1-1;rows++){
           
            for(int cols = 0;cols<n1-1;cols++){
                
                int col = cols;
                int sPtr = 0;          
                int row = rows;
           
           
            while(row < n1 || col < n1){
                if(firstMatrix[row][col] == first[sPtr]){
                    row++;
                    col++;
                    sPtr++;
                   
                } else{
                    break;
                }
                               
                if(sPtr == lens1){
                    o1++;
                    sPtr = 0;
                    break;
                    
                } 
               
            }
        }

      }
          
     }
       
//   }
            
       
      
        
 // }       
        
    cout<<o1<<endl;
    
    
    } 
    return 0;
}
