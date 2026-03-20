//【例题】最长公共子序列
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
typedef long long ll;
ll a[N],b[N];
ll dp[N][N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=m;j++) cin>>b[j];
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
    ll ans=0;
	for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
