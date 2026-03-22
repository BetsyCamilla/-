//°æ’ÊÃ‚°øÌ¿¬Î≥∆÷ÿ
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
typedef long long ll;
bool dp[105][N];
ll a[105];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	ll total=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		total+=a[i];
	}
	dp[0][0]=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=total;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j>=a[i]) dp[i][j]|=dp[i-1][j-a[i]];
			if(j+a[i]<=total) dp[i][j]|=dp[i-1][j+a[i]];
			if(a[i]>=j) dp[i][j]|=dp[i-1][a[i]-j];
		}
	}
	ll ans=0;
	for(int i=1;i<=total;i++)
	{
		if(dp[n][i]) ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
