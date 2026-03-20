//蓝桥勇士
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+9;
ll a[N];
ll dp[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		dp[i]=1;//首先就是每个元素 自成一队 
		for(int j=1;j<=i;j++)
		{
			if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]+1);
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<ans<<"\n";
	return 0;
 } 
