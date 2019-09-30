#include<bits/stdc++.h>
using namespace std;

stack<int> sortedStack(stack<int>s){
	stack<int> ans;

	while(!s.empty()){
		int temp = s.top();
		s.pop();
		if(ans.empty()) ans.push(temp);
		else{
			if(ans.top() <= temp){
				ans.push(temp);
			}
			else{
				while(!ans.empty() && ans.top() > temp){
					s.push(ans.top());
					ans.pop();
				}
				ans.push(temp);
			}
		}
	}
	return ans;
}

int main(){
	int n; cin >> n;
	int a;
	stack<int> s;
	for(int i = 0; i < n; i++){
		cin >> a;
		s.push(a);
	}
	stack<int> ans = sortedStack(s);
	while(!ans.empty()){
		cout << ans.top() << " ";
		ans.pop();
	}
}