#include<bits/stdc++.h>
using namespace std;

vector<int> flip(string str){
    int maxi = 0;
    int maxs = 0, maxe = 0;
    int flag = 0;
    if(str[0] == '0'){
        maxi = 1;
        maxs = 0; maxe = 0;
        flag = 1;
    }
    int ansi = 0, anss = 0, anse = 0;
    for(int i = 1; i < str.length(); i++){
        if(str[i] == '1' && str[i-1] == '0'){
            if(ansi > maxi){
                maxi = ansi;
                maxe = anse;
                maxs = anss;
            }
            flag = 0;
        }
        else if(str[i] == '0' && flag == 1){
            ansi++;
            anse = i;
        }
        else if(str[i] == '0' && flag == 0){
            flag = 1;
            ansi = 1;
            anss = i; anse = i;
        }
    }
    vector<int> ans;
    if(maxi == 0) return ans;
    ans.push_back(maxs);
    ans.push_back(maxe);
    return ans;

}

int main(){
    string str; cin >> str;

    vector<int> ans = flip(str);
    cout << ans[0] << " " << ans[1] << endl;
}