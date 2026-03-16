//三体攻击
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
int d[N];
int a,b,c,m;
int main()
{
	cin>>a>>b>>c>>m;
	int total=a*b*c;
	vector<ll> d(total);     // 战舰生命值
    vector<ll> dmg(total, 0); // 累积伤害
	for(int i=1;i<=total;i++)
	{
		cin>>d[i];
	}

	for(int t=1;t<=m;t++)
	{
		int lat,rat,lbt,rbt,lct,rct;
		ll ht;
		 cin >> lat >> rat >> lbt >> rbt >> lct >> rct >> ht;

        for(int i = lat; i <= rat; i++) {
            for(int j = lbt; j <= rbt; j++) {
                for(int k = lct; k <= rct; k++) {
                    int pos = ((i-1)*b + (j-1))*c + (k-1)+1;
                    dmg[pos] += ht;
                    if(dmg[pos] > d[pos]) {
                        cout << t << "\n"; // 第一个爆炸战舰轮次
                        return 0;
	}
}
}
}
}
return 0;
}
