#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;
const int mod = 1e+9+7;

ll f(ll n) {
  if (n==1) return 1;
  return n * f(n-1) % mod;
}

int main() {
  int n,m; cin >> n >> m;
  if (abs(n-m) > 1) { cout << 0 << endl; return 0; }

  ll ans=f(n) * f(m) % mod;
  if (n==m) ans*=2;

  cout << ans%mod << endl;
  return 0;
}
