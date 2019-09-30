#include<bits/stdc++.h>
using namespace std;

vector<vector<string> > findDuplicate(vector<string> paths){
	map<string, vector<string> > m;
	 vector<vector<string> > ans;
	for(int i = 0; i < paths.size(); i++){
		string str = paths[i];
		string curPath = "";
		int j = 0;
		while(str[j]!=' '){
			curPath+=str[j];
			j++;
		}
		j++;
		// cout << curPath << endl;
	
		while(j < str.length()){
			string curName = "";
			while(str[j]!='('){
				curName+=str[j];
				j++;
			}
			j++;
			string content = "";
			while(str[j]!=')'){
				content+=str[j];
				j++;
			}
			string final = curPath + "/" + curName;
			// cout << final << " " << content << endl;
			if(m.count(content)){
				m[content].push_back(final);
			}
			else{
				vector<string>v;
				v.push_back(final);
				m[content] = v;
			}
			j++;
			j++;
		}
	}

	int k = 0;
	for(map<string,vector<string> >:: iterator it = m.begin(); it!= m.end(); it++){
			ans.push_back(it->second);
				// cout << endl;
			k++;
		}
		sort(ans.begin(), ans.end());
	return ans;

}

int main(){
	int n; cin >> n;
	string s;
	getline(cin, s);
	vector<string> paths;
       for(int i=0;i<n;i++){
           string s;
           getline(cin, s);
           paths.push_back(s);
       }
   
    vector<vector<string> > ans=  findDuplicate(paths);
       for(int i=0;i<ans.size();i++){
           cout<<"[";
           for(int j=0;j<ans[i].size();j++){
               cout<<ans[i][j];
               if(j!=ans[i].size()-1){
                   cout<<", ";
               }            
           }
           cout<<"]"<<endl;
       }    
}