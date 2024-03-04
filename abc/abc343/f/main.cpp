#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();

// 値とその個数のペア
struct P {
  int val, num;
  P(int val=0, int num=0): val(val), num(num) {}
};

// segtree に乗せる値(構造体)
// a: 1番目の区間の最大値，区間の最大値の個数
// b: 2番目の区間の最大値，区間の最大値の個数
struct S {
  P a, b;
  S(P a=P(), P b=P()): a(a), b(b) {}
};

S _op(S x, P p) {
  // p.val と x の 2 番目の値が同じ
  // x の 2番目の個数を加算
  if (p.val == x.b.val) { x.b.num += p.num; return x; }
  // p.val と x の 1 番目の値が同じ
  // x の 1 番目の個数を加算
  if (p.val == x.a.val) { x.a.num += p.num; return x; }
  // p.val より x の 2 番目の値の方が大きい
  // x に変更はないのでそのまま return
  if (p.val < x.b.val) return x;
  // 上記以外のとき( p.val > x.b.val )
  // x の 2番目の値を p に更新
  x.b = p;
  // 逆転していたら swap する
  if (x.a.val < x.b.val) swap(x.a, x.b);
  return x;
}
// 区間結合時の二項演算 op
S op(S x, S y) { return _op(_op(x, y.a), y.b); }
// 単位元
S e() { return S(P(-INF-1,0),P(-INF,0));}

int main() {
  int n,q; cin >> n >> q;
  segtree<S,op,e> seg(n);
  REP(i,n) {
    int a; cin >> a;
    // 初期値の set
    // 1 番目は値 a が 1 つ、2 番目の値ないので十分小さい値で 0 個としておく
    seg.set(i, S(P(a,1), P(-INF,0)));
  }

  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      int p,x; cin >> p >> x; p--;
      // 1 点更新処理
      // p 番目の値を x に更新
      seg.set(p, S(P(x,1), P(-INF,0)));
    } else {
      int l,r; cin >> l >> r; l--;
      cout << seg.prod(l,r).b.num << endl;
    }
  }
  return 0;
}