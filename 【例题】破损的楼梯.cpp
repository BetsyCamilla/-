//ÏßÐÔdp-ÆÆËðµÄÂ¥ÌÝ
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p=1e9+7;
const int N=1e5+9;
int dp[N];
bool vis[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++) 
	{
		int x;cin>>x;
		vis[x]=true; 
	}
	dp[0]=1;
	if(!vis[1]) dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(vis[i]) dp[i]=0; 
		else dp[i]=(dp[i-1]+dp[i-2])%p;
	}
	cout<<dp[n]<<"\n";
	return 0;
}
