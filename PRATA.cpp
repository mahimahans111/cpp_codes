#include<bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define ll long long int
#define S(x) scanf("%d",&x);
using namespace std;
int ranks[55]={0}, p, cooks, minn=10;
int maxTime(int m, int k)
{
	float a = (float)(2*k)/(float)m;
	float x = (float)(-1 + sqrt(1+4*a))/2;
	int ans = (int)floor(x);
	return ans;
}
int check(int k)
{
	int cp=0;
	for(int i=0;i<cooks;++i)
		cp+=maxTime(ranks[i], k);
	return cp;
}

int bs(int p)
{
	int lo=minn, hi=10000007, result=0;
	
	while(lo<=hi)
	{
		int mid = lo + (hi-lo)/2;
		if(check(mid)>=p)
		{
			result = mid;
			hi=mid-1;
		}
		else lo = mid+1;
	}
	return result;
}

void driver()
{
	S(p);
	S(cooks);
	for(int i=0;i<cooks;++i)
	{
		S(ranks[i]);
		if(ranks[i]<minn) minn=ranks[i];
	}
	printf("%d\n", bs(p));
}

int main()
{
	int t;
	S(t);
	while(t--)
	{
		driver();
	}	
	
}