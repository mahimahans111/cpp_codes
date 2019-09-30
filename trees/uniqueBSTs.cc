#include<iostream>
 #include<vector>
 using namespace std;
 
 // This is a functional problem. You have to complete this function.
 // It takes as input N. It should return the number of structurally unique BSTs.

     // write your code here.
long long int binomial(int n, int k){
    k = min(n-k, k);
    long long int res = 1;
    for(int i=0; i<k; i++){
        res *= n - i;
        res /= i + 1;
    }
    return res;
}

long long int numTrees(int n){
    return binomial(n << 1, n) / (n + 1);
}
 
 
 int main(int argc, char** argv){
     int N;
     cin>>N;
     cout<<numTrees(N)<<endl;
 }