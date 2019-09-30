#include<iostream>
 #include<unordered_map>
 #include<string>
 using namespace std;
 
 int main(){
 //write you code here 
 
    string s; cin >> s;
    unordered_map<int, int> m;
    for(int i = 0; i < s.length(); i++){
        if(m.count(int(s[i])))m[int(s[i])]++;
        else m[int(s[i])] = 1;
    }
    int x = 0, y = 0;
    for(unordered_map<int, int> :: iterator it = m.begin(); it!= m.end(); it++){
        if(it->first%2!=0 && it->second%2!=0) y++;
        if(it->first%2==0 && it->second%2==0) x++;
    }
    
    if((x+y)%2 == 0) cout << "EVEN";
    else cout << "ODD";
 }