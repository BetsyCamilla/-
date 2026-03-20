//二维DP-选数异或
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+9;
ll p=998244353;
ll a[N],prefix[N];
ll dp[N][70];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,x;cin>>n>>x;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<64;j++)
		{
			dp[i][j]=(dp[i-1][j]+dp[i-1][j^a[i]])%p;
		}
	}
	cout<<dp[n][a[n]]<<"\n";
	return 0;
}
 
