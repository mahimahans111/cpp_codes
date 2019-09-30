#include<iostream>
 #include<vector>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input two strings
 // It should return required output.	  
 
 int compareVersion(string &version1, string & version2) {
     //Write your code here
     int i=0,j=0;
     while(i<version1.size()||j<version2.size()){
         string s1="",s2="";
         int n1,n2;
         while(i<version1.size()&&version1[i]!='.'){
             s1=s1+version1[i];
             i++;
         }
         while(j<version2.size()&&version2[j]!='.'){
             s2=s2+version2[j];
             j++;
         }
         
         if(s1==""){
             n1=0;
         }
         else{
             n1=stoi(s1);
         }
         if(s2==""){
             n2=0;
         }
         
         else{
             n2=stoi(s2);
         }
         
         if(n1>n2){
             return 1;
         }
         else if(n1<n2){
             return -1;
         }
         i++;
         j++;
     }
     return 0;
 }
  
 //Don't make any changes here.
 int main (int argc,char**argv){
     string version1,version2;
     cin>>version1>>version2;
     cout<<compareVersion(version1,version2);
 
 }