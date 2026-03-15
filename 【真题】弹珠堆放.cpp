//弹珠堆放
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll prefix[N];
ll wprefix[N];
int main()
{
   ll target = 20230610;
	for(int i = 1; i < N; i++) {
        prefix[i] = prefix[i-1] + i;
        wprefix[i] = wprefix[i-1] + 1LL*i*i;
    }
 int l = 1, r = N-1, ans = 0;
    while(l <= r) {
        int mid = (l + r)/2;
        ll sum = (mid+1)*prefix[mid] - wprefix[mid];
        if(sum <= target) {
            ans = mid;  // mid 符合条件，尝试更大
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl; // 输出满足条件的最大 k
    return 0;
}
