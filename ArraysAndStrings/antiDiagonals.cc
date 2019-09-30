#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > antiDiagonals(vector<vector<int> > mat, int n){
	vector<vector<int> > ans;

	for(int j = 0; j < n; j++){
		vector<int> a;
		int i = 0;
		int k = j;
		while(true){
			a.push_back(mat[i][k]);
			if(k-1 < 0 || i+1>=n)break;
			else {k--;
			i++;}
		}
		// for(int m=0; m<a.size();m++)cout << a[m] <<" ";
		// 	cout << endl;
		ans.push_back(a);
	}

	for(int i = 1; i < n; i++){
		vector<int> a;
		int j = n-1;
		int k = i;
		while(true){
			a.push_back(mat[k][j]);
			if(k+1 >= n || j-1 < 0) break;
			else{
				k++; j--;
			}
		}
		// for(int m=0; m<a.size();m++)cout << a[m] <<" ";
		// 	cout << endl;
		ans.push_back(a);
	}
	return ans;
}

int main(){
	int n; cin >> n;
	vector<vector<int> > mat;
	int a;
	for(int i = 0; i < n; i++){
		vector<int> v;
		for(int j = 0; j < n; j++){
			cin >> a;
			v.push_back(a); 
		}
		mat.push_back(v);
	}
	vector<vector<int> >ans = antiDiagonals(mat, n);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}