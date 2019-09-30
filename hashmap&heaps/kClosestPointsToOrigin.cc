#include<iostream>
 #include<string>
 #include<vector>
 #include<queue>
 using namespace std;
 
 class myComparator{
     public:
   bool operator()(pair<int, int> a, pair<int, int> b){
       return (a.first*a.first + a.second*a.second)>(b.first*b.first + b.second*b.second);
   }  
 };
 
 // -----------------------------------------------------
 // This is a functional problem. Do not change main
 // This function takes as input a 2d array and k value
 // It should return required output as 2d array
 vector<vector<int> > kClosest(vector<vector<int> >& points, int K) {
     //Write your code here
     vector<vector<int> > ans;
     priority_queue<pair<int, int>, vector<pair<int, int> >, myComparator >pq;
     for(int i = 0; i < points.size(); i++){
         // cout << points[i][0] << " " << points[i][1] << ".....";
         pq.push(pair<int, int> (points[i][0], points[i][1]));
     }
     for(int i = 0; i < K; i++){
         vector<int> ans1;
        //  cout << pq.top().first << " " << pq.top().second << ";;;;;;";
         ans1.push_back(pq.top().first);
         ans1.push_back(pq.top().second);
         ans.push_back(ans1);
         pq.pop();
     }
     return ans;
 }
 int main(int argc,char** argv){
     int row;
     cin>>row;
     vector<vector<int> > points(row,vector<int> (2));
     for(int i=0;i<row;i++){
         for(int j=0;j<2;j++){
             cin>>points[i][j];
         }
     }
     int k;
     cin>>k;
     vector<vector<int> > res=kClosest(points,k);
     for(int i=0;i<res.size();i++){
         for(int j=0;j<2;j++)
             cout<<res[i][j]<<" ";
         cout<<endl;
     }
 }