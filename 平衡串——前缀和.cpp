//平衡串-使用前缀和的方法
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	unordered_map<int,int> mp;
	int sum=0;
	int ans=0;
	mp[0]=-1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='L') sum++;
		else sum--;
	if(mp.count(sum))
	{
		ans=max(ans,i-mp[sum]);
	}
	else {
		mp[sum]=i;
	}
	}
	cout<<ans<<'\n';
	return 0;
}
