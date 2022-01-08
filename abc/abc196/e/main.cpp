#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const ll INF = 1e9;

int n,q;
vector<ll> a,t,x;

void solve() {
  ll s = 0, l = -INF, r = INF;
  REP(i,n) {
    if (t[i] == 1) { // +
      s += a[i];
      l += a[i];
      r += a[i];
    } else if (t[i] == 2) { // max
      l = max(l,a[i]);
      r = max(r,a[i]);
    } else { // min
      l = min(l,a[i]);
      r = min(r,a[i]);
    }
  }

  REP(i,q) {
    ll ans = x[i]+s;
    if (ans < l) ans = l;
    if (r < ans) ans = r;
    cout << ans << endl;
  }
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  t.resize(n);
  REP(i,n) cin >> a[i] >> t[i];

  cin >> q;
  x.resize(q);
  REP(i,q) cin >> x[i];

  solve();
  return 0;
}