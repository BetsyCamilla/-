//“至少一半长度”，是中点法的近似
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;   //数据范围：1e6 * 2 （由下可知为什么乘以2）
int a[N] , s[N];

int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n , m;
  cin >> n >> m;
  while(n--){
    int l , r;
    cin >> l >> r;
    a[l + r]++; //取中点（至少一半），为避免像1/2这样的小数，所以直接乘以2（ (l + r) / 2 * 2 ）
  }

  for(int i = 1 ; i <= N ; i++) s[i] = s[i - 1] + a[i];

  while(m--){
    int l , r;
    cin >> l >> r;
    cout << s[r * 2] - s[l * 2 - 1] << endl;  //与上面相应的，这里也要乘以2
  }
  return 0;
}
