//【真题】封闭图形个数
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
typedef long long ll;
ll a[N];
int pic(ll x)
{
	int cnt=0;
	string s=to_string(x);
	for(char c:s)
	{
		int num=c-'0';
		if(num==0||num==4||num==6||num==9) cnt++;
		else if(num==8) cnt+=2;
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,[](const ll &x,const ll &y)
	{
		int px = pic(x);
		int py = pic(y);
		return px == py ? x < y : px < py;
	});
	for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
	return 0; 
}
