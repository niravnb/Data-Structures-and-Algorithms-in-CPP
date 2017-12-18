#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void swapRows(int row1, int row2, int array[][3]){
    
    for (int i = 0; i < 3; ++i)
    {
        int temp = array[row1][i];
        array[row1][i] = array[row2][i];
        array[row2][i] = temp;
    }
    
}

double calcualateEuclideanDistance(int row1,int row2,int array[][3]){
    
    double euclideanDistance;
    double a,b,c,total;
    
    a = pow((array[row1][0] - array[row2][0]),2);
    b = pow((array[row1][1] - array[row2][1]),2);
    c = pow((array[row1][2] - array[row2][2]),2);
    
    total = a+b+c;
    
    
    euclideanDistance = sqrt(total);
    return euclideanDistance;
}


void sortOnIndex(int n,int col,int  array[][3], int sortedIndex[3]){
    
    int firstIndex = (col+1)%3;
    int secondIndex = (col+2)%3;
    
    int firstIndexValue = sortedIndex[firstIndex];
    int secondIndexValue = sortedIndex[secondIndex];
    
    
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = array[i][col];
        j = i-1;
        while (j >= 0 && array[j][col] > key)
        {
            
            int internalswap = 0;
            
            if (firstIndexValue == 1)
            {
                if ((array[j][firstIndex] == array[j+1][firstIndex]) && internalswap == 0 )
                {
                    
                    if (secondIndexValue == 1)
                    {
                        if ((array[j][secondIndex] == array[j+1][secondIndex]) && internalswap == 0 )
                        {
                            swapRows(j,j+1,array);
                            
                            internalswap = 1;
                        } else {
                            // swapRows(i,j+1,array);
                            //    j = j-1;
                            //   break;
                        }
                    }else {
                        swapRows(j,j+1,array);
                        
                        internalswap = 1;
                    }
                } else internalswap = 1;
            }
            else if (secondIndexValue == 1)
            {
                if ((array[j][secondIndex] == array[j+1][secondIndex]) && internalswap == 0 )
                {
                    
                    if (firstIndexValue == 1)
                    {
                        if ((array[j][firstIndex] == array[j+1][firstIndex]) && internalswap == 0 )
                        {
                            swapRows(j,j+1,array);
                            
                            internalswap = 1;
                        } else {
                            // swapRows(i,j+1,array);
                            // j = j-1;
                            //   break;
                        }
                    }else {
                        swapRows(j,j+1,array);
                        
                        internalswap = 1;
                    }
                } else internalswap = 1;
            }
            
            
            
            
            
            if (internalswap == 0)
            {
                swapRows(j,j+1,array);
                
            }
            j = j-1;
            
            
            
            // array[j+1][col] = array[i][col]
            
            
            
        }
        
        
        
        // array[j+1][col] = key;
    }
    
}

void sortOnIndexBubble(int n,int col,int  array[][3], int sortedIndex[3]){
    
    int firstIndex = (col+1)%3;
    int secondIndex = (col+2)%3;
    
    int firstIndexValue = sortedIndex[firstIndex];
    int secondIndexValue = sortedIndex[secondIndex];
    
    
    for (int i = 0; i < n; ++i)
    {
        int swapped = 0;
        
        for (int j = 0; j < n-i-1; ++j)
        {
            
            if (array[j][col] > array[j+1][col])
            {
                
                int internalswap = 0;
                
                if (firstIndexValue == 1)
                {
                    if ((array[j][firstIndex] == array[j+1][firstIndex]) && internalswap == 0 )
                    {
                        
                        if (secondIndexValue == 1)
                        {
                            if ((array[j][secondIndex] == array[j+1][secondIndex]) && internalswap == 0 )
                            {
                                swapRows(j,j+1,array);
                                swapped = 1;
                                internalswap = 1;
                            } else internalswap = 1;
                        }else {
                            swapRows(j,j+1,array);
                            swapped = 1;
                            internalswap = 1;
                        }
                    } else internalswap = 1;
                }
                else if (secondIndexValue == 1)
                {
                    if ((array[j][secondIndex] == array[j+1][secondIndex]) && internalswap == 0 )
                    {
                        
                        if (firstIndexValue == 1)
                        {
                            if ((array[j][firstIndex] == array[j+1][firstIndex]) && internalswap == 0 )
                            {
                                swapRows(j,j+1,array);
                                swapped = 1;
                                internalswap = 1;
                            } else internalswap = 1;
                        }else {
                            swapRows(j,j+1,array);
                            swapped = 1;
                            internalswap = 1;
                        }
                    } else internalswap = 1;
                }
                
                
                
                if (internalswap == 0)
                {
                    swapRows(j,j+1,array);
                    swapped = 1;
                }
            }
            
            
            
            
        }
        
        if (swapped == 0)
        {
            break;
        }
    }
}




