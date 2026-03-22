//¡¾Á·Ï°¡¿µ¹Ë®
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9;
typedef long long ll;
ll dp[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int a,b,c,d,e;cin>>a>>b>>c>>d>>e;
		for(int j=m;j>=0;j--)
		{
			
			ll res=dp[j]+e; 
			if(j>=a)
			{
				res=max(res,dp[j-a]+b);
			}
			if(j>=c)
			{
				res=max(res,dp[j-c]+d);
			}
		   dp[j]=res;
		}
	}
	cout<<dp[m]<<"\n";
	return 0;
}
