#include<bits/stdc++.h>
 using namespace std;
 
 //this is a functional problem
 void findIfFake(string s){
     unordered_map<int, int> m;
     for(int i = 0; i < s.length(); i++){
        if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u'){
             if(m.count(s[i])) m[s[i]]++;
             else m[s[i]] = 1;
        }
     }
 
     //write your code here
    
    if(m.size()%2 == 0)  cout << "SHE!";
    else cout << "HE!";
 }
 int main(int argc, char**argv){
     string s;
     getline(cin,s);
     findIfFake(s);
 }