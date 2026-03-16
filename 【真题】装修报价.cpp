//×°ÐÞ±¨¼Û-real
#include <bits/stdc++.h> 
using namespace std; 
using ll=long long;
 const int N=1e5+9,p=1e9+7;
  ll a[N],prefix[N],pow3[N]={1},sum;
  int main() 
  { int n;cin >> n; 
  for(int i=1;i<=n;i++)cin >> a[i]; 
  for(int i=1;i<=n;i++)prefix[i]=prefix[i-1]^a[i];
   for(int i=1;i<=n;i++)pow3[i]=pow3[i-1]*3%p; 
   for(int i=1;i<n;i++)sum=(sum+(2*pow3[n-i-1]*prefix[i])%p)%p; 
   sum=(sum+prefix[n])%p; 
   cout << sum;
    return 0;
	 }
