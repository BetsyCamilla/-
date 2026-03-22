//保险箱
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int N = 1e5 + 9;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    string s1,s2;
   cin>>n>>s1>>s2;
   reverse(s1.begin(), s1.end());
reverse(s2.begin(), s2.end());
	ll dp[n+1][3];//第几位 +状态 
for(int i=0;i<=n;i++)
    for(int j=0;j<3;j++)
        dp[i][j] = INF;

	dp[0][1]=0; 
for (int i = 0; i <n; i++) {
    int a = s1[i] - '0';
    int b = s2[i] - '0';
 for(int j=-1;j<=1;j++)
 {
 	if (dp[i][j] >=INF) continue;
 	int cur=a+j;
 	if(cur<0)cur+=10;
	 if(cur>=10) cur-=10; 
 	int up=(b-cur+10)%10;
 	int nup=(cur+up>=10)?1:0;
 	dp[i+1][nup+1]=min(dp[i+1][nup+1],dp[i][j+1]+up);
	 int down=(cur-b+10)%10;
 	int ndown=(cur-down<0)?-1:0;
dp[i+1][ndown+1] = min(dp[i+1][ndown+1], dp[i][j+1] + down);
}
}
ll ans=1e9;
for(int j=-1;j<=1;j++) ans=min(ans,dp[n][j+1]);
cout<<ans<<"\n";
return 0;
}
 
