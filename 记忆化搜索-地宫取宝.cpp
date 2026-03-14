//dfs 记忆化搜索 地宫取宝
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=55;
int n,m,k;
ll dp[N][N][13][13];
int v[N][N];
int dx[]={0,1};
int dy[]={1,0};
ll p=1e9+7;
ll dfs(int x,int y,int u,int mv)//u为手中宝贝的数量
{
	if(x>n||y>m) return 0;
	if(u>k) return 0;
	if(dp[x][y][u][mv]!=-1) return dp[x][y][u][mv];
	if(x==n&&y==m) 
	{
		ll ans=0;
		if(u==k||(u==k-1&&v[x][y]>mv)) ans++;
		return dp[x][y][u][mv]=ans%p;
	}
	ll res=0;
	for(int i=0;i<2;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		res=(res+dfs(nx,ny,u,mv))%p;
		if(v[x][y]>mv) 
		{
			res=(res+dfs(nx,ny,u+1,v[x][y]))%p;
		}
		
	}
	return dp[x][y][u][mv]=res;
 } 
 int main()
 {
 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 	memset(dp,-1,sizeof dp);
	 cin>>n>>m>>k;
	 for(int i=1;i<=n;i++)
 	{
 		for(int j=1;j<=m;j++)
 		{
 			cin>>v[i][j];
 			v[i][j]++;
		 }
	 }
	cout<<dfs(1,1,0,0);
	return 0;
 }
