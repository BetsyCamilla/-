//泡澡
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
ll w;
ll diff[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		int s,t;
		ll p;
		cin>>s>>t>>p;
	     diff[s]+=p;
	     diff[t]-=p;
	}
	ll cur=0;
	for(int i=0;i<=2e5;i++) 
	{
		cur+=diff[i];//使用前缀和还原 
		if(cur>w)
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
}
