#include<bits/stdc++.h>
using namespace std;
bool lianxu(string s,int &count)
{
  if(s[2]-s[1]==1&&s[1]-s[0]==1) {count+=200;
  return true;
  }
  else {
    string a=s;
    sort(a.begin(),a.end());
    if(a[2]-a[1]==1&&a[1]-a[0]==1) 
    {count+=100;
    return true;
       }
  }
  return false;
}
int check(string s)
{
  int l =s.length();
  int count=0;
  for (int i=0;i<=l-3;i+=3)
  {
    string sub = s.substr(i, 3);
    if(sub[0]==sub[1]&&sub[1]==sub[2]) {count+=200;
    }
    else if(lianxu(sub,count)) {}
    else if(sub[0] == sub[1] || sub[1] == sub[2] || sub[0] == sub[2]){
    count+=100;
    }
    
    }
    return count; 
  }
int main()
{
 
 ios::sync_with_stdio(false);
 cin.tie(0);
 int n;
 cin>>n;
 int mp[3][n];
 for(int i=0;i<3;i++)
 {
   for(int j=0;j<n;j++)
   {
     cin>>mp[i][j];
   }
 }
 int m;
 cin>>m;
 string s="";
 int p1=0,p2=0,p3=0;
for (int j = 0; j < m; j++) {
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        
        // 更新位置
        p1 = (p1 + x1) % n;
        p2 = (p2 + x2) % n;
        p3 = (p3 + x3) % n;

        // 拼接成字符串
        s += (char)(mp[0][p1] + '0');
        s += (char)(mp[1][p2] + '0');
        s += (char)(mp[2][p3] + '0');
    }

    // 最后统一计算总分
    cout << check(s) << endl;
}
// 最近的和最近的相互匹配一下 （算多个0 和多个1 之间距离的最小值） 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> pos0(n), pos1(n);

    // 1. 只记录 0 的位置
    for(int i = 0; i < n; i++) {
        cin >> pos0[i];
    }

    // 2. 只记录 1 的位置
    for(int i = 0; i < n; i++) {
        cin >> pos1[i];
    }

    // 3. 排序（这是贪心算法的核心：让左边的匹配左边的）
    sort(pos0.begin(), pos0.end());
    sort(pos1.begin(), pos1.end());

    // 4. 计算总距离
    ll total_dist = 0;
    for(int i = 0; i < n; i++) {
        total_dist += abs(pos0[i] - pos1[i]);
    }

    cout << total_dist << endl;

    return 0;
}
