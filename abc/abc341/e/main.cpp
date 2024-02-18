#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

using S = int;
using F = int;
S op(S a, S b){ return a+b; }
S e(){ return 0; }
S mapping(F f, S x){ return f^x; }
F composition(F f, F g){ return f^g; }
F id(){ return 0; }

int main() {
  int n,q; cin >> n >> q;
  string s; cin >> s;
  // lazy じゃなくていい
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(n+1);
  REP(i,n-1) if (s[i] != s[i+1]) seg.set(i+1, 1);

  REP(_,q) {
    int t,l,r; cin >> t >> l >> r;
    if (t == 1) {
      seg.set(l-1, seg.get(l-1)^1);
      seg.set(r, seg.get(r)^1);
    } else {
      auto v = seg.prod(l,r);
      cout << (v == r-l ? "Yes" : "No") << endl;
    }
  }
  return 0;
}