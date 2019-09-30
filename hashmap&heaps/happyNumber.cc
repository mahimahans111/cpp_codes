#include<iostream>
 #include<string>
 #include<vector>
 #include<unordered_set>
 using namespace std;
 // This is a functional problem. You have to complete this function.
 // It takes as input a number n. It should return true if the number is
 // happy, else should return false.
 int sumSquares(int n){
     int ans = 0;
     while(n){
         ans+=((n%10)*(n%10));
         n = n/10;
     }
     return ans;
 }
 
 bool isHappy(int n) {
     // write your code here.
     unordered_set<int> s;
     int no = n;
    //  cout << no << " ";
     while(true){
         if(s.count(sumSquares(no))) return false;
         else if(sumSquares(no) == 1) return true;
         else s.insert(sumSquares(no));
         no = sumSquares(no);
        //  cout << no << " ";
     }
 }
 
 int main(int argc,char** argv) {
     int N;
     cin>>N;
 
     if (isHappy(N)) {
         cout<<"Happy"<<endl;
     } else {
         cout<<"Not Happy"<<endl;
     }
 }