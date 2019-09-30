#include <iostream>
 #include <vector>
 #include <string>
 #include <unordered_map>
 #include <unordered_set>
 
 using namespace std;
 
 // --------------------------------------------------------
 bool isTwoArrayEqual(vector<long> &num1, vector<long> &num2)
 {
     // write your code here
     unordered_map<long, long> m;
     for(int i = 0; i < num1.size(); i++){
         if(m.count(num1[i])) m[num1[i]]++;
         else m[num1[i]] = 1;
     }
     
     for(int i = 0; i < num2.size(); i++){
         if(!m.count(num2[i])) {
            //  cout << num2[i] << " ";
             return false;
         }
         else{
             m[num2[i]]--;
             if(m[num2[i]] == 0) m.erase(num2[i]);
         }
     }
     if(m.size() == 0) return true;
     return false;
 }
 // --------------------------------------------------------
 
 int main()
 {
     int n = 0;
     cin >> n;
     vector<long> num(n, 0);
     for (int i = 0; i < n; i++)
     {
         cin >> num[i];
     }
 
     int m = 0;
     //cin >> m;
     vector<long> arr(n, 0);
     for (int i = 0; i < n; i++)
     {
         cin >> arr[i];
     }
 
     if (isTwoArrayEqual(num, arr))
     {
         cout << "true" << endl;
     }
     else
     {
         cout << "false" << endl;
     }
     return 0;
 }