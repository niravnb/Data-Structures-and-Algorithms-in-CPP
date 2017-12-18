#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
     int m,n,k,temp,maxsum,temp1,temp2;
    cin >> m >> n;
 
    int arr[m][n];
    int sum[m][n];
    int sum1[m][n];
     int sum2[m][n];

    for(int i = 0; i < m;i++){
        for(int j = 0; j < n;j++){
             cin >> temp;
             arr[i][j] = temp;
        }
       
    }
    
    
       for(int i = 0; i < m;i++){
        for(int j = 0; j < n;j++){
            
            if(i == 0){
                sum2[i][j] = arr[i][j];
            }else{
                sum2[i][j] = arr[i][j] + sum2[i-1][j];
            }
        }
    
    }
    
    
 
          
    maxsum = sum2[0][0];
    
     for(int i = 0; i < m;i++){
        for(int j = 0; j < n;j++){
            
            if(j == 0){
               sum1[i][j] = sum2[i][j]; 
            }else{
                sum1[i][j] = sum1[i][j-1] + sum2[i][j];
            }
            
            
           //      cout <<  sum[i][j] << " ";
            
            if(sum1[i][j] > maxsum){
                maxsum = sum1[i][j];
            }
            
            
       }
       
       
    }
 
    
     cout <<  maxsum << endl;
    
    return 0;
}
