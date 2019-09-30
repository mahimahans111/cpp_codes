#include<bits/stdc++.h>
using namespace std;

int M = 1000000007;

int binaryStringsWithoutConsecutiveOnes(int n){
    int x = 1, y = 1;
    
    for(int i = 2; i <= n; i++){
        int m = x%M;
        x = y%M;
        y = (m+y)%M;
    }
    return (x+y)%M;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << binaryStringsWithoutConsecutiveOnes(n) << endl;
     }
	return 0;
}