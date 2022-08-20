#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

ll op(ll a, ll b) { return max(a, b); }
ll e() { return 0; }

int main() {
  int n; cin >> n;
  vector<ll> h(n),a(n);
  REP(i,n) cin >> h[i];
  REP(i,n) cin >> a[i];

  segtree<ll, op, e> seg(1<<18);
  REP(i,n) {
    ll opt = seg.prod(0, h[i]) + a[i];
    seg.set(h[i],opt);
  }

  cout << seg.all_prod() << endl;
  return 0;
}