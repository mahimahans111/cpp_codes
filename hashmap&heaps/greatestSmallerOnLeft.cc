#include<iostream>
 #include<vector>
 #include<set>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
void greatestSmaller(vector<int> arr) {
     vector<int> ans;
    set<int, greater<int> > s;
    for(int i = 0; i < arr.size(); i++){
       
        if(s.lower_bound(arr[i]) == s.end())
        cout << -1 << " ";
        else cout << *s.lower_bound(arr[i]) << " ";
        
        s.insert(arr[i]);
    }
 }
 
 //Dont make changes here
 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> arr;
     for(int i=0;i<n;i++){
         int val;
         cin>>val;
         arr.push_back(val);
     }
    greatestSmaller(arr);

 }