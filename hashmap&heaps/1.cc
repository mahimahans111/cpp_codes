#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int mat[100][100] = {};
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}