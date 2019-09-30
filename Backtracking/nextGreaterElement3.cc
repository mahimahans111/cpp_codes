#include<bits/stdc++.h>
 using namespace std;
 
 int nextGreaterElement(int n) {
 	 //Write your code here
 	 string s = to_string(n);
 	 int j = -1, k;
 	 int flag = 0;
 	 for(int i = s.length()-1; i>=0; i--){
 	     if(i-1 >= 0 && s[i-1] < s[i]){
 	        j = i-1;
 	         for(k = s.length()-1; k > j; k--){
 	             if(s[k] > s[j]){
 	               swap(s[k], s[j]);
 	               flag = 1;
 	               break;
 	             } 
 	         }
 	         if(flag == 1)break;
 	     }
 	 }
 	 if(j == -1){
 	     return -1;
 	 }
 	 else{
 	 int len = s.length();
     string news = "";
     string new1 = "";
     for(int i = 0; i <= j; i++)new1+=s[i];
     for(int k = j+1; k < len; k++){
         news+=s[k];
     }
     sort(news.begin(), news.end());
     s = new1+news;
 	 n = stoi(s);
 	 return n; 
 	 }
 	
 }
 
 int main(int argc, char** argv){
     int n; cin>>n;
     cout<<nextGreaterElement(n);
 }