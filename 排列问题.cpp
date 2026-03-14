//排列问题 暴力搜索 
#include<bits/stdc++.h>
using namespace std;
const int N=30;
int n;
int node[N];
int vis[30];
void dfs(int cnt)
{
	if(cnt==n)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<node[i]<<' ';
		}
		cout<<'\n';
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			node[cnt+1]=i;
			vis[i]=1;
			dfs(cnt+1);
			node[cnt+1]=0;
			vis[i]=0;
		}
	}	
 } 
 int main()
 {
 	cin>>n;
 	dfs(0);
 	return 0;
 }
