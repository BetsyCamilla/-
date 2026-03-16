//µç³ØµÄÑ¡Ôñ
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
typedef long long ll;
int n;
ll a[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i =1;i<=n;i++) cin>>a[i]; 
	sort(a+1,a+1+n,[](const ll &n,const ll &m)
	{
		return n>m;
	});
	ll max_p=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		 {
		 ll ans=a[i]*a[j]+a[i]-a[j];
	        max_p=max(max_p,ans);
	 }
}
	cout<<max_p<<'\n';
	return 0;
}
