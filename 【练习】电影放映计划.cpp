//【练习】电影放映计划
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6,M = 200;
int dp[N],m,n,t[M],w[M],k;
int main()
{
    cin>>m>>n;
    for(int i = 0; i < n; i ++) cin>>t[i]>>w[i];
    cin>>k;
    m += k;
    for(int i = 1; i <= m; i ++) {
        dp[i] = dp[i - 1];
        for(int j = 0; j < n; j ++) {
      if(i >= t[j] + k)
              dp[i] = max(dp[i], dp[i - t[j] - k] + w[j]);
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}
