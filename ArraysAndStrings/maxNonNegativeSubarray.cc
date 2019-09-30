#include<bits/stdc++.h>
using namespace std;

vector<int> Solution(vector<int> &arr) {
    vector<int> ansv;
    int n = arr.size();
    int s = 0, e = 0;
    int anss = s, anse = e;
    long long int ans = 0, max = -1;
    int c = 0;
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] >= 0){
            if(flag  == 0){
                s = i; e = i;
                flag = 1;
            }
            else e = i;
            ans+=(long long)arr[i];
        }
        else{
            if(ans > max){
                max = ans;
                anss = s; anse = e;
                
            }
            ans = 0;
            flag = 0;
           c++;
        }
    }
    if(ans > max){
                max = ans;
                anss = s; anse = e;
                
            }
    
    if(max == 0 && c == n) return ansv;
    for(int i = anss; i <= anse; i++){
        ansv.push_back(arr[i]);
        cout << arr[i] << " ";
    }
    return ansv;
}

int main(){
    int n; cin >> n;
    vector<int> arr;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        arr.push_back(a);
    }
    vector<int> ans = Solution(arr);
}