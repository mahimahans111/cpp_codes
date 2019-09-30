#include<bits/stdc++.h>
using namespace std;

class Helper{
 public:    
    int row; 
    int col;
    int level;
    Helper(int r, int c, int l){
        row = r;
        col = c;
        level = l;
    }
};

bool isValid(int arr[][100], int row, int col, int n){
    if(row < 0 || row >= n || col < 0 || col >= n) return false;
    else if(arr[row][col] == 2) return false;
    return true;
}

int main(){
    int n; cin >> n;
    int arr[n][100] = {};
    int sr, sc, dr, dc;
    cin >> sr >> sc >> dr >> dc;
    sr--; sc--; dr--; dc--;
    queue<Helper> q;
    q.push(Helper(sr, sc, 0));
    // cout << q.front().row << " " << q.front().col << " " << q.front().level;
    
    while(!q.empty()){
        Helper rem = q.front();
            // if(q.front().row == 15)cout << q.front().row << " " << q.front().col <<  "      ";
        q.pop();
        if(arr[rem.row][rem.col] == 2) continue;
        arr[rem.row][rem.col] = 2;
        if(rem.row == dr && rem.col == dc){
            cout << rem.level;
            break;
        }
        if(isValid(arr, rem.row+2, rem.col+1, n)){
            q.push(Helper(rem.row+2, rem.col+1, rem.level+1));
        }
         if(isValid(arr, rem.row+1, rem.col+2, n)){
            q.push(Helper(rem.row+1, rem.col+2, rem.level+1));
        }
         if(isValid(arr, rem.row-1, rem.col+2, n)){
            q.push(Helper(rem.row-1, rem.col+2, rem.level+1));
        }
         if(isValid(arr, rem.row-2, rem.col+1, n)){
            q.push(Helper(rem.row-2, rem.col+1, rem.level+1));
        }
         if(isValid(arr, rem.row-2, rem.col-1, n)){
            q.push(Helper(rem.row-2, rem.col-1, rem.level+1));
        }
         if(isValid(arr, rem.row-1, rem.col-2, n)){
            q.push(Helper(rem.row-1, rem.col-2, rem.level+1));
        }
         if(isValid(arr, rem.row+1, rem.col-2, n)){
            q.push(Helper(rem.row+1, rem.col-2, rem.level+1));
        }
         if(isValid(arr, rem.row+2, rem.col-1, n)){
            q.push(Helper(rem.row+2, rem.col-1, rem.level+1));
        }
    }
}



