// dfs 记忆化搜索
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int h[N][N];
int n,m,k;
int a,b,c,d;
int dp[N][N][2];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int dfs(int x,int y,int t)//t 0表示没用 1表示用了一次 
{
   if(x==c&&x==d) return 1;
   if(dp[x][y][t]!=-1) return dp[x][y][t];
   //没有使用过背包
   for(int i=0;i<4;i++)
   {
   	int nx=x+dx[i];
   	int ny=y+dy[i];
   	if(nx>n||nx<1||ny>m||ny<1) continue;
   	if(h[nx][ny]<h[x][y]) return dp[x][y][0];
   	if(h[x][y]+k>h[nx][ny]) return dp[x][y][1];
   }
   //使用过背包
   if(t){
   for(int i=0;i<4;i++)
   {
   	int nx=x+dx[i];
   	int ny=y+dy[i];
   	if(nx>n||nx<1||ny>m||ny<1) continue;
   	if(h[nx][ny]<h[x][y]) return dp[x][y][0];
   }
}
  return dp[x][y][t];
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	cin>>a>>b>>c>>d;
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>h[i][j];
		}
	}
	cout<<(dfs(1,1,0)?"Yes":"No")<<'\n';
	return 0;
}
