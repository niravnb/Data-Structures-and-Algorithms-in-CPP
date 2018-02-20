#include<iostream>

using namespace std;

class point {
        public:
        int x_coord;
        int y_coord;
};
class Rectangle {
        public:
        point lower_left;  // Lower Left point.
        point upper_right; // Upper Right point.
        int area;
        void readRectangle() {
                cin >> lower_left.x_coord;
                cin >> lower_left.y_coord;
                cin >> upper_right.x_coord;
                cin >> upper_right.y_coord;
        }
        void printRectangle() {
                cout << "(" << lower_left.x_coord << ", " << lower_left.y_coord << ")";
                cout << "("<<  upper_right.x_coord << ", " << upper_right.y_coord << ")  ";
        }
        int calculateArea(){
            area = (upper_right.x_coord - lower_left.x_coord + 1)*(upper_right.y_coord - lower_left.y_coord + 1);
            return area;
        }
    
       
    
};
 int main() {
        int N, M, i;
        cin >> N; // number of rectangles.
        Rectangle r[N];
        for (i=0; i< N; i++) {
                // add code to read N input rectangles.
            r[i].readRectangle();
        }

        cin >> M; // number of queries.
        char type;
        for (i=0; i< M; i++) {
                cin >> type;
                if (type == 'I') {
                        int index1, index2;
                        cin >> index1;
                        cin >> index2;
                        // add code to process Intersection query.
                    
                     if  (r[index1-1].upper_right.x_coord >= r[index2-1].lower_left.x_coord ){
                         cout << 1 << endl;
                     } else cout << 0 << endl;
                        
                    
                        continue;
                }
                if (type == 'A') {
                        int index;
                        cin >> index;
                        cout << r[index-1].calculateArea() << endl;
                        continue;
                }
                if (type == 'C') {
                        int index1, index2;
                        cin >> index1;
                        cin >> index2;
                        // add code to process co-ordinates query.
                        
                     if  (r[index1-1].upper_right.x_coord >= r[index2-1].lower_left.x_coord ){
                         int x1,y1,x2,y2;
                         
                         if(r[index1-1].lower_left.x_coord >= r[index2-1].lower_left.x_coord){
                             x1 = r[index1-1].lower_left.x_coord;
                         }else x1 = r[index2-1].lower_left.x_coord;
                         
                          if(r[index1-1].lower_left.y_coord >= r[index2-1].lower_left.y_coord){
                             x2 = r[index1-1].lower_left.y_coord;
                         }else x2 = r[index2-1].lower_left.y_coord;
                         
                          
                         if(r[index1-1].upper_right.x_coord <= r[index2-1].upper_right.x_coord){
                             y1 = r[index1-1].upper_right.x_coord;
                         }else y1 = r[index2-1].upper_right.x_coord;
                         
                         if(r[index1-1].upper_right.y_coord <= r[index2-1].upper_right.y_coord){
                             y2 = r[index1-1].upper_right.y_coord;
                         }else y2 = r[index2-1].upper_right.y_coord;
                         
                         cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
                         
                         
                     } else cout << -1 << " " << -1 << " " << -1 << " " << -1 << endl;
                        
                    
                    
                        continue;
                }
                if (type == 'S') {
                        // add code to process sort-query.
                    int sortArea[N];
                    
                     for (int i=0; i<N; i++) {
                           sortArea[i] = r[i].calculateArea();
                      }
                    
                   
                    
                    int swapped;
                    for(int i=0;i<N;i++){
                        swapped = 0;
                        for(int j = 0;j<N-i-1;j++){
                            if(sortArea[j] < sortArea[j+1]){
                                int temp = sortArea[j];
                                sortArea[j] = sortArea[j+1];
                                sortArea[j+1] = temp;
                                swapped = 1;
                            }
                        }
                        if(swapped == 0){ 
                            break;
                        }
                        
                    }
                    
                    for (int i=0; i< N; i++) {
                         cout << sortArea[i] << endl;
                      }
                        continue;
                }
                if (type == 'P') {
                        int index1, index2, numHops;
                        cin >> index1;
                        cin >> index2;
                     //   cin >> numHops;
                    
                    if(index1 == index2 && index1 < N){
                        cout << 1 << endl;
                    }else{
                    
                    int p1,p2;
                    p1 = 0;
                    p2 = 0;
                    
                         if  (r[index1-1].upper_right.x_coord >= r[index2-1].lower_left.x_coord ){
                         p1 =1;                          
                     }
                    
                    // if  (r[index2-1].upper_right.x_coord >= r[index1-1].lower_left.x_coord ){
                    //     p2 =1;
                    // }
                    
                    int paths[2][2];
                    paths[0][0] = 1;
                    paths[0][1] = p1;
                    paths[1][0] = p1;
                    paths[1][1] = 1;
                    
             

                    int t[2][2];

                            for(int i = 0;i<2;i++){
                                for(int j=0;j<2;j++){
                                  t[i][j] = paths[i][0]*paths[0][j] + paths[i][1]*paths[1][j];                                        
                                }
                            }

                    
              
                    int t1[2][2];

                            for(int i = 0;i<2;i++){
                                for(int j=0;j<2;j++){
                                  t1[i][j] = t[i][0]*paths[0][j] + t[i][1]*paths[1][j];                                        
                                }
                            }
                 
                    
                     
                            
                     cout << paths[0][1] + t[0][1] + t1[0][1] << endl;
                    
                    } 
                        // add code to process path query.
                }
        }
        return 0;
}
