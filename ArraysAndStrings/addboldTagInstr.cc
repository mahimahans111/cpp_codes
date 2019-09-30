#include<bits/stdc++.h>
 using namespace std;

int bold[1000] = {};
  
void computeLPSArray(string pat, int M, int* lps); 
  
void KMPSearch(string pat, string txt) 
{ 
    int M = pat.length(); 
    int N = txt.length(); 

    int lps[M]; 
  
    computeLPSArray(pat, M, lps); 
  
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
            for(int k = i-j; k < i-j+pat.length(); k++){
                bold[k] = 1;
            } 
            // cout << i-j << endl;
            j = lps[j - 1]; 
        } 
  
        else if (i < N && pat[j] != txt[i]) { 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
} 
  
void computeLPSArray(string pat, int M, int* lps) 
{ 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
 
            if (len != 0) { 
                len = lps[len - 1]; 
 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
}
 
 
 
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input an array of strings and a string
 // It should return required output.
 string addBoldTag(string &s, vector<string> &dict) {
     // Write your code here
     for(int i =  0; i < dict.size(); i++){
         KMPSearch(dict[i], s);
        //  cout << endl;
     }
    
    //  for(int i = 0; i < s.length(); i++) cout << bold[i] << " ";
    string ans = "";
    int start = 0;
    int end = 0;
    for(int i = 0; i < s.length(); i++){
        if(bold[i] == 1 && start == 0){
            ans+="<b>";
            // ans+=s[i];
            start = 1;
            end = 0;
        }
        // else if(bold[i] == 1 && start){
        //     ans+=s[i];
        // }
        else if(bold[i] == 0){
            if(start == 1 && end == 0){
                ans+="</b>";
                end = 1;
                start = 0;
            }
        }
        ans+=s[i];
        }
        if(bold[s.length()-1] == 1) ans+="</b>";
     return ans;
 }
 
 int main(int argc, char** argv){
     string s;
     cin>>s;
     int n;
     cin>>n;
 	 vector<string> dict(n);
     for (int i = 0; i < n; i++) {
         cin>>dict[i];
     }
     cout<<addBoldTag(s, dict);
 }