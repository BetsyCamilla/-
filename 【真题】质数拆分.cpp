//ÖÊÊı²ğ·Ö
#include<bits/stdc++.h>
using namespace std;
const int N=2025;
bitset<N> vis;
vector<int> primes;
int f[N];
void aishi(int x)
{
	vis[0]=vis[1]=true;
	for(int i=2;i<=x;i++)
	{
		if(!vis[i])
		{
			for(int j=2*i;j<=x;j+=i) vis[j]=true;
		}
	}
	for(int i=1;i<=x;i++) if(!vis[i]) primes.push_back(i);
}
int main()
{
	int x=2022;
	aishi(2022);
	f[0]=0;
	for(int p:primes)
	{
		for(int j=x;j>=p;j--)
		{
			f[j]=max(f[j],f[j-p]+1);
		}
	}
	cout<<f[2022]<<"\n";
	return 0;
 } 
