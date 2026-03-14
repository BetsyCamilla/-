//平衡串
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
string s;
int len=0;
void dfs(int cnt)//cnt表示切的长度 
{
	if(cnt>s.length())
	{
		return;
	}
	
    for(int i=0;i+cnt<=s.length();i++)
	{
		string res=s.substr(i,cnt);
		int a=0;
		int b=0;
		for(char c:res)
		{
			if(c=='L') a++;
			else if(c=='Q') b++;
			
		}
		if(a==b) len=max(len,cnt);
	}
	dfs(cnt+1);
 } 
 int main()
 {
 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	 cin>>s;
 	dfs(2);
 	cout<<len<<'\n';
 	return 0;
 }
