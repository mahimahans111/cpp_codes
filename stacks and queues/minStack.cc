#include<bits/stdc++.h>
using namespace std;

class splStack{
    stack<int>s;
    int min;
    
 public:
    void Push(int x){
        if(s.empty()){
            s.push(x);
            min = x;
        }
        else{
            if(x>=min){
                s.push(x);
            }
            else{
                s.push(x+x-min);
                min = x;
            }
        }
    }
    int Pop(){
        if(s.empty()) return -1;
        if(s.top()>=min){
            int ans = s.top();
            s.pop();
            return ans;
        }
        else{
            int ans = min;
            min = 2*min-s.top();
            s.pop();
            return ans;
        }
    }
    
    // void Pop(){
    //     if(s.empty()) return;
    //     if(s.top()>=min){
    //         s.pop();
    //     }
    //     else{
    //         min = 2*min-s.top();
    //         s.pop();
    //     }
    // }
    // int Top(){
    //     if(s.empty())return -1;
    //     if(s.top() >= min){
    //         return s.top();
    //     }
    //     else{
    //         return min;
    //     }
    // }
    int GetMin(){
        if(s.empty()) return -1;
        return min;
    }
};

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    splStack s;
    int i=0;
 	 	 while(i<n){
 	 	 	 if(a[i]==1){
 	 	 	 	 i++;
 	 	 	 	 s.Push(a[i]);
 	 	 	 }
 	 	 	 else if(a[i]==2){
 	 	 	    
 	 	 	 	cout << s.Pop() << endl;
 	 	 	 }
 	 	 	 else if(a[i]==3){
 	 	 	 	cout << s.GetMin() << endl;
 	 	 	 }
 	 	 	 i++;
 	 	 }
}