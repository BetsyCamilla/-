//二维前缀和
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,q;
int sum[N][N];
int a[N][N];
int get_sum(int x1,int y1,int x2,int y2)
{
	if(x1>x2||y1>y2) return 0;
	return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
 } 
 int main()
 {
 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 	cin>>n>>m>>q;
 	for(int i=1;i<=n;i++)
 	{
 		for(int j=1;j<=m;j++)
 		{
 			cin>>a[i][j];
		 }
	 }
	 	for(int i=1;i<=n;i++)
 	{
 		for(int j=1;j<=m;j++)
 		{
 			sum[i][j]=sum[i][j-1]+a[i][j];
		 }
		for (int j = 1; j <= m; ++j) {
            sum[i][j] += sum[i - 1][j]; // 二维前缀和处理。
        } 
	 }
	 for(int i=1;i<=q;i++)
	 {
	 	int x1,y1,x2,y2;
	 	cin>>x1>>y1>>x2>>y2;
	 	cout<<get_sum(x1,y1,x2,y2)<<'\n';
	 }
	 return 0;
 }
