#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int count = 0;

    // 我们需要三个三个地看，所以循环到 n-2 即可
    for (int i = 0; i <= n - 3; ) {
        // 取出当前位置开始的三个字符
        string sub = s.substr(i, 3);
        
        // 给这三个字符排序
        sort(sub.begin(), sub.end());

        // 如果排序后是 "blq"，说明它是 6 种排列中的一种
        if (sub == "blq") {
            count++;    // 找到一个，计数加 1
            i += 3;     // 【关键】跳过这三个字符，防止重叠切割
        } else {
            i += 1;     // 没找到，就只往后挪一位继续看
        }
    }

    cout << count << endl;

    return 0;
}
