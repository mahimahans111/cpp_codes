#include<iostream>
  #include<vector>
  using namespace std;
  
  // -----------------------------------------------------
  // This is a functional problem. Do not make changes to main
  // This function takes as input an array and integer k.
  // It should print required output.
  
  bool checkTheMagic(vector<vector<int> > grid, int i, int j){
      for(int k = i; k <= i+2; k++){
          if(grid[k][j]+grid[k][j+1]+grid[k][j+2]!=15) return false;
      }
      for(int k = j; k <= j+2; k++){
          if(grid[i][k]+grid[i+1][k]+grid[i+2][k]!=15) return false;
      }
      if(grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2]!=15) return false;
      if(grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]!=15) return false;
      return true;
  }
  
  int numMagicSquaresInside(vector<vector<int> > &grid) {
      int n = grid.size();
      int m = grid[0].size();
      int cnt = 0;
      for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
              if(i+2 < n && j+2 < m){
                  if(grid[i+1][j+1] == 5){
                      if(checkTheMagic(grid, i, j)) cnt++;
                  }
              }
          }
      }
      return cnt;
  }
  
  int main(int argc, char** argv){
      int r, c;
      cin>>r>>c;
      vector<vector<int> > Input(r, vector<int> (c));
      for (int i = 0; i < r; i++) {
          for (int j = 0; j < c; j++) {
              cin>>Input[i][j];
          }
      }
      cout<<numMagicSquaresInside(Input);
  }