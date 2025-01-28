#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

using S = int;
using F = int;
S op(S a, S b) { return max(a,b); }
S e() { return 0; }
S mapping(F f, S x) { return x+f; }
F composition(F f, F g) { return f+g; }
F id() { return 0; }

int main() {
  int n; cin >> n;

  const int m = 5e5+5;
  vector<int> initial(m);
  iota(initial.begin(),initial.end(),0);
  lazy_segtree<S, op, e, F, mapping, composition, id> t(initial);

  auto lwb = [&](int x) {
    auto f = [&](int a) { return a < x; };
    return t.max_right(0,f);
  };

  REP(i,n) {
    int l,r; cin >> l >> r;
    r++;
    int li = lwb(l);
    int ri = lwb(r);
    t.apply(li,ri,1);
  }

  int q; cin >> q;
  REP(i,q) {
  int x; cin >> x;
    int ans = t.get(x);
    cout << ans << endl;
  }
  return 0;
}