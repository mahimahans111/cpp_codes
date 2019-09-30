#include<iostream>
 #include<vector>
 #include<string>
 using namespace std;
 vector<int> plusOne(vector<int>& digits) {
 //Write your code here	
 vector<int> ans;
    int n = digits.size();
    int carry = 0;
    int k = digits[n-1]+carry+1;
    
    carry = k/10;
    digits[n-1] = k%10;
    for(int i = n-2; i >= 0; i--){
        int k = digits[i]+carry;
        digits[i] = (k)%10;
        carry = k/10;
    }
    if(carry){
        ans.push_back(carry);
    }
    for(int i = 0; i < digits.size(); i++){
        ans.push_back(digits[i]);
    }
    return ans;
 }
 
 //Don't make any changes here.
 int main(int argc,char** argv){
     int n;
     cin>>n;
     vector<int> Input(n);
     for(int i=0;i<n;i++){
         cin>>Input[i];
     }
     vector<int> ans = plusOne(Input);
     for (int i : ans) {
         cout<<i<<" ";
     }
 
 }