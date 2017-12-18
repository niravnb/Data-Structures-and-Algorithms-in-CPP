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
vector<vector<int> > dppath2;
vector<vector<int> > dppath3;
vector<vector<int> > pathindex;
vector<vector<int> > pathindex1;


int findOptimalPathother(int i,int j){

if (i == 0 && j == M-1)
{
    pathindex1[i][j] = 10*(i) + j;
    return quality[i][j];
}else if(i == 0){

    pathindex1[i][j] = 10*(i) + j+1;
    return quality[i][j] + dppath1[i][j+1];

}else if(j == M-1){
    pathindex1[i][j] = 10*(i-1) + j;
    return quality[i][j] + dppath1[i-1][j];

}else{
    int l = quality[i][j] + dppath1[i-1][j];
    int r = quality[i][j] + dppath1[i][j+1];

    if (l > r)
    {
        pathindex1[i][j] = 10*(i-1) + j;
    }else{
        pathindex1[i][j] = 10*(i) + j+1;
    }
    return l>r?l:r;
}
   



}

int findOptimalPath(int i,int j){

if (i == N-1 && j == M-1)
{
    
    return quality[i][j];
}else if(i == N-1){
    
    
    return quality[i][j] + dppath2[i][j+1];

}else if(j == M-1){
    
    
    return quality[i][j] + dppath2[i+1][j];

}else{
    int l = quality[i][j] + dppath2[i+1][j];
    int r = quality[i][j] + dppath2[i][j+1];



    return l>r?l:r;
}
   



}

int findOptimalPathfromtop(int i,int j){

if (i == 0 && j == 0)
{
    pathindex[i][j] = 10*(i) + j;
    return quality[i][j];
}else if(i == 0){
    pathindex[i][j] = 10*(i) + j-1;
    return quality[i][j] + dppath[i][j-1];

}else if(j == 0){
    pathindex[i][j] = 10*(i-1) + j;
    return quality[i][j] + dppath[i-1][j];

}else{
    int l = quality[i][j] + dppath[i-1][j];
    int r = quality[i][j] + dppath[i][j-1];

    if (l>r)
    {
        pathindex[i][j] = 10*(i-1) + j;
    }else{
        pathindex[i][j] = 10*(i) + j-1;
    }

    return l>r?l:r;
}
   



}


int findOptimalPath1(int i,int j){

if (i == N-1 && j == 0)
{
    return quality[i][j];
}else if(i == N-1){
    return quality[i][j] + dppath3[i][j-1];

}else if(j == 0){
    return quality[i][j] + dppath3[i+1][j];

}else{
    int l = quality[i][j] + dppath3[i+1][j];
    int r = quality[i][j] + dppath3[i][j-1];
    return l>r?l:r;
}
   



}



int findCurrentMax(int n,int m){

    int max = 0;
    int max1, max2;
    max1 = 0;
    max2 = 0;

    if(pathindex[n][m] == pathindex1[n][m] ){

        
        max1 = dppath[n][m] + quality[n][m] + dppath1[n][m+1] + dppath2[n+1][m] + dppath3[n][m-1];
        max2 = dppath[n][m-1] + quality[n][m] + dppath1[n][m] + dppath2[n][m+1] + dppath3[n+1][m];
        max = max1>max2?max1:max2;
         




    }else if(pathindex1[n][m] - pathindex[n][m] == 2){

        if (dppath[n][m] > dppath1[n][m])
        {
            max = dppath[n][m] + quality[n][m] + dppath1[n-1][m] + dppath2[n][m+1] + dppath3[n+1][m];
        }else{
            
            max = dppath[n-1][m] + quality[n][m] + dppath1[n][m] + dppath2[n+1][m] + dppath3[n][m-1];
        }

    }

        else{
          max = dppath[n][m] + dppath1[n][m]; // + dppath[n-1][m] +  dppath3[n][m-1];

          if (pathindex1[n][m] == 10*n + m+1)
          {
              max += dppath2[n+1][m];
          }else{
            max += dppath2[n][m+1];
          }

          if (pathindex[n][m] == 10*n + m-1)
          {
              max += dppath3[n+1][m];
          }else{
            max += dppath3[n][m-1];
          }


    }

      


    return max;



}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int temp;
    cin >> N;
    cin >> M;
   
  quality = vector<vector<int>>(N, vector<int>(M));
  dppath = vector<vector<int>>(N, vector<int>(M));
  dppath1 = vector<vector<int>>(N, vector<int>(M));
  dppath2 = vector<vector<int>>(N, vector<int>(M));
  dppath3 = vector<vector<int>>(N, vector<int>(M));
  pathindex = vector<vector<int>>(N, vector<int>(M));
  pathindex1 = vector<vector<int>>(N, vector<int>(M));



    for (int i = 0; i < N; ++i)
    {
        
        for (int j = 0; j < M; ++j)
        {
            cin >> temp;
            quality[i][j] = temp;
        }
    }




    for (int i = 0; i < N; ++i)
    {
        
        for (int j = 0; j < M; ++j)
        {
            dppath[i][j] = (findOptimalPathfromtop(i,j)); 
        }
    }
  

        for (int i = N-1; i >= 0; --i)
    {
        
        for (int j = M-1; j >= 0; --j)
        {
            dppath2[i][j] = (findOptimalPath(i,j)); 
        }
    }
  
  

    
  
   cout << "from top to nm dppath" << endl;
    
     for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
             cout << dppath[i][j] << " ";
        }
           cout << endl;
    }



     for (int i = 0; i < N; ++i)
    {
        for (int j = M-1; j >= 0; --j)
        {
            dppath1[i][j] = findOptimalPathother(i,j); 
        }
    }

        cout << "from top to no dppath1" << endl;

     for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
             cout << dppath1[i][j] << " ";
        }
           cout << endl;
    }

  cout << "from bottom to 00 dppath2" << endl;
     for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
             cout << dppath2[i][j] << " ";
        }
           cout << endl;
    }

       for (int i = N-1; i >= 0; --i)
    {
        for (int j = 0; j < M; ++j)
        {
            dppath3[i][j] = findOptimalPath1(i,j); 
        }
    }


     cout << "from bottom to OM dppath3" << endl;

     for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
             cout << dppath3[i][j] << " ";
        }
           cout << endl;
    }

     cout << "path Index of dpath" << endl;

     for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
             cout << pathindex[i][j] << " ";
        }
           cout << endl;
    }

     cout << "path Index of dpath1" << endl;

     for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
             cout << pathindex1[i][j] << " ";
        }
           cout << endl;
    }




    int currentMax, totalMax;
    currentMax = 0;
    totalMax = 0;
   
     for (int i = 1; i < N-1; ++i)
    {
        for (int j = 1; j < M-1; ++j)
        {

            currentMax = findCurrentMax(i,j);

            cout << "Index i = " << i << " j = " << j << " max = " << currentMax << endl;
            if (totalMax < currentMax)
            {
                totalMax = currentMax;
            }
        }

    }






    
    cout <<  totalMax << endl;

    return 0;
}
