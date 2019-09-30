#include<iostream>
  #include<vector>
  #include<string>
  #include<bits/stdc++.h>
  using namespace std;
 
  int shortestWordDistance(vector<string> &words, string& word1, string & word2){
        int n = words.size();
        int ans=INT_MAX;
        int i1 = -1; int i2 = -1;
        for(int i = 0; i < n; i++){
            if(words[i] == word1){
                i1 = i;
                if(i2 != -1){
                    if(abs(i2-i1) < ans){
                        ans = abs(i2-i1);
                    }
                }
            }
            if(words[i] == word2){
                i2 = i;
                if(i1 != -1){
                    if(abs(i2-i1) < ans){
                        ans = abs(i2-i1);
                    }
                }
            }
        }
        return ans;
  }
      
  int main(int argc,char** argv){
  
      int n;
      cin>>n;
      vector<string> words(n);
      for(int i=0;i<n;i++){
          cin>>words[i];
      }
      string word1,word2;
      cin>>word1>>word2;
      int res= shortestWordDistance(words, word1,word2);
      cout<<res<<endl;
  
  }