#include<iostream>
 #include<vector>
 using namespace std;
 
 bool isToeplitzMatrix(vector<vector<int> >& matrix) {
 //Write your code here
    int n = matrix.size();
    int m = matrix[0].size();
    
    for(int i = 0; i < n; i++){
        // if(!check(matrix, n, m, i, 0)) return false;
        int j = 0;
        int k = i;
        while(true){
            if(k+1 == n || j+1 == m) break;
            else if(matrix[k][j]!=matrix[k+1][j+1]){
               return false; 
            } 
            k++;
            j++;
        }
    }
    for(int j = 0; j < m; j++){
        // if(!check(matrix, n, m, 0, i)) return false;
        int i = 0;
        int k = j;
        while(true){
            if(k+1 == m || i+1 == n) break;
           else if(matrix[i][k]!=matrix[i+1][k+1]){ 
                return false;
            }
            k++;
            i++;
        }
    }
    return true;
 }
 
 int main(int argc,char** argv) {
     int r ,c;
     cin>>r>>c;
     vector<vector<int>> mat (r,vector<int>(c));
     for (int i = 0; i < r; i++) {
         for (int j = 0; j < c; j++) {
             cin>>mat[i][j];
         }
     }
     bool res=isToeplitzMatrix(mat);
     if(res==true){
         cout<<"true"<<endl;
     }else{
         cout<<"false"<<endl;
     }
 }