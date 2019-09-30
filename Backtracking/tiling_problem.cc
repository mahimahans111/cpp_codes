//Given a brick wall of 4*N and tiles of size 4*1 which can be arranged horizontally as well as 
//vertically, you have to find the total number of ways to arrange the tiles on the wall.
#include<bits/stdc++.h>
using namespace std;

int NoOfWaysOfTiling(int N){
	if(N <= 4) return 1;

	int f1 = NoOfWaysOfTiling(N-1);
	int f4 = NoOfWaysOfTiling(N-4);

	return f1 + f4;
}

int main(){
	int N;
	cin >> N;
	int ans = NoOfWaysOfTiling(N);
	cout << ans;
}