#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n, m;
	cin >> n >> m;
	long long int balloons[100000], candies[10000];
	long long int sumBalloons = 0;
	for(long long int i = 0; i < n; i++){
		cin >> balloons[i];
		sumBalloons += balloons[i];
	}
	for (long long int i = 0; i < n; ++i)
	{
		cin >> candies[i];
	}
	long long int ans;
	if(sumBalloons <= m){
		ans = 0;
		cout << ans;
	}
	else{
		priority_queue<pair<long long int, pair<long long int, long long int> > >candiballoon;
		for(long long int i = 0; i < n; i++){
			long long int ans =  balloons[i]*candies[i];
			candiballoon.push(make_pair(ans, make_pair(candies[i], balloons[i])));
			}
	
		while(m--){
			pair<long long int, pair<long long int, long long int> >top1 = candiballoon.top();
			candiballoon.pop();
			top1.second.second--;
			top1.first = top1.second.first*top1.second.second;
			candiballoon.push(top1);
			 }
	cout << candiballoon.top().first;
	}
}
