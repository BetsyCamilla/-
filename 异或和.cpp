//“ÏªÚ∫Õ
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
ll a[N];
ll ans=0;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
    for(int k=0;k<31;k++)
    {
    	ll sum0=0,cnt0=0;
    	ll sum1=0,cnt1=0;
		for(int j=1;j<=n;j++)
    	{
    		if((a[j]>>k)&1)
    		{
    			ans+=(j*cnt0-sum0)*(1ll<<k);
    			cnt1++;
    			sum1+=j;
			}
			else
			{
				ans+=(j*cnt1-sum1)*(1ll<<k);
				cnt0++; 
				sum0+=j;
			}
		}
	}
 cout<<ans;
 return 0;
}
