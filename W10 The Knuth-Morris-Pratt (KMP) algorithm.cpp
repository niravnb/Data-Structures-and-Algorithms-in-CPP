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
    int pl,tl;
    string p,t;
    while(N--){
        cin >> pl;
        cin >> tl;
        cin >> p;
        cin >> t;
        
        int pip[pl];
        pip[0] = 0;
        int q;
        for(int i = 1; i < pl;i++){
            
            q = pip[i-1];
            
            if(p[i] == p[q]){
                pip[i] = q+1;
            }else{
                
                while(q > 0){
                    q = pip[q-1];
                    if(p[i] == p[q]){
                        pip[i] = q+1;
                        break;
                    }else{
                        if(q == 1){
                            q = 0;
                            break;
                        }
                        
                    }
                    
                }
                
                if(q == 0){
                    if(p[i] == p[q]){
                        pip[i] = 1;
                    }else
                        pip[i] = 0;
                }
                
            }
            
            
            
        }
        
        
 
        
            
        int pp = 0;
        int matchl = 0;
        int wloop = 0;
        
        for(int s = 0; s < tl;){
            wloop = 0;
            //  cout << p[pp] << " " << t[s] << endl;
            while(p[pp] == t[s]){
                matchl++;
                pp++;
                wloop++;
                s++;
                if(matchl == pl){
                    cout << s-(pl) << " ";
                    matchl = 0;
                    break;
                }
                
            }
            
            if (pp > 0) {
                pp = pip[pp-1];
                matchl = pp;
            }else {
                s++;
            }

        }
        
        
        
        
        
        
        
        cout << endl;
    }
    
    return 0;
}
