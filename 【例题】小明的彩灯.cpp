//Ð¡Ã÷µÄ²ÊµÆ
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll a[N];
ll diff[N];
void sovle()
{
	int n,m;
	cin>>n>>m;
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
	for(int i=1;i<=n;i++) cout<<max(0ll,a[i])<<" \n"[i==n];
}

int main()
{
	sovle();
	return 0;
}
