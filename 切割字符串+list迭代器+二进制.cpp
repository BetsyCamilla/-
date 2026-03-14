#include <bits/stdc++.h>
using namespace std;
list<int> q1,q2;
int state[10005]; // 0=不在 1=q1 2=q2
list<int>::iterator pos1[10005];//迭代器 （节点 双向链式的删除） 
list<int>::iterator pos2[10005];//迭代器 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n1,n2,m;
  cin>>n1>>n2>>m;
  while(m--)
  {
    int x;
    cin>>x;
    int cur_state = state[x];
    if(cur_state == 0)
    {
      q2.push_front(x);
      pos2[x]=q2.begin();
      state[x] = 2;//记账：进q2了
      if(q2.size()>n2)
      {
        int last = q2.back();
        state[last] = 0;
        q2.pop_back();
      }
    }
    else{
      if(cur_state == 1)
      {
      q1.erase(pos1[x]);
      
      }
      else{
        
        q2.erase(pos2[x]);
      }
      
      q1.push_front(x);
      pos1[x]=q1.begin();
      state[x] = 1;
      if(q1.size()>n1)
      {
        int out=q1.back();
        q1.pop_back();
        state[out] = 0;
        if(q2.size()<n2)
        {
          q2.push_front(out);
          pos2[out]=q2.begin();
          state[out] = 2;
        }
        else{
          state[out]=0;
        }
       
      }
      
    
    }
  }
 bool is_first = true;

    // 先倒 q1 的果果
    for (auto v:q1) {
        if (!is_first) cout << " ";
        cout << v;
        is_first = false;
    }
    cout << "\n";
    is_first = true;
    // 接着倒 q2 的果果，只要前面倒过数，is_first 就是 false，这里就会自动补空格
    for (auto v:q2) {
        if (!is_first) cout << " ";
        cout << v;
        is_first = false;
    }
    cout << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int bitcount(int x)
{
 if (x==0) return 0;
  string ans="";
  int bitc=0;
  while(x>0)
  {
    ans+=('0'+(x%2));//数除以二的余数 
    x/=2;
  }
  reverse(ans.begin(),ans.end());//倒着的余数便是二进制的排列 
  for(char c:ans)
  {
    if(c=='1') bitc++;
  }
  return bitc;
}
int bianhuan(int &x,int m)
{
  while(m--)
  {
    x=x*bitcount(x);
  }
  return x;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  vector<int>a(1e4);
  for(int i =0;i<n;i++)
  {
    cin>>a[i];
  }
  int m;
  cin>>m;
  for(int i=0;i<n;i++)
  {
    cout<<bianhuan(a[i],m)<<" ";
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h,w;
  cin>>h>>w;
  string s="2025";
  string ans="";
  while(ans.length()<h+w) //就是 2025的插入 多个插入 小于h+w 就可以满足所有情况 
  {
    ans+=s;
  }
  for(int i=0;i<h;i++)
  {
    cout<<ans.substr(i,w)<<"\n";//切割字符串 
  }
  return 0;
}
