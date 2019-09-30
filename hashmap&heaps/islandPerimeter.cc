#include<iostream>
 #include<string>
 #include<vector>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input a matrix.
 // It should return perimeter value.
 int islandPerimeter(vector<vector<int> >& v)
 {
     //Write your code here
     int noOf1 = 0;
     int ans = 0;
     for(int i = 0; i < v.size(); i++){
         for(int j = 0; j < v[i].size(); j++){
             if(v[i][j] == 1){noOf1++;
             if(i!=v.size()-1 && v[i+1][j]==1)ans-=2;
             if(j!=v[i].size()-1 && v[i][j+1] == 1) ans-=2;}
         }
     }
     ans+=(4*noOf1);
     return ans;
 }
 int main(int argc, char** argv){
     int row,col;
     cin>>row>>col;
     vector<vector<int> > v (row, vector<int>(col));
     for(int i=0;i<row;i++){
         for(int j=0;j<col;j++)
             cin>>v[i][j];
     }
 
     cout<<islandPerimeter(v);
 }