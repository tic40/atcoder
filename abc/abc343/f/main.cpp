#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();

struct P {
  int val, num;
  P(int val=0, int num=0): val(val), num(num) {}
};

struct S {
  P a, b;
  S(P a=P(), P b=P()): a(a), b(b) {}
};

S _op(S x, P p) {
  if (p.val == x.b.val) {
    x.b.num += p.num;
    return x;
  }
  if (p.val == x.a.val) {
    x.a.num += p.num;
    return x;
  }
  if (p.val < x.b.val) return x;
  x.b = p;
  if (x.a.val < x.b.val) swap(x.a, x.b);
  return x;
}
S op(S x, S y) {
  return _op(_op(x, y.a), y.b);
}

S e() { return S(P(-INF-1,0),P(-INF,0));}

int main() {
  int n,q; cin >> n >> q;
  segtree<S,op,e> seg(n);
  REP(i,n) {
    int a; cin >> a;
    seg.set(i, S(P(a,1), P(-INF,0)));
  }

  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      int p,x; cin >> p >> x; p--;
      seg.set(p, S(P(x,1), P(-INF,0)));
    } else {
      int l,r; cin >> l >> r;
      l--;
      S s = seg.prod(l,r);
      int ans = s.b.num;
      cout << ans << endl;
    }
  }
  return 0;
}