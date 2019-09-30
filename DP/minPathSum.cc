#include<bits/stdc++.h>
using namespace std;

 int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans[r][c] = {};
        
        ans[r-1][c-1] = grid[r-1][c-1];
        for(int i = r-2; i >= 0; i--){
            ans[i][c-1] = grid[i][c-1]+ans[i+1][c-1];
        }
        
        for(int i = c-2; i >= 0; i--){
            ans[r-1][i] = grid[r-1][i]+ans[r-1][i+1];
        }
        
        for(int i = r-2; i >= 0; i--){
            for(int j = c-2; j >= 0; j--){
                ans[i][j] = grid[i][j]+min(ans[i][j+1], ans[i+1][j]);
            }
        }
        return ans[0][0];
    }

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > grid;
	int a;
	for(int i = 0; i < n; i++){
		vector<int> v;
		for(int j = 0; j < m; j++){
			cin >> a;
			v.push_back(a);
		}
		grid.push_back(v);
	}
	cout << minPathSum(grid);
}