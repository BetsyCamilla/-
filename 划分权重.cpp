//【真题】划分权重
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[400010];
int a[40]={
5160, 9191, 6410, 4657, 7492, 1531, 8854, 1253, 4520, 9231,

1266, 4801, 3484, 4323, 5070, 1789, 2744, 5959, 9426, 4433,

4404, 5291, 2470, 8533, 7608, 2935, 8922, 5273, 8364, 8819,

7374, 8077, 5336, 8495, 5602, 6553, 3548, 5267, 9150, 3309, 
	};
int main()
{
	
	int total=0;
	for(int i:a) total+=i;
	dp[0]=1;
	for(int i=0;i<40;i++)
	{
		for(int j=total;j>=a[i];j--)
		{
			dp[j]|=dp[j-a[i]];
		}
	}
	ll ans=0;
	for(int i=0;i<=total;i++)
	{
	 if(dp[i]) ans=max(ans,1ll*i*(total-i));	
	}
	cout<<ans<<"\n";
	return 0;
}
