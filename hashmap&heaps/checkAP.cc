#include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include<unordered_set>
 #include<cmath>
 
 using namespace std;
 
 // ------------------------------------------------------
 bool checkAP(vector<int> &arr)
 {
     int n = arr.size();
     unordered_set<double>s;
     int max = INT8_MIN;
     int min = INT8_MAX;
     for(int i = 0; i < n; i++){
         s.insert(arr[i]);
         if(arr[i] > max) max = arr[i];
         if(arr[i] < min) min = arr[i];
     }
     double d = (double)(max-min)/double(n-1);
     
     for(int i = 0; i < n-1; i++){
         if(s.find(double(d*i)+double(min)) == s.end()) return false;
     }
     return true;
     // write your code here
 }
 // ------------------------------------------------------
 
 // Do not change the main Method
 int main()
 {
     int n = 0;
     cin >> n;
     vector<int> num(n, 0);
     for (int i = 0; i < n; i++)
     {
         cin >> num[i];
     }
     if (checkAP(num))
     {
         cout << "true" << endl;
     }
     else
     {
         cout << "false" << endl;
     }
 
     return 0;
 }