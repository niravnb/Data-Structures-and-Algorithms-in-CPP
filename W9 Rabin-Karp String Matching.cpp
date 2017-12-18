#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

 int main() {
    /* Enter your code here. Read input from STDIN. Pr int output to STDOUT */   

   int N;
  cin >> N;
  string text,pattern;
     int lmatch;
     int match;
 
    
    
  while(N--){
    cin >> text;
    cin >> pattern;

    match = 0;
    lmatch = 0;
     
       int l = pattern.length();
       int b = 124;
       int m = 101;

        int h = 1;
      
      for (int i = 0; i < l-1; i++){
        h = (h*b)%m;
      }


 int hp = 0;
 int oldh = 0;
 int newh = 0;

            for ( int i = 0; i < l; ++i)
            {
                hp =(b*hp + pattern[i])%m;
                newh =(b*newh + text[i])%m;

                
            }


    for( int i = 0; i <= text.length()-l; i++){

      
      if(newh == hp){

        if (text[i] == pattern[0])
           {
          lmatch++;
          for ( int k = 1; k < l; ++k)
          {
            if (text[i+k] == pattern[k]){
              lmatch++;
            }else{
                    lmatch = 0;
                    break;
                }
             }
                
                  if(lmatch == l){
                      match = 1;
                      lmatch = 0;
                     
                  }
           }  
      }

      if(match == 1){
        break;
      }

      if (i < text.length()-l)
      {
        
        newh = ((b*(newh - h*text[i])) + text[i+l])%m;

        if (newh < 0)
        {
          newh += m;
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
