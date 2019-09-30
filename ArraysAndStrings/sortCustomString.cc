#include<iostream>
 #include<vector>
 #include<map>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input two string
 // It should return required output.	  
 
 string customSortString(string& S,string& T) {
     //Write your code here
    map<char, int> m;
    string ans = "";
    
    for(int i = 0; i < T.length(); i++){
        if(m.count(T[i])) m[T[i]]++;
        else m[T[i]] = 1;
    }
    for(int i = 0; i < S.length(); i++){
        if(m.count(S[i])){
            for(int k = 0; k < m[S[i]]; k++){
                ans+=S[i];
            }
            m.erase(S[i]);
        }
    }
    if(m.size()!=0){
        for(map<char, int> :: iterator it = m.begin(); it!=m.end(); it++){
            for(int k = 0; k < it->second; k++){
                ans+=it->first;
            }
        }
    }
    return ans;
 }
 
 //Don't make any changes here.
 int main (int argc,char**argv){
     string S,T;
     cin>>S>>T;   
     string res=customSortString(S,T);
     cout<<res;
     
 
 }