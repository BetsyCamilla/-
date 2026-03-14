//操作,结果,物理意义 n=12345678
//n / 10000,1234,取前 4 位（删掉后 4 位）
//n % 10000,5678,取后 4 位（只要余数部分）
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin>>N;
    int master_count = 0;           // 主节点总元素量
    vector<int> follower_sync(N, 0); // 记录每个副节点的同步进度（下标1到N-1）
    string op;
    while (cin >> op) {
        if (op == "add") {
            int element;
            cin >> element; // 虽然输入了具体元素，但我们不需要存它
            master_count++;
        } 
        else if (op == "sync") {
            int follower_id;
            cin >> follower_id;
            // 副节点同步下一个元素，但不能超过主节点的总量
            if (follower_sync[follower_id] < master_count) {
                follower_sync[follower_id]++;
            }
        } 
        else if (op == "query") {
            // 如果只有主节点(N=1)，可见性就是主节点数量
            // 如果有副节点，可见性 = 所有副节点进度的最小值
            if (N == 1) {
                cout << master_count << endl;
            } else {
                int min_sync = master_count; 
                // 从 1 号节点遍历到 N-1 号节点
                for (int i = 1; i < N; i++) {
                    min_sync = min(min_sync, follower_sync[i]);
                }
                cout << min_sync << endl;
            }
        }
    }

    return 0;
}
