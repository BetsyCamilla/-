//【例题】蓝桥勇士
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9;
typedef long long ll;
ll a[N],dp[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		dp[i]=1;
		for(int j=1;j<i;j++)
		{
			if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]+1);//自成一列 或者是 加入前人 （但是得先给每个自成一列初始化1） 
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<ans<<"\n";
	return 0;
}
