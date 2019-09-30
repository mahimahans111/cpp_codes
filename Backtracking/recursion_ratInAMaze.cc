#include<iostream>
using namespace std;

bool ratInAMaze(char maze[10][10], int soln[][10], int i, int j, int m, int n){
	//base case
	if(i == m && j == n){
		soln[m][n] = 1;
		//print the path..
		for(int i = 0; i <= m; i++){
			for(j = 0; j <= n; j++){
				cout<<soln[i][j]<<" ";
			}
				cout<<endl;
		}
		cout<<endl;

		return true;
	}

	if(i > m || j > n) return false;

	if(maze[i][j] == 'X') return false;

	//assume soln exists through current cell
	soln[i][j] = 1;  //recursive case

	bool rightSuccess = ratInAMaze(maze, soln, i, j + 1, m, n);
	bool downSuccess = ratInAMaze(maze, soln, i + 1, j, m ,n);

	//Backtracking
	soln[i][j] = 0;
	if(rightSuccess || downSuccess) return true;
	return false;
} 

int main(){
	char maze[10][10] = {
							"0000",
							"00X0",
							"000X",
							"0X00"
						};

	int soln[10][10] = {0};
	int m = 4, n = 4;

	bool ans =ratInAMaze(maze, soln, 0, 0, m-1, n-1);
	if(ans == false){
		cout << "path doesn't exist.";
	}
}