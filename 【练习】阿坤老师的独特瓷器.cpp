//【练习】阿坤老师的独特瓷器
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node
{
	int d,h;
	bool operator<(const node &m)const
	{
		return d==m.d?h>m.h:d<m.d;
	}
};
int n;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	node arr[N];
	for(int i=1;i<=n;i++) cin>>arr[i].d>>arr[i].h;
	sort(arr+1,arr+n+1);
	int ans=0;
	int max_h=0;
	for(int i = n; i >= 1; i--)
    {
    	if(arr[i].h >= max_h)
        {
            ans++;
            max_h = arr[i].h;
            }
    
    }
    
    // 最终打出答案
    cout << ans << "\n";
	return 0;        
}
/*因为d是从小到大排的 
如果d相同h从大往小排 从
后面开始 如果h>max_h 就说明不存在即大于d又大于h的瓷器了,也就是独特瓷器*/
