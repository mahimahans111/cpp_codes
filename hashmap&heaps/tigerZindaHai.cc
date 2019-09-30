#include<iostream>
 #include<vector>
 #include<unordered_set>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 int open_closeTabs(vector<string> T) {
     //Write your code here
     unordered_set<string> s;
     for(int i = 0; i < T.size(); i++){
         if(T[i] == "END"){
             s.clear();
         }
         else if(s.count(T[i])){
             s.erase(T[i]);
         }
         else s.insert(T[i]);
     }
     return s.size();
 }
 
 //Dont make changes here
 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<string> T;
     for (int i = 0; i < n; i++) {
         string s;
         cin>>s;
         T.push_back(s);
     }
     cout<<open_closeTabs(T);
 }