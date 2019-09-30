#include<bits/stdc++.h>
using namespace std;

void findFunctionTimes(int n, vector<string> logs, int ans[]){
	stack<pair<pair<int, int>, int> > s;
	for(int i = 0; i < logs.size(); i++){
		string str = logs[i];
		int j = 0;
		int id = 0;
		int se;
		while(str[j]!=':'){
			id=id*10+int(str[j]-'0');
			j++;
		}
		j++;
		if(str[j] == 's'){
			se = 1;
		}
		else{
			se = 2;
		}

		while(str[j]!=':'){
			j++;
		}
		j++;
		int time = 0;
		while(str[j]!='\0'){
			time=time*10+int(str[j]-'0');
			j++;
		}

		if(se == 1){

			s.push(make_pair(make_pair(id,time), 0));
		}
		if(se == 2){
			pair<pair<int, int> , int> p = s.top();
			ans[id] = time-p.first.second+1-p.second;
			s.pop();
			pair<pair<int, int> , int> p2 = s.top();
			s.pop();
			p2.second = p2.second+time-p.first.second+1;
			s.push(p2);
		}


	}
}

int main(){
	int n;
	cin >> n;
	int k; cin >> k;
	vector<string> v;
	string str;
	for(int i = 0; i < k; i++){
		cin >> str;
		v.push_back(str);
	}
	int ans[n];
	findFunctionTimes(n, v, ans);
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
}