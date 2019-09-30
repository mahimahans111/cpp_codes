#include<bits/stdc++.h>
using namespace std;

    vector<vector<int> > merge(vector<vector<int> >& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int min = INT_MAX;
        int max = INT_MIN;
	     vector<vector<int> > ans;

	    for(int i = 0; i < n; i++){
            if(min == INT_MAX && max == INT_MIN){
                min = arr[i][0];
                max = arr[i][1];
            }
            else if(arr[i][0] > max){
                vector<int> one;
                one.push_back(min);
                one.push_back(max);
                ans.push_back(one);
                min = arr[i][0];
                max = arr[i][1];
            }
            else{
			if(arr[i][1] > max){
				max = arr[i][1];
			}
		}
	}
    if(min!=INT_MAX && max!=INT_MIN) {
                vector<int> one;
                one.push_back(min);
                one.push_back(max);
                ans.push_back(one);
    }
	
        return ans;
    }

int main(){
	int n; 
	vector<vector<int> > arr;
	for(int i = 0; i < n; i++){
		vector<int> v;
		int a, b; cin >> a >> b;
		v.push_back(a);
		v.push_back(b);
		arr.push_back(v);
	}
	vector<vector<int> >ans =  merge(arr);
}