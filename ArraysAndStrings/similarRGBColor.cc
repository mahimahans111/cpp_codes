#include<iostream>
 #include<vector>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input one string
 // It should return required output
 
 int toDecimal(string a){
     int ind[6] = {10, 11, 12, 13, 14, 15};
     int ans = 0;
     if(a[1] >= '0' && a[1] <= '9'){
         ans+=(a[1]-'0');
     }
     else{
         ans+=(ind[a[1]-'a']);
     }
    if(a[0] >= '0' && a[0] <= '9'){
         ans+=16*(a[0]-'0');
     }
     else{
         ans+=16*(ind[a[0]-'a']);
     }
     return ans;
 }
 
 int diff(string str1, string str2){
     int a = toDecimal(str1);
     int b = toDecimal(str2);
     return a-b;
 }
 
 string similarRGB(string &color) {
    string ans = "#";
    for(int i = 1; i < color.length(); i+=2){
        string str = "";
        str+=color[i];
        str+=color[i+1];
        if(color[i] == color[i+1]){
            ans+=color[i];
            ans+=color[i+1];
        }
        else if(color[i] > color[i+1]){
        string str2 = "";
        if(color[i] == 'a'){
         str2+='9';
         str2+='9';
        }
        else{
         str2+=color[i]-1;
         str2+=color[i]-1;   
        }
        
        string str3 = "";
        str3+=color[i];
        str3+=color[i];
        if(diff(str,str2) <= diff(str3, str)){
            ans+=str2;
        }
        else{
            ans+=str3;
        }
        }
        else{
        string str2 = "";
        str2+=color[i];
        str2+=color[i];
        string str3 = "";
        str3+=color[i]+1;
        str3+=color[i]+1;
        if(diff(str,str2) <= diff(str3, str)){
            ans+=str2;
        }
        else{
            ans+=str3;
        }
      }
    }
    return ans;
 }
 
 
 int main(int argc,char** argv){
     string color;
     cin>>color;
     cout<<similarRGB(color)<<endl;
 }