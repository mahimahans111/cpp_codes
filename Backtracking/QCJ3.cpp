#include<bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define ll long long int
#define S(x) scanf("%d",&x);
using namespace std;
void driver()
{
	int N;
	S(N);
	int ans=0;
	for(int i=1;i<=N;++i)
	{
		int x;
		S(x);
		if(x%2==1) ans^=i;
	}
	if(ans==0) cout<<"Hanks Wins\n";
	else cout<<"Tom Wins\n";
}
int main()
{
	int t;
	S(t);
	while(t--)
		driver();
}