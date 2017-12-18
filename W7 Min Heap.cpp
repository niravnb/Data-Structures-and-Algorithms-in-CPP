#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class myHeap{

public:

    int *heapArray;
    int noOfElements;

    void createHeap(int n){
        this->heapArray = new int[n];
        this->noOfElements = 0;
    }

    void insertKey(int n){
        noOfElements++;
        heapArray[noOfElements-1] = n;
        heapifyUp(noOfElements-1);

    }

void heapifyUp(int i){
        
        if(i>0 && heapArray[i] < heapArray[(int)((i-1)/2)]){
            int j = (int)((i-1)/2);
            int temp = heapArray[i];
            heapArray[i] = heapArray[j];
            heapArray[j] = temp;
            heapifyUp(j);

        }

    }


    void heapifyDown(int i){
        int l,r;
        l = 2*i + 1;
        r = 2*i + 2;        

        int smallest = i;
    if (l < noOfElements && heapArray[l] < heapArray[i])
        smallest = l;
    if (r < noOfElements && heapArray[r] < heapArray[smallest])
        smallest = r;
    if (smallest != i)
    {
            int temp = heapArray[i];
            heapArray[i] = heapArray[smallest];
            heapArray[smallest] = temp;
            heapifyDown(smallest);      

    }

    }

    void extractMin(){

        cout << heapArray[0];   
        
        if (noOfElements == 1)
        {     
            noOfElements--;
            
        }
        else {
           
            heapArray[0] = heapArray[noOfElements-1];
            noOfElements--;
            heapifyDown(0);
        }


    }

    void levelOrder(){

        for (int i = 0; i < noOfElements; ++i)
        {
            cout << heapArray[i] << " ";
        }

    }


};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,temp;
    cin >> N;
    string cmd;
    myHeap h;
    h.createHeap(N);

    while(N--){
    cin >> cmd;
    if (cmd == "INSERT")
    {
        cin >> temp;
        h.insertKey(temp);


    }
    if (cmd == "EXTRACT_MIN")
    {
        h.extractMin();
        cout << endl;

    }
    if (cmd == "LEVEL_ORDER")
    {
        h.levelOrder();
        cout << endl;

    }

}


    return 0;
}
