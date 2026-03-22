//°æ’ÊÃ‚°ø2022
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2025][15];
int main()
{
	int x=2022;
	int K=10; 
	dp[0][0]=1;
	for(int i=1;i<=x;i++)
	{
		for(int k=K;k>=1;k--)
		{
			for(int j=x;j>=i;j--)
			{
				dp[j][k]+=dp[j-i][k-1];
			}
		}
	}
	cout<<dp[2022][10]<<"\n";
	return 0;
}
