//矩阵相乘
#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N][N];
int b[N][N];
int ans[N][N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
		for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			ans[i][j]=0;//矩阵数学原理上是所有数能相加就相加 
			for(int l=1;l<=m;l++)
			{
					ans[i][j]+=a[i][l]*b[l][j];
			}
			cout<<ans[i][j]<<' ';
		}
		cout<<"\n";
	}
	return 0;
}
