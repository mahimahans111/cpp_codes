#include<iostream>
  #include<vector>
  #include<algorithm>
#include<bits/stdc++.h>
  using namespace std;
  
  // Function to display an array.
  void display(vector<int> &arr) {
      for (int i = 0; i < arr.size(); i++) {
          cout<<arr[i]<<" ";
      }
      cout<<endl;
  }
  
  // This is a functional problem. You have to complete this function.
  // It takes as input a 2D array
  // It should return the min number of meeting rooms required.
  int minMeetingRooms(vector<vector<int> > &intervals) {
      // write your code here.
      vector<int> s;
      vector<int> e;
      for(int i = 0; i < intervals.size(); i++){
          s.push_back(intervals[i][0]);
          e.push_back(intervals[i][1]);
      }
      sort(s.begin(), s.end());
      sort(e.begin(), e.end());

      int i = 0, j = 0;
      int ans = 0;
      int max = INT_MIN;
      while(i < s.size() && j < e.size()){
          if(s[i] < e[j]){
              ans++; i++;
          }
          else{
              ans--; j++;
          }
          if(ans > max) max = ans;
      }
      return max;
  }
  
  int main(int argc, char** argv){
      int n;
      cin>>n;
      vector<vector<int> > intervals(n, vector<int> (2));
      // Input for intervals.
      for (int i = 0; i < n; i++) {
          cin>>intervals[i][0];
          cin>>intervals[i][1];
      }
      int r = minMeetingRooms(intervals);
      cout<<r;
  }