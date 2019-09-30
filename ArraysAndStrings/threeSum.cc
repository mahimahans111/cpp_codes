#include<iostream>
 #include<vector>
 #include<string>
 #include<algorithm>
 #include<unordered_set>
 using namespace std;
  // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input an array
 // It should return an required output
 vector<vector<int> > threeSum(vector<int>& arr) {
         sort(arr.begin(), arr.end());
         vector<vector<int> > ans;
        //  unordered_set<vector<int> > s;
         int n = arr.size();
     for(int i = 0; i < n-2;){
         int s = i+1; int e = n-1;
         while(s < e){
             if(arr[i]+arr[s]+arr[e] == 0){
                 vector<int> v;
                 v.push_back(arr[i]);
                 v.push_back(arr[s]);
                 v.push_back(arr[e]);
                 ans.push_back(v);
                while(arr[s] == arr[s+1])s++;
               s++;
                 while(arr[e] == arr[e-1])e--;
                e--;
             }
             else if(arr[i]+arr[s]+arr[e] < 0){
              while(arr[s] == arr[s+1])s++;
               s++;
             }
             else if(arr[i]+arr[s]+arr[e] > 0){
                while(arr[e] == arr[e-1])e--;
                e--;
             }
         }
         i++;
         while(arr[i] == arr[i-1])i++;
         
     }

     return ans;
     
 }
 
 
 void display(vector<vector<int> >& v){
     cout<<"["; 
     for(int j=0;j<v.size();j++){
         cout<<"[";
         for(int i=0;i<v[j].size();i++){
             cout<<v[j][i];
             if(i!=v[j].size()-1){
                 cout<<", ";
             }
         }
         if(j!=v.size()-1)
             cout<<"], ";
         else
         {
             cout<<"]";
         }
         
     }
     cout<<"]";
 }
 int main(int argc,char** argv){
 
     int n;
     cin>>n;
     vector<int> nums(n);
     for(int i=0;i<n;i++){
         cin>>nums[i];
     }
     vector<vector<int> >res=threeSum(nums);
     display(res);
 
 }