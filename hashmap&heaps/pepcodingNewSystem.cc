#include<iostream>
 #include<vector>
 #include<string>
 #include<unordered_map>
 using namespace std;
 // --------------------------------------------------------------
 // This is a functional problem. You have to complete this function.
 // It takes as input a string array.
 // It should print "Verified" if the username doesn't exists already, 
 //else should print the username with a number added to the end of the username.
 
 void solve(vector<string> &str) {
    unordered_map<string, int>m;
    for(int i = 0; i < str.size(); i++){
        if(m.count(str[i])){
            m[str[i]]++;
            cout << str[i] << m[str[i]]-1 << endl;
        }
        else{
            m[str[i]] = 1;
            cout << "Verified" << endl;
        }
    }
 }
 
 int main(int argc,char** argv){
     // Length of the array
     int N ;
     cin>>N;
     vector<string> arr(N);
     for (int i = 0; i < N; i++) {
         cin>>arr[i];
     }
     
     solve(arr);
 }