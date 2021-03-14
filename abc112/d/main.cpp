#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  ll n,m;
  cin >> n >> m;
  ll ans = 0;

  for (ll a = 1; a*a <= m; a++) {
    if (m%a != 0) continue;

    ll b = m/a;
    if (a*n <= m) ans = max(ans, a);
    if (b*n <= m) ans = max(ans, b);
  }

  cout << ans << endl;
  return 0;
}