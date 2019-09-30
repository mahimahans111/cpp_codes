#include<iostream>
 #include<vector>
 #include<string>
 using namespace std;
 // This is a functional problem. You have to complete this function.
 // It takes as input a heights array, v and k.
 // You have to return the resultant heights array.
 vector<int> pourWater(vector<int>& heights, int v, int k) {
     int n = heights.size();
        for(int i = 1; i <= v; i++){
         int j = k;
         while(j-1 >= 0 && heights[j-1] <= heights[j]){
             j--;
         }
         if(j == 0 && heights[j+1] > heights[j]) {
             heights[0]+=1;
             continue;
         }
         else if(j!=0 && heights[j+1] > heights[j] && heights[j-1] > heights[j]){
             heights[j]+=1;
             continue;
         }
         else{
            
             while(j+1< n && heights[j+1]<=heights[j])j++;
             if(j == n-1 && heights[j-1] > heights[j]){
                 heights[j]+=1;
                 continue;
             }
             else if(j!=n-1 && heights[j+1] > heights[j] && heights[j-1] > heights[j]){
                 heights[j]+=1;
                 continue;
             }
             else if(heights[j] == heights[j-1]){
                 int m = j;
                 while(m > k && heights[m-1] == heights[m]){
                      m--;
                 }
                 heights[m]+=1;
             }
         }
     }
     return heights;
 }
 
 // function to display an array.
 void display(vector<int> & arr) {
    
     for (int i = 0; i < arr.size(); i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }
 
 int main(int argc ,char** argv){
     
     // Input for length of first array.
     int N;
     cin>>N;
 
     vector<int> arr1(N);
 
     // Input for array1 elements.
     for (int i = 0; i < N; i++) {
         cin>>arr1[i];
     }
 
     int V;
     cin>>V;
     int K ;
     cin>>K;
 
     vector<int> res;
     res= pourWater(arr1, V, K);
     display(res);
 
 }