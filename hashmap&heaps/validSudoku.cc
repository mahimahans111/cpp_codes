#include<iostream>
 #include<vector>
 using namespace std;
 
 // This is a functional problem. You have to complete this function.
 // It takes as input a 2D array of characters. It should return true if the
 // board is valid, else should return false.
 bool isValidSudoku(vector<vector<char> > board) {
    //  int n = board[i].size();
     int rows[9]={};
     int cols[9]={};
     int sm[3][3]={};
     for(int i = 0; i < 9; i++){
         for(int j = 0; j < 9; j++){
             if(board[i][j] != '.'){
                 int val = board[i][j];
                 if((rows[i] & (1<<val))==0){
                     rows[i]=rows[i]|(1<<val);
                 }
                 else return false;
                 
                 if((cols[j] & (1<<val))==0){
                     cols[j]=cols[j]|(1<<val);
                 }
                 else return false;
                 
                 if((sm[i/3][j/3] & (1<<val))==0){
                     sm[i/3][j/3]=sm[i/3][j/3]|(1<<val);
                 }
                 else return false;
             }
         }
     }
     return true;
 }
 
 int main(int argc, char** argv){
     vector<vector<char> > board(9, vector<char> (9));
 
     for (int i = 0; i < 9; i++) {
         for (int j = 0; j < 9; j++) {
             cin>>board[i][j];
         }
     }
     if (isValidSudoku(board)) {
         cout<<"Valid";
     } else {
         cout<<"Invalid";
     }
 
 }