#include<iostream>
 #include<vector>
 using namespace std;
 
 
 int Jump(vector<int> &arr) {
     int n = arr.size();
    if(n == 1)return 0;
    int noOfJumps = 0;
    int prevj = 0;
    int j;
    int nowi;
    for(int i = 0; i < n; i = nowi){
        int max = i+arr[i], maxi = i+arr[i];
        
        if(max >= n-1) return noOfJumps+1;
        nowi = i;
        for(j = 1; j <= arr[i]; j++){
            if(i+j > prevj && i+j+arr[i+j] > max ){
                max = i+j+arr[i+j];
                nowi = i+j;
            }
         }
        if(nowi!=i)noOfJumps++;
        if(max == maxi) return -1;
        prevj = j-1;
        
    }
    return -1;
 }
 
 
 int main(int argc,char**argv){
 
     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }   
 
     int res=Jump(v);
     cout<<res<<endl;
 }