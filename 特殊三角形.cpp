//dfs 剪枝 特殊三角形
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int cnt[N];
int prefix[N];
void dfs(int dep,int st,long long mul,int sum)//dep 为探索三角形的边数；st 一开始的数字，mul为乘积，sum为总和 
{
	if(mul>1e6) return;
	if(dep==4)
	{
		cnt[mul]++;
		return;
	}
	int up=pow(1e6/mul,1.0/(4-dep))+1;//稍微多加一点即可 
	for(int i=st+1;i<(dep==3?sum:up);i++)
	{
		dfs(dep+1,i,mul*i,sum+i);
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	dfs(1,0,1,0);
	for(int i=1;i<=1e6;i++) prefix[i]=prefix[i-1]+cnt[i];
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		cout<<prefix[y]-prefix[x-1]<<'\n';
	}
	return 0;
}

