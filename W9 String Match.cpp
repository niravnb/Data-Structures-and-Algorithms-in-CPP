#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

  int N;
  cin >> N;
  string text,pattern;
    int l;
    int match;
    
    
  while(N--){
    cin >> text;
    cin >> pattern;

    match = 0;
    l = 0;

    for(int i = 0; i < text.length(); i++){
         
      if (text[i] == pattern[0])
      {
        l++;
        for (int j = 1; j < pattern.length(); ++j)
        {
          if (text[i+j] == pattern[j]){
            l++;
          }else{
                        l = 0;
                        break;
                    }
    
           }
                
                if(l == pattern.length()){
                    match = 1;
                    break;
                }


    } 

  }
        if(match == 1){
      cout << "YES" << endl;
    }else{
            cout << "NO" << endl;
        }

        
  }
    
    
    return 0;
}
