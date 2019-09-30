 #include<bits/stdc++.h>
using namespace std;

 vector<vector<int> > getSkyline(vector<vector<int> >& v) {
    int n = v.size();
     int arr[10000] = {};
     int maxb = 0;
     for(int i = 0; i < n; i++){
        // cin >> a >> b >> c;
         int a = v[i][0];
         int b = v[i][1];
         int c = v[i][2];
        for(int j = a; j <= b; j++){
            arr[j] = max(arr[j], c);
        }
        maxb = max(maxb, b);
     }
     
         vector<vector<int> > ans;
     if(arr[0] > 0){
         vector<int>a;
         a.push_back(0);
         a.push_back(arr[0]);
         ans.push_back(a);
     }
     for(int i = 1; i <= maxb+1; i++){
         if(arr[i-1]!=0 && arr[i] == 0){
             vector<int>a;
           a.push_back(i-1);
           a.push_back(0);
           ans.push_back(a);
         } 
         else if(arr[i-1]< arr[i]){
             vector<int>a;
         a.push_back(i);
         a.push_back(arr[i]);
         ans.push_back(a);
         }
         else if(arr[i-1] > arr[i]){
              vector<int>a;
         a.push_back(i-1);
         a.push_back(arr[i]);
         ans.push_back(a);
         }
        
     }
         return ans;
     }

         int main(){
            return 0;
         }