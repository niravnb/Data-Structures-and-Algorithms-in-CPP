#include <cstdio>
#include <iostream>
using namespace std;


int main() {
    int n;
    cin>>n;
    
    int arr[n];
    
    for(int i = 0; i < n;i++) {
        int temp;
        cin>>temp;
        arr[i] = temp;
    }
    
    int k;
    cin>>k;
    k=k%n;

    int t;
    for(int i = 0; i < n;i++){
   
        if(k<0){
            
            t = (i-k)%n;
            
        }
        else{
            t = (n+i-k)%n;
            
        }
       
        cout<<arr[t];
        cout<<" "; 
    }
    
    cout<<"\n";
    
    return 0;
}
