//dfs ºÙ÷¶ Ãÿ ‚∂‡±ﬂ–Œ
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int cnt[N];
int prefix[N];
void dfs(int dep,int st,long long mul,long long sum)
{
	if(mul>1e5) return;
	if(dep==n+1) 
	{
		if(st<sum-st){
		cnt[mul]++;
	}
		return;
	}
	int up=pow(1e5/mul,1.0/(n-dep+1))+2;
	for(int i=st+1;i<up;i++)
	{
		dfs(dep+1,i,mul*i,sum+i);
	}
}
 int main()
 {
 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	 int t;
	 cin>>t>>n;
	 dfs(1,0,1,0);
	 for(int i=1;i<1e5;i++) prefix[i]=prefix[i-1]+cnt[i];
	 while(t--)
	 {
	 	int x,y;
	 	cin>>x>>y;
	 	cout<<prefix[y]-prefix[x-1]<<'\n';
	 }
	 return 0;
 }
