#include<bits/stdc++.h>
using namespace std;

int mustang(int petrol[], int dist[], int n){
     if(n == 1){
        if(petrol[0]-dist[0] >= 0){
            return 0;
        }
    }
    else{
    int i = 0, j = 0, spare = petrol[j]-dist[j]; j++;
    while(true){
        if(spare >= 0){
            if(i == j){
                return i;
            }
            else{
                spare = spare+petrol[j]-dist[j];
                j=(j+1)%n;
            }
        }
        else{
            if(i>=j){
                return -1;
            }
            else{
                i = j;
                spare = petrol[j]-dist[j];
                j=(j+1)%n;
            }
        }
    }
    }
}

int main(){
    int n; cin >> n;
    int petrol[n], dist[n];
    for(int i = 0; i < n; i++){
        cin >> petrol[i];
    }
    for(int i = 0; i < n; i++){
        cin >> dist[i];
    }
    
    int ans = mustang(petrol, dist, n);
    cout << ans;
    
}