#include<bits/stdc++.h>
using namespace std;

void SmallestWindow(string str, string patr){
	int matchcount = 0;
	set<char> myset;
	map<char, int> m;
	for(int i = 0; i < patr.length(); i++){
		myset.insert(patr[i]);
	}
	int mc = myset.size();

	int s = 0, e = 0, bs = 0, be = str.length();

	while(e < str.length() && s <= e){
		if(matchcount < mc){
			while(matchcount < mc && e < str.length()){
				if(myset.count(str[e])){
					if(m.count(str[e])){
						m[str[e]]++;
					}
					else{
						m[str[e]] = 1;
						matchcount++;
					}
				}
				e++;
			}
		}
			if(e-s+1 < be-bs+1 && matchcount == mc){
				be = e; bs = s;
			}
			while(matchcount == mc && s<=e){
				if(myset.count(str[s])){
					if(m[str[s]]==1){
						matchcount--;
						m.erase(str[s]);
					}
					else{
						m[str[s]]--;
					}
				}
				s++;
				if(e-s < be-bs && matchcount == mc){
				be = e; bs = s;
					}
				}
	}

	for(int i = bs; i <= be; i++)cout << str[i];
}

int main(){
	string s, t;
	cin >> s >> t;
	SmallestWindow(s, t);
}