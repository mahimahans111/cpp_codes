#include<bits/stdc++.h>
using namespace std;

void printBinaryNumbers(int n){
	queue<pair<int, string> > q;
	//cout << 1 << " " << 1 << endl; 
	string s = "";
	s=s+'1';
	q.push(pair<int, string> (1, s));
	int flag = 0;
	while(!q.empty()){
		pair<int, string> cur = q.front();
		cout << cur.second << " ";
		q.pop();
		int no = cur.first; string s = cur.second;
		q.push(pair<int, string>(2*no, s+'0'));
		if(2*no == n){
			flag = 1;
			while(!q.empty()){
				pair<int, string> cur = q.front();
				cout << cur.second << " ";
				q.pop();
			}
			break;
		}
		if(flag == 1) break;
		q.push(pair<int, string>(2*no+1, s+'1'));
		if(2*no+1 == n){
			flag = 1;
			while(!q.empty()){
				pair<int, string> cur = q.front();
				cout <<  cur.second << " ";
				q.pop();
			}
			break;
		}
		if(flag == 1) break;

	}
}

int main(){
	int n; cin >> n;
	printBinaryNumbers(n);
}