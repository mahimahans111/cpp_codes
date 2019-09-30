
#include<iostream>
 #include<vector>
 #include<string>
 #include<unordered_map>
 #include<algorithm>
 using namespace std;
 
 void print(vector<int>& num1,vector<int> &num2 ,int k){
 	 //write your code here
 	 unordered_map<int, int> m;
 	 for(int i = 0; i < num2.size(); i++){
 	     if(m.count(num2[i]))m[num2[i]]++;
 	     else m[num2[i]] = 1;
 	 }
 	 
 	 int flag =  0;
 	 vector<pair<int, int> > ans;
 	 sort(num1.begin(), num1.end());
 	 for(int i = 0; i < num1.size(); i++){
 	     if(m.count(k-num1[i])){
 	        m[k-num1[i]]--;
 	        if(m[k-num1[i]] == 0) m.erase(k-num1[i]);
 	        
 	        if(flag == 0) {
 	         cout << num1[i] << " " << k-num1[i];
 	         flag = 1;
 	         }
 	         else{
 	         cout << ", " << num1[i] << " " << k-num1[i];
 	     }
 	     }
 	 }
 }
 
 int main(int argc,char ** argv){
 
     int n;
     cin>>n;
     int m;
     cin>>m;
     int k;
     cin>>k;
     vector<int> num1;
     vector<int> num2;
     for(int i=0;i<n;i++){
         int a;
         cin>>a;
         num1.push_back(a);
     }
     for(int i=0;i<m;i++){
         int a;
         cin>>a;
         num2.push_back(a);
     }
 
     print(num1, num2, k);
     cout<<endl;
 
 }