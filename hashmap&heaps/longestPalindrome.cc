#include<iostream>
 #include<vector>
 #include<string>
 #include<unordered_map>
 using namespace std;
 int longestPalindrome(string &str) {
     unordered_map<char, int> m;
     for(int i = 0; i < str.length(); i++){
         if(m.count(str[i])){
            //  cout << str[i] << " " << m[str[i]] << " ";
             m[str[i]]++; 
         }
         else m[str[i]] = 1;
     }
     
     int ans = 0;
     int flag = 0;
     for(unordered_map<char, int> :: iterator it = m.begin(); it != m.end(); it++){
        //  cout << it->second << " ";
         if((it->second)%2 == 0) ans+=(it->second);
         else{
             if(flag == 0){
                 ans+=(it->second);
                 flag = 1;
             }
             else {
                 ans = ans+(it->second);
                 ans--;
             }
         }
     }
     return ans;
 	 //Write your code here	 	 
 }
 
 int main(int argc,char** argv){
     string s;
     cin>>s;
     cout<<longestPalindrome(s)<<endl;
 }