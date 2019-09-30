#include<bits/stdc++.h>
using namespace std;

string longestPalindromicSubstring(string s){
    int n = s.length();
    bool dp[n][n] = {};
    
    int x = 0, y = 0;
    for(int i = 0; i < n; i++){
        dp[i][i] = true;
        x = i; y = i;
    }
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(i!=n-1){
           if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                if(flag == 0){ x = i; y = i+1; 
                flag = 1;
                }
          }
          else dp[i][i+1] = false;
        }
    }
    
   for(int gap = 2; gap < n; gap++){
       int flag = 0;
       for(int i = 0, j = i+gap; j < n; i++, j++){
           if(s[i] == s[j] && dp[i+1][j-1] == true){
               dp[i][j] = true;
              if(flag == 0){ x = i; y = j; flag = 1;}
               
           }
           else dp[i][j] = false;
       }
   }
   
   string ans = "";
   for(int i = x; i <= y; i++){
       ans+=s[i];
   }
   if(x == y){
       string ans = "";
       ans+=s[0];
       return ans;
   }
   return ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << longestPalindromicSubstring(s) << endl;
     }
	return 0;
}