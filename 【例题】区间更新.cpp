//区间更新
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int diff[N];
void sovle(int n,int m)
{
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) diff[i]=a[i]-a[i-1];
	while(m--)
	{
		int l,r,v;
		cin>>l>>r>>v;
		diff[l]+=v,diff[r+1]-=v; 
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i-1]+diff[i];
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
}

int main()
{
	int n,m;
	while(cin>>n>>m) sovle(n,m);
	return 0;
}
