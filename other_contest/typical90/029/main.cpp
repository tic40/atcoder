#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

using S = int;
using F = int;
S op(S a, S b) { return max(a,b); }
S e() { return 0; }
S mapping(F f, S x) { return max(x,f); }
F composition(F f, F g) { return max(f,g); }
F id() { return 0; }

int main() {
  int w,n; cin >> w >> n;
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(w+1);
  REP(i,n) {
    int l,r; cin >> l >> r;
    int now = seg.prod(l,r+1) + 1;
    seg.apply(l,r+1,now);
    cout << now << endl;
  }
  return 0;
}