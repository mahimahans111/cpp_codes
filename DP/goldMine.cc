#include<bits/stdc++.h>
using namespace std;

bool check(int i, int j, int r, int c){
    if(i >= 0 && j >=0 && i < r && j < c) return true;
    return false;
}

int goldMine(vector<vector<int> > v){
    int r = v.size();
    int c = v[0].size();
    int arr[r][c];
    for(int i = 0; i < r; i++){
        arr[i][c-1] = v[i][c-1];
    }
    
    for(int j = c-2; j >= 0; j--){
        for(int i = r-1; i >= 0; i--){
            int one, two, three;
            one= check(i, j+1, r, c) ? arr[i][j+1] : 0;
            two= check(i-1, j+1, r, c) ? arr[i-1][j+1] : 0;
            three= check(i+1, j+1, r, c) ? arr[i+1][j+1] : 0;
            arr[i][j] = max(one, max(two, three))+v[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < r; i++){
        ans = max(ans, arr[i][0]);
    }
    
    return ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        int x;
        int n, m; cin >> n >> m;
        vector<vector<int> > v;
        for(int i = 0; i < n; i++){
            vector<int> a;
            for(int j = 0; j < m; j++){
                cin >> x;
                a.push_back(x);
            }
            v.push_back(a);
        }
        cout << goldMine(v) << endl;
     }
	return 0;
}