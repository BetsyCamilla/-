//°æ’ÊÃ‚°ø∆Ê≈º≈≈–Ú
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n;
int a[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,[](const int &x,const int &y)
	{
		 if ((x & 1) != (y & 1)) 
        {
            return (x & 1) > (y & 1); 
        }
        return x < y;
	});
	for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
	return 0;
}
