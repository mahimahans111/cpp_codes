  #include<iostream>
  #include<string>
  #include<vector>
  #include<map>
  #include<queue>
  using namespace std;
  vector<int> findAnagrams(string& s,string& p){
    int n = 0;
    for(int i = 0; p[i]!='\0'; i++) n++;
    vector<int>ans;
    map<char, int> pmap;
    for(int i = 0; i < p.length(); i++){
        if(pmap.count(p[i])) pmap[p[i]]++;
        else pmap[p[i]] = 1;
        
    }

    queue<int>q;
    map<char, int> smap;
    int matchcount = 0;
    for(int i = 0; i < n; i++){
     
        q.push(s[i]);
        if(smap.count(s[i])) smap[s[i]]++;
        else smap[s[i]] = 1;
        if(pmap.count(s[i])){
            if(smap[s[i]] <= pmap[s[i]]) matchcount++;
        }
    }
    // cout << matchcount<< " zeroth m";
    if(matchcount == n){
        ans.push_back(0); 
    } 
    for(int i = 1; i < s.length()-p.length()+1; i++){
        //   cout << "Here's cur smap......";
        // for(map<char, int>:: iterator it = smap.begin(); it!= smap.end(); it++){
        //     cout << it->first << "-->" << it->second << "!!!";
        // }
        char cur1 = q.front();
        if(pmap.count(cur1)){
            if(smap[cur1] <= pmap[cur1]){ matchcount--;
                smap[cur1]--;
                if(smap[cur1] == 0){
                    // cout << "cur erased" << cur1 << "....";
                    smap.erase(cur1);}
            }
            else{
                 smap[cur1]--;
                if(smap[cur1] == 0){
                    // cout << "cur erased" << cur1 << "....";
                    smap.erase(cur1);}
            }
        }
      q.pop();
        q.push(s[i+n-1]);
         if(smap.count(s[i+n-1])) smap[s[i+n-1]]++;
        else smap[s[i+n-1]] = 1;
        if(pmap.count(s[i+n-1])){
            if(smap[s[i+n-1]] <= pmap[s[i+n-1]]) {
                matchcount++;
                
            }
        }
        // cout << matchcount << i <<" th mtc   ";
        if(matchcount == n) {
            ans.push_back(i);
        }
    }
    return ans;
  }
  
  int main(int argc,char** argv){
      string s;
      string p;
      cin >> s >> p;
    //   getline(cin,p);
      vector<int> v; 
      v=findAnagrams(s,p);
      cout<<"[";
      int i=0;
      for(i=0;i<v.size();i++){
          cout<<v[i];
          if(i!=v.size()-1){
              cout<<", ";
          }
      }
      cout<<"]"<<endl;
  
  }