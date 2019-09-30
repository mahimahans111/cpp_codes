#include<iostream>
 #include<vector>
 using namespace std;
 
 string intToRoman(int num) {
 
    string ans = "";
    vector<pair<int, string> > v;
    v.push_back(pair<int, string>(1, "I"));
    v.push_back(pair<int, string>(4, "IV"));
    v.push_back(pair<int, string>(5, "V"));
    v.push_back(pair<int, string>(9, "IX"));
    v.push_back(pair<int, string>(10, "X"));
    v.push_back(pair<int, string>(50, "L"));
    v.push_back(pair<int, string>(90, "XC"));
    v.push_back(pair<int, string>(100, "C"));
    v.push_back(pair<int, string>(400, "CD"));
    v.push_back(pair<int, string>(500, "D"));
    v.push_back(pair<int, string>(900, "CM"));
    v.push_back(pair<int, string>(1000, "M"));
    
    int n = v.size();
    int k = n-1;
    
    while(num != 0){
        if(num >= v[k].first){
            ans+=v[k].second;
            num = num-v[k].first;
        }
        else k--;
    }
    // cout << ans << " ";
    return ans;
 }
 
 
 //Don't make any changes here	 
 int main(int argc,char** argv ){
 
     int num ;
     cin>>num;
     cout<<intToRoman(num)<<endl;
 
 }