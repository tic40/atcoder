#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

using S = int;
using F = int;
S op (S a, S b) { return max(a,b); }
S e() { return 0; }
S mapping(F f, S x) { return f+x; }
F composition(F f, F g) { return f+g; }
F id() { return 0; }

int main() {
  int n,d; cin >> n >> d;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  lazy_segtree<S, op, e, F, mapping, composition, id> seg(500001);
  REP(i,n) {
    // a[i] の制約は 0 <= a[i] <= 500000 のため
    int l = max(0,a[i]-d);
    int r = min(500000,a[i]+d);
    int mx = seg.prod(l,r+1)+1;
    seg.set(a[i],mx);
  }
  cout << seg.all_prod() << endl;
  return 0;
}