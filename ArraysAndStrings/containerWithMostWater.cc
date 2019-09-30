#include<iostream>
 #include<vector>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input an array of heights
 // It should return required output.	  
 
 int maxArea(vector<int>& arr) {
     //Write your code here
     int n = arr.size();
     int s = 0;
     int e = n-1;
     int maxi = 0;
     int cura = 0;
     while(s < e){
         if(arr[s] <= arr[e]){
             cura = arr[s]*(e-s);
             if(maxi < cura) maxi = cura;
             s++;
         }
         else{
             cura = arr[e]*(e-s);
             if(maxi < cura) maxi = cura;
             e--;
         }
     }
     return maxi;
 }
 //Don't make any changes here.
 int main (int argc,char**argv){
     int n;
     cin>>n;
     vector<int> height(n);
     for (int i = 0; i < height.size(); i++) {
         cin>>height[i];
     }
     cout<<maxArea(height);
 
 }