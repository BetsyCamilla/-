//Ğ¤¶÷µÄÍ¶ÇòÓÎÏ·
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int d[N];
void sovle(int n,int q)
{
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
	while(q--)
	{
	 int l,r,c;
	 cin>>l>>r>>c;
	 d[l]+=c,d[r+1]-=c;	
	}
	for(int i=1;i<=n;i++) a[i]=a[i-1]+d[i];
	for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	sovle(n,q);
	return 0;
}
