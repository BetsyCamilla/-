//【练习】可构造的序列总数
#include<bits/stdc++.h>
using namespace std;
const int N = 2005; // 长度和数值上限
typedef long long ll;
ll p = 1e9 + 7;

// dp[长度][当前这个数字是谁]
ll dp[N][N]; 

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k, n;
    cin >> k >> n; // k 是数值上限，n 是序列长度
    // 每一个数 j 作为开头，都算 1 种方法
    for(int j = 1; j <= k; j++) {
        dp[1][j] = 1;
    }
    for(int i = 2; i <= n; i++) // i 代表当前是序列的第 i 个位置
    {
        for(int prev = 1; prev <= k; prev++) // 遍历上一个位置的数字
        {
            if(dp[i-1][prev] == 0) continue; // 没方案就跳过

            // cur 只能是 prev 的倍数 (prev, 2*prev, 3*prev...)
            for(int cur = prev; cur <= k; cur += prev) 
            {
                // 把上一步的方案数累加到当前这一步的倍数位置
                dp[i][cur] = (dp[i][cur] + dp[i-1][prev]) % p;
            }
        }
    }

    // 把长度为 n 时，以所有数字结尾的情况都加起来
    ll ans = 0;
    for(int j = 1; j <= k; j++) {
        ans = (ans + dp[n][j]) % p;
    }

    cout << ans << "\n";
    return 0; 
}
