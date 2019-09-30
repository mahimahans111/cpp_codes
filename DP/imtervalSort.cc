#include<bits/stdc++.h>
using namespace std;

  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

 class myCompare{
     public:
   bool operator()(Interval a, Interval b){
       if(a.start == b.start) return a.end < b.end;
     return a.start < b.start;
   }  
 };

int main(){
	vector<Interval> intervals;
	intervals.push_back(Interval(3, 6));
	intervals.push_back(Interval(1, 2));
	 intervals.push_back(Interval(8, 10));
    int n = intervals.size();
     sort(intervals.begin(), intervals.end(), myCompare());
     vector<Interval> ans;
     for(int i = 0; i < n; i++)cout << intervals[i].start << " " << intervals[i].end << endl;
    //     int min = INT_MAX;
}