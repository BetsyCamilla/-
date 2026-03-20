2//线性dp-安全序列
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p=1e9+7;
const int N=1e6+9;
ll dp[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	//n-i-1
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		ll res1=dp[i-1];
		ll res2;
		if(i-k-1>=0) res2=dp[i-k-1];
		else res2=1; 
		dp[i]=(res1+res2)%p;
	}
	cout<<dp[n]<<"\n";
	return 0;
}
