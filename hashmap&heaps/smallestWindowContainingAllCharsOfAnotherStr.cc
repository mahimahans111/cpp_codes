#include<bits/stdc++.h>
using namespace std;

void SmallestWindow(string str, string patr){
	int matchcount = 0;
	set<char> myset;
	map<char, int> m, mymap;
	for(int i = 0; i < patr.length(); i++){
		if(mymap.count(patr[i])){
		    mymap[patr[i]]++;
		}
		else mymap[patr[i]] = 1;
	}
	int mc = patr.length();
    
	int s = 0, e = 0, bs = 0, be = str.length();

	while(s <= e && e < str.length()){
		
			while(matchcount < mc && e < str.length()){
				if(mymap.count(str[e])){
				    if(m.count(str[e])){
					    if(mymap[str[e]] > m[str[e]]){
					      	m[str[e]]++;
					      	matchcount++;
					    }
					    else{
					        m[str[e]]++;
					    }
					}
					else{
						m[str[e]] = 1;
						matchcount++;
					}
				}
				e++;
			}
		
			if(e-s+1 < be-bs+1 && matchcount == mc){
				be = e; bs = s;
			}
			while(matchcount == mc && s<=e){
				if(mymap.count(str[s])){
				// 	if(m[str[s]]==1){
				// 		matchcount--;
				// 		m.erase(str[s]);
				// 	}
				// 	else{
				// 		m[str[s]]--;
				// 	}
				    if(m[str[s]] <= mymap[str[s]]){
				        matchcount--;
				        m[str[s]]--;
				        if(m[str[s]] == 0) m.erase(str[s]);
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
    // cout << be-bs;
	for(int i = bs; i < be; i++)cout << str[i];
}

int main(){
	string s, t;
	cin >> s >> t;
// 	t = s;
	SmallestWindow(s, t);
}