#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = 1e18;

ll op(ll a, ll b) { return min(a, b); }
ll e() { return LINF; }

int main() {
  int n,l,k; cin >> n >> l >> k;
  segtree<ll, op, e> seg(l+1);
  REP(i,n) {
    int a; ll c; cin >> a >> c;
    seg.set(a, min(seg.get(a),c));
  }

  ll ans = 0;
  for(int i = 1; i <= l-k; i++) {
    ll now = seg.prod(i,i+k);
    if (now == LINF) { cout << -1 << endl; return 0; }
    ans += now;
  }

  cout << ans << endl;
  return 0;
}