//【例题】小明的背包1
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9;
int dp[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,V;cin>>n>>V;
	for(int i=1;i<=n;i++)
	{
		int w,v;cin>>w>>v;
		for(int j=V;j>=w;j--)
		{
			dp[j]=max(dp[j],dp[j-w]+v);
		}
	}
	cout<<dp[V]<<"\n";
	return 0;
}
