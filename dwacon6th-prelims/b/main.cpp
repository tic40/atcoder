#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const int mod=1e9+7;

ll inv(ll x) {
  return x == 1 ? x : (mod-mod/x)*inv(mod%x)%mod;
}

int main() {
  int n;
  cin >> n;
  int a[n+1];
  for(int i=1; i<=n; i++) cin >> a[i];
  ll ans=0,c=0;
  for(int i=1; i<n; i++){
    c = (c+inv(i)) % mod;
    ans = (ans+c*(a[i+1]-a[i])) % mod;
  }
  for(int i=2; i<=n-1; i++) ans = ans * i % mod;
  cout << ans << endl;
}