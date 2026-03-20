//二维DP-数字三角形
#include<bits/stdc++.h>
using namespace std;
const int N=105;
typedef long long ll;
ll a[N][N],dp[N][N][N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=i;j++)
		{
			for(int k=0;k<=n-i;k++)
			{
			  if(k>=1)	dp[i][j][k]=a[i][j]+max(dp[i+1][j+1][k-1],dp[i+1][j][k]);
			  else dp[i][j][k]=a[i][j]+dp[i+1][j][k];
			}
		}
	}
	if(n&1) cout<<dp[1][1][(n-1)/2];
	else cout<<max(dp[1][1][(n-1)/2],dp[1][1][n-1-(n-1)/2]);
	return 0;
}
 
