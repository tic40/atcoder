#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n,q;
vector<ll> a,l,r,v;

void solve() {
  vector<ll> b(n);
  ll ans = 0;

  REP(i,n-1) {
    b[i] += a[i+1]-a[i];
    ans += abs(b[i]);
  }

  REP(i,q) {
    ll before = abs(b[l[i] - 1]) + abs(b[r[i]]);

    if (0 < l[i]) b[l[i] - 1] += v[i];
    if (r[i] < n-1) b[r[i]] -= v[i];

    ll after = abs(b[l[i] - 1]) + abs(b[r[i]]);

    ans += after - before;
    cout << ans << endl;
  }
  return;
}

int main() {
  cin >> n >> q;
  a.resize(n);
  REP(i,n) cin >> a[i];
  l.resize(q);
  r.resize(q);
  v.resize(q);
  REP(i,q) {
    cin >> l[i] >> r[i] >> v[i];
    l[i]--; r[i]--;
  }

  solve();
  return 0;
}