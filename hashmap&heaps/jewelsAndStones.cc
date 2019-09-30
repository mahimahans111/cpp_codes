#include<iostream>
 #include<string>
 #include<unordered_set>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input 2 strings.
 // It should return a integer value.
 int numJewelsInStones(string& J, string& S) {
     unordered_set<char> m;
     int ans = 0;
     for(int i = 0; i < J.length(); i++){
         m.insert(J[i]);
     }
     for(int i = 0; i < S.length(); i++){
         if(m.count(S[i]))ans++;
     }
     //Write your code here
     return ans;
 }
 int main(int argc,char** argv){
     string J,S;
     cin>>J;
     cin>>S;
     int res=numJewelsInStones(J, S);
         cout<<res;
 }