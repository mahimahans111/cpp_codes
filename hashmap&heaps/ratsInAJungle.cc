#include<bits/stdc++.h>
using namespace std;

int minRatsReqd(map<int, int> m){
	int ans = 0;
	for(unordered_map<int, int> :: iterator it = m.begin(); it!= m.end(); it++){
		int gs = it->first+1;
		int ng = ((it->second)/gs);
		if((it->second)%gs != 0) ng++;
		ans+=gs*ng;
	}
	return ans;
}

int main(){
	int q; cin >> q;
	unordered_map<int, int> m;
	int response;
	for(int i = 0; i < q; i++){
		cin >> response;
		if(m.count(response))m[response]++;
		else m[response] = 1;
	}
	int ans = minRatsReqd(m);
	cout << ans;
}