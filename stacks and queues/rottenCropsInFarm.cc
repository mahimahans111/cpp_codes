#include<bits/stdc++.h>
using namespace std;

class Helper{
public:
	int row;
	int col;
	int time;
	Helper(int r, int c, int t){
		row = r;
		col = c;
		time = t;
	}
};

bool isValid(int arr[][100], int i, int j, int r, int c){
	if(i >= r || j >= c || i < 0 || j < 0) return false;
	if(arr[i][j] == 0 || arr[i][j] == 2) return false;
	return true;
}

int minTimeToRot(int arr[][100], int r, int c, int cnt){
	queue<Helper>q;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(arr[i][j] == 2) q.push(Helper(i, j, 0));
		}
	}

	int finalTime = 0;
	while(!q.empty()){
		Helper cur = q.front();
		finalTime = cur.time;
		q.pop();
		arr[cur.row][cur.col] = 2;
		cnt--;
		if(isValid(arr, cur.row-1, cur.col, r, c)){
			q.push(Helper(cur.row-1, cur.col, cur.time+1));
		}
		if(isValid(arr, cur.row+1, cur.col, r, c)){
			q.push(Helper(cur.row+1, cur.col, cur.time+1));
		}
		if(isValid(arr, cur.row, cur.col-1, r, c)){
			q.push(Helper(cur.row, cur.col-1, cur.time+1));
		}
		if(isValid(arr, cur.row, cur.col+1, r, c)){
			q.push(Helper(cur.row, cur.col+1, cur.time+1));
		}
	}

	// for(int i = 0; i < r; i++){
	// 	for(int j = 0; j < c; j++){
	// 		if(arr[i][j] == 1) return -1;
	// 	}
	// }
	if(cnt != 0) return -1;
	return finalTime;
}

int main(){
	int r, c;
	cin >> r >> c;
	int arr[100][100];
	int cnt = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 1) cnt++;
		}
	}
	int ans = minTimeToRot(arr, r, c, cnt);
	cout << ans;
}