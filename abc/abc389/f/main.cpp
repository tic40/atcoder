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

  // 取りうるレート x の値のシミュレーションを事前計算しておく
  const int m = 5e5+1;
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(m);
  REP(i,m) seg.set(i,i);

  // lower bound
  auto lwb = [&](int x) {
    auto f = [&](int a) { return a < x; };
    return seg.max_right(1,f);
  };

  REP(i,n) {
    int l,r; cin >> l >> r;
    // レーティングが l 以上 r 以下の範囲の区間へ 1 加算
    // 区間に 1 ずつ加算するので必ず単調増加になっている
    seg.apply(lwb(l),lwb(r+1),1);
  }

  int q; cin >> q;
  REP(i,q) {
    int x; cin >> x;
    cout << seg.get(x) << endl;
  }
  return 0;
}