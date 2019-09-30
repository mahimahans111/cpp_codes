#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 
 class Logger {
     public:
     unordered_map<string,int> m;
     /**
      * Initialize your data structure here.
      */
     Logger() {
        
     }
 
     /**
      * Returns true if the message should be printed in the given timestamp,
      * otherwise returns false. If this method returns false, the message
      * will not be printed. The timestamp is in seconds granularity.
      */
     bool shouldPrintMessage(int timestamp, string message) {
         //Write your code here
        if(m.count(message)){
            if(timestamp-m[message] >= 10) {
                m[message] = timestamp;
                return true;
            }
            else return  false;
        }
        else{
            m[message] = timestamp;
            return true;
        }
     }
 };
 
 
 int main(int argc,char** argv) {
     Logger lg;
     int n;
     cin>>n;
     vector<int> v(n);
     for (int i = 0; i < n; i++) {
         cin>>v[i];
     }
     vector<string> S(n);
     for (int i = 0; i < n; i++) {
         cin>>S[i];
     }
     for (int i = 0; i < n; i++) {
         lg.shouldPrintMessage(v[i], S[i])?cout << "true" << " " : cout << "false ";
     }
 }