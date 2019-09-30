#include<iostream>
using namespace std;

void clearBoard(char board[][100], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			board[i][j] = 'X';
		}
	}
}

bool canPlace(char board[][100], int r, int c, int dim){
	for(int x = 0; x < r; x++){
		if(board[x][c]== 'Q') return false; 
	}

	int rowDir[] = {-1, -1};
	int colDir[] = {+1, -1};
	for(int dir = 0; dir < 2; ++dir){
		for(int dist = 1; dist < dim; dist++){
			int nextRow = r + dist * rowDir[dir];
			int nextCol = c + dist * colDir[dir];
			if((nextRow < 0 || nextCol >= dim) || (nextCol < 0 || nextCol >= dim)){
				break;
			}
			if(board[nextRow][nextCol] == 'Q'){
				return false;
			}
		}
	}
	return true;
}

void solveNQueen(char board[][100], int r, int dim){
	if(r == dim){
		for(int i = 0; i < dim; i++){
			for(int j = 0; j < dim; j++){
				if(board[i][j] == 'Q'){
					cout<<"{"<<i+1<<"-"<<j+1<<"}"<<" ";
				}
			}
		}
		cout<<" ";
	return;

	}

	for(int c = 0; c < dim; c++){
		bool check = canPlace(board, r, c, dim);
		if(check == true){
			board[r][c] = 'Q';
		 solveNQueen(board, r + 1, dim);
			board[r][c] = 'X';
		}
	}
}

int main(){
	int n;
	cin>>n;

	char board[100][100] = {};
	clearBoard(board, n);

	solveNQueen(board, 0, n);

}