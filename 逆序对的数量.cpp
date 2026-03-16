//逆序对的数量
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
/*void MergeSort(ll a[],int l,int r)
{
	if(l==r) return;
	int mid=(l+r)/2;
	MergeSort(a,l,mid);
	MergeSort(a,mid+1,r);
	int pl=l,pr=mid,pb=l;
	while(pl<=mid||pr<=r)
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
			if(a[pl]<a[pr])b[pb++]=a[pl++];
			else b[pb++]=a[pr++];
		}
	}
	for(int i=l;i<=r;i++) a[i]=b[i];
}*/
#include <iostream>
#include <vector>

// 使用 long long 来存储逆序对的数量，防止整数溢出
// 当 N=500000 时，逆序对数量最多可达 N*(N-1)/2，会超过 int 范围
long long merge_sort_and_count(vector<int>& arr, int l, int r) {
    // 当区间只有一个元素或没有元素时，不存在逆序对
    if (l >= r) {
        return 0;
    }

    // 1. 分解
    int mid = l + (r - l) / 2;
    
    // 2. 解决子问题
    // 计算左半部分的逆序对数量
    long long count = merge_sort_and_count(arr, l, mid);
    // 计算右半部分的逆序对数量
    count += merge_sort_and_count(arr, mid + 1, r);

    // 3. 合并，并计算跨越左右两部分的逆序对数量
    vector<int> temp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            // 核心步骤：arr[i] > arr[j]
            // 说明从 arr[i] 到 arr[mid] 的所有元素都比 arr[j] 大
            // 产生了 (mid - i + 1) 个逆序对
            count += (mid - i + 1);
            j++;
        }
    }

    // 处理剩余的元素
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= r) {
        temp.push_back(arr[j]);
        j++;
    }

    // 将排好序的临时数组复制回原数组的对应位置
    for (int k = 0; k < temp.size(); ++k) {
        arr[l + k] = temp[k];
    }

    return count;
}

int main() {
    // C++ 中为了提高输入输出效率，通常会加上这两句
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long inversions = merge_sort_and_count(arr, 0, n - 1);

    cout << inversions << endl;

    return 0;
}
