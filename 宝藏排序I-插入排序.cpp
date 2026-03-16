//±¶≤ÿ≈≈–Ú
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++)
	{
		int val=a[i],j;
		for(j=i;j>1&&val<a[j-1];j--)
		{
			a[j]=a[j-1];
		}
		a[j]=val;
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
	return 0;
}
