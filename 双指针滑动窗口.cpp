//vector<vector<ll>>&s //二维矩阵
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,h;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>h;
  vector<ll>a(n);
  ll total=0;
  for(int i=0;i<n;i++)
  {
     cin>>a[i];
     total+=a[i];
  }
  if(total<=h) {cout<<total<<"\n";
  return 0;}
  ll target=total-h; //后续用while作比较用时的变量 
  ll current=0;//现在兜里的糖 
  ll min_left=total;//最少扔的糖，初始值是全部； 
  ll left=0;//左手 慢 
  for(ll right=0;right<n;right++)//右手 拿糖 （准备可能被扔掉的糖） 
  {
    current+=a[right];
    while(current>=target)//如果多了就用左手扔掉 
    {
     min_left=min(min_left,current);//不断刷新最少扔的糖数量 
     current-=a[left];//左手扔糖 
     left++; //左手位置+1，保证其的连续性 
    }
  }
  cout<<total-min_left<<"\n";
  return 0;
}
 
