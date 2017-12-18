#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N,M;

vector<vector<int> > quality;
vector<vector<int> > dppath;
vector<vector<int> > dppath1;


int findOptimalPathother(int i,int j){

if (i == 0 && j == M-1)
{
    return quality[i][j];
}else if(i == 0){
    return quality[i][j] + dppath1[i][j+1];

}else if(j == M-1){
    return quality[i][j] + dppath1[i-1][j];

}else{
    int l = quality[i][j] + dppath1[i-1][j];
    int r = quality[i][j] + dppath1[i][j+1];
    return l>r?l:r;
}
   



}

int findOptimalPath(int i,int j){

if (i == N-1 && j == M-1)
{
    return quality[i][j];
}else if(i == N-1){
    return quality[i][j] + dppath[i][j+1];

}else if(j == M-1){
    return quality[i][j] + dppath[i+1][j];

}else{
    int l = quality[i][j] + dppath[i+1][j];
    int r = quality[i][j] + dppath[i][j+1];
    return l>r?l:r;
}
   



}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int temp;
    cin >> N;
    cin >> M;
   
  quality = vector<vector<int>>(N, vector<int>(M));
    dppath = vector<vector<int>>(N, vector<int>(M));
  dppath1 = vector<vector<int>>(N, vector<int>(M));


    for (int i = 0; i < N; ++i)
    {
        
        for (int j = 0; j < M; ++j)
        {
            cin >> temp;
            quality[i][j] = temp;
        }
    }

    int sumA, sumB;
    sumA = 0;
    sumB = 0;



    for (int i = N-1; i >= 0; --i)
    {

        for (int j = M-1; j >= 0; --j)
        {
            dppath[i][j] = (findOptimalPath(i,j)); 
        }
    }
  
    sumA = dppath[0][0];
  


    //  for (int i = 0; i < N; ++i)
    // {
    //     for (int j = 0; j < M; ++j)
    //     {
    //          cout << quality[i][j] << " ";
    //     }
    //        cout << endl;
    // }
    // cout << "Array" << endl;
    
    //  for (int i = 0; i < N; ++i)
    // {
    //     for (int j = 0; j < M; ++j)
    //     {
    //          cout << dppath[i][j] << " ";
    //     }
    //        cout << endl;
    // }

    // cout << "NExt Array" << endl;

     for (int i = 0; i < N; ++i)
    {
        for (int j = M-1; j >= 0; --j)
        {
            dppath1[i][j] = findOptimalPathother(i,j); 
        }
    }

    //  for (int i = 0; i < N; ++i)
    // {
    //     for (int j = 0; j < M; ++j)
    //     {
    //          cout << dppath1[i][j] << " ";
    //     }
    //        cout << endl;
    // }

    sumB = dppath1[N-1][0];
    
    cout <<  sumA+sumB << endl;

    return 0;
}
