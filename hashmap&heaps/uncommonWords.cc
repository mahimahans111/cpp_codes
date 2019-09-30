#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 vector<string> uncommonFromSentences(string A, string B) {
 	 //Write your code here	 
 	 vector<string> ans;
 	 unordered_map<string, int> m;
 	 int i = 0;
 	 while(A[i]!='\0'){
 	     string one = "";
 	     while(A[i]!=' ' && A[i]!='\0'){
 	         one+=A[i];
 	         i++;
 	     }
 	     if(m.count(one))m[one]++;
 	     else m[one] = 1;
 	     if(A[i]!='\0')i++;

 	 }
 	 int j = 0;
 	 while(B[j]!='\0'){
 	     string one = "";
 	     while(B[j]!=' ' && B[j]!='\0'){
 	         one+=B[j];
 	         j++;
 	     }
 	     // cout << one << endl;
 	     if(m.count(one))m[one]++;
 	     else m[one] = 1;
 	     if(B[j]!='\0')j++;
 	 }
 	 
 	 for(unordered_map<string, int> :: iterator it = m.begin(); it!=m.end(); it++){
 	     if(it->second == 1)ans.push_back(it->first);
 	 }
 	 // ans.push_back("abcd");
 	 return ans;
 }
 
 //Don't make any changes here
 int main(int argc, char** argv){
     string A, B;
     getline(cin, A);
     getline(cin, B);
 	 // cout << A << endl << B << endl;
     vector<string> ans= uncommonFromSentences(A, B);
     sort(ans.begin(), ans.end());
     for(int i=0; i<ans.size(); i++){
         cout<<ans[i] << " ";
     }
 }