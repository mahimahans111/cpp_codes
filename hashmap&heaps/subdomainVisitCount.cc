#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 
class myComparator{
public:
    bool operator()(pair<string, string>a, pair<string, string> b){
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
void subdomainVisits(vector<string> cpdomains) {
     //Write your code here
    map<string, int> m;
    for(int i = 0; i < cpdomains.size(); i++){
        string str = cpdomains[i];
        int j = 0;
        int curf = 0;
        while(str[j] >= '0' && str[j] <= '9'){
            curf=curf*10+int(str[j]-'0');
            j++;
        }
        int curj = j;
        // cout << curf <<endl;
        j = str.size()-1;
            string cur="";
        while(j > curj){
                while(str[j]!='.' && j > curj){
                string ansss = "";
                ansss+=str[j];
                ansss+=cur;
                cur = ansss;
                j--;
            }
            if(m.count(cur))m[cur]+=curf;
            else m[cur] = curf;
            // cout << cur << endl;
            if(str[j] == '.'){
                string ansss = "";
                ansss+=str[j];
                ansss+=cur;
                cur = ansss;
            }
            j--;
        }
    }

    priority_queue<pair<string, string>, vector<pair<string, string> >, myComparator> pq;
    for(map<string, int> :: iterator it = m.begin(); it != m.end(); it++){
        // it->first = reverse(it->first);
        pq.push(pair<string, string>(to_string(it->second), it->first));
    }
    cout << '[';
    int flag = 0;
    while(!pq.empty()){
        if(flag == 0){
            cout << pq.top().first << " "<< pq.top().second;
            flag = 1;
        }
        else
        cout << ", " << pq.top().first << " " << pq.top().second;
        pq.pop();
    } 
    cout << ']';
 }
 
 //Don't make any changes here
 int main(int argc, char** argv){
     int n;
     // string sn;
     // getline(cin, sn);
     // n = stoi(sn);
     cin >> n;
     int k;
     // cin >> k;
     // cin.get();
     vector<string> cpd;
     string s;
     int i = 0;
     getline(cin, s);
     for(int i=0; i<n; i++) {
         string s;
         getline(cin, s);
         // std::cout<<"";
         cpd.push_back(s);
     }
    subdomainVisits(cpd);
     // sort(ans.begin(), ans.end());
     // for(int i = 0; i < ans.size(); i++){
     //     cout<<ans[i]<<" ";
     // }
     // for(int i = 0; i < cpd.size(); i++){
     //    cout << cpd[i] << " ";
     // }
 }