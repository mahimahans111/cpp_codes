#include<bits/stdc++.h>
using namespace std;

class QUsing2S {
 
        stack<int>s1, s2;
        public:
         QUsing2S() {

         }
 
         void push(int x) {
             s1.push(x);
         }
 
         int pop() {
             while(!s1.empty()){
                 s2.push(s1.top());
                 s1.pop();
             }
             int ans =  -1;
            if(!s2.empty()) {ans = s2.top();
             s2.pop();}
             while(!s2.empty()){
                 s1.push(s2.top());
                 s2.pop();
             }
             return ans;
         }
 
         int peek() {
             while(!s1.empty()){
                 s2.push(s1.top());
                 s1.pop();
             }
             int ans = -1;
             if(!s2.empty()) ans = s2.top();
             while(!s2.empty()){
                 s1.push(s2.top());
                 s2.pop();
             }
             return ans;
         }
 
         bool empty() {
             if(s1.size() == 0) return true;
             return false;
         }
 
     };


 int main(){
     int n; cin >> n;
     QUsing2S Qu;
      for(int i=0;i<n;i++){
             int q; cin >> q;
             if(q==1){
                 int a; cin >> a;
                 Qu.push(a);
             }
             else if(q==2){
                 cout << Qu.pop() << " ";
             }
             else if(q==3){
                cout << Qu.peek() << " ";
             }
             else if(q==4){
                 if(Qu.empty())cout << "true" << " ";
                 else cout << "false" << " ";
               }
         }
 }
