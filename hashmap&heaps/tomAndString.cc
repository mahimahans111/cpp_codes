#include<iostream>
 #include<vector>
 #include<unordered_map>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 int getHashValue(string line) {
     char ch = 'a';
     unordered_map<char, int> m;
     for(int i = 0; i < 26; i++){
         m[ch+i] = i;
     }
     int j = 26;
     for(int i = 1; i < 9; i++){
         m['0'+i] = j;
         j++;
     }
     m['0'] = 35;
     ch = 'A';
     j = 36;
     for(int i = 0; i < 26; i++){
         m[ch+i] = j;
         j++;
     }
     
     int i = 0;
     int ans = 0;
     int n = 0;
     while(i < line.length()){
         int cur = 0;
         n++;
         while(line[i]!=' ' && i < line.length()){
             ans+=m[line[i]]+cur;
             cur++;
             i++;
         }
         i++;
     }
     ans=n*ans;
     return ans;
     //write your code here
 }
 
 int main(int argc, char** argv){
     string line;
     getline(cin, line);
     cout<<getHashValue(line);
 
 }