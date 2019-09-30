#include<iostream>
 #include<vector>
 #include<algorithm>
 #include<unordered_map>
 using namespace std;

 bool splitArray(vector<int> & arr) { 
    int n = arr.size(); 
    int ps[n];
    ps[0] = arr[0];
    for(int i = 1; i < n; i++){
        ps[i] = ps[i-1]+arr[i];
    }
    
    unordered_map<int, int> m;
    int ansi, ansj, ansk;
    int prs = 0;
    for(int i = 1; i <= n-6; i++){
        prs = ps[i]-arr[i];
        m[prs] = i;
    }
    
    for(int k = n-2; k >= 5; k--){
        prs = ps[n-1]-ps[k];
        if(m.count(prs)){
            int i = m[prs];
            for(int j = i+2; j <= k-2; j++){
                if((ps[n-1]-ps[k] == ps[k-1]-ps[j]) && (ps[n-1]-ps[k] == ps[j-1]-ps[i]) ){
                    ansi = i;
                    ansj = j;
                    ansk = k;
                    return true;
                }
            }
        }
    }
    return false;
 }
 
 int main(int argc,char** argv){
     int n;
     cin>>n;
     vector<int> nums(n);
     for(int i=0;i<n;i++){
         cin>>nums[i];
     }
     bool res=splitArray(nums);
     if(res==true){
         cout<<"true"<<endl;
     }else{
         cout<<"false"<<endl;
     }
 }