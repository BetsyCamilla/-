#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, m;
int stock[N];       // 最终库存量
int diff[N];        // 差分数组
pair<int,int> ops[N];  // 存储每个操作的区间 [L,R]
int prefix1[N];     // 前缀和数组，记录库存为1的数量

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    // 读操作
    for (int i = 1; i <= m; i++) {
        int L, R;
        cin >> L >> R;
        ops[i] = {L, R};
        diff[L] += 1;
        diff[R+1] -= 1;
    }

    // 计算每个商品的库存量
    stock[0] = 0;
    for (int i = 1; i <= n; i++) {
        stock[i] = stock[i-1] + diff[i];
    }

    // 统计原本库存为0的商品数量
    int cnt0 = 0;
    for (int i = 1; i <= n; i++) {
        if (stock[i] == 0) cnt0++;
    }

    // 构建前缀和数组，统计库存为1的商品数量
    prefix1[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix1[i] = prefix1[i-1] + (stock[i] == 1 ? 1 : 0);
    }

    // 输出每个操作去掉后库存为0的商品数量
    for (int i = 1; i <= m; i++) {
        int L = ops[i].first;
        int R = ops[i].second;
        int ones_in_range = prefix1[R] - prefix1[L-1];
        cout << cnt0 + ones_in_range << "\n";
    }

    return 0;
}
