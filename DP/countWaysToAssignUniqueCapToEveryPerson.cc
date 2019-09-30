#include<bits/stdc++.h>
using namespace std;

int ans = 0;

bool check(int c, int n){
	for(int i = 0; i < n; i++){
		if(c & (1<<i)!=(1<<i))return false;
	}
	return true;
}

void noOfWays(map<int, vector<int> > cpmap, int cc, int tc, int ct, int n, string psf){
	if(cc == tc && check(ct, n)){
		cout << psf << endl;
		ans++;
		return;
	}

	int flag = 0;
	for(int i = 0; i < cpmap[cc].size(); i++){

		if(ct & (1 << cpmap[cc][i]) == 0){
			flag = 1;
			ct = ct^(1 << cpmap[cc][i]);
			psf+=" ";
			psf+=cc;
			psf+=" ";
			noOfWays(cpmap, cc+1, tc, ct, n, psf);
			ct = ct^(1 << cpmap[cc][i]);
		}
	}
	if(flag == 0) noOfWays(cpmap, cc+1, tc, ct, n, psf);
}

int main(){
	int n; cin >> n;

	map<int, vector<int> > m;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		int a;
		for(int j = 0; j < x; j++){
			cin >> a;
			if(m.count(a)){
				m[a].push_back(i);
			}
			else {
				vector<int>v;
				v.push_back(i);
				m[a] = v;
			}
		}
	}
	// cout << m.size() << endl;
	// for(map<int, vector<int> > :: iterator it = m.begin(); it!=m.end(); it++){
	// 	cout << it->first << " -> ";
	// 	for(int i = 0; i < it->second.size(); i++){
	// 		cout << it->second[i] << " ";
	// 	}
	// 	cout << endl;
	// }
	int t = m.size();
	noOfWays(m, 0, t, 0, n, "");
	cout << ans;
}