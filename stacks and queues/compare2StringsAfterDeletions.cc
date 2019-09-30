#include<bits/stdc++.h>
using namespace std;

bool compareAfterDeletion(string s1, string s2){
	stack<int>st1, st2;
	for(int i = 0; i < s1.length(); i++){
		if(s1[i] == '#' && !st1.empty()) st1.pop();
		else st1.push(s1[i]);
	}

	for(int i = 0; i < s2.length(); i++){
		if(s2[i] == '#' && !st2.empty()) st2.pop();
		else st2.push(s2[i]);
	}

	while(!st1.empty() && !st2.empty()){
		if(st1.top()!=st2.top()) return false;
		else {
			st1.pop();  st2.pop();
		}
	}
	if(st1.empty() && st2.empty()) return true;

}

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	bool ans = compareAfterDeletion(s1, s2);
	ans == 1? cout << "true" : cout << "false"; 
}