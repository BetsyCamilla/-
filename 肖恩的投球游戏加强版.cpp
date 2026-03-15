//肖恩的投球游戏加强版
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N][N];
int b[N][N];
int n,m,q;
void insert(int x1,int y1,int x2,int y2,int v)
{
	b[x1][y1]+=v;
	b[x1][y2+1]-=v;
	b[x2+1][y1]-=v;
	b[x2+1][y2+1]+=v;
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
			insert(i,j,i,j,a[i][j]);
		}
	}
	while(q--)
	{
		int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    // 前缀和还原
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = b[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
	
