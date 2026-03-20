//¶þÎ¬DP-°Ú»¨ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
ll dp[N][N];
ll a[N];
ll p=1e6+7;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
    	for(int j=0;j<=m;j++)
    	{
    		for(int k=0;k<=a[i]&&k<=j;k++)
    		{
    			dp[i][j]=(dp[i][j]+dp[i-1][j-k])%p;
			}
		}
	}
	cout<<dp[n][m]<<"\n";
	return 0;
	
}
