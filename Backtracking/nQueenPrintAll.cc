#include<bits/stdc++.h>
using namespace std;

bool canPlace(vector<string > board, int r, int c, int dim) {
    for (int x = 0; x < r; ++x) {
        if (board[x][c] == 'Q') return false;
    }

    int rowDir[] = { -1, -1};
    int colDir[] = { +1, -1};
    for (int dir = 0; dir < 2; ++dir) {
        for (int dist = 1; dist < dim; ++dist) {
            int nextRow = r + dist * rowDir[dir];
            int nextCol = c + dist * colDir[dir];
            if ((nextRow < 0 || nextRow >= dim) || (nextCol < 0 || nextCol >= dim)){
                // out of the board
                break;
            } 
            if (board[nextRow][nextCol] == 'Q'){
                return false;
            }
        }
    }
    return true;
}

void nQueen(int n, int r, vector<vector<string> > &ans, vector<string> &mat){
	if(r == n){
		ans.push_back(mat);
	}

	for(int c = 0; c < n; c++){
		if(canPlace(mat, r, c, n)){
			mat[r][c] = 'Q';
		
		nQueen(n, r+1, ans, mat);
		
		mat[r][c] = '.';
	}
	}
}

int main(){
	int n;
	cin >> n;
	vector<vector<string> > ans;
	vector<string> mat;
	string str = "";
	for(int i = 0; i < n; i++){
		str+='.';
	}
	for(int i = 0; i < n; i++){
		mat.push_back(str);
	}
	nQueen(n, 0, ans, mat);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << ans[i][j] << endl;
		}
		cout << endl;
	}
}