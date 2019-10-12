#include<bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define ll long long int
#define S(x) scanf("%d",&x);
using namespace std;
int A[1000000+10]={0};
int n, m, maxx=-1;
	
ll check(int c)
{
	ll sum=0;
	for(int i=0;i<n;++i)
		if(A[i]-c > 0) sum+=(A[i]-c);
	return sum;
}

int bs(ll k)
{
	int lo=0, hi=maxx;
	int result = 0;
	while(lo<=hi)
	{
		int mid = lo + (hi-lo)/2;
		if(check(mid) >= k)
		{
			result = mid;
			lo=mid+1;
		}
		else hi=mid-1;
	}

	cout<<result;
}	

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
		S(A[i]);
		if(maxx<A[i]) maxx=A[i];
	}
	bs(m);
}