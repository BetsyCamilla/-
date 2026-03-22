//完全背包（正序遍历）当前可以重复
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9;
int dp[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int w,v;cin>>w>>v;
		for(int j=w;j<=m;j++)
		{
			dp[j]=max(dp[j],dp[j-w]+v);
		}
	}
	cout<<dp[m]<<"\n";
	return 0;
 } 
