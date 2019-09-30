#include <iostream>
 #include <vector>
 #include <set>
 
 using namespace std;
 
 // -------------------------------------------------------
 void completeTask(int n, int m, vector<int> &comp)
 {
     // Write Your Code here;
     set<int> s;
     for(int i = 1; i <= n; i++){
         s.insert(i);
     }
     for(int i = 0; i < m; i++){
         s.erase(comp[i]);
     }
     int flag = 0;
     vector<int>v1, v2;
     for(set<int>:: iterator it = s.begin(); it!= s.end(); it++){
         if(flag == 0) v1.push_back(*it);
         else v2.push_back(*it);
         flag = 1-flag;
     }
     for(int i = 0; i < v1.size(); i++){
         cout << v1[i] << " ";
     }
     cout << endl;
     for(int i = 0; i < v2.size(); i++){
         cout << v2[i] << " ";
     }
 }
 // -------------------------------------------------------
 
 int main(int argc, char *argv[])
 {
     int n = 0, m = 0;
     cin >> n >> m;
     vector<int> num(m);
     for (int i = 0; i < m; i++)
     {
         cin >> num[i];
     }
     completeTask(n, m, num);
     return 0;
 }