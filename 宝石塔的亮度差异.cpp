//宝石塔的亮度差异
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
typedef long long ll;
int min_light=0;
int a[N*N],b[N*N];
int n;
void MergeSort(int a[],int l,int r)
{
	if(l==r) return;
	int mid=(l+r)/2;
	MergeSort(a,l,mid);
	MergeSort(a,mid+1,r);
	int pl=l,pr=mid+1,pb=l;
	while(pl<=mid&&pr<=r)
	{
	  if(pl>mid)
	  {
	  	b[pb++]=a[pr++];
	   } 
	   else if(pr>r)
	   {
	   	b[pb++]=a[pl++];
	   }
	   else 
	   {
	   	if(a[pl]<a[pr]) b[pb++]=a[pl++];
	   	else b[pb++]=a[pr++];
	   }
	}
	for(int i=l;i<=r;i++) a[i]=b[i];
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
// 对应第二行输入：读取第一个宝石塔的 N 个亮度值 (A1...AN)
for(int i = 1; i <= n; i++) cin >> a[i];

// 对应第三行输入：读取第二个宝石塔的 N 个亮度值 (B1...BN)，直接拼接在后面
for(int i = n + 1; i <= 2 * n; i++) cin >> a[i];
MergeSort(a, 1, 2 * n);
int min_light = 2e9; // 初始化为一个很大的数（2乘10的9次方）
    
    // 我们要在 2N 个宝石中，挑出连续的 N 个。
    // 窗口的起点 i 可以从 1 开始，最多滑动到 n + 1。
    for(int i = 1; i <= n + 1; i++)
    {
        // 窗口的起点是 a[i]，终点是 a[i + n - 1]
        int current_diff = a[i + n - 1] - a[i];
        
        // 更新最小值
        if(current_diff < min_light)
        {
            min_light = current_diff;
        }
    }
    
    // 输出最终答案
    cout << min_light << "\n";
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;

const int N=2005;
int a[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n+1;i<=2*n;i++) cin>>a[i];

    sort(a+1,a+2*n+1);

    int ans=2e9;

    for(int i=1;i<=n+1;i++)
        ans=min(ans,a[i+n-1]-a[i]);

    cout<<ans;
}*/
