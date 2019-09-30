#include<bits/stdc++.h>
using namespace std;
// void inputMat(int mat[][100], int m, int n) {
//     for (int r = 0; r < m; ++r) {
//         for (int c = 0; c < n; ++c) {
//             cin >> mat[r][c];
//         }
//     }
// }
// void outputMat(int mat[][100], int m, int n) {
//     cout << "\n-----MAT Begins----\n";
//     for (int r = 0; r < m; ++r) {
//         for (int c = 0; c < n; ++c) {
//             cout << mat[r][c] << " ";
//         }
//         cout << endl;
//     }
//     cout << "-----MAT Ends------\n";
// }

bool canPlace(vector<string>board, int N, int r, int c, char num){
    for(int x = 0; x < N; ++x){
        if (board[x][c] == num || board[r][x] == num) return false;
    }

    int rootN = sqrt(N);
    int subMatBeginRow = r - r % rootN;
    int subMatBeginCol = c - c % rootN;
    for(int i = subMatBeginRow; i < subMatBeginRow + rootN; ++i){
        for(int j = subMatBeginCol; j < subMatBeginCol + rootN; ++j){
            if (board[i][j] == num) return false;
        }
    }
    return true;
}

bool solveSudoku(vector<string> &board, int N, int r, int c) {
    // if r is out of bound
    if (r >= N){
        return true;
    }

    // if c is out of bound
    if (c >= N){
        return solveSudoku(board, N, r + 1, 0);
    }

    // if fixed cell
    if (board[r][c] != '.'){
        return solveSudoku(board, N, r, c + 1);
    }

    // if empty cell
    for (char num = '1'; num <= char(N+'0'); ++num) {
        if (canPlace(board, N, r, c, num)) {
            board[r][c] = num;
            bool isSuccessful = solveSudoku(board, N, r, c+ 1);
            if (isSuccessful){
                return true;
            }
            board[r][c] = '.';    // reset/vacate the cell
        }
    }
    return false;
}

int main() {

    int N;
    cin >> N;
    vector<string> board(N, "");    
    for(int i = 0; i < N; i++){
    	cin >> board[i];
    }

    bool success = solveSudoku(board, N, 0, 0);
    if (success) {
        for(int i = 0; i < N; i++){
    	cout << board[i] << endl;
    }
    }
    
}