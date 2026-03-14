#include <bits/stdc++.h>
using namespace std;
bool check_max(int v,int n,const vector<pair<int,int>>&records){
  for(int i=0;i<n;i++)
  {
    if(records[i].first / v<records[i].second){ //V太大了 返回false 
      return false;
    }
  }
  return true;//V还可以更大，返回true 
}
bool check_min(int v,int n,const vector<pair<int,int>>&records){
  for(int i=0;i<n;i++)
  {
    if(records[i].first / v>records[i].second){//V太小了，返回false 
      return false;
    }
  }
  return true;//v还可以更小，返回true 
}
int main()
{
  int n;
  cin>>n;
vector<pair<int,int>>records(n);
for(int i=0;i<n;i++)
{
  cin>>records[i].first>>records[i].second;
}
  int low=1;
  int high=1e9+7;
  int v_max=low; 
  while(low<=high)
  {
    int mid=low+(high-low)/2;//防止溢出 
    if(check_max(mid,n,records))//mid还可以再大 
    {
      v_max=mid;//先mid赋值给v_max 
      low=mid+1;//从mid+1继续找更大的数 
    }
    else{
      high=mid-1;//v（mid）太大了 ，往小的找 
      
    }
  }
   low=1;
   high=1e9+7;
  int v_min=high;
  while(low<=high)
  {
    int mid=low+(high-low)/2;
    if(check_min(mid,n,records)){//mid还可以更小 
      v_min=mid;
      high=mid-1;
    }
    else{
      low=mid+1;//mid太小了往大的找 
    }
  }
  cout<<v_min<<" "<<v_max<<endl;
  return 0;
}




