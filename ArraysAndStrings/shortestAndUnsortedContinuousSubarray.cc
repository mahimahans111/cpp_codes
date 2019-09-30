#include<iostream>
 #include<vector>
 using namespace std;
 
 void display(vector<int> &arr) {
     for (int i = 0; i < arr.size(); i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }
 
 int findUnsortedSubarray(vector<int> &a) {
     int n = a.size();
     int minr[n];
     int maxl[n];
     
     minr[n-1] = a[n-1];
     for(int i = n-2; i >= 0; i--){
         minr[i] = min(minr[i+1], a[i]);
     }
     maxl[0] = a[0];
     for(int i = 1; i < n; i++){
         maxl[i] = max(maxl[i-1], a[i]);
     }
     
     int mini = -1, maxi = -1;
     for(int i = 0; i < n; i++){
         if(maxl[i] != minr[i] && mini == -1){
             mini = i;
         }
         if(i!= 0 && minr[i] == maxl[i] && minr[i-1]!=maxl[i-1]){
             maxi = i-1;
         }
     }
     if(maxl[n-1] != minr[n-1])maxi = n-1;
    if(maxi == -1 && mini == -1) return 0;
    cout << mini << " " << maxi << endl;
     return (maxi-mini+1);
 }
 
 int main(int argc, char** argv){
     int length;
     cin>>length;
     vector<int> arr(length);
 
     for (int i = 0; i < arr.size(); i++) {
         cin>>arr[i];
     }
 
     cout<<findUnsortedSubarray(arr);
 
 }