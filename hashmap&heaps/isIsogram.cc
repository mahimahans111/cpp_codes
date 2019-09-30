#include <iostream>
 #include <vector>
 #include <string>
 #include <unordered_map>
 #include <unordered_set>
 
 using namespace std;
 
 // --------------------------------------
 bool isIsogram(string &data)
 {
     unordered_set<int> s;
     for(int i = 0; i < data.length(); i++){
         if(s.find(data[i])==s.end()){
             s.insert(data[i]);
         }
         else return false;
     }
     return true;
     // write your code here
 }
 // --------------------------------------
 
 int main()
 {
     string s;
     cin >> s;
 
     if (isIsogram(s))
     {
         cout << "true" << endl;
     }
     else
     {
         cout << "false" << endl;
     }
     return 0;
 }