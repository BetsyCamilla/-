//ÆåÅÌ
#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int mp[N][N];
int diff[N][N];
int n,m;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	memset(mp,0,sizeof mp);//È«ÊÇ°××Ó 
    for(int i=1;i<=n;i++)
    {
     for(int j=1;j<=n;j++)
     {
     	diff[i][j]=mp[i][j]-mp[i-1][j]-mp[i][j-1]+mp[i-1][j-1];
	 }    	   	
	}
	for(int i=1;i<=m;i++)
    {
    	int x1,y1,x2,y2;
    	cin>>x1>>y1>>x2>>y2;
    	diff[x1][y1]+=1;
    	diff[x2+1][y1]-=1;
    	diff[x1][y2+1]-=1;
    	diff[x2+1][y2+1]+=1;
	}
	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				mp[i][j]=diff[i][j]+mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1];
				if(mp[i][j]%2==0) mp[i][j]=0;
				else mp[i][j]=1;
				cout<<mp[i][j];
			 } 
			 cout<<'\n';
		 } 
	return 0; 
 } 
