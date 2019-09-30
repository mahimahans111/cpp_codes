#include <iostream>
 #include <vector>
 #include <string>
 #include <unordered_map>
 #include <unordered_set>
 #include<algorithm>
 #include<cmath>
 
 using namespace std;
 
 // -------------------------------------------
 bool isFrequencyEqual(string &str)
 {
     int n = str.length();
     // write your code here
     unordered_map<int, int>m;
     for(int i = 0; i < str.length(); i++){
         if(m.count(str[i])) m[str[i]]++;
         else m[str[i]] = 1;
     }
     
     int maxf = INT8_MIN;
     int maxc = 0;
    //  int totf = 0;
     for(unordered_map<int, int> :: iterator it = m.begin(); it != m.end(); it++){
        //  totf += it->second;
         if(it->second > maxf){
           maxf = it->second;
           maxc = 1;
         }   
         else if(it->second == maxf){
             maxc++;
         }
     }
     
     if(maxc == 1){
         int cnt = 0;
         for(unordered_map<int, int> :: iterator it = m.begin(); it!=m.end(); it++){
             if(it->second == maxf-1)cnt++;
         }
         if(cnt == m.size()-1) return true;
     }
     if(maxc == m.size()-1){
         int cnt = 0;
         for(unordered_map<int, int> :: iterator it = m.begin(); it!=m.end(); it++){
             if(it->second == 1)cnt++;
         }
         if(cnt == 1) return true;
     }
     if(maxc == m.size()){
         return true;
     }
     return false;
     
 }
 // -------------------------------------------
 
 int main()
 {
     string s;
     cin >> s;
 
     if (isFrequencyEqual(s))
     {
         cout << "true" << endl;
     }
     else
     {
         cout << "false" << endl;
     }
 
     return 0;
 }