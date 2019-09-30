#include <iostream>
 #include <algorithm>
 #include <vector>
 #include <unordered_map>
 
 using namespace std;
 
     // This is a functional problem. Only this function has to be written.
     // This function takes as input the head of the linked list.
     // It should return the head of the modified list.
 
 void customerSolution(vector<int> &arr, int k)
 {
     unordered_map<int, int> m;
     int maxf = 0;
     for(int i = 0; i < arr.size(); i++){
         if(m.count(arr[i])){
             m[arr[i]]++;
             if(m[arr[i]] > maxf) maxf = m[arr[i]];
         }
         else m[arr[i]] = 1;
     }
     if(maxf > 2*k) cout << false;
     else cout << true;
 }
 
 void solve()
 {
     int n;
     cin >> n;
     vector<int> arr(n, 0);
 
     for (int i = 0; i < n; i++)
     {
         cin >> arr[i];
     }
     int k;
     cin >> k;
     
     customerSolution(arr,k);
     cout<<endl;
 }
 
 int main()
 {
     solve();
     return 0;
 }