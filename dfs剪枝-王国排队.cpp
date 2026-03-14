//dfs剪枝-数字王国之军训排队 
#include<bits/stdc++.h>
using namespace std;
const int N=15;
int a[N];
int n;
vector<int>v[N]; 
bool dfs(int cnt,int dep) //队伍数量 和深度 
{
	if(dep==n+1) return true;
	for(int i=1;i<=cnt;i++)
	{
		bool tag=true;
		for(const auto &j:v[i])
		{
			if(a[dep]%j==0)
			{
				tag=false;
				break;
			}
		}
		 if(!tag) continue;
			v[i].push_back(a[dep]);
			if(dfs(cnt,dep+1)) return true;
			v[i].pop_back();
		}
	return false;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(dfs(i,1))
		{
			cout<<i<<'\n';//找到最小的就直接退出 
			break;
		}
	}
	return 0;
}
