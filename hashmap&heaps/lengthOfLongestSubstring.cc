#include<bits/stdc++.h>
using namespace std;

int longestSubstringWithUniqueChars(string str){
	int s = 0;
	int e = 0;
	int ans = 0;
	int max = 0;
	map<char, int> m;	
	while(s <= e && e < str.length()){
		if(m.find(str[e]) == m.end()){
			// cout << e << " " << str[e] << endl;
			m[str[e]] = 1;
			e++;
		}
		else {
			
			break;
		}
	}
	if(e-s > max) max = e-s;
	// cout << max << endl;
	while(s <= e && e < str.length()){
			while(s <= e && e < str.length()){
				if(m.count(str[e])){
					m[str[e]]++;
					e++;
					break;
				}
				else{
					m[str[e]] = 1;
					e++;
					if(e-s > max)max = e-s;
				}
			}
			// if(e-s > max) max = e-s;
			while(s <= e && e < str.length()){
				if(m[str[s]]==1)m.erase(str[s]);
				
				else m[str[s]]--;
				s++;
				int cnt = 0;
				for(map<char, int> :: iterator it = m.begin(); it!=m.end(); it++){
					if(it->second == 1)cnt++;
				}
				if(cnt == m.size()){
				if(e-s > max) max = e-s;
			    break;
			}
			}
			
	}
	return max;

}

int main(){
	string s;
	cin >> s;
	int ans = longestSubstringWithUniqueChars(s);
	cout << ans;
}