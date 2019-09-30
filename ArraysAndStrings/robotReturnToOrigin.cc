#include<iostream>
 using namespace std;
 
 //This is a functional problem, complete this function only.
 bool judgeCircle(string &s) {
     int x = 0; int y = 0;
     for(int i = 0; i < s.length(); i++){
         if(s[i] == 'U'){
             y--;
         }
         else if(s[i] == 'D'){
             y++;
         }
         else if(s[i] == 'L'){
             x--;
         }
         else{
             x++;
         }
     }
     // Write code here
     if(x == 0 && y == 0) return true;
     return false;
 }
 
 //Don't make any changes here
 int main(int argc, char** argv){
     string str;
     getline(cin, str);
     if(judgeCircle(str)){
         cout<<"true";
     }else{
         cout<<"false";
     }
 }