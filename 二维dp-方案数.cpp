//建造房屋
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p=1e9+7;
int dp[55][55*55];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,K;cin>>n>>m>>K;
	for(int i=0;i<=K;i++) dp[0][i]=1;//从成本0到K 每个都算一个方案 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=i-1;k<=K-1;k++)
			{
				dp[i][j+k]=(dp[i-1][k]+dp[i][j+k])%p;
			}
		}
	}
	cout<<dp[n][K]<<"\n";
	return 0;
} 
