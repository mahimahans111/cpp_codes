#include<bits/stdc++.h>
using namespace std;

double euclideanDist(int x1, int y1, int x2, int y2){
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main(){
	int n, k;
	cin >> n >> k;
	int x[1000], y[1000], r[1000];
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i] >> r[i];
	}
	int m;
	for(int q = 0; q < k; q++){
		cin >> m;
	int goodCircles = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			double distBnCentres = euclideanDist(x[i], y[i], x[j], y[j]);
			double radialSum = r[i] + r[j];
			double minDist, maxDist;
			if(distBnCentres < max(r[i], r[j])){
				 minDist = max(r[i], r[j]) - distBnCentres - min(r[i], r[j]);
				 maxDist = distBnCentres + radialSum;
			}
			else{
			 minDist = distBnCentres - radialSum;
			 maxDist = distBnCentres + radialSum;}
			if(double(m) >= minDist && double(m) <= maxDist) goodCircles++;
					}
	}
	cout << goodCircles << endl;
} 
}