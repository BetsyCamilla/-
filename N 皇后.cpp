//dfs N皇后
#include<bits/stdc++.h>
using namespace std;
const int N=15;
int mp[N][N];
bool vis[N];
bool d1[N];
bool d2[N];//表示同列斜线 这些位置的状态 有还是没有棋子
int n;
int ans=0;
void dfs(int dep)//每行每行放棋子 
{    
	if(dep==n+1)
	{
		ans++;
		return;
	}
    for(int i=1;i<=n;i++)
    {
    	if(!vis[i]&&!d1[dep-i+n]&&!d2[dep+i])
    	{
    		vis[i]=true;
    		d1[dep-i+n]=true;
    		d2[dep+i]=true;
    		dfs(dep+1);
    		vis[i]=false;
    		d1[dep-i+n]=false;
    		d2[dep+i]=false;
		}
	}
 } 
 int main()
 {
 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 	cin>>n;
 	dfs(1);
 	cout<<ans<<"\n";
 	return 0;
 }
 
