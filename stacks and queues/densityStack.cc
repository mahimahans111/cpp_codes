#include<bits/stdc++.h>
using namespace std;

class DensityStack{
  unordered_map<int, int> m;
   stack<pair<int, int>> s1, s2; 
    int ind = 0;
    public:
    void push(int x){
        if(m.count(x)){
            m[x]++;
        }
        else m[x] = 1;
        s1.push(pair<int, int>(x, ind));
        ind++;
    }
    
    int pop(){
        int max = 0;
        int 
        for(unordered_map<int, int> :: iterator it = m.begin(); it!=m.end(); it++){
            if(it->second > max) max = it->second;
        }
        int minind = INT_MAX;
        int ans;
        while(!s1.empty()){
            if(s1.top().first == max){
                if(s1.top().second < minind){
                    minind = s1.top();
                    ans = s1.top().first;
                }
            }
            
        }
    }
        
};

int main(){
    
}