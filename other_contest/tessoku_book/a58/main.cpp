#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int op(int a, int b) { return max(a, b); }
int e() { return 0; }

int main() {
  int n,q; cin >> n >> q;

  segtree<int, op, e> seg(n);
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      int pos,x; cin >> pos >> x;
      pos--;
      seg.set(pos,x);
    } else {
      int l,r; cin >> l >> r;
      l--; r--;
      cout << seg.prod(l,r) << endl;
    }
  }
  return 0;
}