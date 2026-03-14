//dfs 小朋友的崇拜圈
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dfn[N];//储存时间戳
int idx;//给每个标序号
int a[N];
int mindfn;
int dfs(int x)
{
	dfn[x]=++idx;
	if(dfn[a[x]])//如果当前节点崇拜的人已经有时间戳了 
	//那么这个时间戳是要大于等于最开始节点的数（也就是在它右边或其本身） 
	{
		if(dfn[a[x]]>=mindfn) return dfn[x]-dfn[a[x]]+1;
		return 0;
	}
	return dfs(a[x]);
 } 
 int main()
 {
 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 	int n;
 	cin>>n;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i];
	 }
	 int ans=0;
	 for(int i=1;i<=n;i++)
	 {
	 	mindfn=idx+1;
	 	ans=max(ans,dfs(i));
	 }
	 cout<<ans<<'\n';
	 return 0;
 }
