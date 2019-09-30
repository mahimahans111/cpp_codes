#include<iostream>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input a string
 // It should return required output.
 int minFlipsMonoIncr(string &S) {
     // Write your code here
     int a, b, c;
     if(S[0] == '0'){
         a = 0; b = 0; c = 1;
     }
     else{
         a = 1; b = 1; c = 0;
     }

     for(int i = 1; i < S.length(); i++){
         if(S[i] == '0'){
             b = min(a, b)+1;
             c = c+1;
         }
         else{
             b = min(a, b);
             a = a+1;
         }
        
     }
     return min(a, min(b, c));
 }
 
 int main(int argc, char** argv){
     string s;
     cin>>s;
 	 cout<<minFlipsMonoIncr(s);
 }