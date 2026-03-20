//合唱队形
#include<bits/stdc++.h>
using namespace std;
const int N= 105;
int dpr[N],dpl[N];
int a[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)//前面走 
	{
		dpl[i]=1;
		for(int j=1;j<=i;j++)
		{
			if(a[i]>a[j]) dpl[i]=max(dpl[i],dpl[j]+1);
		}
	 } 
	 	for(int i=n;i>=1;i--)//后面走 
	{
		dpr[i]=1;
		for(int j=i;j<=n;j++)
		{
			if(a[i]>a[j]) dpr[i]=max(dpr[i],dpr[j]+1);
		}
	 } 
	int ans=n;
	for(int i=1;i<=n;i++) ans=min(ans,n-(dpr[i]+dpl[i]-1));
	cout<<ans<<"\n";
	 return 0;	 
}
