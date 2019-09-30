#include<iostream>
#include<stack>
   using namespace std;
   
   class Pair{
       public:
       int data;
       int level;
       int state;
       
       Pair(int d, int l, int s){
           data = d;
           level = l;
           state = s;
       }
   };
   
   int NodesOfKLevel(string arr, int k){
       stack<Pair> s;
       int ans = 0;
       for(int i = 0; i < arr.length(); i++){
           if(arr[i] == '(') continue;
           else if(arr[i] >= '0' && arr[i] <= '9'){
              
               int no = 0;
               while(arr[i] >= '0' && arr[i] <= '9'){
                   no=no*10+int(arr[i]-'0');
                   i++;
               }
               i--;
               if(s.empty()){
                   Pair n = Pair(no, 0, 0);
                   if(n.level == k)ans += n.data;
                   s.push(n);
               }
               else{
              Pair P = s.top();
              Pair n = Pair(no, P.level+1, 0);
              if(n.level == k)ans += n.data;
              s.pop();
              if(P.state <=1){
                  P.state ++;
                 
              }
               s.push(P);
              s.push(n);
               }
           }
           
           else if(arr[i] == ')'){
               Pair P = s.top();
               s.pop();
               if(P.state <= 1){
                   P.state++;
                   s.push(P);
               }
           }
       }
       return ans;
   }
   
   int main(int argc, char** argv){
       int k; cin >> k;
       string str; cin >> str;
       int ans = NodesOfKLevel(str, k);
       cout << ans;
   }