void sort(int  array[][3]){
    
    
    if (array[0][0] > array[1][0]) {
        swapRows(0,1,array);
    }else if (array[0][0] == array[1][0]){
        if (array[0][1] > array[1][1]) {
            swapRows(0,1,array);
        }else if (array[0][1] == array[1][1]){
            if (array[0][2] > array[1][2]) {
                swapRows(0,1,array);
            }
        }

    }
}







int main() {
    
    int N;
    cin >> N;
    
    int coordinateMatrix[N][3];
    int referencePoint[3] = {1,2,3};
    int sortedIndex[3] = {0,0,0};
    int comb = (N*(N-1))/2;
    double arreuclideanDistance[comb];
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j)
        {
            cin >> coordinateMatrix[i][j];
        }
        
    }
    
    int combindex = 0;
    for (int i = 0; i < N; ++i) {
        
        for (int j=i+1; j < N; j++) {
            arreuclideanDistance[combindex] = calcualateEuclideanDistance(i,j,coordinateMatrix);
            combindex++;
        }
        
        
    }
    
    
    // if(N > 100){
    // if (!(referencePoint[0] == 0 && referencePoint[1] == 0 && referencePoint[2] == 0))
    // {
    //   for (int j = 0; j < 3; ++j) {
    //      if (referencePoint[j] == 1){
    //          sortOnIndex(N,j,coordinateMatrix,sortedIndex);
    //          sortedIndex[j] = 1;
    //          break;
    
    //      }
    //  }
    
    //  for (int j = 0; j < 3; ++j) {
    //      if (referencePoint[j] == 2){
    //          sortOnIndex(N,j,coordinateMatrix,sortedIndex);
    //          sortedIndex[j] = 1;
    //          break;
    //      }
    //  }
    
    //  for (int j = 0; j < 3; ++j) {
    //      if (referencePoint[j] == 3){
    //          sortOnIndex(N,j,coordinateMatrix,sortedIndex);
    //          sortedIndex[j] = 1;
    //          break;
    //      }
    //  }           
    // }
    
    // }else{
    
    //     if (!(referencePoint[0] == 0 && referencePoint[1] == 0 && referencePoint[2] == 0))
    // {
    //   for (int j = 0; j < 3; ++j) {
    //      if (referencePoint[j] == 1){
    //          sortOnIndexBubble(N,j,coordinateMatrix,sortedIndex);
    //          sortedIndex[j] = 1;
    //          break;
    
    //      }
    //  }
    
    //  for (int j = 0; j < 3; ++j) {
    //      if (referencePoint[j] == 2){
    //          sortOnIndexBubble(N,j,coordinateMatrix,sortedIndex);
    //          sortedIndex[j] = 1;
    //          break;
    //      }
    //  }
    
    //  for (int j = 0; j < 3; ++j) {
    //      if (referencePoint[j] == 3){
    //          sortOnIndexBubble(N,j,coordinateMatrix,sortedIndex);
    //          sortedIndex[j] = 1;
    //          break;
    //      }
    //  }           
    // }
    
    
    // }
    
    
    // cout << "matrix";
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = 0; j < 3; ++j)
//        {
//            cout << coordinateMatrix[i][j] << " ";
//        }
//        cout << endl;
//    }     
    
    float min = arreuclideanDistance[0];
    int minindex = 0;
    for (int i = 1; i < combindex; ++i)
    {
        //cout << arreuclideanDistance[i] << " ";
       // printf("%.2f \n",arreuclideanDistance[i]);
        if (arreuclideanDistance[i] < min) {
            min = arreuclideanDistance[i];
            minindex = i;
        }
    }
    
    
    printf("%.2f \n",min);
  //  cout << minindex << " ";

    
    
    int row1 = 0, row2 = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        
        for (int j=i+1; j < N; j++) {
            
            if (count == minindex) {
                row1 = i;
                row2 = j;
                break;
            }
            count++;
        }
        
        if (count == minindex) {
            break;
        }
        
    }

    int toSortMatrix[2][3];
    
    for (int i = 0; i<3; i++) {
        toSortMatrix[0][i] =  coordinateMatrix[row1][i];
        toSortMatrix[1][i] =  coordinateMatrix[row2][i];
    }
    
    
   // for (int i = 0; i<2; i++) {
        sort(toSortMatrix);

    //}
    
    
    
    
    for (int i = 0; i < 2; ++i)
        {
                for (int j = 0; j < 3; ++j)
                {
                    cout << toSortMatrix[i][j] << endl;
                }
            
            }
    
    
  

  
    
    return 0;
}
