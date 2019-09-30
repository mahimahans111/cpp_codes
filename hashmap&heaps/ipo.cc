#include<bits/stdc++.h>
using namespace std;

class Project{
public:
	int cap;
	int prof;
	Project(int c,int p){
		cap = c;
		prof = p;
	}
	Project(){

	}
};

bool ProjectCapitalComparator(Project one, Project two){
	return one.cap < two.cap;
}

struct ProjectProfitComparator{
	bool operator()(const Project& one, const Project & two){
		return one.prof < two.prof;
	}
};

int main(){
	int k; cin >> k;
	int tcap; cin >> tcap;
	int n; cin >> n;
	int profs[n];
	for(int i = 0; i < n; i++){
		cin >> profs[i];
	}
	int caps[n];
	for(int i = 0; i < n; i++){
		cin >> caps[i];
	}
	Project projs[n];
	for(int i = 0; i < n; i++){
		projs[i].prof = profs[i];
		projs[i].cap = caps[i];
	}

	sort(projs, projs+n, ProjectCapitalComparator);

	priority_queue<Project, vector<Project>, ProjectProfitComparator>pq;

	int i = 0;
	for(i = 0; i < n; i++){
		if(projs[i].cap <= tcap){
			pq.push(projs[i]);
		}
		else break;
	}
	while(k > 0){
		Project cur = pq.top();
		pq.pop();
		tcap+=cur.prof;

		for(; i < n; i++){
			if(projs[i].cap <= tcap){
			pq.push(projs[i]);
		}
		else break;
		}

		k--;
	}
	cout << tcap;
}