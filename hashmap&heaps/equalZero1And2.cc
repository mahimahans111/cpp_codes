#include<iostream>
 #include<bits/stdc++.h> 
 using namespace std; 
   
   int fact(int n){
       if(n == 0 || n == 1) return 1;
       return n*fact(n-1);
   }
   
 // Method to count number of substring which 
 // has equal 0, 1 and 2 
 //write your code here
 int getSubstringWithEqual012(string str) 
 { 
   int n0 = 0, n1 = 0, n2 = 0;
   map<pair<int, int>, int> m;
   m[pair<int, int>(0, 0)] =1;
   for(int i = 0; i < str.length(); i++){
       if(str[i] == '0'){
           n0++;
           int var1 = int(n1)-int(n0);
           int var2 = int(n2)-int(n0);
           if(m.count(pair<int, int>(var1, var2))) m[pair<int, int>(var1, var2)]++;
           else m[pair<int, int>(var1, var2) ]= 1;
       }
       else if(str[i] == '1'){
            n1++;
           int var1 = int(n1)-int(n0);
           int var2 = int(n2)-int(n0);
           if(m.count(pair<int, int>(var1, var2))) m[pair<int, int>(var1, var2)]++;
           else m[pair<int, int>(var1, var2) ]= 1;
       } 
       else{
          n2++;
          int var1 = int(n1-'0')-int(n0-'0');
           int var2 = int(n2-'0')-int(n0-'0');
           if(m.count(pair<int, int>(var1, var2))) m[pair<int, int>(var1, var2)]++;
           else m[pair<int, int>(var1, var2) ]= 1;
       }
       
   }
   
   int ans = 0;
   for(map<pair<int, int>, int>:: iterator it = m.begin(); it!=m.end(); it++){
    // cout << it->first.first << " " << it->first.second << " " << it->second <<endl;
       if(it->second >= 2){
           int n = it->second;
           ans+=(fact(n)/(fact(n-2)*fact(2)));
           // cout << ans << endl;
       }
   }
   return ans;
 } 
   
 int main(int argc, char** argv) 
 { 
     string str;
     cin>>str; 
     cout << getSubstringWithEqual012(str) << endl; 
     return 0; 
 }