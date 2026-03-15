#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e7+7;
ll a[N],b[N];
ll n,m,t,k;

void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>t;
        if (t > 0) a[t]++;
        else if (t < 0) b[-t]++;
        else a[0]++; // 0Ö»ËãÒ»´Î
    }
    for(int i=1;i<=m;i++)    a[i]=a[i-1]+a[i],b[i]=b[i-1]+b[i];
    ll ans=0;
	for(int j=0;j<=m;j++)   
	{
		ll res=m-j;
		if(res <0) break;
		ans=max(ans,min(a[j],j)+min(b[res],res));
	}
     cout<<ans;
    return ;
}

int main() {
    solve();
    return 0;
}
