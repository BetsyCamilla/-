//dfs  全球变暖
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
char mp[N][N];
int col[N][N];//表示是否染过色
int scc=0;//颜色
int n;
int ans=0;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool is_island_safe[N*N];
void dfs(int x,int y)
{
	col[x][y]=scc;	
	//染过色 且永远不会沉的
	bool is_safe=true;
	if(col[x][y])
	{
		for(int i=0;i<4;i++)
		{
		   int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx>n||nx<1||ny>n||ny<1) continue;//不能超出边界 
			if(mp[nx][ny]=='.') is_safe=false;
		}
	}
	if(is_safe&&!is_island_safe[scc])
	{
		ans++;
		is_island_safe[scc]=true;
	}
	//没染过色的识别为岛屿那就可以增加一种颜色 
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx>n||nx<1||ny>n||ny<1) continue;//不能超出边界 
			if(mp[nx][ny]=='#'&&!col[nx][ny])
			{
				dfs(nx,ny);
			}
		}
	 } 
 int main()
 {
 	cin>>n;
 	for(int i=1;i<=n;i++)
 	{
 		for(int j=1;j<=n;j++)
 		{
 			cin>>mp[i][j];
		 }
	 }
	for(int i=1;i<=n;i++)
 	{
 		for(int j=1;j<=n;j++)
 		{
 			if(mp[i][j]=='#'&&!col[i][j])
 			{
 				scc++;
				 dfs(i,j);
			 }
		 }
	 }
	 cout<<scc-ans<<'\n';
	 return 0;
	 
 }
