#include<bits/stdc++.h>
using namespace std;

vector<char> levelNodes(int level, string str){
	vector<char>ans;
	stack<pair<pair<char, int>, int> > s;
	for(int i = 0; i < str.length();  i++){
		if(str[i] == '('){
			continue;
		}
		else if(str[i] >= 'a' && str[i] <= 'z'){
			if(s.empty()){
				char c = str[i];			
				
				s.push(make_pair(make_pair(str[i], 0), 0));
			}
			else{
				pair<pair<char, int>, int>  p = s.top();
				s.pop(); 
				p.second++;
				s.push(p);
				int l;
				if(p.second == 1) l = p.first.second-1;
				if(p.second == 2) l = p.first.second+1;
				s.push(make_pair(make_pair(str[i], l), 0));
			}
		}
		else if(str[i] == '.'){
				pair<pair<char, int>, int>  p = s.top();
				s.pop(); 
				p.second++;
				s.push(p);
		}

		else if(str[i] == ')'){
				pair<pair<char, int>, int>  p = s.top();
				if(p.first.second == level)ans.push_back(p.first.first);
				s.pop();
		}
	}
	return ans;
}

int main(){
	int level; cin >> level;
	string s; cin >> s;
	vector<char> ans = levelNodes(level, s);
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i];
	}
}