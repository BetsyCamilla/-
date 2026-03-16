//例题:给定a数组求a的离散化数组，并可以通过值找到下标。
/*lower_bound 是找到第一个x*/
#include<bits/stdc++.h>
using namespace std;
vector<int> L;
int getidx(int x)
{
	int idx=lower_bound(L.begin(),L.end(),x)-L.begin();
	return idx;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,num;
	cin>>n;
	 for(int i=1;i<=n;i++)
	 {
	 	int x;
	 	cin>>x;
	 	L.push_back(x);
	  } 
	  sort(L.begin(),L.end());
	  L.erase(unique(L.begin(),L.end()),L.end());//排序去除模板 
	  cin>>num;
	  cout<<getidx(num);
	  return 0;
	 
}

