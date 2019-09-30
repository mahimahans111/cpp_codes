#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}


int maxPointsOnALine(vector<pair<int, int> > points, int n){
	map<pair<int, int>, int> m;
	int ans=INT_MIN;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int dx = points[i].first-points[j].first;
			int dy = points[i].second-points[j].second;
			int g = gcd(dx, dy);
			dx = dx/g; dy = dy/g;
			if(m.count(pair<int, int>(dx, dy)))m[pair<int, int>(dx, dy)]++;
			else m[pair<int, int>(dx, dy)] = 1;
		}
		int maxVal = INT_MIN;
		for(map<pair<int, int>, int> :: iterator it = m.begin(); it!=m.end(); it++){
			if(it->second > maxVal)maxVal = it->second;
		}
		ans = max(ans, maxVal+1);
		m.clear();
	}
	return ans;
}

int main(){
	int n; cin >> n;
	vector<pair<int, int> > points;
	int a, b;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		points.push_back(pair<int, int>(a, b));
	}
	int ans = maxPointsOnALine(points, n);
	cout << ans;
}