#include<bits/stdc++.h>
using namespace std;

bool canPlace(char board[][10]; int r, int c, int dim){
	for(int x = 0; x < c; x++){
		if(board[x][c] == 'Q') return false;
	}

	int rowDir[] = {-1, -1};
	int colDir[] = {-1, 1};

	for(int dir = 0; dir < 2; dir++){
		for(int dist = 0; dist < dim; dist++){
			int nextRow = r+dist*rowDir[dir];
			int nextCol = c+dist*colDir[dir];

			if((nextRow < 0 || nextRow >= dim)||(nextCol < 0|| nextCol >= dim)){
				break;
			}

			if(board[nextRow][nextCol] == 'Q') return false;
		}
	}
	return true;
}

bool solveNQueen(char board[][10], int r, int dim){
	if(r >= dim) return true;

	for(int c = 0; c < dim; c++){
		bool check = canPlace(board, r, c, dim);

		if(check){
			board[r][c] = 'Q';
			bool success = solveNQueen(board, r+1, dim);

			if(success) return true;
			board[r][c] = 'X';
		}
	}
}