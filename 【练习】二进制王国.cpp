//【练习】二进制王国
#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> a;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++) 
	{
		string s;
        cin >> s; 
        a.push_back(s);	
	}
	sort(a.begin(),a.end(),[](const string &x,const string &y)
	{
		return x+y<y+x;//
	});
	for(int i=0;i<n;i++) cout<<a[i];
	return 0;
}
