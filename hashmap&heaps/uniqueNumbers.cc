#include<iostream>
#include<unordered_set>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input two numbers as range
 // It should print required output
 
bool isUnique(int no){
    unordered_set<int> s;
    while(no){
        if(s.count(no%10)) return false;
        s.insert(no%10);
        no = no/10;
    }
    return true;
} 
 
 void numbers(int l, int r) {
     // Write your code here
     for(int i = l; i <= r; i++){
         if(isUnique(i)) cout << i << " ";
     }
 }
 
 int main(int argc, char** argv){
     int l, r;
     cin>>l>>r;
     numbers(l, r);
 }