#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,q; cin >> n >> q;
  vector<int> t(q),x(q),y(q),v(q);
  REP(i,q) {
    cin >> t[i] >> x[i] >> y[i] >> v[i];
    x[i]--; y[i]--;
  }

  vector<ll> s(n), potential(n);
  // s[i] := a[i]+a[i+1]
  REP(i,q) if (t[i] == 0) s[x[i]] = v[i];
  // a[0] = 0 としたときの a[i+1] = s[i] - a[i]
  REP(i,n-1) potential[i+1] = s[i] - potential[i];

  dsu uf(n);
  REP(i,q) {
    if (t[i] == 0) { uf.merge(x[i],y[i]); continue; }
    // 連結していない
    if (!uf.same(x[i],y[i])) { cout << "Ambiguous" << endl; continue; }

    ll diff = v[i] - potential[x[i]];
    ll ans = potential[y[i]] + (abs(x[i]-y[i]) % 2 == 0 ? diff : -diff);
    cout << ans << endl;
  }
  return 0;
}