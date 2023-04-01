#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  ll n,m; cin >> n >> m;

  ll ans = LINF;
  for(ll a = 1; a*a <= 1e15; a++) {
    ll b = (m+a-1)/a;
    if (a <= n && b <= n && a*b >= m) ans = min(ans,a*b);
  }

  if (ans == LINF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}