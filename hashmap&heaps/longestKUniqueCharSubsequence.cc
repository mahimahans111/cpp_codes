#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 void print(string &str, int k) {
 	 //Write your code here
 	 int s = 0;
	int e = 0;
	int ans = 0;
	int max = 0;
	unordered_map<char, int> m;	
	while(s <= e && e < str.length()){
		if(m.find(str[e]) == m.end()){
			// cout << e << " " << str[e] << endl;
			m[str[e]] = 1;
			e++;
		}
		else {
			m[str[e]]++;
			e++;
		}
		if(m.size() == k) {
		    	if(e-s > max) max = e-s;
		}
			if(m.size() > k){
				    e--; m.erase(str[e]);
				    break;
				}
		
	}
// 	if(e-s > max) max = e-s;

	// cout << max << endl;
	while(s <= e && e < str.length()){
	    		while(s <= e && e < str.length()){
				if(m[str[s]]==1)m.erase(str[s]);
				
				else m[str[s]]--;
				s++;
				if(m.size() < k) break;
			}
			
			while(s <= e && e < str.length()){
				if(m.count(str[e])){
					m[str[e]]++;
					e++;
				}
				else{
					m[str[e]] = 1;
					e++;
				}
				
				if(m.size() == k){
				    if(e-s > max) max = e-s;
				}
				
				if(m.size() > k){
				    e--; m.erase(str[e]); 
				    break;
				}
			}
 }
cout << max;
	}

 
 int main(int argc,char** argv){
     string s;
     cin>>s;
     int k;
     cin>>k;
     print(s,k);
 }