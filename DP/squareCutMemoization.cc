#include<bits/stdc++.h>
using namespace std;

int squareCut(int h, int w, vector<vector<int> > &qb){
    if(h == 0 || w == 0) return 0;

    if(qb[h][w]!=-1) return qb[h][w];
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
        
        int f1 = squareCut(r1hh, r1hw, qb)+squareCut(r2hh, r2hw, qb);
        int f2 = squareCut(r1vh, r1vw, qb)+squareCut(r2vh, r2vw, qb);
        int f = min(f1, f2);
        omin = min(omin, f);
    }
    // omin =0;
    omin++;
    qb[h][w] = omin;
    return omin;
    // return 0;
}

int main(){
    int t; cin >> t;
    while(t--){
        int w, h;
        cin >> w >> h;
        vector<vector<int> > qb;
        for(int i = 0; i <= h; i++){
            vector<int> a;
            for(int j = 0; j <= w; j++){
               a.push_back(-1);
            }
            qb.push_back(a);
        }
        int ans = squareCut(h, w, qb);
        cout << ans << endl;
     }
    return 0;
}