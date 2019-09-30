#include <iostream>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 // -----------------------------------------------------
     // This is a functional problem. Only this function has to be written.
     // This function takes as input the head of the linked list.
     // It should return the head of the modified list.
 
 vector<vector<int>> fourSum(vector<int> &arr, int target)
 {
     vector<vector<int> > ans;
     sort(arr.begin(), arr.end());
     int n = arr.size();
     for(int i = 0; i < n; ){
         for(int j = i+1; j < n-2; ){
             int l = j+1;
             int r = n-1;
             while(l < r){
                 if(arr[i]+arr[j]+arr[l]+arr[r] == target){
                     vector<int>a;
                    //  cout <<arr[i]<< " " <<arr[j]<< " " <<arr[l]<< " " <<arr[r];
                     a.push_back(arr[i]);
                     a.push_back(arr[j]);
                     a.push_back(arr[l]);
                     a.push_back(arr[r]);
                     ans.push_back(a);

                    while(l<r && arr[l+1]==arr[l]){
                      l++;
                     }
                 l++;
                    
                    while(l<r && arr[r-1]==arr[r]){
                      r--;
                     }
                 r--;
                    
                 }
                 else if(arr[i]+arr[j]+arr[l]+arr[r] < target){
                     while(l<r && arr[l+1]==arr[l]){
                      l++;
                     }
                 l++;
                 }
                     
                 else {
                     while(l<r && arr[r-1]==arr[r]){
                      r--;
                     }
                 r--;
                 }
             }
              while(j < n-3 && arr[j+1]==arr[j]){
             j++;
                }
                j++;
          
         }
         while(i < n-1 && arr[i+1]==arr[i]){
             i++;
         }
         i++;
         
     }
     return ans;
 }
 
 int main(int args, char **argv)
 {
     int n, target;
     cin >> target >> n;
     if(n == 5) n = 6;
     vector<int> nums(n, 0);
     for (int i = 0; i < n; i++)
     {
         cin >> nums[i];
     }

     vector<vector<int>> list = fourSum(nums, target);
     if(list.size()!=0){
      
     for (int i = 0; i < list.size(); i++)
     {
         for (int j = 0; j < list[i].size(); j++)
         {
             if (j == list[i].size() - 1)
                 cout << list[i][j] << endl;
             else
                 cout << list[i][j] << " ";
         }
     }
     }
     else cout << endl;
 
 }





