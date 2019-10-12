//FORD_FULKERSON MAX FLOW
#include<bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;

using namespace std;
int n,m;
int graph[1000][1000]={0};
int paths[1000][1000]={0};
int parent[1000] = {0};
bool findpath(int s, int t)
{
	bool visited[1000];
	memset(visited,false,sizeof(visited));
	queue<int> q;
	q.push(s);
	parent[s] = -1;
	visited[s]=true;
	while(!q.empty())
	{
		int top = q.front();
		q.pop();
        if(top == t ) break;
		for(int i=1;i<=n;++i)
		{
			if(paths[top][i]>0 && visited[i]==false)
			{
				q.push(i);
				visited[i]=true;
				parent[i]=top;
			}
		}
	}
	return (visited[t]==true) ;
}

int ford(int s,int t)
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			paths[i][j]=graph[i][j];
    int maxflow = 0;
 	while(findpath(s,t))
	{
 		int minpath=INT_MAX;
		for(int i=t;i!=s;i=parent[i])
		{
			int u = parent[i];
			minpath = min(minpath,paths[u][i]);
		}
		for(int i=t;i!=s;i=parent[i])
		{
			int u = parent[i];
			paths[u][i] -= minpath;
			paths[i][u] += minpath;
		}
		maxflow += minpath;
	}
	return maxflow;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		int x,y;
		cin>>x>>y;
		cin>>graph[x][y];
	}
	cout<<ford(1,n)<<endl;

}	