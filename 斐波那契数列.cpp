//dfs 记忆化搜索
#include<bits/stdc++.h>
using namespace std;
const int N=35;
int dp[N];
int dfs(int x)//表示深度 
{
	if(x<=1) return x;
	if(dp[x]!=-1) return dp[x];
	return dp[x]=dfs(x-1)+dfs(x-2);
	
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(dp,-1,sizeof dp);
	int t;
	cin>>t;
	while(t--)
	{
		int x;
		cin>>x;
		cout<<dfs(x)<<'\n';
	}
	return 0;
}
