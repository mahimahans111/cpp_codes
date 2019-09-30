#include<bits/stdc++.h>
using namespace std;

vector<int> killedProcesses(int pid[], int ppid[], int n, int kill){
	map<int, vector<int> >m;
	for(int i = 0; i < n; i++){
		if(m.find(ppid[i]) == m.end()){
			vector<int> v;
			v.push_back(pid[i]);
			m[ppid[i]] = v;
		}
		else{
			m[ppid[i]].push_back(pid[i]);
		}
	}

	queue<int> q;
	q.push(kill);
	vector<int>ans;
	while(!q.empty()){
		int a = q.front();
		ans.push_back(a);
		q.pop();
		if(m.find(a)!=m.end()){
			for(int i = 0; i < m[a].size(); i++){
				q.push(m[a][i]);
			}
		}
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	int kill;
	cin >> kill;
	int pid[n];
	int ppid[n];
	for(int i = 0; i < n; i++){
		cin >> pid[i];
	}
	for(int i = 0; i < n; i++){
		cin >> ppid[i];
	}
	vector<int> ans = killedProcesses(pid, ppid, n, kill);
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
}