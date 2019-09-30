#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 // This is a functional problem. You have to complete this function.
 // It takes as input a string representing a time.
 // It should return the next closest time.
 
 bool range0(int n){
     if(n==0||n==1||n==2) return true;
     return false;
 }
 
 bool range1(int n){
     if(n== 0||n==1||n==2||n==3) return true;
     return false;
 }

 bool range2(int n){
     if(n>=0 && n<=5) return true;
     return false;
 }
 
 string nextClosestTime(string& t) {
     int n = 4;
     vector<int> time;
     time.push_back(t[0]-'0');
     time.push_back(t[1]-'0');
     time.push_back(t[3]-'0');
     time.push_back(t[4]-'0');
     
     vector<int> ans(4, -1);
     int flag =  0;
     vector<int>time1 = time;
     sort(time1.begin(), time1.end());
     
     
     for(int i = 3; i >= 0; i--){
         int done = 0;
            for(int j = 0; j < time1.size(); j++){
                if(time1[j] > time[i]){
                    if((i == 1 && (time[i-1] == 1 || time[i-1] == 0))|| (i == 1 && time[i-1]==2 && range1(time1[j])) || (i == 3) || (i == 2 && range2(time[j])) || (i == 0 && range0(time[j]))){
                       flag = 1;
                    ans[i] = time1[j];
                    break;  
                    }
                   
                }
                if(flag == 1) break;
            }
            if(flag == 1){
                for(int i = 0; i < n; i++){
                    if(ans[i] == -1)ans[i] = time[i];
                }
                break;
            }
            if(done == 0){
                ans[i] = time1[0];
            }
            // cout << i << " " << ans[i] << endl;
            
         } 
        //  cout <<  ans[3] << " " << ans[2] << endl;
         
         string ansf = "";
         ansf+=ans[0]+'0';
         ansf+=ans[1]+'0';
         ansf+=":";
         ansf+=ans[2]+'0';
         ansf+=ans[3]+'0';
         return ansf;
 }
 
 int main(int argc,char** argv){
     string time;
     cin>>time;
     cout<<nextClosestTime(time)<<endl;
 
 }