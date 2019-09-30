#include<iostream>
 #include<vector>
 #include<string>
 #include<unordered_map>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input an array of string.
 // It should return an array of suitable strings.
 
 vector<string> findWords(vector<string>& words) {
     vector<string> ans;
     unordered_map<char, int> m;
     m['q'] = m['w'] = m['e'] = m['r'] = m['t'] = m['y'] = m['u'] = m['i'] = m['o'] = m['p'] = 1;
    m['Q'] = m['W'] = m['E'] = m['R'] = m['T'] = m['Y'] = m['U'] = m['I'] = m['O'] = m['P'] = 1;    
     m['a'] = m['s'] = m['d'] = m['f'] = m['g'] = m['h'] = m['j'] = m['k'] = m['l'] = 2;
      m['A'] = m['S'] = m['D'] = m['F'] = m['G'] = m['H'] = m['J'] = m['K'] = m['L'] = 2;
     m['z'] = m['x'] = m['c'] = m['v'] = m['b'] = m['n'] = m['m'] = 3;
     m['Z'] = m['X'] = m['C'] = m['V'] = m['B'] = m['N'] = m['N'] = 3;
     
     for(int i = 0; i < words.size(); i++){
         string cur = words[i];
         int thisans = m[cur[0]];
         int cnt = 1;
         for(int i = 1; i < cur.length(); i++){
             if(m[cur[i]] == thisans) cnt++;
         }
         if(cnt == cur.length())ans.push_back(cur);
     }
     return ans;
      //Write your code here 
 }
 
 int main(int argc,char** argv){
     int n;
     cin>>n;
     
     vector<string> words(n);
     for(int i=0;i<n;i++)
         cin>>words[i];
     
     vector<string>res;
     res= findWords(words);
     for(int i=0;i<res.size();i++)
         cout<<res[i]<<" ";
 
     cout << endl;    
 
 }