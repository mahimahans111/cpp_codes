#include<bits/stdc++.h>
using namespace std;

bool longPressName(string s, string t){
	int k = s.length()-1;
	for(int i = 0, j = 0; j < t.length();){
	        
			if(i < s.length()){
			if(s[i] == t[j]){
				i++; j++;
			}
			else if(j > 0 && t[j] == t[j-1]){
				j++;
			}
			else return false;				
			}
			else{
			if(s[k] == t[j]){
				j++;
			}
			else if(j > 0 && t[j] == t[j-1]){
				j++;
			}
			else return false;	
			}
		if(i < s.length() && j == t.length()) return false;
		}
		
		return true;
	
}

int main(){
	string s, t; cin >> s >> t;
	bool ans = longPressName(s, t);
	ans==1?cout << "true":cout<<"false";
}