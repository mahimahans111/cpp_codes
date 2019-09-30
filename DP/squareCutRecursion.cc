#include<bits/stdc++.h>
using namespace std;

int squareCut(int w, int h){
    if(h == 0 || w == 0) return 0;
    
    int omin = INT_MAX;
    
    for(int x = 1; x <= min(h, w); x++){
        int r1hh = x;
        int r1hw = w-x;
        int r2hh = h-x;
        int r2hw = w;
        
        int r1vh = h-x;
        int r1vw = x;
        int r2vh = h;
        int r2vw = w-x;
        
        int f1 = squareCut(r1hh, r1hw)+squareCut(r2hh, r2hw);
        int f2 = squareCut(r1vh, r1vw)+squareCut(r2vh, r2vw);
        int f = min(f1, f2);
        omin = min(omin, f);
    }
    omin++;
    return omin;
}

int main(){
    int t; cin >> t;
    while(t--){
        int w, h;
        cin >> w >> h;
        int qb[h][w];
        int ans = squareCut(h, w);
        cout << ans << " ";
        cout << min(w, h) << endl;
     }
	return 0;
}