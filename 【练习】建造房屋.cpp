//【练习】建造房屋
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p=1e9+7;
const int N=55;
ll dp[N][N*N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,K;
	cin>>n>>m>>K;
	for(int i=0;i<=K;i++) dp[0][i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=i-1;k<=K-1;k++)//前i-1个街道建了至少i-1个房屋 至多K-1 （因为当前街道至少建一个） 
			{
				dp[i][j+k] = (dp[i][j+k] + dp[i-1][k]) % p;
			}
		}
    }
cout << dp[n][K] << "\n";
	return 0;
}
