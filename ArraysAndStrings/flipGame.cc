#include<iostream>
 #include<vector>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input a string
 // It should return required List
 vector<string> generatePossibleNextMoves(string &s) {
     // Write your code here
     vector<string> ans;
     int n = s.length();
     string str = "";
     for(int i = 0; i < n; i++){
         if(s[i] == '+' && s[i+1] == '+'){
             for(int m = 0; m < n; m++){
                 if(m == i || m==i+1){
                     str+='-';
                 }
                 else str+=s[m];
             }
             ans.push_back(str);
             str = "";
         }
     }
     return ans;
 }
 
 int main(int argc, char** argv){
     string s;
     cin>>s;
 	 vector<string> res = generatePossibleNextMoves(s);
     cout<<"[";
 	 for(int i=0; i<res.size(); i++){
         cout<<res[i];
         if(i != res.size() - 1){
             cout<<", ";
         }
     }
     cout<<"]";
 }