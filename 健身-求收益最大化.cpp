//健身【算法赛】
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
typedef long long ll;
ll dp[N];//当前的日子 
bool vis[N];//表示当前是否ok？ true为不ok 
int sum[N] = {0}; // 前缀和
ll d[N],s[N];
ll max_s[25]; // 存储每个 2^k 长度对应的最大收益
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,q;cin>>n>>m>>q;
	for(int j=1;j<=q;j++)
	{
		int x;cin>>x;
		vis[x]=true;
	}
	for(int i=1;i<=n;i++) sum[i] = sum[i-1] + (vis[i]?1:0);
	memset(max_s, 0, sizeof(max_s));
	for(int i=1;i<=m;i++)
	{
		int k;ll s;
		cin>>k>>s;
		max_s[k]=max(max_s[k],s);
	}
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{ 
		dp[i]=dp[i-1];
		if(vis[i]) continue; 
		for(int k=0;k<=20;k++)
		{
			if(max_s[k]==0) continue;
			ll len=(1ll<<k);
			if(i >= len && sum[i] - sum[i-len] == 0){
                dp[i] = max(dp[i], dp[i-len] + max_s[k]);
			}
		}
	}
	for(int j=n;j>=1;j++)
	{
		if(!vis[j])
		{
		 cout<<dp[j]<<"\n";
		 break;	
		}
	}
	return 0;
}
