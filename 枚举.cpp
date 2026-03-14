#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int cnt = 0;

    for(int i = 1; i <= n; i++) {
        string s = to_string(i);
        int l = s.size();
        bool flag = true;

        // 从低位到高位遍历
        for(int j = 0; j < l; j++) {
            int digit = s[l - 1 - j] - '0'; // 低位在最右边
            if(j % 2 == 0) { // 奇数位（从低位开始算第1位）
                if(digit % 2 == 0) { // 必须是奇数
                    flag = false;
                    break;
                }
            } else { // 偶数位
                if(digit % 2 != 0) { // 必须是偶数
                    flag = false;
                    break;
                }
            }
        }

        if(flag) cnt++;
    }

    cout << cnt << "\n";
    return 0;
}
#include <iostream>
#include <cmath>    // 开根号要用的“数学工具箱”
#include <iomanip>  // 后面打印大数字用的

using namespace std;

typedef long long ll; // 给 long long 起个短外号

int main() {
    // 1. 准备好咱们的家底
    ll x = 7385137888721LL; // 2x2 的块数
    ll y = 10470245LL;      // 1x1 的块数

    // 2. 算总面积 (注意加 LL 标签防止溢出)
    // 总面积 = 大块数 * 4 + 小块数 * 1
    ll totalArea = x * 4 + y;

    // 3. 算出理论上的最大边长 (开根号)
    // sqrt 返回的是小数，咱们把它转成整数
    ll L = (ll)sqrt((long double)totalArea); 

    // 4. 最关键的“能不能拼成”检查
    // 逻辑：如果边长 L 是奇数，中间必然会剩下 1x1 的空隙，
    // 需要 2*L - 1 个 1x1 的方块才能填满这些缝隙。
    if (L % 2 != 0) {
        if (y < (2 * L - 1)) {
            // 如果小块不够填缝，边长就只能退而求其次，减 1 变成偶数
            L--;
        }
    }

    // 5. 输出结果
    cout << L << endl;

    return 0;
}
