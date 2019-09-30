#include<bits/stdc++.h>
 using namespace std;
      int cnt = 0;

 void minTransfer(vector<int> heights) {
     // Write your code here
     map<int, int> m;
     int n = heights.size();
     for(int i = 0; i < heights.size(); i++){
         m[heights[i]] = i;
     }
     
     vector<int> cont(n+1, 0);
     int maxc = -1;
     int atn=0;
     int ind=0;
     cont[0] = 0;
     for(int i = 0; i < heights.size(); i++){
        cont[heights[i]] = cont[heights[i]-1]+1;
        if(cont[heights[i]] > maxc){
            maxc = cont[heights[i]];
            atn = heights[i];
            //ind = i;
        }
     }
     int maxr = atn;
     int minr = atn-maxc+1;
     for(int i = 0; i < heights.size(); i++){
         if(heights[i] < minr || heights[i] > maxr){
            cnt++; 
         }
     }
     
 }
 
 //Dont make changes here
 int main(int argc, char** argv) {
     int n;
     cin>>n;
     vector<int> heights;
     for (int i = 0; i < n; i++) {
         int val; cin>>val;
         heights.push_back(val);
     }
     minTransfer(heights);
     cout << cnt;
 }