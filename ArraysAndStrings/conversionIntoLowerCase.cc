#include<iostream>
 #include<vector>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input one string
 // It should return required output
 string toLowerCase(string &a) {
 //Write your code here
    for(int i = 0; i < a.length(); i++){
        if(a[i] >= 65 && a[i] <= 90){
            a[i] = a[i]+32;
        }
    }
    return a;
 }
 
 
 int main(int argc,char** argv){
     string a;
     cin>>a;
     cout<<toLowerCase(a)<<endl;
 }